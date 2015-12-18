// Fig. 2.12: addition.cpp
// Addition program with MFC dialog box
#include <afxwin.h>
#include "addition_ids.h"
#include "CAdditionDialog.h"

// clicked the "Add" button
afx_msg void CAdditionDialog::OnAdd()
{
   const TEXT_SIZE = 16;
   char szText[ TEXT_SIZE + 1 ]; // buffer for conversions

   // get addresses of Edit Box Controls 

   CEdit *pTotal = ( CEdit * ) ( GetDlgItem( IDC_TOTAL ) );
   CEdit *pNum   = ( CEdit * ) ( GetDlgItem( IDC_NUMBER ) );

   pNum->GetWindowText( szText, TEXT_SIZE ); // get Number
   m_nTotal += atoi( szText );      // add binary value
   
   itoa( m_nTotal, szText, 10 );    // convert total to text

   pTotal->SetWindowText( szText ); // display total
   pNum->SetWindowText( "" );       // clear input
   pNum->SetFocus();                // next input to Number
}

// clicked the "Clear" button
afx_msg void CAdditionDialog::OnClear()
{
   CEdit *pTotal = ( CEdit * ) ( GetDlgItem( IDC_TOTAL ) );
   CEdit *pNum   = ( CEdit * ) ( GetDlgItem( IDC_NUMBER ) );

   m_nTotal = 0;                // clear the total
   pTotal->SetWindowText( "" ); // clear the edit box
   pNum->SetFocus();            // next input to Number
}

BEGIN_MESSAGE_MAP( CAdditionDialog, CDialog )
   ON_COMMAND( IDC_ADD, OnAdd )
   ON_COMMAND( IDC_CLEAR, OnClear )
END_MESSAGE_MAP()

// dialog-based application 
class CAdditionApp : public CWinApp {
public:
   BOOL InitInstance()
   {
      CAdditionDialog additionDialog;
      additionDialog.DoModal();  // run dialog
      return FALSE;              // finished
   }

} addition;
