// Fig. 3.4: keyboard.cpp
// keyboard input example
#include <afxwin.h>
#include "CKeyboardWin.h"

// initialize main window
CKeyboardWin::CKeyboardWin()
{
   m_nLine = 0;             // empty text array
   m_anLen[ m_nLine ] = 0;  // empty line of text

   Create( NULL, "Keyboard Example", WS_OVERLAPPEDWINDOW,
           CRect( 0, 0, 200, 200 ) );
}

// refresh window when requested to by the system
afx_msg void CKeyboardWin::OnPaint()
{
   CPaintDC dc( this );    // get device context

   int nPosition = m_anLen[ m_nLine ]++;

   m_asText[ m_nLine ][ nPosition ] = '_';  // make a cursor

   for ( int ln = 0; ln <= m_nLine; ln++ ) // paint lines
      dc.TextOut( 1, LINE_HEIGHT * ln, 
                  m_asText[ ln ], m_anLen[ ln ] );

   m_anLen[ m_nLine ]--;                   // remove cursor
}

// process each character typed on keyboard
afx_msg void CKeyboardWin::OnChar( UINT uChar, UINT uRepCnt, 
                                   UINT uFlg )
{
   switch ( uChar ) {
      case '\r':                         // start new line
         m_nLine++;

         if ( m_nLine >= LINES ) 
            m_nLine = 0;                 // wrap around

         m_anLen[ m_nLine ] = 0;
         break;
      case '\b':        // backspace erases previous char
         if ( m_anLen[ m_nLine ] > 0 ) 
            m_anLen[ m_nLine ]--;

         break;
      default:
         int nPosition = m_anLen[ m_nLine ]++;

         m_asText[ m_nLine ][ nPosition ] = uChar;

         if ( m_anLen[ m_nLine ] >= LINE_LENGTH ) {

            if ( ++m_nLine >= LINES ) 
               m_nLine = 0;                // wrap around

            m_anLen[ m_nLine ] = 0;
         }
   }

   InvalidateRect( NULL );      // send WM_PAINT message
}

BEGIN_MESSAGE_MAP( CKeyboardWin, CFrameWnd )
   ON_WM_CHAR()      // listen for any key press message
   ON_WM_PAINT()     // listen for paint message
END_MESSAGE_MAP()

// application class creates window
class CKeyboardApp : public CWinApp {
public:
   BOOL InitInstance()
   {
      m_pMainWnd = new CKeyboardWin;        // create window
      m_pMainWnd->ShowWindow( m_nCmdShow ); // make it visible
      m_pMainWnd->UpdateWindow();           // force refresh
      return TRUE;                          // report success
   }

} keyboardApp;
