// Fig. 2.8: welcome.h
// A First Program in C++ with MFC

class CWelcomeWindow : public CFrameWnd {
public:
   CWelcomeWindow();    // constructor initializes window
   ~CWelcomeWindow();   // destructor releases resources

private:
   CStatic *m_pGreeting;   // contains welcome message
};
