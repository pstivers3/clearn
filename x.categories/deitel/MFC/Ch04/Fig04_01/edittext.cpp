// Fig. 4.1: edittext.cpp
// multiline edit text example
#include <afxwin.h>
#include <strstrea.h>
#include "edittext_ids.h"
#include "CEditTextDialog.h"

// Dialog constructor
CEditTextDialog::CEditTextDialog( char *lpszName )       
   : CDialog( lpszName )   // base class constructor
{
   m_szText[ 0 ] = '\0';
}

// count the characters in the edit text control
afx_msg void CEditTextDialog::OnCount()
{
   // get address of edit control 
   CEdit *pText = ( CEdit * ) GetDlgItem( IDC_TEXT );
   pText->GetWindowText( m_szText, MAX_TEXT );

   // display length of text read from edit text control
   static char szBuf[ 20 ];
   static ostrstream str( szBuf, 20);

   str.seekp( 0 );
   str << "Text length = " << strlen( m_szText ) << ends;
   pText->SetWindowText( szBuf );
}

BEGIN_MESSAGE_MAP( CEditTextDialog, CDialog )
   ON_COMMAND( IDC_COUNT, OnCount )
END_MESSAGE_MAP()

// start dialog-based application 
class CEditApp : public CWinApp {
public:
   BOOL InitInstance()
   {
      CEditTextDialog editTextDialog( "EditText" );
      editTextDialog.DoModal();     // run dialog
      return FALSE;                 // finished
   }

} editApp;
