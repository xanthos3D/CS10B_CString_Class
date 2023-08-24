//pointer review#1 - basic pointer to variable review
#include<iostream>
using namespace std;

int main()
{
  int *p;
  int x =37;

  cout<< "x = " << x << endl;

  p = &x; //store the address of x in p ..no new memory is allocated

  //p has address of x and p dereferenced shows current value and x has this value
  cout << "*p = " << *p << ", x = " << x << endl;

  *p = 58; // changes the content at address pointed to

  //p has address of x and p dereferenced shows current value and x has the new value too
  cout << "*p = " << *p << ", x = " << x << endl;

  cout << "Address of &p = " << &p <<endl;
  cout << "Value of p = " << p <<endl;
  cout << "Value at the memory location pointed to by *p = " << *p <<endl;

  cout << "Address of &x = " << &x <<endl;
  cout << "Value of x = " << x <<endl;

  return 0;
}
