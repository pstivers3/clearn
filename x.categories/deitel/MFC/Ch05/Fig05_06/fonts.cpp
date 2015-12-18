// Fig. 5.6: fonts.cpp
// manipulate fonts
#include <afxwin.h>
#include "CFontWin.h"

CFontWin::CFontWin()
{
   // finish Windows frame in MFC CFrameWnd
   Create( NULL, "Font Example" );

   // create client area device context for this window
   CClientDC dc( this );

   // make default font
   m_sysFont.CreateStockObject( SYSTEM_FONT );

   // make 32 bit high bold italic font
   m_italicFont.CreateFont( 32, 0, 0, 0, FW_BOLD, 1, 0, 0, 0,
                             0, 0, 0, 0, "Times New Roman" );
}

// refresh window when requested to by the system
afx_msg void CFontWin::OnPaint()
{
   static char *aText[] =     // sample text to display
   { 
      "Welcome to C++ and MFC!", 
      " ",
      "Height is 32 pixels.",
      "Font weight is Bold.",
      "Italic is set.",
      "Face name is Times New Roman.",
      NULL 
   };

   CPaintDC dc( this );    // get paint device context 

   // select italic font for text display
   CFont *pFontSv = dc.SelectObject( &m_italicFont );

   int x = 10;   // top margin
   int y = 10;   // left margin

   // display lines of text centered in region of screen
   for ( int nLine = 0; aText[ nLine ] != 0; nLine++ )
   {
      int nLength = strlen( aText[ nLine ] );

      // get size of text in current font
      CSize nCSizeText 
         = dc.GetTextExtent( aText[ nLine ], nLength );

      // set text color, display text at computed position
      dc.SetTextColor( RGB( 255, 64, 64 ) ); // light red text
      dc.TextOut( x, y, aText[ nLine ], nLength );

      y += nCSizeText.cy;  // advance to next line
   }

   char *lpszText = "This line uses SYSTEM_FONT.";

   // select system font for text display
   dc.SelectObject( &m_sysFont );
   dc.SetTextColor( RGB( 0, 0, 0 ) );  // black text
   y += 20;      // space down the screen
   dc.TextOut( 10, y, lpszText, strlen( lpszText ) );
   dc.SelectObject( pFontSv );    // original font
}

BEGIN_MESSAGE_MAP( CFontWin, CFrameWnd )
   ON_WM_PAINT()
END_MESSAGE_MAP()


class CFontApp : public CWinApp {
public:

   BOOL InitInstance()
   {
      m_pMainWnd = new CFontWin;             // create window
      m_pMainWnd->ShowWindow( m_nCmdShow );  // make visible
      m_pMainWnd->UpdateWindow();            // force refresh
      return TRUE;
   }

} fontApp;
