///////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 1999, Microsoft Corp. All rights reserved.
//
// FILE
//
//    changelangmsg.mc
//
// SYNOPSIS
//
//    This f ile defines the messages for the Server project
//
// MODIFICATION HISTORY 
//
//    08/06/2000    Original version. 
//
///////////////////////////////////////////////////////////////////////////////

// please choose one of these severity names as part of your messages
 

// The Facility Name identifies the Alert ID range to be used by
// the specific component. For each new message you add choose the
// facility name corresponding to your component. If none of these
// correspond to your component add a new facility name with a new
// value and name 
///////////////////////////////////////////////////////////////////////////////
//
// 
//
///////////////////////////////////////////////////////////////////////////////
//
//  Values are 32 bit values layed out as follows:
//
//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//  +---+-+-+-----------------------+-------------------------------+
//  |Sev|C|R|     Facility          |               Code            |
//  +---+-+-+-----------------------+-------------------------------+
//
//  where
//
//      Sev - is the severity code
//
//          00 - Success
//          01 - Informational
//          10 - Warning
//          11 - Error
//
//      C - is the Customer code flag
//
//      R - is a reserved bit
//
//      Facility - is the facility code
//
//      Code - is the facility's status code
//
//
// Define the facility codes
//
#define SA_FACILITY_SELFSIGNCERT         0x1


//
// Define the severity codes
//
#define SA_SEVERITY_WARNING              0x2
#define SA_SEVERITY_SUCCESS              0x0
#define SA_SEVERITY_INFORMATIONAL        0x1
#define SA_SEVERITY_ERROR                0x3


//
// MessageId: SA_SSC_ALERT_TITLE
//
// MessageText:
//
//  Install new certificate
//
#define SA_SSC_ALERT_TITLE               0x40010001L

//
// MessageId: SA_SSC_ALERT_DISCRIPTION
//
// MessageText:
//
//  The SSL certificate automatically created for the administration of this server ensures encrypted communications. However, it also causes a warning when you administer the server. To avoid this warning, obtain a properly signed certificate from a certificate authority.
//
#define SA_SSC_ALERT_DISCRIPTION         0x40010002L

