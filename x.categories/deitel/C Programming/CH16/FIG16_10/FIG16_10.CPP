// FIG5_10.CPP
// Demonstrating the Time class set and get functions
#include <iostream.h>
#include "time3.h"

main()
{
   Time t;
   void incrementMinutes(Time &, const int);

   t.setHour(17);
   t.setMinute(34);
   t.setSecond(25);

   cout << "Result of setting all valid values:\n  Hour: "
        << t.getHour()
        << "  Minute: " << t.getMinute()
        << "  Second: " << t.getSecond() << "\n\n";

   t.setHour(234);      // invalid hour set to 0
   t.setMinute(43);
   t.setSecond(6373);   // invalid second set to 0

   cout << "Result of attempting to set invalid hour and"
        << " second:\n  Hour: " << t.getHour()
        << "  Minute: " << t.getMinute()
        << "  Second: " << t.getSecond() << "\n\n";

   t.setTime(11, 58, 0);
   incrementMinutes(t, 3);

   return 0;
}

void incrementMinutes(Time &tt, const int count)
{
   cout << "Incrementing minute " << count
        << " times:\nStart time: ";
   tt.printStandard();

   for (int i = 1; i <= count; i++) {
      tt.setMinute((tt.getMinute() + 1) % 60);

      if (tt.getMinute() == 0)
	 tt.setHour((tt.getHour() + 1) % 24);

      cout << "\nminute + 1: ";
      tt.printStandard();
   }

   cout << endl;
}