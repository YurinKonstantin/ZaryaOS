<% @LANGUAGE="VBScript" @EnableSessionState="False"  %>
<% 'Option Explicit

Function GetString(ByVal sStringName)
	If InStr(sStringName, "L_") <> 1 Then sStringName = "L_" & sStringName & "_Text"

	'' Texts
	Const L_StartRemoteAssistance_Text  		= "Uruchom Pomoc zdaln�"
	Const L_ProductName_Text			= "Pomoc zdalna"
	Const L_Title1Paragraph1_Text		= "Udzielanie pomocy przy u�yciu Pomocy zdalnej"
	Const L_Paragraph1_Text				= "Czasem najlepszym sposobem udzielenia komu� pomocy w rozwi�zaniu problemu jest zademonstrowanie jego rozwi�zania. Pomoc zdalna jest bezpiecznym po��czeniem, kt�re mo�na wykorzysta� do pokazania przyjacielowi, w jaki spos�b mo�e rozwi�za� problem z komputerem."
	Const L_Paragraph2_Text				= "Je�li dopiero zaczynasz, przeczytaj poni�sze uwagi."
	Const L_StartRAMessage_Text			= "<font color=""#000000"" size=""2"">Aby po��czy� si� z komputerem przyjaciela, kliknij przycisk</font><b><font color=""#000000"" size=""2""><b> Uruchom Pomoc zdaln�.</b></font></b>"
	Const L_StartRAButton_Text			= "Uruchom Pomoc zdaln�"
	Const L_JScriptNotAvail1_Text		= "Bie��cy poziom ustawie� zabezpiecze� programu Internet Explorer jest zbyt wysoki, aby mo�na by�o u�ywa� Pomocy zdalnej. Aby u�y� Pomocy zdalnej, zmie� ustawienia lub dodaj tej witryn� do zaufanych witryn."
	Const L_IEHelp_Text					= "Wi�cej informacji na temat zmiany ustawie� zabezpiecze� mo�na znale�� w Pomocy programu Internet Explorer."
	Const L_TicketError1_Text			= "Brak zaproszenia Pomocy zdalnej lub jest ono nieprawid�owe. Do u�ywania Pomocy zdalnej potrzebne jest prawid�owe zaproszenie."
	Const L_InstallIE_Text				= "Aby zaakceptowa� zaproszenie Pomocy zdalnej, musisz zainstalowa� program Internet Explorer 5.5."
	Const L_TicketErrorMsg_Text			= "Aby uzyska� wi�cej informacji o Pomocy zdalnej, kliknij przycisk <B>Start</B> w systemie Windows XP, kliknij polecenie <B>Pomoc i obs�uga techniczna</B>, a nast�pnie wpisz <B>Pomoc zdalna</B> w polu <B>Wyszukaj</B>."
	
	Const L_NotesTitle_Text				= "Uwagi"
	Const L_NotesLine1_Text				= "Akceptuj zaproszenia tylko od os�b, kt�re znasz."
	
	Const L_NotesLine2_Text				= "Wraz z osob�, kt�rej udzielasz pomocy musicie mie� po��czenie z Internetem podczas u�ywania Pomocy zdalnej. Po zaakceptowaniu przez osob�, kt�ra wys�a�a to zaproszenie, Twojego ��dania pod��czenia si� do jej komputera mo�esz zobaczy� ekran komputera tej osoby i prowadzi� z ni� rozmow� w czasie rzeczywistym."
	
	Const L_NotesLine6_Text				= "Jest to bezpieczne po��czenie jednokierunkowe. Osoba, z kt�rej komputerem masz po��czenie nie b�dzie mog�a u�y� swojego komputera do uzyskania dost�pu do Twojego komputera. Je�li pracujesz w sieci lokalnej, zapory mog� uniemo�liwi� u�ywanie Pomocy zdalnej. W tym wypadku skontaktuj si� z administratorem sieci."
	
	Const L_LearnXP_Text				= "Aby uzyska� wi�cej informacji o Pomocy zdalnej, kliknij przycisk <B>Start</B> w systemie Windows XP, kliknij polecenie <B>Pomoc i obs�uga techniczna</B>, a nast�pnie wpisz <B>Pomoc zdalna</B> w polu <B>Wyszukaj</B>."
	
	Const L_ContactUsMsg_Text			= "Napisz do nas"
	

	Const L_XPNewsletterMsg_Text		= "Bezp�atne biuletyny"
	Const L_EmailPage_Text				= "Wy�lij t� stron� poczt� e-mail"
	
	Const L_CopyRightMsg_Text			= "(C) 2001 Microsoft Corporation. Wszelkie prawa zastrze�one. Zasady u�ytkowania witryny microsoft.com."
	
	Const L_PrivacyMsg_Text				= "Deklaracja ochrony prywatno�ci w witrynie microsoft.com."

	Const L_AccMsg_Text					= "U�atwienia dost�pu"

	Const L_NotIEError1_Text			= "Aby zaakceptowa� zaproszenie Pomocy zdalnej, musisz zainstalowa� program Internet Explorer 5.5 lub nowszy."

	Const L_NotXPError1_Text			= "Pomoc zdalna Microsoft jest funkcj� systemu Windows&nbsp;XP. Aby u�y� Pomocy zdalnej, musisz najpierw zainstalowa� system Windows&nbsp;XP."

	Const L_IELinkMsg_Text				= "Pobierz najnowsz� wersj� programu Internet Explorer"
	Const L_XPLinkMsg_Text				= "Aby uzyska� wi�cej informacji o systemie Windows XP, przejd� do witryny "
	Const L_XPLinkMsg2_Text				= "Microsoft Windows w sieci Web"
	Const L_XPLinkMsg3_Text				= "."
	
	Const L_IntroMsg1_Text              = "Trwa pobieranie sk�adnika potrzebnego do korzystania z Pomocy zdalnej. Je�eli korzystasz z modemu 28.8 kbps, pobieranie powinno potrwa� 1 minut�."
    Const L_IntroMsg2_Text              = "Aby uruchomi� Pomoc zdaln�, nale�y w��czy� wykonywanie aktywnych skrypt�w. Je�eli po up�yni�ciu oszacowanego czasu pobierania nie zostanie wy�wietlone potwierdzenie o zako�czeniu pobierania, nale�y sprawdzi�, czy w��czono wykonywanie aktywnych skrypt�w."
    Const L_IntroMsg3_Text              = "Aby w��czy� wykonywanie aktywnych skrypt�w"
    Const L_IntroMsg4_Text              = "W menu <B>Narz�dzia</B> programu Internet Explorer kliknij polecenie <B>Opcje internetowe</B>."
    Const L_IntroMsg5_Text              = "Kliknij kart� <B>Zabezpieczenia</B>."
    Const L_IntroMsg6_Text              = "Kliknij ikon� <STRONG>Internet</STRONG>, a nast�pnie kliknij przycisk <STRONG>Poziom niestandardowy</STRONG>."
    Const L_IntroMsg7_Text              = "W sekcji Wykonywanie skrypt�w, pod nag��wkiem <STRONG>Wykonywanie aktywnych skrypt�w</STRONG>, zaznacz pole wyboru <STRONG>W��cz</STRONG>."
    
	' **************************************
	' Links - No need for localization
	' **************************************
	Const L_AccLink_Text				= "http://www.microsoft.com/enable/"		
	Const L_XPLink_Text					= "http://www.microsoft.com/windowsxp/default.asp"
	Const L_PrivacyLink_Text			= "http://www.microsoft.com/info/privacy.htm"
	Const L_ContactUsLink_Text			= "http://register.microsoft.com/contactus30/contactus.asp?domain=windows&amp;lcid=1033&amp;cu=http://register.microsoft.com/contactus30/contactus.asp?domain=windows"
	Const L_MailTo1_Text				= "mailto:?subject=��cze z firmy Microsoft&body=To ��cze jest z witryny Microsoft Windows XP w sieci Web"
	Const L_CopyRightLink_Text			= "http://www.microsoft.com/info/cpyright.htm"
	Const L_XPNewsletterLink_Text		= "http://www.microsoft.com/windowsxp/newsletters.asp"
	Const L_LinkToIE_Text				= "http://www.microsoft.com/windows/ie/default.htm"
	'*************************************	
	
	GetString = Eval(sStringName)
End Function

%>