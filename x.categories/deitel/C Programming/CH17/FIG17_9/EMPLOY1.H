// EMPLOY1.H
// An employee class
#ifndef EMPLOY1_H
#define EMPLOY1_H

class Employee {
public:
   Employee(const char*, const char*);  // constructor
   ~Employee();            // destructor
   char *getFirstName() const;  // return first name
   char *getLastName() const;   // return last name

   // static member function
   static int getCount();  // return # objects instantiated
private:
   char *firstName;
   char *lastName;

   // static data member
   static int count;  // number of objects instantiated
};

#endif