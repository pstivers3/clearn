// Fig. 2.11: CMenusWin.h
// create menus with MFC
const int TEXT_SIZE = 16;

class CMenusWin : public CFrameWnd {
public:
   CMenusWin();
   void tally( int &nCount, double dAmount );
   afx_msg void OnExit(); 
   afx_msg void OnDoFood(UINT nFood); 
   afx_msg void OnShowTotal();
   afx_msg void OnClearTotal();

private:
   int m_nChicken, m_nFish;     // count items ordered
   int m_nGingerale, m_nRootbeer;
   double m_dTotal;             // tally cost of the order

   char m_szText[ TEXT_SIZE ];  // output string
   ostrstream m_str;            // output string stream

   DECLARE_MESSAGE_MAP()
};
