// Fig. 2.8: welcome.cpp
// A First Program in C++ with MFC

// include application framework windows class definitions:
#include <afxwin.h>     // application frameworks header
#include "welcome.h"    // class definition for application

// constructor initializes the window
CWelcomeWindow::CWelcomeWindow()     
{
   // Create Window with Title Bar
   Create( NULL,                // default CFrameWnd class
           "Welcome",           // window title
           WS_OVERLAPPEDWINDOW, // full-featured window
           CRect( 100, 100, 300, 300 ) ); // screen coordinates

   m_pGreeting = new CStatic;   // create a static control

   m_pGreeting->Create(           // create Windows control
      "Welcome to Visual C++ with MFC!", // text
      WS_CHILD | WS_VISIBLE | WS_BORDER  // window styles
      | SS_CENTER,                // static object styles
      CRect( 40, 50, 160, 100 ),  // window coordinates
      this );                     // context that owns child window
}

CWelcomeWindow::~CWelcomeWindow()
{
   delete m_pGreeting;
}


// declare our application class based on CWinApp
class CWelcomeApp : public CWinApp {
public:
   BOOL InitInstance()   // override default function
   {
      m_pMainWnd = new CWelcomeWindow();    // create window
      m_pMainWnd->ShowWindow( m_nCmdShow ); // make visible
      m_pMainWnd->UpdateWindow();           // force refresh
      return TRUE;                          // report success
   }

} welcomeApp;     // instantiate application
