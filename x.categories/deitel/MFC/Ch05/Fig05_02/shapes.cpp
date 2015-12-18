// Fig. 5.2: shapes.cpp
// Draw shapes and colors example
#include <afxwin.h>
#include "shapes.h"

CShapesWin::CShapesWin()
{
   Create( NULL, "Draw Shapes" );

}  // end CShapesWin()

// refresh window when requested to by the system
afx_msg void CShapesWin::OnPaint()
{
   CPaintDC dc( this );   // get device context for paint

   // get current window size
   CRect rect;
   GetClientRect( &rect ); // get current client area size

   int x = rect.right  / 4; // quarter x
   int y = rect.bottom / 4; // quarter y

   // draw a rectangle giving left, top, right, bottom edges
   dc.Rectangle( x, y, 2 * x, 2 * y );

   // create solid red brush and make it the current brush
   CBrush redBrush;
   redBrush.CreateSolidBrush( RGB( 255, 0, 0 ) );
   CBrush *pBrushSv = dc.SelectObject( &redBrush );

   // draw an ellipse, giving bounding rectangle
   dc.Ellipse( 2 * x, 2 * y,   // left, top coord
               3 * x, 3 * y ); // right, bottom

   dc.SelectObject( pBrushSv );  // revert to original brush
}  // end OnPaint()

BEGIN_MESSAGE_MAP( CShapesWin, CFrameWnd )
   ON_WM_PAINT()     // OnPaint() when screen changes
END_MESSAGE_MAP()

class CShapesApp : public CWinApp {
public:

   BOOL InitInstance()
   {
      m_pMainWnd = new CShapesWin;           // create window
      m_pMainWnd->ShowWindow( m_nCmdShow );  // make visible
      m_pMainWnd->UpdateWindow();            // force refresh

      return TRUE;         // run until user closes program
   }

} shapesApp;
