// Fig. 5.3: lines.h
// Draw lines

class CLinesWin : public CFrameWnd {
public:
   CLinesWin();      // window constructor

   // refresh window when requested to by the system
   afx_msg void OnPaint();

private:
   CBrush m_greenBrush;     // green brush
   CPen m_redPen;           // red pen

   DECLARE_MESSAGE_MAP()
};
