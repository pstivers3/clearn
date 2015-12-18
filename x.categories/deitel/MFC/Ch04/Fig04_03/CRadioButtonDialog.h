// Fig. 4.3: CRadioButtonDialog.h
// radio button example

class CRadioButtonDialog : public CDialog
{
public:
   CRadioButtonDialog( char *lpszName )
      : CDialog( lpszName ), m_lpszFlavor( "" ),
        m_lpszContainer( "" ) {}

   afx_msg void OnOK();     // clicked the "OK" button

private:
   char *m_lpszFlavor;
   char *m_lpszContainer;
   char m_szOrder[ 64 ];

   DECLARE_MESSAGE_MAP()
};
