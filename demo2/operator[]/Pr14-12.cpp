// This program demonstrates an overloaded [] operator.
#include <iostream>
#include "IntArray.h"
using namespace std;

int main()
{
   const int SIZE = 10;  // Array size

   // Define an IntArray with 10 elements.
   IntArray table(SIZE);

   // Store values in the array.
   for (int x = 0; x < SIZE; x++)
      table[x] = (x * 2); //lvalue needs &operator[]

   // Display the values in the array.
   for (int x = 0; x < SIZE; x++)
      cout << table[x] << " ";
   cout << endl;

   // Use the standard + operator on array elements.
   for (int x = 0; x < SIZE; x++)
      table[x] = table[x] + 5; //lvalue needs &operator[]

   // Display the values in the array.
   for (int x = 0; x < SIZE; x++)
      cout << table[x] << " ";
   cout << endl;

   // Use the standard ++ operator on array elements.
   for (int x = 0; x < SIZE; x++)
      table[x]++; //lvalue needs &operator[]

   // Display the values in the array.
   for (int x = 0; x < SIZE; x++)
      cout << table[x] << " ";
   cout << endl;

   return 0;
}
