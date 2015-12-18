// Fig. 4.3: radiobutton.cpp
// radio button example
#include <afxwin.h>
#include "radiobutton_ids.h"
#include "CRadioButtonDialog.h"

// clicked the "OK" button
afx_msg void CRadioButtonDialog::OnOK()
{
   // get flavor ID of selected radiobutton from group
   int nFlavor = GetCheckedRadioButton( IDC_CHOCOLATE,
                                        IDC_STRAWBERRY );
   switch ( nFlavor ) {
      case IDC_CHOCOLATE:
         m_lpszFlavor = "Chocolate";
         break;
      case IDC_STRAWBERRY:
         m_lpszFlavor = "Strawberry";
         break;
      default:
         m_lpszFlavor = "Vanilla";
   }

   // get container ID of selected radiobutton from group
   int nContainer = GetCheckedRadioButton( IDC_CONE,
                                           IDC_CUP );
   switch ( nContainer ) {
      case IDC_CONE:
         m_lpszContainer = "Cone";
         break;
      default:
         m_lpszContainer = "Cup";
   }

   // concatenate the flavor and container in a string
   strcpy( m_szOrder, m_lpszFlavor );
   strcat( m_szOrder, " " );
   strcat( m_szOrder, m_lpszContainer );

   MessageBox( m_szOrder, "Ice Cream Order:" );
}

BEGIN_MESSAGE_MAP( CRadioButtonDialog, CDialog )
   ON_COMMAND( IDOK, OnOK )
END_MESSAGE_MAP()

// start application, create dialog window
class CRadioButtonApp : public CWinApp 
{
public:
   BOOL InitInstance()
   {
      CRadioButtonDialog radioButtonDialog( "CRadioButton" );
      radioButtonDialog.DoModal();  // run dialog window
      return FALSE;                 // exit
   }

} radioButtonApp;
