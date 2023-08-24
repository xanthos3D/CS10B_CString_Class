//pointer review#3 - basic pointers and allocate and deallocate dynamic memory on the heap
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
  int *p;       //p is a pointer of type int
  char *name;   //name is pointer of type char
  string *str;  //str is a pointer of type string

  p = new int;      //allocates memory on the heap of type int
                    //and stores the address of the allocated memory in p
  *p = 28;          //stores a value of type int in dynamic memory space

  //p has address of a dynamic memory area,*p dereferenced shows current value stored dynamically
  cout << "\nAddress of &p = " << &p <<" Dereferenced  *p = " << *p << endl;

  name = new char[7];  //allocates memory on the heap for an array of 7
                    //components of type char and stores the base address
                    // of the array in name
  strcpy(name,"Gandalf"); //Stores Gandalf in name

  //name has address/s for a dynamic char array,*name dereferenced shows current characters stored dynamically in char array
  cout << "\nAddress of name = " << &name <<" Dereferenced  *name " << " " << name << endl;


  str = new string;  //allocates memory on the heap for an array of type string
                    //and stores the address of the allocated memory in str
  *str = "Rivendale"; //Stores the string "Rivendale" in the memory pointed to by str

   //str has address/s for a dynamic string,*str dereferenced shows current characters stored dynamically in str (string)
  cout << "\nAddress of str = " << &str <<" Dereferenced  *str "<< " " << *str << endl;

  // deallocate memory from heap
  delete p;         //deallocate a single dynamic variable
  p = nullptr;      //set to NULL - prevent dangling pointer
  delete []name;    //deallocate a dynamically created array
  name = nullptr;   //set to NULL - prevent dangling pointer
  delete str;       //deallocate a single dynamic variable
  str = nullptr;    //set to NULL - prevent dangling pointer*
                     //*not needed as the string class destructor may contain code to set to NULL

  cout << "\nAddress of p = " << &p << " Content of p = " << p << endl;
  cout << "\nAddress of name = " << &name << " Content of name = " << name << endl;
  cout << "\nAddress of str = " << &str << " Content of str = " << str << endl;

  return 0;
}
