<% @LANGUAGE="VBScript" @EnableSessionState="False"  %>
<% 'Option Explicit

Function GetString(ByVal sStringName)
	If InStr(sStringName, "L_") <> 1 Then sStringName = "L_" & sStringName & "_Text"

	'' Texts
	Const L_StartRemoteAssistance_Text  		= "Starta Fj�rrhj�lp"
	Const L_ProductName_Text			= "Fj�rrhj�lp"
	Const L_Title1Paragraph1_Text		= "S� h�r hj�lper du andra med Fj�rrhj�lp"
	Const L_Paragraph1_Text				= "Det b�sta s�ttet att hj�lpa n�gon �r ibland att kunna visualisera en l�sning. Fj�rrhj�lp �r en s�ker anslutning som du kan anv�nda f�r att visa en v�n en l�sning p� ett datorproblem."
	Const L_Paragraph2_Text				= "L�s anteckningarna nedan om detta �r f�rsta g�ngen du anv�nder Fj�rrhj�lp."
	Const L_StartRAMessage_Text			= "<font color=""#000000"" size=""2"">Om du vill ansluta till din v�ns dator klickar du p�</font><b><font color=""#000000"" size=""2""><b> Starta Fj�rrhj�lp.</b></font></b>"
	Const L_StartRAButton_Text			= "Starta Fj�rrhj�lp"
	Const L_JScriptNotAvail1_Text		= "S�kerhetsinst�llningarna f�r Internet Explorer �r f�r h�gt satta f�r anv�ndning av Fj�rrhj�lp. �ndra dessa inst�llningar eller l�gg till denna sida som en tillf�rlitlig plats."
	Const L_IEHelp_Text					= "Mer information om hur du �ndrar s�kerhetsinst�llningar finns i direkthj�lpen i Internet Explorer."
	Const L_TicketError1_Text			= "Din inbjudan till Fj�rrhj�lp saknas eller �r ogiltig. Du beh�ver en giltig inbjudan f�r att anv�nda Fj�rrhj�lp."
	Const L_InstallIE_Text				= "Internet Explorer 5.5 kr�vs f�r att kunna acceptera en inbjudan till Fj�rrhj�lp."
	Const L_TicketErrorMsg_Text			= "Om du vill l�sa mer om <B>Fj�rrhj�lp</B> klicka p� <B>Start</B>, <B>Hj�lp och support</B> i Windows XP och skriv <B>Fj�rrhj�lp</B> i <B>S�kf�nstret</B>."
	
	Const L_NotesTitle_Text				= "Anteckningar"
	Const L_NotesLine1_Text				= "Acceptera endast inbjudningar fr�n personer du litar p�."
	
	Const L_NotesLine2_Text				= "B�de du och den person som du hj�lper m�ste vara anslutna till Internet medan Fj�rrhj�lp anv�nds. Om personen som skickade denna inbjudan accepterar din beg�ran att ansluta till dennes dator kommer du att kunna se hans eller hennes datorsk�rm och chatta i realtid."
	
	Const L_NotesLine6_Text				= "Detta �r en s�ker enkelriktad anslutning. Den person du ansluter till kan inte komma �t inneh�llet p� din dator. Om du arbetar i ett lokalt n�tverk kan det h�nda att en brandv�gg hindrar dig fr�n att anv�nda Fj�rrhj�lp. Du b�r i s�dana fall kontakta n�tverksadministrat�ren."
	
	Const L_LearnXP_Text				= "Om du vill l�sa mer om <B>Fj�rrhj�lp</B> kan du klicka p� <B>Start</B>, <B>Hj�lp och support</B> i Windows XP och d�refter skriva <B>Fj�rrhj�lp</B> i <B>s�kf�ltet</B>."
	
	Const L_ContactUsMsg_Text			= "Kontakta oss"
	

	Const L_XPNewsletterMsg_Text		= "Gratis nyhetsbrev"
	Const L_EmailPage_Text				= "Skicka denna sida med e-post"
	
	Const L_CopyRightMsg_Text			= "(C) 2001 Microsoft Corporation. Med ensamr�tt. Anv�ndningsvillkor."
	
	Const L_PrivacyMsg_Text				= "Sekretesspolicy"

	Const L_AccMsg_Text					= "Hj�lpmedel"

	Const L_NotIEError1_Text			= "Internet Explorer 5.5 eller nyare kr�vs f�r att kunna acceptera en inbjudan till Fj�rrhj�lp."

	Const L_NotXPError1_Text			= "Microsoft Fj�rrhj�lp �r en funktion i Windows&nbsp;XP. Du m�ste f�rst installera Windows&nbsp;XP f�r att kunna anv�nda Fj�rrhj�lp."

	Const L_IELinkMsg_Text				= "H�mta den senaste versionen av Internet Explorer"
	Const L_XPLinkMsg_Text				= "Du kan l�sa mer om Windows XP p� "
	Const L_XPLinkMsg2_Text				= "Webbplatsen f�r Microsoft Windows"
	Const L_XPLinkMsg3_Text				= "."
	
	Const L_IntroMsg1_Text              = "H�mtar en komponent som kr�vs f�r Fj�rrhj�lp. Om ett 28,8 kbit/s modem anv�nds kan filh�mtningen ta 1 minut."
    Const L_IntroMsg2_Text              = "F�r att Fj�rrhj�lp ska fungera korrekt m�ste Active Scripting aktiveras. Om denna sida inte bekr�ftar att h�mtningen �r slutf�rd efter den ber�knade h�mtningstiden, b�r du kontrollera att Active Scripting �r aktiverat."
    Const L_IntroMsg3_Text              = "Aktivera Active Scripting"
    Const L_IntroMsg4_Text              = "Klicka p� <B>Internet-alternativ</B> p� <B>Verktyg</B>-menyn i Internet Explorer."
    Const L_IntroMsg5_Text              = "Klicka p� fliken <B>S�kerhet</B>."
    Const L_IntroMsg6_Text              = "Markera <STRONG>Internet</STRONG>och klicka sedan p� <STRONG>Anpassad niv�</STRONG>."
    Const L_IntroMsg7_Text              = "Markera alternativet <STRONG>Aktivera</STRONG> under <STRONG>Active Scripting</STRONG> i sektionen f�r Skript."
    
	' **************************************
	' Links - No need for localization
	' **************************************
	Const L_AccLink_Text				= "http://www.microsoft.com/enable/"		
	Const L_XPLink_Text					= "http://www.microsoft.com/windowsxp/default.asp"
	Const L_PrivacyLink_Text			= "http://www.microsoft.com/info/privacy.htm"
	Const L_ContactUsLink_Text			= "http://register.microsoft.com/contactus30/contactus.asp?domain=windows&amp;lcid=1033&amp;cu=http://register.microsoft.com/contactus30/contactus.asp?domain=windows"
	Const L_MailTo1_Text				= "mailto:?subject=En l�nk fr�n Microsoft&body=Denna l�nk kommer fr�n webbplatsen Microsoft Windows XP"
	Const L_CopyRightLink_Text			= "http://www.microsoft.com/info/cpyright.htm"
	Const L_XPNewsletterLink_Text		= "http://www.microsoft.com/windowsxp/newsletters.asp"
	Const L_LinkToIE_Text				= "http://www.microsoft.com/windows/ie/default.htm"
	'*************************************	
	
	GetString = Eval(sStringName)
End Function

%>