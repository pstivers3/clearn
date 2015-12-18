// Fig. 3.4: CKeyboardWin.h
// keyboard input example

const int LINES = 24;          // maximum number of lines
const int LINE_LENGTH = 64;    // maximum characters per line
const int LINE_HEIGHT = 16;    // pixels between lines

// application window
class CKeyboardWin : public CFrameWnd {
public:
   CKeyboardWin();

   // refresh window when requested to by the system
   afx_msg void OnPaint();

   // process each character typed on keyboard
   afx_msg void OnChar( UINT uChar, UINT uRepCnt, UINT uFlg );
private:
   char m_asText[ LINES ][ LINE_LENGTH ]; // text to paint
   int m_anLen[ LINES ];          // keep track of line lengths
   int m_nLine;                   // line receiving keystrokes
   DECLARE_MESSAGE_MAP()
};
