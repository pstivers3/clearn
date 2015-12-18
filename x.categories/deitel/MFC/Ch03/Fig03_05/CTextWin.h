// Fig. 3.5: CTextWin.h
// Text display in the client area of a window

class CTextWin : public CFrameWnd {
public:
   CTextWin();

   // Refresh window when requested to by the system
   afx_msg void OnPaint();
private:
   DECLARE_MESSAGE_MAP()
};
