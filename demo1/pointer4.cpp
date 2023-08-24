//pointer review#5 - shallow verses deep copy pointers
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int main()
{
  int *first;           //first is a pointer of type int
  int *second;          //second is a pointer of type int
  const int SIZE = 10;

  //allocates new memory on the heap for a 3-element int array
  //and stores the address of the allocated memory in first
  first = new int[SIZE];
  for(int index = 0; index < SIZE; index++)
    first[index]= rand()%10;


//first has address of a dynamic memory area,*first++ dereferenced shows current values
//stored dynamically in the first array
  cout << "\nAddress of first dynamic array pointer = " << (int*)&first[0]  << "\nListing of elements: ";
  for(int index = 0; index < SIZE; index++)
    cout << first[index] << " ";
  cout <<endl;

  second = first; // a shallow copy

  cout <<"\nsecond = first; //a shallow copy assignment is made\n";

  cout << "\nAddress of second dynamic array pointer = " << (int*)&second[0] << "\nListing of elements: ";
  for(int index = 0; index < SIZE; index++)
    cout << second[index] << " ";
  cout <<endl;

  delete []second;  //to be commented out later
  second = nullptr; //to be commented out later

  cout << "\ndelete [] second; //with this next statement...\n\n";

  cout << "\nAddress of first dynamic array pointer = " << (int*)&first[0]  << "\nListing of elements: ";
  for(int index = 0; index < SIZE; index++)
    cout << first[index] << " ";
  cout <<endl;

  cout << "\nNotice the error in attempting to read array data with the first pointer...\n\n"
       << "Because first and second pointed to the same array\n"
       << "first becomes invalid, that is, first (as well as second) are \n"
       << "now dangling pointers. Therefore, if the program will access the \n"
       << "wrong memory or it will terminate in an error.\n"
       << "This case is known as a shallow copy, ie., two or more pointers \n"
       << "of the same type point to the same memory or same data." <<endl;

 cout  << "\nHow to prevent this is instead of the earlier statement, second = first;\n"
       << "setup a new dynamic array for second and then do a component by component\n"
       << "assignment starting with the base addresses of each array.\n\n"
       << "second = new int[10]; \n\n"
       << " for(int index = 0; index < SIZE; index++)\n"
       << "    second[index]= first[index];\n\n"
       << "This is known as deep copy, ie., two or more pointers have their data\n"
       << "If either pointer is deleted in memory there is no effect on the other\n";


 second = new int[10];

 for(int index = 0; index < SIZE; index++)
    second[index]= first[index];


cout << "\nAddress of second dynamic array pointer = " << (int*)&second[0] << "\nListing of elements: ";
  for(int index = 0; index < SIZE; index++)
    cout << second[index] << " ";
  cout <<endl;



  return 0;
}
