

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 6.00.0366 */
/* Compiler settings for httprequest.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_WinHttp,0x662901fc,0x6951,0x4854,0x9e,0xb2,0xd9,0xa2,0x57,0x0f,0x2b,0x2e);


MIDL_DEFINE_GUID(IID, IID_IWinHttpRequest,0x016fe2ec,0xb2c8,0x45f8,0xb2,0x3b,0x39,0xe5,0x3a,0x75,0x39,0x6b);


MIDL_DEFINE_GUID(IID, IID_IWinHttpRequestEvents,0xf97f4e15,0xb787,0x4212,0x80,0xd1,0xd3,0x80,0xcb,0xbf,0x98,0x2e);


MIDL_DEFINE_GUID(CLSID, CLSID_WinHttpRequest,0x2087c2f4,0x2cef,0x4953,0xa8,0xab,0x66,0x77,0x9b,0x67,0x04,0x95);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



