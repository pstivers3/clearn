// Fig. 4.2: checkbox.cpp
// check box example
#include <afxwin.h>
#include <strstrea.h>
#include "checkbox_ids.h"
#include "CCheckBoxDialog.h"

CCheckBoxDialog::CCheckBoxDialog( char *lpszName )
     : CDialog( lpszName ) {}

// helper function combines two MFC calls in one
int CCheckBoxDialog::GetButtonStatus( int nId )
{
   CButton *pCButton = ( CButton * ) GetDlgItem( nId );
   return pCButton->GetCheck();
}

// overriding OnOK function
afx_msg void CCheckBoxDialog::OnOK() // clicked "OK" button
{
   static char sMessage[ 64 ];
   static ostrstream str( sMessage, 64 );
   str.seekp( 0 );

   int nChocolate  = GetButtonStatus( IDC_CHOCOLATE );
   int nVanilla    = GetButtonStatus( IDC_VANILLA );
   int nStrawberry = GetButtonStatus( IDC_STRAWBERRY );

   str << "Flavor(s) Selected:\n\n";

   if ( nChocolate ) 
      str << "   Chocolate\n";

   if ( nVanilla )   
      str << "   Vanilla\n";

   if ( nStrawberry ) 
      str << "   Strawberry\n";

   if ( nChocolate + nVanilla + nStrawberry == 0 )
      str << "   None\n";

   str << ends;

   MessageBox( sMessage, "Ice Cream" );
}

BEGIN_MESSAGE_MAP( CCheckBoxDialog, CDialog )
   ON_COMMAND( IDOK, OnOK )
END_MESSAGE_MAP()


// start application, create dialog window
class CCheckBoxApp : public CWinApp {
public:
   BOOL InitInstance()
   {
      CCheckBoxDialog checkBoxDialog( "CCheckBox" );
      checkBoxDialog.DoModal();        // run dialog window
      return FALSE;                    // exit
   }

} checkBoxApp;
