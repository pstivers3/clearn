// Fig. 3.5: text.cpp
// Text display in the client area of a window
#include <afxwin.h>
#include "CTextWin.h"

char *aszText[] = 
{ 
   "Welcome to C++ and MFC!",
   "This is text in the client area.",
   " ",
   "<---Neatly Centered--->",
   NULL
};

// Create window for displaying text
CTextWin::CTextWin()
{
   Create( NULL, "Text Example", WS_OVERLAPPEDWINDOW,
           CRect( 100, 100, 400, 300 ) );
}

// Refresh window when requested to by the system
afx_msg void CTextWin::OnPaint()
{
   CPaintDC dc( this );    // get paint display context 

   CRect rect;
   GetClientRect( &rect ); // get size of client area

   int nX = rect.right / 2;       // centered horizontally
   int nY = rect.bottom / 4;      // 1/4 for top margin 

   // display lines of text centered in region of screen
   for ( int nLine = 0; aszText[ nLine ] != NULL; nLine++ )
   {
      int nLength = strlen( aszText[ nLine ] );
      CSize nCSizeText = dc.GetTextExtent( aszText[ nLine ],
                                           nLength );

      dc.SetTextColor( RGB( 255, 0, 0 ) );  // red text
      dc.TextOut( nX - nCSizeText.cx / 2,   // center text
                  nY,                // vertical offset
                  aszText[ nLine ],  // text to display
                  nLength );         // char count

      nY += nCSizeText.cy;  // advance to next line
   }
}

BEGIN_MESSAGE_MAP( CTextWin, CFrameWnd )
   ON_WM_PAINT()     // OnPaint handles WM_PAINT message
END_MESSAGE_MAP()


// application creates main window
class CTextApp : public CWinApp {
public:
   BOOL InitInstance()
   {
      m_pMainWnd = new CTextWin;            // create window
      m_pMainWnd->ShowWindow( m_nCmdShow ); // make it visible
      m_pMainWnd->UpdateWindow();           // force refresh
      return TRUE;                          // report success
   }

} textApp;
