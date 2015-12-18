// Fig 5.4: colors.cpp
// Draw with many colors example
#include <afxwin.h>
#include "colors.h"

CColorsWin::CColorsWin()
{
   Create( NULL, "Draw with many colors" );

   m_lpszText = "DYNAMIC COLORS";
   m_nLength = strlen( m_lpszText );
   m_cRed = m_cGreen = m_cBlue = 0;

   // get physical screen limits
   int xMax = GetSystemMetrics( SM_CXSCREEN );
   int yMax = GetSystemMetrics( SM_CYSCREEN );

   CClientDC dc( this );   // get client area device context

   // create a memory device context and bitmap to save
   // the color square so it can be copied quickly 
   m_memDC.CreateCompatibleDC( &dc );
   m_bitmap.CreateCompatibleBitmap( &dc, xMax, yMax );
   m_memDC.SelectObject( &m_bitmap );
   colorSquare();    // compute once rather than on each tick
}  // end CColorsWin()

// draw a colorful square a pixel at a time
void CColorsWin::colorSquare()
{
   // step through red intensity values
   for ( int cRed = 0, x = 0;      // red increases with x
         cRed <= 255; 
         cRed++, x++ )
      // step through green intensity values
      for ( int cGreen = 0, y = 0; // green increases with y
            cGreen <= 255;
            cGreen++, y++ )
      {
         // make blue balance the average of red and green
         int cBlue = 255 - ( cRed + cGreen ) / 2;

         // set pixel (x,y) to RGB value
         m_memDC.SetPixel( x, y, RGB( cRed, cGreen, cBlue ) );
      }
}

// refresh window when requested to by the system
afx_msg void CColorsWin::OnPaint()
{
   CPaintDC dc( this );   // get device context for paint

   // get current window size
   CRect rect;
   GetClientRect( rect ); // get current client area size

   int x = rect.right  / 2; // middle x
   int y = rect.bottom / 4; // quarter y

   // display text with dynamically changing colors
   dc.SetTextColor( RGB( m_cRed, m_cGreen, m_cBlue ) );
   dc.SetBkColor( RGB( 255, 255, 255 ) );
   dc.TextOut( x - 60, y / 2, m_lpszText, m_nLength );

   x -= 128;    // center 256 pixel square in window
   y += 10;     // color square position

   // copy color square from memory bitmap to screen bitmap
   dc.BitBlt( x, y,            // destination
              256, 256,        // width, height
              &m_memDC, 0, 0,  // source, x, y
              SRCCOPY );       // straight copy

   // draw a shaded rectangle around the color square
   dc.Draw3dRect( x - 2, y - 2,            // left, top
                  260, 260,                // width, height
                  RGB( 150, 150, 150 ),    // gray left, top
                  RGB(  10,  10,  10 ) );  // dark gray shadow
}  // end OnPaint()

// cyclic timer tells when to update colors
afx_msg void CColorsWin::OnTimer()
{
   // cycle through colors in prime number steps
   m_cRed = ( m_cRed + 3 ) % 256;
   m_cGreen = ( m_cGreen + 7 ) % 256;
   m_cBlue = ( m_cBlue + 11 ) % 256;

   InvalidateRect( NULL, FALSE ); // redraw all, no erase
}

// release resources at end of program
afx_msg void CColorsWin::OnDestroy()
{
   KillTimer( 1 );    // release timer 1
}

BEGIN_MESSAGE_MAP( CColorsWin, CFrameWnd )
   ON_WM_TIMER()     // OnTimer() when timer ticks
   ON_WM_PAINT()     // OnPaint() when screen changes
   ON_WM_DESTROY()   // OnDestroy() when program ends
END_MESSAGE_MAP()


class CColorsApp : public CWinApp {
public:

   BOOL InitInstance()
   {
      m_pMainWnd = new CColorsWin;           // create window
      m_pMainWnd->ShowWindow( m_nCmdShow );  // make visible
      m_pMainWnd->UpdateWindow();            // force refresh

      // start timer id 1, 30 milliseconds, use WM_TIMER
      if ( !m_pMainWnd->SetTimer( 1, 30, NULL ) )
         return FALSE;     // quit on failure

      return TRUE;         // run until user closes program
   }

} colorsApp;

