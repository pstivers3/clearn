// Fig. 4.2: CCheckBoxDialog.h
// check box example

class CCheckBoxDialog : public CDialog {
public:
   CCheckBoxDialog( char *lpszName );

   afx_msg void OnOK();     // clicked the "OK" button

private:
   // helper function combines two MFC calls in one
   int GetButtonStatus( int nId );

   DECLARE_MESSAGE_MAP()
};
