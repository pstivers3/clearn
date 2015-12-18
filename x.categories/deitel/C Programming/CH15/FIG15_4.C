// Examples of valid macros, invalid macros
// and inline functions
#include <iostream.h>

#define VALIDSQUARE(x)    (x) * (x)
#define INVALIDSQUARE(x)  x * x

inline int square(int x) { return x * x; }

main()
{
   cout << "  VALIDSQUARE(2 + 3) = "
        << VALIDSQUARE(2 + 3)
        << "\nINVALIDSQUARE(2 + 3) = "
        << INVALIDSQUARE(2 + 3)
        << "\n       square(2 + 3) = "
        << square(2 + 3) << '\n';

   return 0;
}

