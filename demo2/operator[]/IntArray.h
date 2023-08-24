// Specification file for the IntArray class
#ifndef INTARRAY_H
#define INTARRAY_H

class IntArray
{
private:
   int *aptr;                         // Pointer to the array
   int arraySize;                     // Holds the array size
   void subscriptError();             // Handles invalid subscripts
public:
   IntArray(int);                     // Constructor
   IntArray(const IntArray &);        // Copy constructor
   ~IntArray();                       // Destructor

   int size() const                   // Returns the array size
      { return arraySize; }

   const IntArray operator=(const IntArray &);  // Overloaded = operator

// &int operator[](const int &); //syntax error can only have const or static to left of int
// int operator[](const int &);  //pass by value will work for right value but not if there is an lvalue where [] is used
   int &operator[](const int &);   // Overloaded [] operator needed for lvalue assignment in client code
};
#endif
