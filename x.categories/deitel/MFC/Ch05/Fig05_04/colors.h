// Fig. 5.4: colors.h
// Draw with many colors

class CColorsWin : public CFrameWnd {
public:
   CColorsWin();

   // refresh window when requested to by the system
   afx_msg void OnPaint();

   // cyclic timer tells when to update colors
   afx_msg void OnTimer();

   // release resources at end of program
   afx_msg void OnDestroy();

private:
   // draw a colorful square a pixel at a time
   void colorSquare();

   char *m_lpszText;     // text to draw
   int m_nLength;        // text length

   int m_cRed;           // red component of a color
   int m_cGreen;         // green component of a color
   int m_cBlue;          // blue component of a color

   CDC m_memDC;          // memory device context
   CBitmap m_bitmap;     // memory bitmap

   DECLARE_MESSAGE_MAP()
};
