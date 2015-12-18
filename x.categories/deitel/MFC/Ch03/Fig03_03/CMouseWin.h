// Fig 3.3: CMouseWin.h
// Mouse coordinates display

class CMouseWin : public CFrameWnd {
public:
   CMouseWin();

   // display mouse coordinates and mouse button status
   void showPoint( UINT uFlags, CPoint point );

   // mouse button handlers
   afx_msg void OnLButtonDown( UINT uFlags, CPoint point );
   afx_msg void OnRButtonDown( UINT uFlags, CPoint point );
private:
   DECLARE_MESSAGE_MAP()
};
