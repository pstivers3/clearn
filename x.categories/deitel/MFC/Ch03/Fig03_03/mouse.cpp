// Fig 3.3: mouse.cpp
// Mouse coordinates display
#include <afxwin.h>
#include <strstrea.h>
#include "CMouseWin.h"

CMouseWin::CMouseWin()
{
   Create( NULL, "Mouse Example", WS_OVERLAPPEDWINDOW );
}

// display mouse coordinates and mouse button status
void CMouseWin::showPoint( UINT uFlags, CPoint point )
{
   CClientDC dc( this );      // get display context
   
   static char sText[ 64 ];
   static ostrstream s( sText, sizeof( sText ) );

   s.seekp( 0 );    // reset to start of output string

   // format data to display in sText buffer
   s << "(" << point.x << ", " << point.y << ")";

   // at point (x, y) on screen, display (x, y) value
   dc.TextOut( point.x, point.y, sText, s.pcount() );

   s.seekp( 0 );    // reset to start of output string
   s << ( uFlags & MK_LBUTTON ? '*' : ' ' ) << " Left  "
     << ( uFlags & MK_RBUTTON ? '*' : ' ' ) << " Right ";

   // at 1,1 on screen, display mouse buttons' states
   dc.TextOut( 1, 1, sText, s.pcount() );
}

// left mouse button handler
afx_msg void CMouseWin::OnLButtonDown( UINT uFlags, 
                                       CPoint point )
{
   showPoint( uFlags, point );
}

// right mouse button handler
afx_msg void CMouseWin::OnRButtonDown( UINT uFlags, 
                                       CPoint point )
{
   showPoint( uFlags, point );
}

BEGIN_MESSAGE_MAP( CMouseWin, CFrameWnd )
   ON_WM_LBUTTONDOWN()   // left mouse button message handler
   ON_WM_RBUTTONDOWN()   // right mouse button message handler
END_MESSAGE_MAP()


// load main application window
class CMouseApp : public CWinApp {
public:
   BOOL InitInstance()
   {
      m_pMainWnd = new CMouseWin;      // create window
      m_pMainWnd->ShowWindow( m_nCmdShow );
      m_pMainWnd->UpdateWindow();      // force refresh
      return TRUE;                     // report success
   }

} mouseApp;
