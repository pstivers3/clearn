// Fig. 4.5: combobox.cpp   
// combo box control example
#include <afxwin.h>
#include "combobox_ids.h"
#include "CComboBoxDialog.h"

BOOL CComboBoxDialog::OnInitDialog()
{
   CDialog::OnInitDialog();
   CComboBox *pChoices; 
   pChoices = ( CComboBox * ) GetDlgItem( IDC_CHOICES );

   // add strings to combo box
   for ( int i = 0; s_alpszChoices[ i ] != NULL; i++ )
      pChoices->AddString( s_alpszChoices[ i ] );

   return TRUE;
}

// clicked the "Add" button
afx_msg void CComboBoxDialog::OnAdd()
{
   CComboBox *pChoices; 
   pChoices = ( CComboBox * ) GetDlgItem( IDC_CHOICES );

   int iCurSel = pChoices->GetCurSel();

   if ( iCurSel == CB_ERR ) {
      MessageBox( "Select an item.", "Choices", 
                  MB_ICONWARNING );
      return;
   }

   char lpszText[ 32 ];
   pChoices->GetLBText( iCurSel, lpszText );

   CListBox *pSelected = 
             ( CListBox * ) GetDlgItem( IDC_SELECTED );
   pSelected->AddString( lpszText );
}


afx_msg void CComboBoxDialog::OnClear()
{
   CListBox *pSelected = 
             ( CListBox * ) GetDlgItem( IDC_SELECTED );
   pSelected->ResetContent();     // clear list box                   
}

char *CComboBoxDialog::s_alpszChoices[] 
   = { "Chicken", "Fish", "Salad", NULL };

BEGIN_MESSAGE_MAP( CComboBoxDialog, CDialog )
   ON_COMMAND( IDC_ADD,   OnAdd )
   ON_COMMAND( IDC_CLEAR, OnClear )
END_MESSAGE_MAP()


class CComboBoxApp : public CWinApp {
public:
   BOOL InitInstance()
   {
      CComboBoxDialog comboBoxDialog( "ComboBoxDialog" );
      comboBoxDialog.DoModal();     // returns IDOK or IDCANCEL
      return FALSE;                 // exit
   }

} comboBoxApp;
