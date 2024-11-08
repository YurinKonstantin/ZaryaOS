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


//
// Define the severity codes
//
#define STATUS_SEVERITY_WARNING          0x2
#define STATUS_SEVERITY_SUCCESS          0x0
#define STATUS_SEVERITY_INFORMATIONAL    0x1
#define STATUS_SEVERITY_ERROR            0x3


//
// MessageId: EVENT_MSG_GENERIC
//
// MessageText:
//
//  %1
//
#define EVENT_MSG_GENERIC                0x00000000L

//
// MessageId: EVENT_MSG_INFORMATIONAL
//
// MessageText:
//
//  Information:
//  %1
//
#define EVENT_MSG_INFORMATIONAL          0x000003E8L

//
// MessageId: EVENT_MSG_SUCCESS
//
// MessageText:
//
//  Success:
//  %1
//
#define EVENT_MSG_SUCCESS                0x000007D0L

//
// MessageId: EVENT_MSG_WARNING
//
// MessageText:
//
//  Warning:
//  %1
//
#define EVENT_MSG_WARNING                0x00000BB8L

//
// MessageId: EVENT_MSG_ERROR
//
// MessageText:
//
//  Error:
//  %1
//
#define EVENT_MSG_ERROR                  0x00000FA0L

