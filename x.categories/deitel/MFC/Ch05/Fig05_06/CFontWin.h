// Fig. 5.6: CFontWin.h
// manipulate fonts

class CFontWin : public CFrameWnd {
public:
   CFontWin();

   // refresh window when requested to by the system
   afx_msg void OnPaint();

private:
   CFont m_sysFont;        // system font
   CFont m_italicFont;     // italic font

   DECLARE_MESSAGE_MAP()
};
