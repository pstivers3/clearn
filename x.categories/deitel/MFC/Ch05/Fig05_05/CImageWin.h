// Fig. 5.5: CImageWin.h
// display a bitmap image

class CImageWin : public CFrameWnd {
public:
   CImageWin();

   // refresh window when requested to by the system
   afx_msg void OnPaint();
private:
   CBitmap m_bmpCool;  // bitmap stores image
   CDC m_memDC;        // memory device context

   DECLARE_MESSAGE_MAP()
};
