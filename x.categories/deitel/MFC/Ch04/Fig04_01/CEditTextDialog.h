// Fig. 4.1: CEditTextDialog.h
// multiline edit text example

const int MAX_TEXT = 128;

class CEditTextDialog : public CDialog {
public:
   CEditTextDialog( char *lpszName );
   afx_msg void OnCount();     // clicked the "Count" button

private:
   char m_szText[ MAX_TEXT + 1 ];

   DECLARE_MESSAGE_MAP()
};
