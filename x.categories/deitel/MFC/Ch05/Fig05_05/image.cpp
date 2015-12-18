// Fig. 5.5: image.cpp
// display a bitmap image
#include <afxwin.h>
#include "CImageWin.h"

CImageWin::CImageWin()
{
   // create frame window
   Create( NULL, "Display an Image", WS_OVERLAPPEDWINDOW );

   // load bitmap image from resources by name
   m_bmpCool.LoadBitmap( "COOL_BMP" );

   // device context of client area of window
   CClientDC dc( this );

   // create memory device context to hold image
   m_memDC.CreateCompatibleDC( &dc );
   m_memDC.SelectObject( &m_bmpCool );
}

// refresh window when requested to by the system
afx_msg void CImageWin::OnPaint()
{
   CPaintDC dc( this );    // get paint device context

   // bit block transfer image from memory DC to paint DC
   dc.BitBlt( 0, 0, 300, 300, &m_memDC, 0, 0, SRCCOPY );
}

BEGIN_MESSAGE_MAP( CImageWin, CFrameWnd )
   ON_WM_PAINT()
END_MESSAGE_MAP()


class CImageApp : public CWinApp {
public:

   BOOL InitInstance()
   {
      m_pMainWnd = new CImageWin;            // create window
      m_pMainWnd->ShowWindow( m_nCmdShow );  // make visible
      m_pMainWnd->UpdateWindow();            // force refresh

      return TRUE;
   }
} imageApp;
