/*++

Copyright (c) 1997-1999  Microsoft Corporation

Module Name:

    tracelog.c

Abstract:

    Sample trace control program. Allows user to start, stop event tracing


--*/
#ifndef UNICODE
#define UNICODE
#endif
#ifndef _UNICODE
#define _UNICODE
#endif

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <shellapi.h>
#include <tchar.h>
#include <wmistr.h>
#include <initguid.h>
#include <guiddef.h>
#include <evntrace.h>
#include <wmiguid.h>

#define MAXSTR                          1024
#define DEFAULT_LOGFILE_NAME            _T("C:\\LogFile.Etl")

#define MAXIMUM_LOGGERS_W2K             32
#define MAXIMUM_LOGGERS_XP              64
#define MAXGUIDS                        128

#define ACTION_QUERY                    0
#define ACTION_START                    1
#define ACTION_STOP                     2
#define ACTION_UPDATE                   3
#define ACTION_LIST                     4
#define ACTION_ENABLE                   5
#define ACTION_HELP                     6
#define ACTION_FLUSH                    7
#define ACTION_ENUM_GUID                8
#define ACTION_UNDEFINED               10

#define IsEqualGUID(rguid1, rguid2) (!memcmp(rguid1, rguid2, sizeof(GUID)))
#define WSTRSIZE(str) (ULONG) ( (str) ? ((PCHAR) &str[wcslen(str)] - (PCHAR)str) + sizeof(UNICODE_NULL) : 0 )

// Functions not implemented on Win2K need to be searched and loaded separately.
// To make further accesses easy, an array of function pointers will be used.
// The following list serves as indices to that array.
//
// If new functions are added to evntrace.h, the following list should be updated
// as well as the array initialization routine at the beginning of main(). 
#define FUNC_FLUSH_TRACE        0
#define FUNC_ENUM_TRACE_GUIDS   1
// Funtion pointer array for unimplemented functions on Win2K.
// Note: This may not work if this code is ported to C++, because
// all the function pointers may be typedefed differently.
#define MAXFUNC                 10
FARPROC FuncArray[MAXFUNC];
HINSTANCE advapidll;

BOOLEAN XP;

//keep track of whether or not the kernel debugging option has been turned on to assure the buffer size is no greater than 3 kb
BOOLEAN kdOn = FALSE;

void
PrintLoggerStatus(
    IN PEVENT_TRACE_PROPERTIES LoggerInfo,
    IN ULONG Status,
    IN BOOL PrintStatus
    );

#define PRINTSTATUS TRUE
#define NOPRINTSTATUS FALSE

LPTSTR
DecodeStatus(
    IN ULONG Status
    );

LONG
GetGuids(
    IN LPTSTR GuidFile, 
    OUT LPGUID *GuidArray
    );

ULONG 
ahextoi(
    IN TCHAR *s
    );

void 
StringToGuid(
    IN TCHAR *str,
    OUT LPGUID guid
    );

PTCHAR 
GuidToString(
    IN OUT PTCHAR s,
    IN LPGUID piid
    );

TCHAR ErrorMsg[MAXSTR];

void 
PrintHelpMessage();


//
//  main function
//
__cdecl main(argc, argv)
    int argc;
    char **argv;
/*++

Routine Description:

    It is the main function.

Arguments:
  

Return Value:

    Error Code defined in winerror.h : If the function succeeds, 
                it returns ERROR_SUCCESS (== 0).


--*/{
    ULONG i, j;
    LONG GuidCount;
    USHORT Action = ACTION_UNDEFINED;
    ULONG Status = 0;
    LPTSTR LoggerName;
    LPTSTR LogFileName;
    TCHAR GuidFile[MAXSTR];
    PEVENT_TRACE_PROPERTIES pLoggerInfo;
    TRACEHANDLE LoggerHandle = 0;
    LPTSTR *targv, *utargv = NULL;
    LPGUID *GuidArray;
    char *Space;
    char *save;
    BOOL bKill = FALSE;
    BOOL bForceKill = FALSE ;
    BOOL bEnable = TRUE;
    ULONG iLevel = 0;
    ULONG iFlags = 0;
    ULONG SizeNeeded = 0;
    ULONG specialLogger = 0;
    ULONG GlobalLoggerStartValue = 0;
    PULONG pFlags = NULL;

    BOOL bProcess = TRUE;
    BOOL bThread  = TRUE;
    BOOL bDisk    = TRUE;
    BOOL bNetwork = TRUE;

    OSVERSIONINFO OSVersion;

    OSVersion.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
    XP = FALSE;
    if (GetVersionEx(&OSVersion)) {
        XP = (OSVersion.dwMajorVersion > 5) ||
                    ((OSVersion.dwMajorVersion == 5) && (OSVersion.dwMinorVersion > 0));
    }

    // Load functions that are not implemented on Win2K
    for (i = 0; i < MAXFUNC; ++i)
        FuncArray[i] = NULL;
    if (XP) {
        advapidll = LoadLibrary(_T("advapi32.dll"));
        if (advapidll != NULL) {
#ifdef UNICODE
            FuncArray[FUNC_FLUSH_TRACE] = GetProcAddress(advapidll, "FlushTraceW");
#else
            FuncArray[FUNC_FLUSH_TRACE] = GetProcAddress(advapidll, "FlushTraceA");
#endif
            FuncArray[FUNC_ENUM_TRACE_GUIDS] = GetProcAddress(advapidll, "EnumerateTraceGuids");
        }
    }

    // Initialize structure first
    SizeNeeded = sizeof(EVENT_TRACE_PROPERTIES) + 2 * MAXSTR * sizeof(TCHAR);
    pLoggerInfo = (PEVENT_TRACE_PROPERTIES) malloc(SizeNeeded);
    if (pLoggerInfo == NULL) {
        if (advapidll != NULL)
            FreeLibrary(advapidll);
        return (ERROR_OUTOFMEMORY);
    }
    

    RtlZeroMemory(pLoggerInfo, SizeNeeded);

    pLoggerInfo->Wnode.BufferSize = SizeNeeded;
    pLoggerInfo->Wnode.Flags = WNODE_FLAG_TRACED_GUID; 
    pLoggerInfo->LoggerNameOffset = sizeof(EVENT_TRACE_PROPERTIES);
    pLoggerInfo->LogFileNameOffset = pLoggerInfo->LoggerNameOffset + MAXSTR * sizeof(TCHAR);

    LoggerName = (LPTSTR)((char*)pLoggerInfo + pLoggerInfo->LoggerNameOffset);
    LogFileName = (LPTSTR)((char*)pLoggerInfo + pLoggerInfo->LogFileNameOffset);
    _tcscpy(LoggerName, KERNEL_LOGGER_NAME);

    Space = (char*) malloc( (MAXGUIDS * sizeof(GuidArray)) +
                            (MAXGUIDS * sizeof(GUID) ));
    if (Space == NULL) {
        free(pLoggerInfo);
        if (advapidll != NULL)
            FreeLibrary(advapidll);
        return(ERROR_OUTOFMEMORY);
    }
    save = Space;
    GuidArray = (LPGUID *) Space;
    Space += MAXGUIDS * sizeof(GuidArray);

    for (GuidCount=0; GuidCount<MAXGUIDS; GuidCount++) {
        GuidArray[GuidCount] = (LPGUID) Space;
        Space += sizeof(GUID);
    }
    GuidCount = 0;

#ifdef UNICODE
    if ((targv = CommandLineToArgvW(
                      GetCommandLineW(),    // pointer to a command-line string
                      &argc                 // receives the argument count
                      )) == NULL) {
        free(pLoggerInfo);
        free(save);
        if (advapidll != NULL)
            FreeLibrary(advapidll);
        return (GetLastError());
    };
    utargv = targv;
#else
    targv = argv;
#endif

    pFlags = &pLoggerInfo->EnableFlags;
    //
    // Add default flags. Should consider options to control this independently
    //
    while (--argc > 0) {
        ++targv;
        if (**targv == '-' || **targv == '/') {  // argument found
            if(targv[0][0] == '/' ) targv[0][0] = '-';
            if (!_tcsicmp(targv[0], _T("-start"))) {
                Action = ACTION_START;
                if (argc > 1) {
                    if (targv[1][0] != '-' && targv[1][0] != '/') {
                        ++targv; --argc;
                        _tcscpy(LoggerName, targv[0]);
                    }
                }
            }
            else if (!_tcsicmp(targv[0], _T("-enable"))) {
                Action = ACTION_ENABLE;
                if (argc > 1) {
                    if (targv[1][0] != '-' && targv[1][0] != '/') {
                        ++targv; --argc;
                        _tcscpy(LoggerName, targv[0]);
                    }
                }
            }
            else if (!_tcsicmp(targv[0], _T("-disable"))) {
                Action = ACTION_ENABLE;
                bEnable = FALSE;
                if (argc > 1) {
                    if (targv[1][0] != '-' && targv[1][0] != '/') {
                        ++targv; --argc;
                        _tcscpy(LoggerName, targv[0]);
                    }
                }
            }
            else if (!_tcsicmp(targv[0], _T("-stop"))) {
                Action = ACTION_STOP;
                if (argc > 1) {
                    if (targv[1][0] != '-' && targv[1][0] != '/') {
                        ++targv; --argc;
                        _tcscpy(LoggerName, targv[0]);
                    }
                }
            }
            else if (!_tcsicmp(targv[0], _T("-update"))) {
                Action = ACTION_UPDATE;
                if (argc > 1) {
                    if (targv[1][0] != '-' && targv[1][0] != '/') {
                        ++targv; --argc;
                        _tcscpy(LoggerName, targv[0]);
                    }
                }
            }
            else if (!_tcsicmp(targv[0], _T("-q"))) {
                Action = ACTION_QUERY;
                if (argc > 1) {
                    if (targv[1][0] != '-' && targv[1][0] != '/') {
                        ++targv; --argc;
                        _tcscpy(LoggerName, targv[0]);
                    }
                }
            }
            else if (!_tcsicmp(targv[0], _T("-flush"))) {
                Action = ACTION_FLUSH;
                if (argc > 1) {
                    if (targv[1][0] != '-' && targv[1][0] != '/') {
                        ++targv; --argc;
                        _tcscpy(LoggerName, targv[0]);
                    }
                }
            }
            else if (!_tcsicmp(targv[0], _T("-enumguid"))) {
                Action = ACTION_ENUM_GUID;
            }
            else if (!_tcsicmp(targv[0], _T("-f"))) {
                if (argc > 1) {
                    if (XP) 
                        _tcscpy(LogFileName, targv[1]);
                    else 
                        _tfullpath(LogFileName, targv[1], MAXSTR);

                    ++targv; --argc;
                    // _tprintf(_T("Setting log file to: %s\n"), LogFileName);
                }
            }
            else if (!_tcsicmp(targv[0], _T("-append"))) {
                // _tprintf(_T("Appending log file: %s\n"), LogFileName);
                pLoggerInfo->LogFileMode |= EVENT_TRACE_FILE_MODE_APPEND;
            }
            else if (!_tcsicmp(targv[0], _T("-prealloc"))) {
                // _tprintf(_T("Preallocating log file: %s\n"), LogFileName);
                pLoggerInfo->LogFileMode |= EVENT_TRACE_FILE_MODE_PREALLOCATE;
            }
            else if (!_tcsicmp(targv[0], _T("-kb"))) {
                // _tprintf(_T("Using KBytes for maximum file size\n"));
                pLoggerInfo->LogFileMode |= EVENT_TRACE_USE_KBYTES_FOR_SIZE;
            }
            else if (!_tcsicmp(targv[0], _T("-guid"))) {
                if (argc > 1) {
                    if (targv[1][0] == _T('#')) {
                        StringToGuid(&targv[1][1], GuidArray[0]);
                        ++targv; --argc;
                        GuidCount = 1;
                    }
                    else if (targv[1][0] != '-' && targv[1][0] != '/') {
                        _tfullpath(GuidFile, targv[1], MAXSTR);
                        ++targv; --argc;
                        // _tprintf(_T("Getting guids from %s\n"), GuidFile);
                        GuidCount = GetGuids(GuidFile, GuidArray);
                        if (GuidCount < 0) {
                            _tprintf( _T("Error: %s does no exist\n"), GuidFile );
                        }
                        else if (GuidCount == 0){
                            _tprintf( _T("Error: %s is invalid\n"), GuidFile );
                            Status = ERROR_INVALID_PARAMETER;
                            goto CleanupExit;
                        }
                    }
                }
            }
            else if (!_tcsicmp(targv[0], _T("-seq"))) {
                if (argc > 1) {
                    pLoggerInfo->LogFileMode |= EVENT_TRACE_FILE_MODE_SEQUENTIAL;
                    pLoggerInfo->MaximumFileSize = _ttoi(targv[1]);
                    ++targv; --argc;
                    // _tprintf(_T("Setting maximum sequential logfile size to: %d\n"),
                    //    pLoggerInfo->MaximumFileSize);
                }
            }
            else if (!_tcsicmp(targv[0], _T("-newfile"))) {
                if (argc > 1) {
                    pLoggerInfo->LogFileMode |= EVENT_TRACE_FILE_MODE_NEWFILE;
                    pLoggerInfo->MaximumFileSize = _ttoi(targv[1]);
                    ++targv; --argc;
                    // _tprintf(_T("Setting maximum logfile size to: %d\n"),
                    //    pLoggerInfo->MaximumFileSize);
                }
            }
            else if (!_tcsicmp(targv[0], _T("-cir"))) {
                if (argc > 1) {
                    pLoggerInfo->LogFileMode |= EVENT_TRACE_FILE_MODE_CIRCULAR;
                    pLoggerInfo->MaximumFileSize = _ttoi(targv[1]);
                    ++targv; --argc;
                    // _tprintf(_T("Setting maximum circular logfile size to: %d\n"),
                    //    pLoggerInfo->MaximumFileSize);
                }
            }
            else if (!_tcsicmp(targv[0], _T("-b"))) {
                if (argc > 1) {
                    ULONG ulSize = _ttoi(targv[1]);
                    if (kdOn && ulSize > 3) {
                        _tprintf(_T("Kernel Debugging has been enabled: Buffer size has been set to 3kBytes\n"));
                        ulSize = 3;
                    }
                    pLoggerInfo->BufferSize = ulSize;                 	
                    ++targv; --argc;
                    // _tprintf(_T("Changing buffer size to %d\n"),
                    //    pLoggerInfo->BufferSize);
                }
            }
            else if (!_tcsicmp(targv[0], _T("-flag")) || !_tcsicmp(targv[0], _T("-flags"))) {
                if (argc > 1) {
                    if (targv[1][1] == _T('x') || targv[1][1] == _T('X')) {
                        pLoggerInfo->EnableFlags |= ahextoi(targv[1]);
                    } else {
                        pLoggerInfo->EnableFlags |= _ttoi(targv[1]);
                    }
                    iFlags =  pLoggerInfo->EnableFlags ;   // Copy for EnableTrace
                    ++targv; --argc;
                    // Do not accept flags with MSB = 1.

                    if (0x80000000 & pLoggerInfo->EnableFlags) {
                        _tprintf(_T("Invalid Flags: 0x%0X(%d.)\n"),
                            pLoggerInfo->EnableFlags, pLoggerInfo->EnableFlags);
                        Status = ERROR_INVALID_PARAMETER;
                        goto CleanupExit;
                    }

                    // _tprintf(_T("Setting logger flags to 0x%0X(%d.)\n"),
                    //    pLoggerInfo->EnableFlags, pLoggerInfo->EnableFlags );
                }
            }
            else if (!_tcsicmp(targv[0], _T("-min"))) {
                if (argc > 1) {
                    pLoggerInfo->MinimumBuffers = _ttoi(targv[1]);
                    ++targv; --argc;
                    // _tprintf(_T("Changing Minimum Number of Buffers to %d\n"),
                    //    pLoggerInfo->MinimumBuffers);
                }
            }
            else if (!_tcsicmp(targv[0], _T("-max"))) {
                if (argc > 1) {
                    pLoggerInfo->MaximumBuffers = _ttoi(targv[1]);
                    ++targv; --argc;
                    // _tprintf(_T("Changing Maximum Number of Buffers to %d\n"),
                    //    pLoggerInfo->MaximumBuffers);
                }
            }
            else if (!_tcsicmp(targv[0], _T("-level"))) {
                if (argc > 1) {
                    iLevel = _ttoi(targv[1]);
                    ++targv; --argc;
                    // _tprintf(_T("Setting tracing level to %d\n"), iLevel);
                }
            }
            else if (!_tcsicmp(targv[0], _T("-ft"))) {
                if (argc > 1) {
                    pLoggerInfo->FlushTimer = _ttoi(targv[1]);
                    ++targv; --argc;
                    // _tprintf(_T("Setting buffer flush timer to %d seconds\n"),
                    //    pLoggerInfo->FlushTimer);
                }
            }
            else if (!_tcsicmp(targv[0], _T("-um"))) {
                    pLoggerInfo->LogFileMode |= EVENT_TRACE_PRIVATE_LOGGER_MODE;
                    // _tprintf(_T("Setting Private Logger Flags\n"));
            }
            else if (!_tcsicmp(targv[0], _T("-paged"))) {
                    pLoggerInfo->LogFileMode |= EVENT_TRACE_USE_PAGED_MEMORY;
                    // _tprintf(_T("Setting Paged Memory Flag\n"));
            }
            else if (!_tcsicmp(targv[0], _T("-rt"))) {
                    pLoggerInfo->LogFileMode |= EVENT_TRACE_REAL_TIME_MODE;
                    // _tprintf(_T("Setting real time mode\n"));
            }            
            else if(!_tcsicmp(targv[0], _T("-kd"))) {
                    pLoggerInfo->LogFileMode |= EVENT_TRACE_KD_FILTER_MODE;
                    pLoggerInfo->BufferSize = 3;
                    kdOn = TRUE;
            }
            else if (!_tcsicmp(targv[0], _T("-age"))) {
                if (argc > 1) {
                    pLoggerInfo->AgeLimit = _ttoi(targv[1]);
                    ++targv; --argc;
                    // _tprintf(_T("Changing Aging Decay Time to %d\n"),
                    //    pLoggerInfo->AgeLimit);
                }
            }
            else if (!_tcsicmp(targv[0], _T("-l"))) {
                Action  = ACTION_LIST;
                bKill   = FALSE;
            }
            else if (!_tcsicmp(targv[0], _T("-x"))) {
                Action  = ACTION_LIST;
                bKill   = TRUE;
            }
            else if (!_tcsicmp(targv[0], _T("-xf"))) {
                Action  = ACTION_LIST;
                bKill   = TRUE;
                bForceKill = TRUE ;
            }
            else if (!_tcsicmp(targv[0], _T("-noprocess"))) {
                bProcess = FALSE;
            }
            else if (!_tcsicmp(targv[0], _T("-nothread"))) {
                bThread = FALSE;
            }
            else if (!_tcsicmp(targv[0], _T("-nodisk"))) {
                bDisk = FALSE;
            }
            else if (!_tcsicmp(targv[0], _T("-nonet"))) {
                bNetwork = FALSE;
            }
            else if (!_tcsicmp(targv[0], _T("-dbg"))) {
            	//comment out for now until this functionality is supported
              /* if (pFlags == &pLoggerInfo->EnableFlags) {
                    *pFlags |= EVENT_TRACE_FLAG_DBGPRINT;
                }
                */
            }
            else if (!_tcsicmp(targv[0], _T("-ntsuccess"))){
            	  //comment out for now until this functionality is supported
                /*if(pFlags == &pLoggerInfo->EnableFlags) {
                	*pFlags |= EVENT_TRACE_FLAG_NTSUCCESS;
                }
                */
            	}
            else if (!_tcsicmp(targv[0], _T("-fio"))) {
                if (pFlags == &pLoggerInfo->EnableFlags) {
                    *pFlags |= EVENT_TRACE_FLAG_DISK_FILE_IO;
                }
                else {
                    _tprintf(_T("Option -fio cannot be used with -eflags. Ignored\n"));
                }
            }
            else if (!_tcsicmp(targv[0], _T("-pf"))) {
                if (pFlags == &pLoggerInfo->EnableFlags) {
                    *pFlags |= EVENT_TRACE_FLAG_MEMORY_PAGE_FAULTS;
                }
                else {
                    _tprintf(_T("Option -pf cannot be used with -eflags. Ignored\n"));
                }
            }
            else if (!_tcsicmp(targv[0], _T("-hf"))) {
                if (pFlags == &pLoggerInfo->EnableFlags) {
                    *pFlags |= EVENT_TRACE_FLAG_MEMORY_HARD_FAULTS;
                }
                else {
                    _tprintf(_T("Option -hf cannot be used with -eflags. Ignored\n"));
                }
            }
            else if (!_tcsicmp(targv[0], _T("-img"))) {
                if (pFlags == &pLoggerInfo->EnableFlags) {
                    *pFlags |= EVENT_TRACE_FLAG_IMAGE_LOAD;
                }
                else {
                    _tprintf(_T("Option -img cannot be used with -eflags. Ignored\n"));
                }
            }
            else if (!_tcsicmp(targv[0], _T("-cm"))) {
                if (pFlags == &pLoggerInfo->EnableFlags) {
                    *pFlags |= EVENT_TRACE_FLAG_REGISTRY;
                }
                else {
                    _tprintf(_T("Option -cm cannot be used with -eflags. Ignored\n"));
                }
            }
            else if ( targv[0][1] == 'h' || targv[0][1] == 'H' || targv[0][1] == '?'){
                Action = ACTION_HELP;
                PrintHelpMessage();
                goto CleanupExit;
            }
            else Action = ACTION_UNDEFINED;
        }
        else { // get here if "-" or "/" given
            _tprintf(_T("Invalid option given: %s\n"), targv[0]);
            Status = ERROR_INVALID_PARAMETER;
            goto CleanupExit;
        }
    }
    if (!_tcscmp(LoggerName, KERNEL_LOGGER_NAME)) {
        if (pFlags == &pLoggerInfo->EnableFlags) {
            if (bProcess)
                *pFlags |= EVENT_TRACE_FLAG_PROCESS;
            if (bThread)
                *pFlags |= EVENT_TRACE_FLAG_THREAD;
            if (bDisk)
                *pFlags |= EVENT_TRACE_FLAG_DISK_IO;
            if (bNetwork)
                *pFlags |= EVENT_TRACE_FLAG_NETWORK_TCPIP;
        }

        pLoggerInfo->Wnode.Guid = SystemTraceControlGuid; // defaults to OS
        specialLogger = 1;
    }
    if ( !(pLoggerInfo->LogFileMode & EVENT_TRACE_REAL_TIME_MODE) ) {
        if (specialLogger != 3 && _tcslen(LogFileName) <= 0 && Action == ACTION_START) {
            _tcscpy(LogFileName, DEFAULT_LOGFILE_NAME); // for now...
        }
    }

    switch (Action) {
        case  ACTION_START:
        {

           if (pLoggerInfo->LogFileMode & EVENT_TRACE_PRIVATE_LOGGER_MODE) {
               if (GuidCount != 1) {
                   _tprintf(_T("Need exactly one GUID for PRIVATE loggers\n"));
                   Status = ERROR_INVALID_PARAMETER;
                   break;
               }
               pLoggerInfo->Wnode.Guid = *GuidArray[0];
           }

           if (pLoggerInfo->LogFileMode & EVENT_TRACE_FILE_MODE_PREALLOCATE  &&
               pLoggerInfo->MaximumFileSize == 0) {
               _tprintf(_T("Need file size for preallocated log file\n"));
               Status = ERROR_INVALID_PARAMETER;
               break;
           }
            if(pLoggerInfo->EnableFlags & EVENT_TRACE_FLAG_EXTENSION){
                if(IsEqualGUID(&CritSecGuid,GuidArray[0]) ||
                    IsEqualGUID(&HeapGuid,GuidArray[0])){
                    pLoggerInfo->Wnode.HistoricalContext = 0x1000001;
                }
            }
            Status = StartTrace(&LoggerHandle, LoggerName, pLoggerInfo);

            if (Status != ERROR_SUCCESS) {
                _tprintf(_T("Could not start logger: %s\n") 
                         _T("Operation Status:       %uL\n")
                         _T("%s\n"),
                         LoggerName,
                         Status,
                         DecodeStatus(Status));

                break;
            }
            _tprintf(_T("Logger Started...\n"));

        case ACTION_ENABLE:

            if (Action == ACTION_ENABLE ){

                if (pLoggerInfo->LogFileMode & EVENT_TRACE_PRIVATE_LOGGER_MODE)
                {
                    if (GuidCount != 1)
                    {
                        _tprintf(_T("Need one GUID for PRIVATE loggers\n"));
                        Status = ERROR_INVALID_PARAMETER;
                        break;
                    }
                    pLoggerInfo->Wnode.Guid = *GuidArray[0];
                }

                Status = ControlTrace((TRACEHANDLE) 0, LoggerName, pLoggerInfo, EVENT_TRACE_CONTROL_QUERY);
                if( Status != ERROR_SUCCESS ){
                    if( Status != ERROR_SUCCESS ){
                        if( IsEqualGUID(&HeapGuid,&pLoggerInfo->Wnode.Guid) 
                        || IsEqualGUID(&CritSecGuid,&pLoggerInfo->Wnode.Guid) 
                        ){
                            //do nothing 
                        } else {

                            _tprintf( _T("ERROR: Logger not started\n")
                                      _T("Operation Status:    %uL\n")
                                      _T("%s\n"),
                                      Status,
                                      DecodeStatus(Status));
							break;
                        }
                    }
                }
                LoggerHandle = pLoggerInfo->Wnode.HistoricalContext;
            }

            if ( (GuidCount > 0) && (specialLogger == 0)) {
                _tprintf(_T("Enabling trace to logger %d\n"), LoggerHandle);
                for (i=0; i<(ULONG)GuidCount; i++) {
                    Status = EnableTrace (
                                    bEnable,
                                    iFlags,
                                    iLevel,
                                    GuidArray[i], 
                                    LoggerHandle);

                    //
                    // If the Guid can not be enabled, it is a benign 
                    // failure. Print Warning message and continue. 
                    //
                    if (Status == 4317) {
                       _tprintf(_T("WARNING: Could not enable some guids.\n")); 
                       _tprintf(_T("Check your Guids file\n")); 
                        Status = ERROR_SUCCESS;
                    }

                    if (Status != ERROR_SUCCESS) {
                        _tprintf(_T("ERROR: Failed to enable Guid [%d]...\n"), i);
                        _tprintf(_T("Operation Status:       %uL\n"), Status);
                        _tprintf(_T("%s\n"),DecodeStatus(Status));
                        break;
                    }
                }
            }
            else {
                if (GuidCount > 0) {
                    _tprintf(_T("ERROR: System Logger does not accept application guids...\n"));
                    Status = ERROR_INVALID_PARAMETER;
                }
            }
            break;
        }

        case ACTION_STOP :
            LoggerHandle = (TRACEHANDLE) 0;

            if (pLoggerInfo->LogFileMode & EVENT_TRACE_PRIVATE_LOGGER_MODE) {
                if (GuidCount != 1) {
                    _tprintf(_T("Need exactly one GUID for PRIVATE loggers\n"));
                    Status = ERROR_INVALID_PARAMETER;
                    break;
                }
                pLoggerInfo->Wnode.Guid = *GuidArray[0];
            }
            if ( (GuidCount > 0) && 
                 !( IsEqualGUID(&HeapGuid,GuidArray[0]) || 
                    IsEqualGUID(&CritSecGuid,GuidArray[0]) ))  {
                if (pLoggerInfo->LogFileMode & EVENT_TRACE_PRIVATE_LOGGER_MODE) {
                    Status = ControlTrace(LoggerHandle, LoggerName, pLoggerInfo, EVENT_TRACE_CONTROL_QUERY);
                    if (Status != ERROR_SUCCESS)
                        break;
                    LoggerHandle = pLoggerInfo->Wnode.HistoricalContext;
                    Status = EnableTrace( FALSE,
                                          EVENT_TRACE_PRIVATE_LOGGER_MODE,
                                          0,
                                          GuidArray[0],
                                          LoggerHandle );
                }
                else {
                    Status = ControlTrace(LoggerHandle, LoggerName, pLoggerInfo, EVENT_TRACE_CONTROL_QUERY);
                    if (Status == ERROR_WMI_INSTANCE_NOT_FOUND)
                        break;
                    LoggerHandle = pLoggerInfo->Wnode.HistoricalContext;

                    for (i=0; i<(ULONG)GuidCount; i++) {
                    Status = EnableTrace( FALSE,
                                              0,
                                              0,
                                              GuidArray[i],
                                              LoggerHandle);
                    }

                }
            }

            Status = ControlTrace(LoggerHandle, LoggerName, pLoggerInfo, EVENT_TRACE_CONTROL_STOP);
            break;

        case ACTION_LIST :
        {
            ULONG returnCount ;
            ULONG ListSizeNeeded;
            PEVENT_TRACE_PROPERTIES pListLoggerInfo[MAXIMUM_LOGGERS_XP];
            PEVENT_TRACE_PROPERTIES pStorage;
            PVOID Storage;

            ListSizeNeeded = MAXIMUM_LOGGERS_XP * (sizeof(EVENT_TRACE_PROPERTIES)
                                      + 2 * MAXSTR * sizeof(TCHAR));

            Storage =  malloc(ListSizeNeeded);
            if (Storage == NULL) {
                Status = ERROR_OUTOFMEMORY;
                break;
            }
            RtlZeroMemory(Storage, ListSizeNeeded);

            pStorage = (PEVENT_TRACE_PROPERTIES)Storage;
            for (i=0; i<MAXIMUM_LOGGERS_XP; i++) {
                pStorage->Wnode.BufferSize = sizeof(EVENT_TRACE_PROPERTIES)
                                         + 2 * MAXSTR * sizeof(TCHAR);
                pStorage->LogFileNameOffset = sizeof(EVENT_TRACE_PROPERTIES)
                                        + MAXSTR * sizeof(TCHAR);
                pStorage->LoggerNameOffset = sizeof(EVENT_TRACE_PROPERTIES);
                pListLoggerInfo[i] = pStorage;
                pStorage = (PEVENT_TRACE_PROPERTIES) (
                                 (char*)pStorage + 
                                  pStorage->Wnode.BufferSize);
            }
            
            if (XP) {
                Status = QueryAllTraces(pListLoggerInfo,
                                    MAXIMUM_LOGGERS_XP,
                                    & returnCount);
            }
            else {
                Status = QueryAllTraces(pListLoggerInfo,
                                    MAXIMUM_LOGGERS_W2K,
                                    & returnCount);
            }
    
            if (Status == ERROR_SUCCESS)
            {
                for (j= 0; j < returnCount; j++)
                {
                    LPTSTR ListLoggerName;
                    TCHAR asked = _T('?') ;
                    BOOL StatusPrint = FALSE ;
                    if (bKill)
                    {

                        ListLoggerName = (LPTSTR) ((char*)pListLoggerInfo[j] + 
                                      pListLoggerInfo[j]->LoggerNameOffset);
                        if (!bForceKill) {
                            while (!(asked == _T('y')) && !(asked == _T('n'))) {
                                ULONG ReadChars = 0;
                                _tprintf(_T("Do you want to kill Logger \"%s\" (Y or N)?"), ListLoggerName);
                                ReadChars = _tscanf(_T(" %c"), &asked);
                                if (ReadChars == 0 || ReadChars == EOF) {
                                    continue;
                                }
                                if (asked == _T('Y')) {
                                    asked = _T('y') ;
                                } else if (asked == _T('N')) {
                                    asked = _T('n') ;
                                }
                            }
                        } else {
                            asked = _T('y');
                        }
                        if (asked == _T('y')) {
                            if (!IsEqualGUID(& pListLoggerInfo[j]->Wnode.Guid,
                                         & SystemTraceControlGuid))
                            {
                                LoggerHandle = pListLoggerInfo[j]->Wnode.HistoricalContext;
                                Status = EnableTrace(
                                          FALSE,
                                          (pListLoggerInfo[j]->LogFileMode &
                                                  EVENT_TRACE_PRIVATE_LOGGER_MODE)
                                              ? (EVENT_TRACE_PRIVATE_LOGGER_MODE)
                                              : (0),
                                          0,
                                          & pListLoggerInfo[j]->Wnode.Guid,
                                          LoggerHandle);
                            }
                            Status = ControlTrace((TRACEHANDLE) 0,
                                            ListLoggerName,
                                            pListLoggerInfo[j],
                                            EVENT_TRACE_CONTROL_STOP);
                            _tprintf(_T("Logger \"%s\" has been killed\n"), ListLoggerName);
                            StatusPrint = TRUE ;
                        } else {
                            _tprintf(_T("Logger \"%s\" has not been killed, current Status is\n"), ListLoggerName);
                            StatusPrint = FALSE ;
                        }
                    }
                    PrintLoggerStatus(pListLoggerInfo[j], 
                                        Status, 
                                        StatusPrint);
                    _tprintf(_T("\n"));
                }
            }

            free(Storage);
            break;
        }

        case ACTION_UPDATE :
        case ACTION_FLUSH  :
        case ACTION_QUERY  :
            if (pLoggerInfo->LogFileMode & EVENT_TRACE_PRIVATE_LOGGER_MODE) {
                if (GuidCount != 1) {
                    _tprintf(_T("Need exactly one GUID for PRIVATE loggers\n"));
                    Status = ERROR_INVALID_PARAMETER;
                    break;
                }
                pLoggerInfo->Wnode.Guid = *GuidArray[0];
            }
            if (Action == ACTION_QUERY) {
                Status = ControlTrace(LoggerHandle, LoggerName, pLoggerInfo, EVENT_TRACE_CONTROL_QUERY);
            }

            else if (Action == ACTION_UPDATE) {
                Status = ControlTrace(LoggerHandle, LoggerName, pLoggerInfo, EVENT_TRACE_CONTROL_UPDATE);
            }
            else if (Action == ACTION_FLUSH) {
                // Since FlushTrace is not implemented on Win2K, use the function pointer
                // loaded from advapi32.dll separately.
                // Originally, this block had one line: 
                // Status = FlushTrace(LoggerHandle, LoggerName, pLoggerInfo);
                if (FuncArray[FUNC_FLUSH_TRACE] == NULL) {
                    _tprintf(_T("Flush Trace is not supported on this system\n"));
                    Status = ERROR_INVALID_PARAMETER;
                    break;
                }
                Status = (ULONG)(*FuncArray[FUNC_FLUSH_TRACE])(LoggerHandle, LoggerName, pLoggerInfo);
            }

            break;

        case ACTION_ENUM_GUID:
        {
            ULONG PropertyArrayCount=10;
            PTRACE_GUID_PROPERTIES  *GuidPropertiesArray;
            ULONG EnumGuidCount;
            ULONG SizeStorage;
            PVOID StorageNeeded;
            PTRACE_GUID_PROPERTIES CleanStorage;
            TCHAR str[MAXSTR];

            // Since EnumTraceGuids is not implemented on Win2K, use the function pointer
            // loaded from advapi32.dll separately.
            if (FuncArray[FUNC_ENUM_TRACE_GUIDS] == NULL) {
                _tprintf(_T("Enumerating trace GUIDS is not supported on this system\n"));
                Status = ERROR_INVALID_PARAMETER;
                break;
            }

Retry:
            SizeStorage = PropertyArrayCount * (sizeof(TRACE_GUID_PROPERTIES) + sizeof(PTRACE_GUID_PROPERTIES));
            StorageNeeded =  malloc(SizeStorage);
            if (StorageNeeded== NULL) {
                Status = ERROR_OUTOFMEMORY;
                break;
            }
            RtlZeroMemory(StorageNeeded, SizeStorage);
            GuidPropertiesArray = (PTRACE_GUID_PROPERTIES *)StorageNeeded;
            CleanStorage = (PTRACE_GUID_PROPERTIES)((char*)StorageNeeded + PropertyArrayCount * sizeof(PTRACE_GUID_PROPERTIES));
            for (i=0; i < PropertyArrayCount; i++) {
                GuidPropertiesArray[i] = CleanStorage;
                CleanStorage = (PTRACE_GUID_PROPERTIES) (
                                    (char*)CleanStorage + sizeof(TRACE_GUID_PROPERTIES)
                                    );
            }
            // Use function pointer for EnumTraceGuids
            Status = (ULONG)(*FuncArray[FUNC_ENUM_TRACE_GUIDS])(GuidPropertiesArray,PropertyArrayCount,&EnumGuidCount);
            if(Status == ERROR_MORE_DATA)
            {
                PropertyArrayCount=EnumGuidCount;
                free(StorageNeeded);
                goto Retry;

            }

            //
            // print the GUID_PROPERTIES and Free Strorage
            //

            _tprintf(_T("    Guid                     Enabled  LoggerId Level Flags\n"));
            _tprintf(_T("------------------------------------------------------------\n"));
            for (i=0; i < EnumGuidCount; i++) {
                _tprintf(_T("%s     %5s  %d    %d    %d\n"),
                                           GuidToString(&str[0],&GuidPropertiesArray[i]->Guid), 
                                           (GuidPropertiesArray[i]->IsEnable) ? _T("TRUE") : _T("FALSE"),
                                            GuidPropertiesArray[i]->LoggerId,
                                           GuidPropertiesArray[i]->EnableLevel,
                                           GuidPropertiesArray[i]->EnableFlags 
                                                               );
            }
            free(StorageNeeded);
        }
        break;

        case ACTION_HELP:
            PrintHelpMessage();
            break;
        default :
            _tprintf(_T("Error: no action specified\n"));
            PrintHelpMessage();
            break;
    }
    
    if ((Action != ACTION_HELP) && (Action != ACTION_ENUM_GUID) 
        && (Action != ACTION_UNDEFINED) && (Action != ACTION_LIST))
        PrintLoggerStatus(pLoggerInfo,
                            Status, 
                            PRINTSTATUS);
CleanupExit: 
    SetLastError(Status);
    if (utargv != NULL) {
        GlobalFree(utargv);
    }
    free(pLoggerInfo);
    free(save);
    if (advapidll != NULL)
        FreeLibrary(advapidll);
    return(Status);
}


void
PrintLoggerStatus(
    IN PEVENT_TRACE_PROPERTIES LoggerInfo,
    IN ULONG Status,
    IN BOOL PrintStatus
    )
/*++

Routine Description:

    Prints out the status of the specified logger.

Arguments:

    LoggerInfo - The pointer to the resident EVENT_TRACE_PROPERTIES that has
        the information about the current logger.
    Status - The returned status of the last executed command 
        or
        the operation status of the current logger.

    PrintStatus - Determines which type of status it is using.

Return Value:

    None

--*/
{
    LPTSTR LoggerName, LogFileName;
    
    if ((LoggerInfo->LoggerNameOffset > 0) &&
        (LoggerInfo->LoggerNameOffset  < LoggerInfo->Wnode.BufferSize)) {
        LoggerName = (LPTSTR) ((char*)LoggerInfo +
                                LoggerInfo->LoggerNameOffset);
    }
    else LoggerName = NULL;

    if ((LoggerInfo->LogFileNameOffset > 0) &&
        (LoggerInfo->LogFileNameOffset  < LoggerInfo->Wnode.BufferSize)) {
        LogFileName = (LPTSTR) ((char*)LoggerInfo +
                                LoggerInfo->LogFileNameOffset);
    }
    else LogFileName = NULL;

    if (PrintStatus) {
        _tprintf(_T("Operation Status:       %uL\t"), Status);
        _tprintf(_T("%s\n"), DecodeStatus(Status));
    }
    
    _tprintf(_T("Logger Name:            %s\n"),
            (LoggerName == NULL) ?
            _T(" ") : LoggerName);
        _tprintf(_T("Logger Id:              %I64x\n"), LoggerInfo->Wnode.HistoricalContext);
        _tprintf(_T("Logger Thread Id:       %p\n"), LoggerInfo->LoggerThreadId);
        if (Status != 0)
            return;

        _tprintf(_T("Buffer Size:            %d Kb"), LoggerInfo->BufferSize);
        if (LoggerInfo->LogFileMode & EVENT_TRACE_USE_PAGED_MEMORY) {
            _tprintf(_T(" using paged memory\n"));
        }
        else {
            _tprintf(_T("\n"));
        }
        _tprintf(_T("Maximum Buffers:        %d\n"), LoggerInfo->MaximumBuffers);
        _tprintf(_T("Minimum Buffers:        %d\n"), LoggerInfo->MinimumBuffers);
        _tprintf(_T("Number of Buffers:      %d\n"), LoggerInfo->NumberOfBuffers);
        _tprintf(_T("Free Buffers:           %d\n"), LoggerInfo->FreeBuffers);
        _tprintf(_T("Buffers Written:        %d\n"), LoggerInfo->BuffersWritten);
        _tprintf(_T("Events Lost:            %d\n"), LoggerInfo->EventsLost);
        _tprintf(_T("Log Buffers Lost:       %d\n"), LoggerInfo->LogBuffersLost);
        _tprintf(_T("Real Time Buffers Lost: %d\n"), LoggerInfo->RealTimeBuffersLost);
        _tprintf(_T("AgeLimit:               %d\n"), LoggerInfo->AgeLimit);

        if (LogFileName == NULL) {
            _tprintf(_T("Buffering Mode:         "));
        }
        else {
            _tprintf(_T("Log File Mode:          "));
        }
        if (LoggerInfo->LogFileMode & EVENT_TRACE_FILE_MODE_APPEND) {
            _tprintf(_T("Append  "));
        }
        if (LoggerInfo->LogFileMode & EVENT_TRACE_FILE_MODE_CIRCULAR) {
            _tprintf(_T("Circular\n"));
        }
        else if (LoggerInfo->LogFileMode & EVENT_TRACE_FILE_MODE_SEQUENTIAL) {
            _tprintf(_T("Sequential\n"));
        }
        else {
            _tprintf(_T("Sequential\n"));
        }
        if (LoggerInfo->LogFileMode & EVENT_TRACE_REAL_TIME_MODE) {
            _tprintf(_T("Real Time mode enabled"));
            _tprintf(_T("\n"));
        }

        if (LoggerInfo->MaximumFileSize > 0) {
            if (LoggerInfo->LogFileMode & EVENT_TRACE_USE_KBYTES_FOR_SIZE)
                _tprintf(_T("Maximum File Size:      %d Kb\n"), LoggerInfo->MaximumFileSize);
            else
                _tprintf(_T("Maximum File Size:      %d Mb\n"), LoggerInfo->MaximumFileSize);
        }

        if (LoggerInfo->FlushTimer > 0)
            _tprintf(_T("Buffer Flush Timer:     %d secs\n"), LoggerInfo->FlushTimer);

        if (LoggerInfo->EnableFlags != 0) {
            _tprintf(_T("Enabled tracing:        "));

            if ((LoggerName != NULL) && (!_tcscmp(LoggerName, KERNEL_LOGGER_NAME))) {

                if (LoggerInfo->EnableFlags & EVENT_TRACE_FLAG_PROCESS)
                    _tprintf(_T("Process "));
                if (LoggerInfo->EnableFlags & EVENT_TRACE_FLAG_THREAD)
                    _tprintf(_T("Thread "));
                if (LoggerInfo->EnableFlags & EVENT_TRACE_FLAG_DISK_IO)
                    _tprintf(_T("Disk "));
                if (LoggerInfo->EnableFlags & EVENT_TRACE_FLAG_DISK_FILE_IO)
                    _tprintf(_T("File "));
                if (LoggerInfo->EnableFlags & EVENT_TRACE_FLAG_MEMORY_PAGE_FAULTS)
                    _tprintf(_T("PageFaults "));
                if (LoggerInfo->EnableFlags & EVENT_TRACE_FLAG_MEMORY_HARD_FAULTS)
                    _tprintf(_T("HardFaults "));
                if (LoggerInfo->EnableFlags & EVENT_TRACE_FLAG_IMAGE_LOAD)
                    _tprintf(_T("ImageLoad "));
                if (LoggerInfo->EnableFlags & EVENT_TRACE_FLAG_NETWORK_TCPIP)
                    _tprintf(_T("TcpIp "));
                if (LoggerInfo->EnableFlags & EVENT_TRACE_FLAG_REGISTRY)
                    _tprintf(_T("Registry "));
            }else{
                _tprintf(_T("0x%08x"), LoggerInfo->EnableFlags );
            }
            _tprintf(_T("\n"));
        }
        if (LogFileName != NULL) {
            _tprintf(_T("Log Filename:           %s\n"), LogFileName);
        }

}

LPTSTR
DecodeStatus(
    IN ULONG Status
    )
/*++

Routine Description:

    Decodes WIN32 error into a string in the default language.

Arguments:

    Status - The error status from the last executed command 
        or
        the operation status of the current logger.

Return Value:

    LPTSTR - String containing the decoded message.


--*/
{
    memset( ErrorMsg, 0, MAXSTR );
    FormatMessage(     
        FORMAT_MESSAGE_FROM_SYSTEM |     
        FORMAT_MESSAGE_IGNORE_INSERTS,    
        NULL,
        Status,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
        (LPTSTR) ErrorMsg,
        MAXSTR,
        NULL );

    return ErrorMsg;
}

LONG
GetGuids(
    IN LPTSTR GuidFile, 
    IN OUT LPGUID *GuidArray
)
/*++

Routine Description:

    Reads GUIDs from a file and stores them in an GUID array.

Arguments:

    GuidFile - The file containing GUIDs. 
    GuidArray - The GUID array that will have GUIDs read from the file.

Return Value:

    ULONG - The number of GUIDs processed.


--*/
{
    FILE *f;
    TCHAR line[MAXSTR], arg[MAXSTR];
    LPGUID Guid;
    int i, n;

    f = _tfopen((TCHAR*)GuidFile, _T("r"));

    if (f == NULL)
        return -1;

    n = 0;
    while ( _fgetts(line, MAXSTR, f) != NULL ) {
        if (_tcslen(line) < 36)
            continue;
        if (line[0] == ';'  || 
            line[0] == '\0' || 
            line[0] == '#' || 
            line[0] == '/')
            continue;
        Guid = (LPGUID) GuidArray[n];
        n ++;
        StringToGuid(line, Guid);
    }
    fclose(f);
    return (ULONG)n;
}

ULONG 
ahextoi(
    IN TCHAR *s
    )
/*++

Routine Description:

    Converts a hex string into a number.

Arguments:

    s - A hex string in TCHAR. 

Return Value:

    ULONG - The number in the string.


--*/
{
    int len;
    ULONG num, base, hex;

    len = _tcslen(s);
    hex = 0; base = 1; num = 0;
    while (--len >= 0) {
        if ( (s[len] == 'x' || s[len] == 'X') &&
             (s[len-1] == '0') )
            break;
        if (s[len] >= '0' && s[len] <= '9')
            num = s[len] - '0';
        else if (s[len] >= 'a' && s[len] <= 'f')
            num = (s[len] - 'a') + 10;
        else if (s[len] >= 'A' && s[len] <= 'F')
            num = (s[len] - 'A') + 10;
        else 
            continue;

        hex += num * base;
        base = base * 16;
    }
    return hex;
}


void 
StringToGuid(
    IN TCHAR *str, 
    IN OUT LPGUID guid
)
/*++

Routine Description:

    Converts a string into a GUID.

Arguments:

    str - A string in TCHAR.
    guid - The pointer to a GUID that will have the converted GUID.

Return Value:

    None.


--*/
{
    TCHAR temp[10];
    int i;

    try {

        _tcsncpy(temp, str, 8);
        temp[8] = 0;
        guid->Data1 = ahextoi(temp);
        _tcsncpy(temp, &str[9], 4);
        temp[4] = 0;
        guid->Data2 = (USHORT) ahextoi(temp);
        _tcsncpy(temp, &str[14], 4);
        temp[4] = 0;
        guid->Data3 = (USHORT) ahextoi(temp);

        for (i=0; i<2; i++) {
            _tcsncpy(temp, &str[19 + (i*2)], 2);
            temp[2] = 0;
            guid->Data4[i] = (UCHAR) ahextoi(temp);
        }
        for (i=2; i<8; i++) {
            _tcsncpy(temp, &str[20 + (i*2)], 2);
            temp[2] = 0;
            guid->Data4[i] = (UCHAR) ahextoi(temp);
        }
    }
    except (EXCEPTION_EXECUTE_HANDLER) {
        _tprintf( _T("Error: Invalid GuidFile!\n") );
        exit(0);
    }
}

void 
DisplayVersionInfo()
/*++

Routine Description:

    prints out a version information.

Arguments:

    None.

Return Value:

    None.


--*/
{
    TCHAR buffer[512];
    TCHAR strProgram[MAXSTR];
    DWORD dw;
    BYTE* pVersionInfo;
    LPTSTR pVersion = NULL;
    LPTSTR pProduct = NULL;
    LPTSTR pCopyRight = NULL;

    dw = GetModuleFileName(NULL, strProgram, MAXSTR);

    if( dw>0 ){

        dw = GetFileVersionInfoSize( strProgram, &dw );
        if( dw > 0 ){

            pVersionInfo = (BYTE*)malloc(dw);
            if( NULL != pVersionInfo ){
                if(GetFileVersionInfo( strProgram, 0, dw, pVersionInfo )){
                    LPDWORD lptr = NULL;
                    VerQueryValue( pVersionInfo, _T("\\VarFileInfo\\Translation"), (void**)&lptr, (UINT*)&dw );
                    if( lptr != NULL ){
                        _stprintf( buffer, _T("\\StringFileInfo\\%04x%04x\\%s"), LOWORD(*lptr), HIWORD(*lptr), _T("ProductVersion") );
                        VerQueryValue( pVersionInfo, buffer, (void**)&pVersion, (UINT*)&dw );
                        _stprintf( buffer, _T("\\StringFileInfo\\%04x%04x\\%s"), LOWORD(*lptr), HIWORD(*lptr), _T("OriginalFilename") );
                        VerQueryValue( pVersionInfo, buffer, (void**)&pProduct, (UINT*)&dw );
                        _stprintf( buffer, _T("\\StringFileInfo\\%04x%04x\\%s"), LOWORD(*lptr), HIWORD(*lptr), _T("LegalCopyright") );
                        VerQueryValue( pVersionInfo, buffer, (void**)&pCopyRight, (UINT*)&dw );
                    }
                
                    if( pProduct != NULL && pVersion != NULL && pCopyRight != NULL ){
                        _tprintf( _T("\nMicrosoft (R) %s (%s)\n%s\n\n"), pProduct, pVersion, pCopyRight );
                    }
                }
                free( pVersionInfo );
            }
        }
    }
}

void PrintHelpMessage()
/*++

Routine Description:

    prints out a help message.

Arguments:

    None.

Return Value:

    None.


--*/
{
    _tprintf(_T("Usage: tracelog [actions] [options] | [-h | -help | -?]\n"));
    _tprintf(_T("\n    actions:\n"));
    _tprintf(_T("\t-start   [LoggerName] Starts up the [LoggerName] trace session\n"));
    _tprintf(_T("\t-stop    [LoggerName] Stops the [LoggerName] trace session\n"));
    _tprintf(_T("\t-update  [LoggerName] Updates the [LoggerName] trace session\n"));
    _tprintf(_T("\t-enable  [LoggerName] Enables providers for the [LoggerName] session\n"));
    _tprintf(_T("\t-disable [LoggerName] Disables providers for the [LoggerName] session\n"));
    if (XP)
        _tprintf(_T("\t-flush   [LoggerName] Flushes the [LoggerName] active buffers\n"));
    if (XP)
        _tprintf(_T("\t-enumguid             Enumerate Registered Trace Guids\n"));
    _tprintf(_T("\t-q       [LoggerName] Query status of [LoggerName] trace session\n"));
    _tprintf(_T("\t-l                    List all trace sessions\n"));
    _tprintf(_T("\t-x                    Stops all active trace sessions\n"));

    _tprintf(_T("\n    options:\n"));
    _tprintf(_T("\t-b   <n>              Sets buffer size to <n> Kbytes\n"));
    _tprintf(_T("\t-min <n>              Sets minimum buffers\n"));
    _tprintf(_T("\t-max <n>              Sets maximum buffers\n"));
    _tprintf(_T("\t-f <name>             Log to file <name>\n"));
    if (XP) {
        _tprintf(_T("\t-append               Append to file\n"));
        _tprintf(_T("\t-prealloc             Pre-allocate\n"));
    }
    _tprintf(_T("\t-seq <n>              Sequential logfile of up to n Mbytes\n"));
    _tprintf(_T("\t-cir <n>              Circular logfile of n Mbytes\n"));
    if (XP)
        _tprintf(_T("\t-newfile <n>          Log to a new file after every n Mbytes\n"));
    _tprintf(_T("\t-ft <n>               Set flush timer to n seconds\n"));
    if (XP)
        _tprintf(_T("\t-paged                Use pageable memory for buffers\n"));
    _tprintf(_T("\t-noprocess            Disable Process Start/End tracing\n"));
    _tprintf(_T("\t-nothread             Disable Thread Start/End tracing\n"));
    _tprintf(_T("\t-nodisk               Disable Disk I/O tracing\n"));
    _tprintf(_T("\t-nonet                Disable Network TCP/IP tracing\n"));
    _tprintf(_T("\t-fio                  Enable file I/O tracing\n"));
    _tprintf(_T("\t-pf                   Enable page faults tracing\n"));
    _tprintf(_T("\t-hf                   Enable hard faults tracing\n"));
    _tprintf(_T("\t-img                  Enable image load tracing\n"));
    _tprintf(_T("\t-cm                   Enable registry calls tracing\n"));
    _tprintf(_T("\t-um                   Enable Process Private tracing\n"));
    _tprintf(_T("\t-guid <file>          Start tracing for providers in file\n"));
    _tprintf(_T("\t-rt                   Enable tracing in real time mode\n"));
    _tprintf(_T("\t-kd                   Enable tracing in kernel debugger\n"));
   // _tprintf(_T("\t-dbg                  Enable debug tracing in DbgPrint(Ex) statements\n"));
   // _tprintf(_T("\t-ntsuccess                  Enable debug tracing in NT_SUCCESS macro\n"));
    _tprintf(_T("\t-age <n>              Modify aging decay time to n minutes\n"));
    _tprintf(_T("\t-level <n>            Enable Level passed to the providers\n"));
    _tprintf(_T("\t-flag <n>             Enable Flags passed to the providers\n"));
    _tprintf(_T("\n"));
    _tprintf(_T("\t-h\n"));
    _tprintf(_T("\t-help\n"));
    _tprintf(_T("\t-?                    Display usage information\n"));
}


PTCHAR 
GuidToString(
    IN OUT PTCHAR s,
    LPGUID piid
    )
/*++

Routine Description:

    Converts a GUID into a string.

Arguments:

    s - A string in TCHAR that will have the converted GUID.
    piid - The pointer to a GUID.

Return Value:

    PTCHAR - The string containig the convereted GUID.


--*/
{
    _stprintf(s, _T("%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x"),
               piid->Data1, piid->Data2,
               piid->Data3,
               piid->Data4[0], piid->Data4[1],
               piid->Data4[2], piid->Data4[3],
               piid->Data4[4], piid->Data4[5],
               piid->Data4[6], piid->Data4[7]);
    return(s);
}

