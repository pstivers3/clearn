// Fig. 3.1: login.cpp
// login dialog
#include <afxwin.h>
#include "login_ids.h"
#include "CLoginDialog.h"

CLoginDialog::CLoginDialog( char *lpszName )
   : CDialog( lpszName )
{
   m_szUserid[ 0 ] = m_szPassword[ 0 ] = '\0';
}

// clicked the "Log in" button
afx_msg void CLoginDialog::OnLogin() 
{
   CEdit *pUserid;  
   CEdit *pPassword;
   
   // get user ID value 
   pUserid = ( CEdit * ) GetDlgItem( IDC_USERID );
   pUserid->GetWindowText( m_szUserid, 16 );

   // get password value
   pPassword = ( CEdit * ) GetDlgItem( IDC_PASSWORD );
   pPassword->GetWindowText( m_szPassword, 12 );

   // validate password
   int j = strcmp( m_szPassword, "PassWord" );

   if ( *m_szUserid != '\0' && j == 0 ) {
      MessageBox( m_szUserid, "Access Granted", 
                  MB_ICONINFORMATION );
      EndDialog( IDOK );        // Report login success
   }
   else {
      MessageBox( "Invalid userid or password", 
                  "Login error", 
                  MB_ICONEXCLAMATION );

      pPassword->SetWindowText( "" );  // clear password
      pUserid->SetFocus();             // cursor in userid
   }
}

BEGIN_MESSAGE_MAP( CLoginDialog, CDialog )
   ON_COMMAND( IDC_LOGIN, OnLogin )    // Log in handler
END_MESSAGE_MAP()


// after validating user, main application continues
CMainWin::CMainWin()
{
   Create( NULL, "Application Window",
           WS_OVERLAPPEDWINDOW,
           rectDefault );
}

// launch login dialog
void CMainWin::login()
{
   CLoginDialog loginDialog( "Login" );

   if ( loginDialog.DoModal() != IDOK )
      SendMessage( WM_CLOSE );   // login failed
}


// application creates main window, requests login dialog
class CLoginApp : public CWinApp {
public:
   BOOL InitInstance()
   {
      CMainWin *pMainWnd = new CMainWin;  // create window
      m_pMainWnd = pMainWnd;              // set main window
      pMainWnd->ShowWindow( m_nCmdShow ); // make visible
      pMainWnd->UpdateWindow();           // force refresh

      pMainWnd->login();                  // login dialog
      return TRUE;                        // report success
   }

} loginApp;
