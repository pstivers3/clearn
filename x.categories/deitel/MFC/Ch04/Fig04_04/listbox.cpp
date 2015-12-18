// Fig. 4.4: listbox.cpp
// list box control example
#include <afxwin.h>
#include "listbox_ids.h"
#include "CListBoxDialog.h"

BOOL CListBoxDialog::OnInitDialog()
{
   // call base class initialization first
   CDialog::OnInitDialog();

   // Get address of List Box
   CListBox *pChoices; 
   pChoices = ( CListBox * ) GetDlgItem( IDC_CHOICES );

   // add items to list box
   for ( int i = 0; s_alpszChoices[ i ] != NULL; i++ )
      pChoices->AddString( s_alpszChoices[ i ] );

   return TRUE;
}

// clicked the "Add" button
afx_msg void CListBoxDialog::OnAdd()
{
   CListBox *pChoices;
   pChoices = ( CListBox *) GetDlgItem( IDC_CHOICES );

   int iCurSel = pChoices->GetCurSel();

   if ( iCurSel == LB_ERR ) {
      MessageBox( "Select an item.", "Choices", 
                  MB_ICONWARNING );
      return;
   }

   CListBox *pSelected;
   pSelected = ( CListBox * ) GetDlgItem( IDC_SELECTED );
   char szText[ 32 ];
   pChoices->GetText( iCurSel, szText );
   pSelected->AddString( szText );
}

afx_msg void CListBoxDialog::OnClear()
{
   CListBox *pSelected;
   pSelected = ( CListBox * ) GetDlgItem( IDC_SELECTED );
   pSelected->ResetContent();     // clear list box
}

char *CListBoxDialog::s_alpszChoices[] 
      = { "Chicken", "Fish", "Salad", NULL };

BEGIN_MESSAGE_MAP( CListBoxDialog, CDialog )
   ON_COMMAND( IDC_ADD,   OnAdd )
   ON_COMMAND( IDC_CLEAR, OnClear )
END_MESSAGE_MAP()


class CListBoxApp : public CWinApp {
public:
   BOOL InitInstance()
   {
      CListBoxDialog listBoxDialog( "ListBoxDialog" );
      listBoxDialog.DoModal();   // returns IDOK or IDCANCEL
      return FALSE;
   }

} listBoxApp;
