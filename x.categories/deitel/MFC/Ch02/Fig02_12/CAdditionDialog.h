// Fig. 2.12: CAdditionDialog.h
// Addition program with MFC dialog box

class CAdditionDialog : public CDialog {
public:
   CAdditionDialog()
      : CDialog( "Addition" ), m_nTotal( 0 ) {}

   afx_msg void OnAdd();         // clicked the "Add" button
   afx_msg void OnClear();       // clicked the "Clear" button

private:
   int m_nTotal;                 // sum of numbers

   DECLARE_MESSAGE_MAP()
};
