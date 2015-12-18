// Fig. 2.11: menus.cpp
// create menus with MFC
#include <afxwin.h>        // MFC application framework
#include <strstrea.h>      // string stream
#include <iomanip.h>       // I/O manipulators
#include "menus_ids.h"     // application message ID symbols
#include "CMenusWin.h"

CMenusWin::CMenusWin()               // construct window
   : m_str( m_szText, TEXT_SIZE )    // initialize ostrstream
{
   Create( NULL, "Menus Example", WS_OVERLAPPEDWINDOW,
      CRect( 0, 0, 200, 200 ), NULL, "Food" );

   m_nChicken = m_nFish = 0;
   m_nGingerale = m_nRootbeer = 0;
   m_dTotal = 0.0;
}

// count each type of item ordered, compute total bill
void CMenusWin::tally( int &nCount, double dAmount )
{
   nCount++;
   m_dTotal += dAmount;
}

// afx_msg precedes each message handler function
afx_msg void CMenusWin::OnExit() 
{
   SendMessage( WM_CLOSE ); 
}

afx_msg void CMenusWin::OnDoFood(UINT nFood) 
{
   switch (nFood)
   {
   case IDM_CHICKEN:
      tally( m_nChicken, 2.25 );
      break;
   case IDM_FISH:     
      tally( m_nFish, 1.80 );
      break;
   case IDM_GINGERALE:
      tally( m_nGingerale, .80 );
      break;
   case IDM_ROOTBEER:
      tally( m_nRootbeer, .80 );
      break;
   }
}

afx_msg void CMenusWin::OnShowTotal()
{
   m_str.seekp( 0 );              // reset output string
   m_str << setprecision( 2 ) 
       << setiosflags( ios::fixed | ios::showpoint )
       << "        $" << m_dTotal << ends;  // stopper

   // display new dialog box with output string
   MessageBox( m_szText, "Your total is:" );
   m_dTotal = 0.0;
}

afx_msg void CMenusWin::OnClearTotal()
{
   m_dTotal = 0.0;
   MessageBox( "          $0.00", "Cleared Order" );
}

BEGIN_MESSAGE_MAP( CMenusWin, CFrameWnd )
   
   ON_COMMAND( IDM_EXIT, OnExit )

   ON_COMMAND_RANGE(IDM_CHICKEN, IDM_ROOTBEER, OnDoFood)

   ON_COMMAND( IDM_SHOW_TOTAL, OnShowTotal )
   ON_COMMAND( IDM_CLEAR_TOTAL, OnClearTotal )

END_MESSAGE_MAP()


class CMenusApp : public CWinApp {
public:
   BOOL InitInstance()        // called by CWinApp::CWinApp
   {
      m_pMainWnd = new CMenusWin;           // create window
      m_pMainWnd->ShowWindow( m_nCmdShow ); // make it visible
      m_pMainWnd->UpdateWindow();           // force refresh
      return TRUE;                          // report success
   }

} menusApp;                   // calls CWinApp::CWinApp
