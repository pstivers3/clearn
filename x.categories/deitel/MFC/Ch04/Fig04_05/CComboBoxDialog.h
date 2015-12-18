// Fig. 4.5: CComboBoxDialog.h   
// combo box control example

class CComboBoxDialog : public CDialog {
public:
   CComboBoxDialog( char *lpszName ) : CDialog( lpszName ) {}

   BOOL OnInitDialog();
   afx_msg void OnAdd();     // clicked the "Add" button
   afx_msg void OnClear();   // clicked the "Clear" button

private:   
   static char *s_alpszChoices[];

   DECLARE_MESSAGE_MAP()
};
