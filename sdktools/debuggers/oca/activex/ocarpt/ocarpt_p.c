

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 6.00.0366 */
/* Compiler settings for ocarpt.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#if !defined(_M_IA64) && !defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */
#pragma warning( disable: 4211 )  /* redefine extent to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma optimize("", off ) 

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif // __RPCPROXY_H_VERSION__


#include "ocarpt.h"

#define TYPE_FORMAT_STRING_SIZE   1057                              
#define PROC_FORMAT_STRING_SIZE   343                               
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   2            

typedef struct _MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } MIDL_TYPE_FORMAT_STRING;

typedef struct _MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } MIDL_PROC_FORMAT_STRING;


static RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString;
extern const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IOcarptMain_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IOcarptMain_ProxyInfo;


extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];

#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT50_OR_LATER)
#error You need a Windows 2000 or later to run this stub because it uses these features:
#error   /robust command line switch.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will die there with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure Upload */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x7 ),	/* 7 */
/*  8 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 10 */	NdrFcShort( 0x8 ),	/* 8 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 16 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 18 */	NdrFcShort( 0x20 ),	/* 32 */
/* 20 */	NdrFcShort( 0x4 ),	/* 4 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter SourceFile */

/* 24 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 26 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 28 */	NdrFcShort( 0x20 ),	/* Type Offset=32 */

	/* Parameter DestFile */

/* 30 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 32 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 34 */	NdrFcShort( 0x20 ),	/* Type Offset=32 */

	/* Parameter Langage */

/* 36 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 38 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 40 */	NdrFcShort( 0x20 ),	/* Type Offset=32 */

	/* Parameter OptionCode */

/* 42 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 44 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 46 */	NdrFcShort( 0x20 ),	/* Type Offset=32 */

	/* Parameter ConvetToMini */

/* 48 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 50 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 52 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter ReturnCode */

/* 54 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 56 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 58 */	NdrFcShort( 0x416 ),	/* Type Offset=1046 */

	/* Return value */

/* 60 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 62 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 64 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Search */

/* 66 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 68 */	NdrFcLong( 0x0 ),	/* 0 */
/* 72 */	NdrFcShort( 0x8 ),	/* 8 */
/* 74 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 76 */	NdrFcShort( 0x0 ),	/* 0 */
/* 78 */	NdrFcShort( 0x8 ),	/* 8 */
/* 80 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 82 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 84 */	NdrFcShort( 0x20 ),	/* 32 */
/* 86 */	NdrFcShort( 0x0 ),	/* 0 */
/* 88 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pvFileList */

/* 90 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 92 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 94 */	NdrFcShort( 0x416 ),	/* Type Offset=1046 */

	/* Return value */

/* 96 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 98 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 100 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Browse */

/* 102 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 104 */	NdrFcLong( 0x0 ),	/* 0 */
/* 108 */	NdrFcShort( 0x9 ),	/* 9 */
/* 110 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 112 */	NdrFcShort( 0x0 ),	/* 0 */
/* 114 */	NdrFcShort( 0x8 ),	/* 8 */
/* 116 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 118 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 120 */	NdrFcShort( 0x20 ),	/* 32 */
/* 122 */	NdrFcShort( 0x2 ),	/* 2 */
/* 124 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pbstrTitle */

/* 126 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 128 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 130 */	NdrFcShort( 0x20 ),	/* Type Offset=32 */

	/* Parameter Lang */

/* 132 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 134 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 136 */	NdrFcShort( 0x20 ),	/* Type Offset=32 */

	/* Parameter Path */

/* 138 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 140 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 142 */	NdrFcShort( 0x416 ),	/* Type Offset=1046 */

	/* Return value */

/* 144 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 146 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 148 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ValidateDump */

/* 150 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 152 */	NdrFcLong( 0x0 ),	/* 0 */
/* 156 */	NdrFcShort( 0xa ),	/* 10 */
/* 158 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 160 */	NdrFcShort( 0x0 ),	/* 0 */
/* 162 */	NdrFcShort( 0x8 ),	/* 8 */
/* 164 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 166 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 168 */	NdrFcShort( 0x20 ),	/* 32 */
/* 170 */	NdrFcShort( 0x1 ),	/* 1 */
/* 172 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter FileName */

/* 174 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 176 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 178 */	NdrFcShort( 0x20 ),	/* Type Offset=32 */

	/* Parameter Result */

/* 180 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 182 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 184 */	NdrFcShort( 0x416 ),	/* Type Offset=1046 */

	/* Return value */

/* 186 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 188 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 190 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RetrieveFileContents */

/* 192 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 194 */	NdrFcLong( 0x0 ),	/* 0 */
/* 198 */	NdrFcShort( 0xb ),	/* 11 */
/* 200 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 202 */	NdrFcShort( 0x0 ),	/* 0 */
/* 204 */	NdrFcShort( 0x8 ),	/* 8 */
/* 206 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 208 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 210 */	NdrFcShort( 0x20 ),	/* 32 */
/* 212 */	NdrFcShort( 0x1 ),	/* 1 */
/* 214 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter FileName */

/* 216 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 218 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 220 */	NdrFcShort( 0x20 ),	/* Type Offset=32 */

	/* Parameter pvContents */

/* 222 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 224 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 226 */	NdrFcShort( 0x416 ),	/* Type Offset=1046 */

	/* Return value */

/* 228 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 230 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 232 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetUploadStatus */

/* 234 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 236 */	NdrFcLong( 0x0 ),	/* 0 */
/* 240 */	NdrFcShort( 0xc ),	/* 12 */
/* 242 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 244 */	NdrFcShort( 0x0 ),	/* 0 */
/* 246 */	NdrFcShort( 0x8 ),	/* 8 */
/* 248 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 250 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 252 */	NdrFcShort( 0x20 ),	/* 32 */
/* 254 */	NdrFcShort( 0x0 ),	/* 0 */
/* 256 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter PercentDone */

/* 258 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 260 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 262 */	NdrFcShort( 0x416 ),	/* Type Offset=1046 */

	/* Return value */

/* 264 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 266 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 268 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetUploadResult */

/* 270 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 272 */	NdrFcLong( 0x0 ),	/* 0 */
/* 276 */	NdrFcShort( 0xd ),	/* 13 */
/* 278 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 280 */	NdrFcShort( 0x0 ),	/* 0 */
/* 282 */	NdrFcShort( 0x8 ),	/* 8 */
/* 284 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 286 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 288 */	NdrFcShort( 0x20 ),	/* 32 */
/* 290 */	NdrFcShort( 0x0 ),	/* 0 */
/* 292 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter UploadResult */

/* 294 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 296 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 298 */	NdrFcShort( 0x416 ),	/* Type Offset=1046 */

	/* Return value */

/* 300 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 302 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 304 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CancelUpload */

/* 306 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 308 */	NdrFcLong( 0x0 ),	/* 0 */
/* 312 */	NdrFcShort( 0xe ),	/* 14 */
/* 314 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 316 */	NdrFcShort( 0x0 ),	/* 0 */
/* 318 */	NdrFcShort( 0x8 ),	/* 8 */
/* 320 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 322 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 324 */	NdrFcShort( 0x20 ),	/* 32 */
/* 326 */	NdrFcShort( 0x0 ),	/* 0 */
/* 328 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ReturnCode */

/* 330 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 332 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 334 */	NdrFcShort( 0x416 ),	/* Type Offset=1046 */

	/* Return value */

/* 336 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 338 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 340 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0x0,	/* FC_RP */
/*  4 */	NdrFcShort( 0x1c ),	/* Offset= 28 (32) */
/*  6 */	
			0x12, 0x0,	/* FC_UP */
/*  8 */	NdrFcShort( 0xe ),	/* Offset= 14 (22) */
/* 10 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 12 */	NdrFcShort( 0x2 ),	/* 2 */
/* 14 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 16 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 18 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 20 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 22 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 24 */	NdrFcShort( 0x8 ),	/* 8 */
/* 26 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (10) */
/* 28 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 30 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 32 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 34 */	NdrFcShort( 0x0 ),	/* 0 */
/* 36 */	NdrFcShort( 0x4 ),	/* 4 */
/* 38 */	NdrFcShort( 0x0 ),	/* 0 */
/* 40 */	NdrFcShort( 0xffde ),	/* Offset= -34 (6) */
/* 42 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 44 */	NdrFcShort( 0x3ea ),	/* Offset= 1002 (1046) */
/* 46 */	
			0x13, 0x0,	/* FC_OP */
/* 48 */	NdrFcShort( 0x3d2 ),	/* Offset= 978 (1026) */
/* 50 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 52 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 54 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 56 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 58 */	NdrFcShort( 0x2 ),	/* Offset= 2 (60) */
/* 60 */	NdrFcShort( 0x10 ),	/* 16 */
/* 62 */	NdrFcShort( 0x2f ),	/* 47 */
/* 64 */	NdrFcLong( 0x14 ),	/* 20 */
/* 68 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 70 */	NdrFcLong( 0x3 ),	/* 3 */
/* 74 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 76 */	NdrFcLong( 0x11 ),	/* 17 */
/* 80 */	NdrFcShort( 0x8001 ),	/* Simple arm type: FC_BYTE */
/* 82 */	NdrFcLong( 0x2 ),	/* 2 */
/* 86 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 88 */	NdrFcLong( 0x4 ),	/* 4 */
/* 92 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 94 */	NdrFcLong( 0x5 ),	/* 5 */
/* 98 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 100 */	NdrFcLong( 0xb ),	/* 11 */
/* 104 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 106 */	NdrFcLong( 0xa ),	/* 10 */
/* 110 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 112 */	NdrFcLong( 0x6 ),	/* 6 */
/* 116 */	NdrFcShort( 0xe8 ),	/* Offset= 232 (348) */
/* 118 */	NdrFcLong( 0x7 ),	/* 7 */
/* 122 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 124 */	NdrFcLong( 0x8 ),	/* 8 */
/* 128 */	NdrFcShort( 0xe2 ),	/* Offset= 226 (354) */
/* 130 */	NdrFcLong( 0xd ),	/* 13 */
/* 134 */	NdrFcShort( 0xe0 ),	/* Offset= 224 (358) */
/* 136 */	NdrFcLong( 0x9 ),	/* 9 */
/* 140 */	NdrFcShort( 0xec ),	/* Offset= 236 (376) */
/* 142 */	NdrFcLong( 0x2000 ),	/* 8192 */
/* 146 */	NdrFcShort( 0xf8 ),	/* Offset= 248 (394) */
/* 148 */	NdrFcLong( 0x24 ),	/* 36 */
/* 152 */	NdrFcShort( 0x320 ),	/* Offset= 800 (952) */
/* 154 */	NdrFcLong( 0x4024 ),	/* 16420 */
/* 158 */	NdrFcShort( 0x31a ),	/* Offset= 794 (952) */
/* 160 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 164 */	NdrFcShort( 0x318 ),	/* Offset= 792 (956) */
/* 166 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 170 */	NdrFcShort( 0x316 ),	/* Offset= 790 (960) */
/* 172 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 176 */	NdrFcShort( 0x314 ),	/* Offset= 788 (964) */
/* 178 */	NdrFcLong( 0x4014 ),	/* 16404 */
/* 182 */	NdrFcShort( 0x312 ),	/* Offset= 786 (968) */
/* 184 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 188 */	NdrFcShort( 0x310 ),	/* Offset= 784 (972) */
/* 190 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 194 */	NdrFcShort( 0x30e ),	/* Offset= 782 (976) */
/* 196 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 200 */	NdrFcShort( 0x2f8 ),	/* Offset= 760 (960) */
/* 202 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 206 */	NdrFcShort( 0x2f6 ),	/* Offset= 758 (964) */
/* 208 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 212 */	NdrFcShort( 0x300 ),	/* Offset= 768 (980) */
/* 214 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 218 */	NdrFcShort( 0x2f6 ),	/* Offset= 758 (976) */
/* 220 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 224 */	NdrFcShort( 0x2f8 ),	/* Offset= 760 (984) */
/* 226 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 230 */	NdrFcShort( 0x2f6 ),	/* Offset= 758 (988) */
/* 232 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 236 */	NdrFcShort( 0x2f4 ),	/* Offset= 756 (992) */
/* 238 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 242 */	NdrFcShort( 0x2f2 ),	/* Offset= 754 (996) */
/* 244 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 248 */	NdrFcShort( 0x2f0 ),	/* Offset= 752 (1000) */
/* 250 */	NdrFcLong( 0x10 ),	/* 16 */
/* 254 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 256 */	NdrFcLong( 0x12 ),	/* 18 */
/* 260 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 262 */	NdrFcLong( 0x13 ),	/* 19 */
/* 266 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 268 */	NdrFcLong( 0x15 ),	/* 21 */
/* 272 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 274 */	NdrFcLong( 0x16 ),	/* 22 */
/* 278 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 280 */	NdrFcLong( 0x17 ),	/* 23 */
/* 284 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 286 */	NdrFcLong( 0xe ),	/* 14 */
/* 290 */	NdrFcShort( 0x2ce ),	/* Offset= 718 (1008) */
/* 292 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 296 */	NdrFcShort( 0x2d2 ),	/* Offset= 722 (1018) */
/* 298 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 302 */	NdrFcShort( 0x2d0 ),	/* Offset= 720 (1022) */
/* 304 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 308 */	NdrFcShort( 0x28c ),	/* Offset= 652 (960) */
/* 310 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 314 */	NdrFcShort( 0x28a ),	/* Offset= 650 (964) */
/* 316 */	NdrFcLong( 0x4015 ),	/* 16405 */
/* 320 */	NdrFcShort( 0x288 ),	/* Offset= 648 (968) */
/* 322 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 326 */	NdrFcShort( 0x27e ),	/* Offset= 638 (964) */
/* 328 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 332 */	NdrFcShort( 0x278 ),	/* Offset= 632 (964) */
/* 334 */	NdrFcLong( 0x0 ),	/* 0 */
/* 338 */	NdrFcShort( 0x0 ),	/* Offset= 0 (338) */
/* 340 */	NdrFcLong( 0x1 ),	/* 1 */
/* 344 */	NdrFcShort( 0x0 ),	/* Offset= 0 (344) */
/* 346 */	NdrFcShort( 0xffff ),	/* Offset= -1 (345) */
/* 348 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 350 */	NdrFcShort( 0x8 ),	/* 8 */
/* 352 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 354 */	
			0x13, 0x0,	/* FC_OP */
/* 356 */	NdrFcShort( 0xfeb2 ),	/* Offset= -334 (22) */
/* 358 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 360 */	NdrFcLong( 0x0 ),	/* 0 */
/* 364 */	NdrFcShort( 0x0 ),	/* 0 */
/* 366 */	NdrFcShort( 0x0 ),	/* 0 */
/* 368 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 370 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 372 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 374 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 376 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 378 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 382 */	NdrFcShort( 0x0 ),	/* 0 */
/* 384 */	NdrFcShort( 0x0 ),	/* 0 */
/* 386 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 388 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 390 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 392 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 394 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 396 */	NdrFcShort( 0x2 ),	/* Offset= 2 (398) */
/* 398 */	
			0x13, 0x0,	/* FC_OP */
/* 400 */	NdrFcShort( 0x216 ),	/* Offset= 534 (934) */
/* 402 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x49,		/* 73 */
/* 404 */	NdrFcShort( 0x18 ),	/* 24 */
/* 406 */	NdrFcShort( 0xa ),	/* 10 */
/* 408 */	NdrFcLong( 0x8 ),	/* 8 */
/* 412 */	NdrFcShort( 0x5a ),	/* Offset= 90 (502) */
/* 414 */	NdrFcLong( 0xd ),	/* 13 */
/* 418 */	NdrFcShort( 0x7e ),	/* Offset= 126 (544) */
/* 420 */	NdrFcLong( 0x9 ),	/* 9 */
/* 424 */	NdrFcShort( 0x9e ),	/* Offset= 158 (582) */
/* 426 */	NdrFcLong( 0xc ),	/* 12 */
/* 430 */	NdrFcShort( 0xc8 ),	/* Offset= 200 (630) */
/* 432 */	NdrFcLong( 0x24 ),	/* 36 */
/* 436 */	NdrFcShort( 0x124 ),	/* Offset= 292 (728) */
/* 438 */	NdrFcLong( 0x800d ),	/* 32781 */
/* 442 */	NdrFcShort( 0x140 ),	/* Offset= 320 (762) */
/* 444 */	NdrFcLong( 0x10 ),	/* 16 */
/* 448 */	NdrFcShort( 0x15a ),	/* Offset= 346 (794) */
/* 450 */	NdrFcLong( 0x2 ),	/* 2 */
/* 454 */	NdrFcShort( 0x174 ),	/* Offset= 372 (826) */
/* 456 */	NdrFcLong( 0x3 ),	/* 3 */
/* 460 */	NdrFcShort( 0x18e ),	/* Offset= 398 (858) */
/* 462 */	NdrFcLong( 0x14 ),	/* 20 */
/* 466 */	NdrFcShort( 0x1a8 ),	/* Offset= 424 (890) */
/* 468 */	NdrFcShort( 0xffff ),	/* Offset= -1 (467) */
/* 470 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 472 */	NdrFcShort( 0x4 ),	/* 4 */
/* 474 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 476 */	NdrFcShort( 0x0 ),	/* 0 */
/* 478 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 480 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 482 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 484 */	NdrFcShort( 0x4 ),	/* 4 */
/* 486 */	NdrFcShort( 0x0 ),	/* 0 */
/* 488 */	NdrFcShort( 0x1 ),	/* 1 */
/* 490 */	NdrFcShort( 0x0 ),	/* 0 */
/* 492 */	NdrFcShort( 0x0 ),	/* 0 */
/* 494 */	0x13, 0x0,	/* FC_OP */
/* 496 */	NdrFcShort( 0xfe26 ),	/* Offset= -474 (22) */
/* 498 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 500 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 502 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 504 */	NdrFcShort( 0x8 ),	/* 8 */
/* 506 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 508 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 510 */	NdrFcShort( 0x4 ),	/* 4 */
/* 512 */	NdrFcShort( 0x4 ),	/* 4 */
/* 514 */	0x11, 0x0,	/* FC_RP */
/* 516 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (470) */
/* 518 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 520 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 522 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 524 */	NdrFcShort( 0x0 ),	/* 0 */
/* 526 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 528 */	NdrFcShort( 0x0 ),	/* 0 */
/* 530 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 532 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 536 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 538 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 540 */	NdrFcShort( 0xff4a ),	/* Offset= -182 (358) */
/* 542 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 544 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 546 */	NdrFcShort( 0x8 ),	/* 8 */
/* 548 */	NdrFcShort( 0x0 ),	/* 0 */
/* 550 */	NdrFcShort( 0x6 ),	/* Offset= 6 (556) */
/* 552 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 554 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 556 */	
			0x11, 0x0,	/* FC_RP */
/* 558 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (522) */
/* 560 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 562 */	NdrFcShort( 0x0 ),	/* 0 */
/* 564 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 566 */	NdrFcShort( 0x0 ),	/* 0 */
/* 568 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 570 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 574 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 576 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 578 */	NdrFcShort( 0xff36 ),	/* Offset= -202 (376) */
/* 580 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 582 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 584 */	NdrFcShort( 0x8 ),	/* 8 */
/* 586 */	NdrFcShort( 0x0 ),	/* 0 */
/* 588 */	NdrFcShort( 0x6 ),	/* Offset= 6 (594) */
/* 590 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 592 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 594 */	
			0x11, 0x0,	/* FC_RP */
/* 596 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (560) */
/* 598 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 600 */	NdrFcShort( 0x4 ),	/* 4 */
/* 602 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 604 */	NdrFcShort( 0x0 ),	/* 0 */
/* 606 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 608 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 610 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 612 */	NdrFcShort( 0x4 ),	/* 4 */
/* 614 */	NdrFcShort( 0x0 ),	/* 0 */
/* 616 */	NdrFcShort( 0x1 ),	/* 1 */
/* 618 */	NdrFcShort( 0x0 ),	/* 0 */
/* 620 */	NdrFcShort( 0x0 ),	/* 0 */
/* 622 */	0x13, 0x0,	/* FC_OP */
/* 624 */	NdrFcShort( 0x192 ),	/* Offset= 402 (1026) */
/* 626 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 628 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 630 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 632 */	NdrFcShort( 0x8 ),	/* 8 */
/* 634 */	NdrFcShort( 0x0 ),	/* 0 */
/* 636 */	NdrFcShort( 0x6 ),	/* Offset= 6 (642) */
/* 638 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 640 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 642 */	
			0x11, 0x0,	/* FC_RP */
/* 644 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (598) */
/* 646 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 648 */	NdrFcLong( 0x2f ),	/* 47 */
/* 652 */	NdrFcShort( 0x0 ),	/* 0 */
/* 654 */	NdrFcShort( 0x0 ),	/* 0 */
/* 656 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 658 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 660 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 662 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 664 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 666 */	NdrFcShort( 0x1 ),	/* 1 */
/* 668 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 670 */	NdrFcShort( 0x4 ),	/* 4 */
/* 672 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 674 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 676 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 678 */	NdrFcShort( 0x10 ),	/* 16 */
/* 680 */	NdrFcShort( 0x0 ),	/* 0 */
/* 682 */	NdrFcShort( 0xa ),	/* Offset= 10 (692) */
/* 684 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 686 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 688 */	NdrFcShort( 0xffd6 ),	/* Offset= -42 (646) */
/* 690 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 692 */	
			0x13, 0x0,	/* FC_OP */
/* 694 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (664) */
/* 696 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 698 */	NdrFcShort( 0x4 ),	/* 4 */
/* 700 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 702 */	NdrFcShort( 0x0 ),	/* 0 */
/* 704 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 706 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 708 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 710 */	NdrFcShort( 0x4 ),	/* 4 */
/* 712 */	NdrFcShort( 0x0 ),	/* 0 */
/* 714 */	NdrFcShort( 0x1 ),	/* 1 */
/* 716 */	NdrFcShort( 0x0 ),	/* 0 */
/* 718 */	NdrFcShort( 0x0 ),	/* 0 */
/* 720 */	0x13, 0x0,	/* FC_OP */
/* 722 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (676) */
/* 724 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 726 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 728 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 730 */	NdrFcShort( 0x8 ),	/* 8 */
/* 732 */	NdrFcShort( 0x0 ),	/* 0 */
/* 734 */	NdrFcShort( 0x6 ),	/* Offset= 6 (740) */
/* 736 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 738 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 740 */	
			0x11, 0x0,	/* FC_RP */
/* 742 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (696) */
/* 744 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 746 */	NdrFcShort( 0x8 ),	/* 8 */
/* 748 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 750 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 752 */	NdrFcShort( 0x10 ),	/* 16 */
/* 754 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 756 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 758 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (744) */
			0x5b,		/* FC_END */
/* 762 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 764 */	NdrFcShort( 0x18 ),	/* 24 */
/* 766 */	NdrFcShort( 0x0 ),	/* 0 */
/* 768 */	NdrFcShort( 0xa ),	/* Offset= 10 (778) */
/* 770 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 772 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 774 */	NdrFcShort( 0xffe8 ),	/* Offset= -24 (750) */
/* 776 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 778 */	
			0x11, 0x0,	/* FC_RP */
/* 780 */	NdrFcShort( 0xfefe ),	/* Offset= -258 (522) */
/* 782 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 784 */	NdrFcShort( 0x1 ),	/* 1 */
/* 786 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 788 */	NdrFcShort( 0x0 ),	/* 0 */
/* 790 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 792 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 794 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 796 */	NdrFcShort( 0x8 ),	/* 8 */
/* 798 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 800 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 802 */	NdrFcShort( 0x4 ),	/* 4 */
/* 804 */	NdrFcShort( 0x4 ),	/* 4 */
/* 806 */	0x13, 0x0,	/* FC_OP */
/* 808 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (782) */
/* 810 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 812 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 814 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 816 */	NdrFcShort( 0x2 ),	/* 2 */
/* 818 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 820 */	NdrFcShort( 0x0 ),	/* 0 */
/* 822 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 824 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 826 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 828 */	NdrFcShort( 0x8 ),	/* 8 */
/* 830 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 832 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 834 */	NdrFcShort( 0x4 ),	/* 4 */
/* 836 */	NdrFcShort( 0x4 ),	/* 4 */
/* 838 */	0x13, 0x0,	/* FC_OP */
/* 840 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (814) */
/* 842 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 844 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 846 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 848 */	NdrFcShort( 0x4 ),	/* 4 */
/* 850 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 852 */	NdrFcShort( 0x0 ),	/* 0 */
/* 854 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 856 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 858 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 860 */	NdrFcShort( 0x8 ),	/* 8 */
/* 862 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 864 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 866 */	NdrFcShort( 0x4 ),	/* 4 */
/* 868 */	NdrFcShort( 0x4 ),	/* 4 */
/* 870 */	0x13, 0x0,	/* FC_OP */
/* 872 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (846) */
/* 874 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 876 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 878 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 880 */	NdrFcShort( 0x8 ),	/* 8 */
/* 882 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 884 */	NdrFcShort( 0x0 ),	/* 0 */
/* 886 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 888 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 890 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 892 */	NdrFcShort( 0x8 ),	/* 8 */
/* 894 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 896 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 898 */	NdrFcShort( 0x4 ),	/* 4 */
/* 900 */	NdrFcShort( 0x4 ),	/* 4 */
/* 902 */	0x13, 0x0,	/* FC_OP */
/* 904 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (878) */
/* 906 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 908 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 910 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 912 */	NdrFcShort( 0x8 ),	/* 8 */
/* 914 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 916 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 918 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 920 */	NdrFcShort( 0x8 ),	/* 8 */
/* 922 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 924 */	NdrFcShort( 0xffd8 ),	/* -40 */
/* 926 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 928 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 930 */	NdrFcShort( 0xffec ),	/* Offset= -20 (910) */
/* 932 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 934 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 936 */	NdrFcShort( 0x28 ),	/* 40 */
/* 938 */	NdrFcShort( 0xffec ),	/* Offset= -20 (918) */
/* 940 */	NdrFcShort( 0x0 ),	/* Offset= 0 (940) */
/* 942 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 944 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 946 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 948 */	NdrFcShort( 0xfdde ),	/* Offset= -546 (402) */
/* 950 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 952 */	
			0x13, 0x0,	/* FC_OP */
/* 954 */	NdrFcShort( 0xfeea ),	/* Offset= -278 (676) */
/* 956 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 958 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 960 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 962 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 964 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 966 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 968 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 970 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 972 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 974 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 976 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 978 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 980 */	
			0x13, 0x0,	/* FC_OP */
/* 982 */	NdrFcShort( 0xfd86 ),	/* Offset= -634 (348) */
/* 984 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 986 */	NdrFcShort( 0xfd88 ),	/* Offset= -632 (354) */
/* 988 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 990 */	NdrFcShort( 0xfd88 ),	/* Offset= -632 (358) */
/* 992 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 994 */	NdrFcShort( 0xfd96 ),	/* Offset= -618 (376) */
/* 996 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 998 */	NdrFcShort( 0xfda4 ),	/* Offset= -604 (394) */
/* 1000 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1002 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1004) */
/* 1004 */	
			0x13, 0x0,	/* FC_OP */
/* 1006 */	NdrFcShort( 0x14 ),	/* Offset= 20 (1026) */
/* 1008 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 1010 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1012 */	0x6,		/* FC_SHORT */
			0x1,		/* FC_BYTE */
/* 1014 */	0x1,		/* FC_BYTE */
			0x8,		/* FC_LONG */
/* 1016 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 1018 */	
			0x13, 0x0,	/* FC_OP */
/* 1020 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1008) */
/* 1022 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1024 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 1026 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 1028 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1030 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1032 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1032) */
/* 1034 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1036 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1038 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1040 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1042 */	NdrFcShort( 0xfc20 ),	/* Offset= -992 (50) */
/* 1044 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1046 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1048 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1050 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1052 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1054 */	NdrFcShort( 0xfc10 ),	/* Offset= -1008 (46) */

			0x0
        }
    };

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ] = 
        {
            
            {
            BSTR_UserSize
            ,BSTR_UserMarshal
            ,BSTR_UserUnmarshal
            ,BSTR_UserFree
            },
            {
            VARIANT_UserSize
            ,VARIANT_UserMarshal
            ,VARIANT_UserUnmarshal
            ,VARIANT_UserFree
            }

        };



/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IOcarptMain, ver. 0.0,
   GUID={0x53E2D7B5,0xEC6C,0x4FF7,{0x80,0xF2,0x1C,0xE5,0xFD,0x65,0x44,0xCE}} */

#pragma code_seg(".orpc")
static const unsigned short IOcarptMain_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    66,
    102,
    150,
    192,
    234,
    270,
    306
    };

static const MIDL_STUBLESS_PROXY_INFO IOcarptMain_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IOcarptMain_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IOcarptMain_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IOcarptMain_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(15) _IOcarptMainProxyVtbl = 
{
    &IOcarptMain_ProxyInfo,
    &IID_IOcarptMain,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IOcarptMain::Upload */ ,
    (void *) (INT_PTR) -1 /* IOcarptMain::Search */ ,
    (void *) (INT_PTR) -1 /* IOcarptMain::Browse */ ,
    (void *) (INT_PTR) -1 /* IOcarptMain::ValidateDump */ ,
    (void *) (INT_PTR) -1 /* IOcarptMain::RetrieveFileContents */ ,
    (void *) (INT_PTR) -1 /* IOcarptMain::GetUploadStatus */ ,
    (void *) (INT_PTR) -1 /* IOcarptMain::GetUploadResult */ ,
    (void *) (INT_PTR) -1 /* IOcarptMain::CancelUpload */
};


static const PRPC_STUB_FUNCTION IOcarptMain_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IOcarptMainStubVtbl =
{
    &IID_IOcarptMain,
    &IOcarptMain_ServerInfo,
    15,
    &IOcarptMain_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    __MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x600016e, /* MIDL Version 6.0.366 */
    0,
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0   /* Reserved5 */
    };

const CInterfaceProxyVtbl * _ocarpt_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IOcarptMainProxyVtbl,
    0
};

const CInterfaceStubVtbl * _ocarpt_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IOcarptMainStubVtbl,
    0
};

PCInterfaceName const _ocarpt_InterfaceNamesList[] = 
{
    "IOcarptMain",
    0
};

const IID *  _ocarpt_BaseIIDList[] = 
{
    &IID_IDispatch,
    0
};


#define _ocarpt_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _ocarpt, pIID, n)

int __stdcall _ocarpt_IID_Lookup( const IID * pIID, int * pIndex )
{
    
    if(!_ocarpt_CHECK_IID(0))
        {
        *pIndex = 0;
        return 1;
        }

    return 0;
}

const ExtendedProxyFileInfo ocarpt_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _ocarpt_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _ocarpt_StubVtblList,
    (const PCInterfaceName * ) & _ocarpt_InterfaceNamesList,
    (const IID ** ) & _ocarpt_BaseIIDList,
    & _ocarpt_IID_Lookup, 
    1,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#pragma optimize("", on )
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/

