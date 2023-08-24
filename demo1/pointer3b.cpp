//pointer review#3 - Creating dynamic arrays during program execution
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
 cout << "Set up a dynamic int array, number of elements provided by user\n"
      << "***************************************************************\n";

  int *intList;   //a pointer to a dynamic int array
  int arraySize;

  cout << "Enter array size: ";
  cin >> arraySize;
  cout <<endl;

  intList = new int[arraySize];

  cout << "Enter " << arraySize << " values below...\n";
  for(int index = 0; index < arraySize; index++)
  {
      cout <<"Element#" << index+1 <<": ";
      cin >> intList[index];
      cin.ignore();
  }

  //intList has address of a dynamic memory area,*intList++ dereferenced shows current values stored dynamically in the intList array
  cout << "Address of intList = " << &intList << " First element address in intList = " <<(int*)&intList[0]  << endl;
  cout << "Listing of dereferenced *intList elements: ";
  for(int index = 0; index < arraySize; index++)
  {
      cout <<*intList++ << " "; // or intList[index] << " ";
  }
  cout <<endl;

cout << "\nSet up a dynamic char array(c-string),overall character limit 127\n"
     << "memory allocated based on characters actually input\n"
     << "*******************************************************************\n";
  char *name;           //name is pointer of dynamic char type array
  char temp[127];
  cout << "Enter some text ...\n";

  cin.getline(temp,127,'\n'); //delimiter can be something else like '.' or ':'

  name = new char[strlen(temp)+1]; //correctly sized dynamic memory allocated
  strcpy(name, temp); //storing c-string characters in memory space

//name has address/s for a dynamic char array,*name dereferenced shows current characters stored dynamically in char array
  cout << "Address of name = " << &name << " First element address in name = " << (int*)&name[0] << endl;
  cout <<"Dereferenced  *name " << " " << name << endl;

cout << "\nSet up a dynamic string pointer,memory allocated based on string length\n"
     << " of characters actually input\n"
     << "*******************************************************************\n";

  string *str;  //str is a pointer of type string

  str = new string;  //allocates memory on the heap for an array of type string
                    //and stores the address of the allocated memory in str
  cout << "Enter some text ...\n";

  getline( cin, *str ); //delimiter can be something else like '.' or ':'

  //str has address/s for a dynamic string,*str dereferenced shows current characters stored dynamically in str (string)
  cout << "Address of str = " << &str <<" First element address in str = " << (int*)&str[0] << endl;
   cout <<"Dereferenced  *str " << " " << *str << endl;

  // deallocate memory from heap
  cout<< "\nDynamic memory now deallocated and all pointers set to NULL\n";
  delete []intList;         //deallocate a single dynamic variable
  intList = nullptr;      //set to NULL - prevent dangling pointer
  cout << "Address of first element in intList = " << (int*)&intList[0] << endl;

  delete [] name;    //deallocate a dynamically created array
  name = nullptr;   //set to NULL - prevent dangling pointer
  cout << "Address of first element in name = " << (int*)&name[0] << endl;

  delete str;       //deallocate a single dynamic variable
  str = nullptr;    //set to NULL - prevent dangling pointer*
                     //*not needed as the string class destructor may contain code to set to NULL
  cout << "Address of first element in str = " << (int*)&str[0] << endl << endl;;


  return 0;
}
