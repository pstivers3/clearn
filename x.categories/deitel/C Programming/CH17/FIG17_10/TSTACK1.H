// TSTACK1.H
// Simple template class Stack
#ifndef TSTACK1_H
#define TSTACK1_H

#include <iostream.h>

template <class T>
class Stack {
public:
   Stack(int = 10);      // Constructor with default size 10
   ~Stack() { delete [] stackPtr; } // Destructor
   int push(const T&);   // Push an element onto the stack
   int pop(T&);          // Pop an element off the stack
   int isEmpty() const { return top == -1; } // return 1 if empty
   int isFull() const { return top == size - 1; } // return 1 if full
private:
   int size;             // # of elements in the stack
   int top;              // location of the top element
   T *stackPtr;          // pointer to the stack
};

// Constructor with default size 10
template <class T>
Stack<T>::Stack(int s)
{
   size = s;
   top = -1;  // Empty stack
   stackPtr = new T[size];
}

// Push an element onto the stack
// return 1 if successful, 0 otherwise
template <class T>
int Stack<T>::push(const T &item)
{
   if (!isFull()) {
      stackPtr[++top] = item;
      return 1;  // push successful
   }
   return 0;     // push unsuccessful
}

// Pop an element off the stack
template <class T>
int Stack<T>::pop(T &popValue)
{
   if (!isEmpty()) {
      popValue = stackPtr[top--];
      return 1;  // pop successful
   }
   return 0;     // pop unsuccessful
}

#endif