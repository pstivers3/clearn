// Fig. 5.2: shapes.h
// Draw shapes

class CShapesWin : public CFrameWnd {
public:
   CShapesWin();

   // refresh window when requested to by the system
   afx_msg void OnPaint();

private:
   DECLARE_MESSAGE_MAP()
};
