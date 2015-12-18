// Fig. 4.4: CListBoxDialog.h
// list box control example

class CListBoxDialog : public CDialog {
public:
   CListBoxDialog( char *lpszName ) : CDialog( lpszName ) {}

   BOOL OnInitDialog();

   afx_msg void OnAdd();
   afx_msg void OnClear();

private:
   static char *s_alpszChoices[];

   DECLARE_MESSAGE_MAP()
};
