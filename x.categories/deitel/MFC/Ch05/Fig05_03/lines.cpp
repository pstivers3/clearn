// Fig 5.3: lines.cpp
// line drawing example

#include <afxwin.h>     // MFC application framework 
#include "lines.h"      // application class

CLinesWin::CLinesWin()  // main window
{
   Create( NULL, "Draw Lines" ); // Frame window with title

   // create a pen for solid, 2 pixel wide, red lines
   m_redPen.CreatePen( PS_SOLID, 2, RGB( 255, 0, 0 ) ); // red
   m_greenBrush.CreateSolidBrush( RGB( 0, 255, 0 ) ); // green
}  

// refresh window when requested to by the system
afx_msg void CLinesWin::OnPaint()
{
   CPaintDC dc( this );   // get device context for paint

   // get current window size
   CRect rect;
   GetClientRect( rect ); // get current client area size

   int x = rect.right  / 4; // quarter x
   int y = rect.bottom / 4; // quarter y

   // draw rectangle, a line at a time
   dc.MoveTo( x, y );         // set starting point
   dc.LineTo( 3 * x, y );     // draw top line
   dc.LineTo( 3 * x, 2 * y ); // draw right line
   dc.LineTo( x, 2 * y );     // draw bottom line
   dc.LineTo( x, y );         // draw left line

   x *= 2;      // point to the middle of the window
   y *= 2;

   // create a list of points for a shape

   CPoint alpPoints[] = {  // arrow shape
      CPoint( x + 00, y + 10 ),
      CPoint( x + 30, y + 50 ),
      CPoint( x + 10, y + 50 ),
      CPoint( x + 10, y + 70 ),
      CPoint( x - 10, y + 70 ),
      CPoint( x - 10, y + 50 ),
      CPoint( x - 30, y + 50 ),
      CPoint( x + 00, y + 10 )
   };
   const int POLY_POINTS         // array size
      = sizeof( alpPoints ) / sizeof( alpPoints[ 0 ] );

   // select solid green brush, saving default brush
   CBrush *pBrushSv = dc.SelectObject( &m_greenBrush );

   // select red pen, saving default pen
   CPen *pPenSv = dc.SelectObject( &m_redPen );

   // display a polygon from a list of points
   dc.Polygon( alpPoints, POLY_POINTS );

   // restore default pen and brush
   dc.SelectObject( pBrushSv );
   dc.SelectObject( pPenSv );
}

BEGIN_MESSAGE_MAP( CLinesWin, CFrameWnd )
   ON_WM_PAINT()     // OnPaint() when screen changes
END_MESSAGE_MAP()

class CDrawApp : public CWinApp {
public:

   BOOL InitInstance()
   {
      m_pMainWnd = new CLinesWin;            // create window
      m_pMainWnd->ShowWindow( m_nCmdShow );  // make visible
      m_pMainWnd->UpdateWindow();            // force refresh
      return TRUE;         // run until user closes program
   }

} linesApp;
