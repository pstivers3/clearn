// CREATE.H
// Definition of class CreateAndDestroy.
// Member functions defined in CREATE.CPP.

#ifndef CREATE_H
#define CREATE_H

class CreateAndDestroy {
public:
   CreateAndDestroy(int);  // constructor
   ~CreateAndDestroy();    // destructor
private:
   int data;
};

#endif
