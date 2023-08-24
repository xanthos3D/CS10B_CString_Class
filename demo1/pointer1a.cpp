//pointer review#1
#include<iostream>
using namespace std;

int main()
{
  int x =25;
  cout << &x << " " << x << endl; //the address and value in x

  int *p;

  p = &x; //store the address of x in p
  cout << p << " " << *p << endl; //p has address of x and dereference shows value

  *p = 24; // changes the content at address pointed to

  //p has address of x and dereference shows current value and x has the new value too
  cout << p << " " << *p << " " << x <<endl;

  // &p, p, and *p all have different meaning

  return 0;
}
