//=================================================================
//
// SystemName.cpp
//
//  Copyright (c) 1995-2003 Microsoft Corporation, All Rights Reserved
//
//=================================================================

#include "precomp.h"
#include <cregcls.h>
#include <lockwrap.h>
#include "resource.h"

#include "SystemName.h"

#include "KUserdata.h"
#include "WMI_FilePrivateProfile.h"

CHString CSystemName::s_sKeyName;
CHString CSystemName::s_sLocalKeyName;

CSystemName::CSystemName()
{
    CLockWrapper SystemName(g_csSystemName);

    if (s_sKeyName.IsEmpty())
    {
	    TCHAR szDir[_MAX_PATH];
	    TCHAR szDevice[_MAX_PATH] ;

	    CRegistry RegInfo ;

	    s_sKeyName = GetKeyName();

	    if ( ! GetWindowsDirectory ( szDir, sizeof ( szDir ) / sizeof(TCHAR)) )
	    {
		    szDir[0] = '\0';
	    }

    #ifdef NTONLY
	    {
    	    WCHAR szFileName[_MAX_PATH] ;

		    wcscpy ( szFileName , szDir ) ;
		    wcscat ( szFileName , L"\\REPAIR\\SETUP.LOG" ) ;

		    WMI_FILE_GetPrivateProfileStringW (
                    L"Paths" ,
                    L"TargetDevice" ,
                    L"" ,
                    szDevice ,
                    sizeof ( szDevice ) / sizeof(WCHAR) ,
                    szFileName
                    ) ;
	    }
    #endif
	    s_sKeyName += '|' ;
	    s_sKeyName += szDir ;
	    s_sKeyName += '|' ;
	    s_sKeyName += szDevice ;
    }
}

CSystemName::~CSystemName()
{
}

bool CSystemName::ObjectIsUs(const CInstance *pInstance)
{
   CHString sName ;

   // Get the values from the object
   pInstance->GetCHString(IDS_Name, sName);

   // Do the comparison
   return (s_sKeyName.CompareNoCase(sName) == 0);
}

void CSystemName::SetKeys(CInstance *pInstance)
{
	pInstance->SetCHString(IDS_Name, s_sKeyName);
}

/*****************************************************************************
 *
 *  FUNCTION    : GetKeyName
 *
 *  DESCRIPTION : Gets the Name property (not the machine name!)
 *
 *  INPUTS      : none
 *
 *  OUTPUTS     : none
 *
 *  RETURNS     : CHString for the name
 *
 *  COMMENTS    :
 *
 *****************************************************************************/
CHString CSystemName::GetKeyName(void)
{
	CHString chsName;
	CRegistry RegInfo;

#ifdef NTONLY
	{
		KUserdata ku;
		ULONG uProductType = 0xffffffff;

		if ( ku.ProductTypeIsValid() )
			uProductType = ku.NtProductType();

		// Start with the product name
		if( IsWinNT5() )
		{
			if( ERROR_SUCCESS == RegInfo.Open ( HKEY_LOCAL_MACHINE ,
									_T("SOFTWARE\\Microsoft\\Windows NT\\Currentversion") ,
									KEY_READ) )
			{
				RegInfo.GetCurrentKeyValue( _T("ProductName") , chsName );
			}

			if(chsName.IsEmpty())
			{
				if ( IsWinNT51 () || IsWinNT52 () )
				{
					if ( VER_NT_SERVER == uProductType || VER_NT_DOMAIN_CONTROLLER == uProductType )
					{
						if ( VER_SUITE_SMALLBUSINESS_RESTRICTED & ku.SuiteMask() )
						{
							//
							// SBS doesn't seem to contain coma in the name
							//
							chsName = L"Microsoft(R) Windows(R) Server 2003" ;
						}
						else
						{
							chsName = _T("Microsoft(R) Windows(R) Server 2003,");
						}
					}
					else
					{
						chsName = _T("Microsoft Windows XP");
					}
				}
				else if ( IsWinNT5 () )
				{
					chsName = _T("Microsoft Windows 2000");
				}
				else
				{
					chsName = _T("Unknown Microsoft Windows");
				}
			}
		}
		else
			chsName = _T("Microsoft Windows NT");


		/* now for the product type */

		// Blade Server
		if ( IsWinNT5() && VER_SUITE_BLADE & ku.SuiteMask() )
		{
            chsName += _T(" Web Edition");
		}
		// NT5 Datacenter Server
		else if( IsWinNT5() &&
			( VER_SUITE_DATACENTER & ku.SuiteMask() ) &&
			( VER_NT_SERVER == uProductType || VER_NT_DOMAIN_CONTROLLER == uProductType ) )
		{
			chsName += _T(" Datacenter Edition");
		}
		// Enterprise or Advanced Server
		else if( (VER_SUITE_ENTERPRISE & ku.SuiteMask()) &&
				 (VER_NT_SERVER == uProductType ||VER_NT_DOMAIN_CONTROLLER == uProductType ) )
		{
			if( IsWinNT5() )
			{
				if ( IsWinNT52 () )
				{
					chsName += _T(" Enterprise Edition");
				}
				else
				{
					chsName += _T(" Advanced Server");
				}
			}
			else
			{
				chsName += _T(" Enterprise Server");
			}
		}
		// Server edition
		else if( ( VER_NT_SERVER == uProductType || VER_NT_DOMAIN_CONTROLLER == uProductType ) )
		{

#ifdef	_WIN64
			chsName = _T(" Microsoft Windows Advanced Server Limited Edition");
#else
			if( IsWinNT52 () )
			{
				if ( VER_SUITE_SMALLBUSINESS_RESTRICTED & ku.SuiteMask() )
				{
					chsName += L" for Small Business Server" ;
				}
				else
				{
					chsName += _T(" Standard Edition");
				}
			}
			else
			{
				chsName += _T(" Server");
			}
#endif	_WIN64

		}
		// embedded windows
		else if ( IsWinNT51() && VER_SUITE_EMBEDDEDNT & ku.SuiteMask() )
		{
			chsName += _T(" Embedded");
		}
		// NT5 Professional or NT4 Workstation
		else if(VER_NT_WORKSTATION == uProductType)
		{

#ifdef	_WIN64
			chsName += _T(" 64-Bit Edition");
#else
			if( IsWinNT5() )
			{
				if (VER_SUITE_PERSONAL & ku.SuiteMask())
				{
					chsName += _T(" Home Edition");
				}
				else
				{
					chsName += _T(" Professional");
				}
			}
			else
			{
				chsName += _T(" Workstation");
			}
#endif	_WIN64

		}
	}
#endif
	return chsName;
}
/*****************************************************************************
 *
 *  FUNCTION    : GetLocalizedName
 *
 *  DESCRIPTION : Gets the Name property (not the machine name!) localized
 *
 *  INPUTS      : none
 *
 *  OUTPUTS     : none
 *
 *  RETURNS     : CHString for the name
 *
 *  COMMENTS    :
 *
 *****************************************************************************/
CHString CSystemName::GetLocalizedName(void)
{
    CLockWrapper SystemName(g_csSystemName);
    if (s_sLocalKeyName.IsEmpty())
    {

#ifdef NTONLY
		KUserdata	t_ku ;
		ULONG		t_uProductType = 0xffffffff ;
		UINT		t_nID ;

		if ( t_ku.ProductTypeIsValid() )
		{
			t_uProductType = t_ku.NtProductType();
		}

		//windows powered
		if ( IsWinNT5() && VER_SUITE_BLADE & t_ku.SuiteMask() )
		{
			t_nID = IDR_Blade_StockName ;
		}

		// W2k Datacenter Server
		else if( IsWinNT5() && ( VER_SUITE_DATACENTER & t_ku.SuiteMask() ) &&
							( VER_NT_SERVER == t_uProductType ||
							  VER_NT_DOMAIN_CONTROLLER == t_uProductType ) )
		{
			if ( IsWinNT52 () )
			{
				t_nID = IDR_W2kPlus1_Datacenter ;
			}
			else
			{
				t_nID = IDR_W2k_Datacenter ;
			}
		}

		// Enterprise or Advanced Server
		else if( ( VER_SUITE_ENTERPRISE & t_ku.SuiteMask() ) &&
					( VER_NT_SERVER == t_uProductType ||
					  VER_NT_DOMAIN_CONTROLLER == t_uProductType ) )
		{
			if( IsWinNT5() )
			{
				if ( IsWinNT52 () )
				{
					t_nID = IDR_W2kPlus1_AdvancedServer ;
				}
				else
				{
					t_nID = IDR_W2k_AdvancedServer ;
				}
			}
			else
			{
				t_nID = IDR_NT_EnterpriseServer ;
			}
		}

		// Server edition
		else if( ( VER_NT_SERVER == t_uProductType ||
				   VER_NT_DOMAIN_CONTROLLER == t_uProductType ) )
		{

#ifdef	_WIN64
			t_nID = IDR_W2kPlus1_Server_64Bit;
#else
			if( IsWinNT5() )
			{
				if ( IsWinNT52 () )
				{
					if ( VER_SUITE_SMALLBUSINESS_RESTRICTED & t_ku.SuiteMask() )
					{
						t_nID = IDR_W2kPlus1_Server_SBS ;
					}
					else
					{
						t_nID = IDR_W2kPlus1_Server ;
					}
				}
				else
				{
					t_nID = IDR_W2k_Server ;
				}				    
			}
			else
			{
				t_nID = IDR_NT_Server ;
			}
#endif	_WIN64

		}

		// embedded windows
		else if ( IsWinNT51() && VER_SUITE_EMBEDDEDNT & t_ku.SuiteMask() )
		{
			t_nID = IDR_W2kPlus1_Embedded;
		}

		// NT5 Professional or NT4 Workstation
		else if( VER_NT_WORKSTATION == t_uProductType )
		{

#ifdef	_WIN64
			t_nID = IDR_W2kPlus1_Professional_64Bit;
#else
			if( IsWinNT5() )
			{
				if (IsWinNT51() || IsWinNT52())
				{
					if (VER_SUITE_PERSONAL & t_ku.SuiteMask())
					{
						t_nID = IDR_W2kPlus1_Personal ; 
					}
					else
					{
						t_nID = IDR_W2kPlus1_Professional ; 
					}
				}
				else
				{
					t_nID = IDR_W2k_Professional ;
				}				    
			}
			else
			{
				t_nID = IDR_NT_Workstation ;
			}
#endif	_WIN64

		}

		// Stock name ( should not be here )
		else
		{
			if( IsWinNT5() )
			{
				if ( IsWinNT51 () )
				{
					t_nID = IDR_W2kPlus1_StockName ;
				}
				else
				{
					t_nID = IDR_W2k_StockName ;
				}				    
			}
			else
			{
				t_nID = IDR_NT_StockName ;
			}
		}

		LoadStringW( s_sLocalKeyName, t_nID );
#endif
    }
	return s_sLocalKeyName;
}
