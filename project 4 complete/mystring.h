//xander maniaci, project 4 ,cs10b
/* class declaration for the my string data type.
 contains all functions needed for working with a dynamic c string */
#include <iostream>
#ifndef MYSTRING_H
#define MYSTRING_H
using namespace std;
//namespace definition
namespace cs_mystring{
    class MyString
    {
    public:
        static const int MAX_INPUT_SIZE = 127;
        int length() const;//length function
        //pre:gets a mystring
        //post: returns the c strings length
        MyString();  // default constructor
        //pre:gets a mystring
        //post: creates a empty dynamic c string within the mystring
        MyString(const char*); // parameterized constructor
        //pre:gets a mystring
        //post: creates a dynamic  c string within the mystring
        ~MyString();  // class destructor
        //pre:gets a mystring
        //post: deallocates and clears a dynamic c string.
        MyString operator=(const MyString& right);  // = operator used in client code
        //pre:gets a two mystrings
        //post: sets them equal to each other by creating two spaces in memory so that each char pointer point to different places. prevents creation of shallow copy
        MyString(const MyString& copyMe);  //copy constructor makes a deep copy
        //pre:gets a two mystrings
        //post: sets two mystrings equal to each other without creating a memberwise copy
        friend std::ostream& operator<<(std::ostream& out, const MyString& source); //to overload <<
        //pre:gets a mystring
        //post: displays the mystring
        friend std::istream& operator>>(std::istream& in, MyString& target);//to overload >>
        //pre:gets a mystring
        //post: fills that my string with data read by the insertion operator. ignores white space.
        void readline(std::istream& in ,char getMe);
        //pre:gets a mystring
        //post: fills that my string with data read by the insertion operator.fills c string with entire line.

        //relational overloaded operators
        friend bool operator < (const MyString leftOp, const MyString rightOp);
        //pre:gets a two mystrings
        //post: compares them by using the value strcat(left,right) with zero.
        friend bool operator <= (const MyString leftOp, const MyString rightOp);
        //pre:gets a two mystrings
        //post: compares them by using the value strcat(left,right) with zero.
        friend bool operator > (const MyString leftOp, const MyString rightOp);
        //pre:gets a two mystrings
        //post: compares them by using the value strcat(left,right) with zero.
        friend bool operator >= (const MyString leftOp, const MyString rightOp);
        //pre:gets a two mystrings
        //post: compares them by using the value strcat(left,right) with zero.
        friend bool operator == (const MyString leftOp, const MyString rightOp);
        //pre:gets a two mystrings
        //post: compares them by using the value strcat(left,right) with zero.
        friend bool operator != (const MyString leftOp, const MyString rightOp);
        //pre:gets a two mystrings
        //post: compares them by using the value strcat(left,right) with zero.

        //overloads the [] operator
        char operator[] (int index) const;
        //pre:gets a mystring.
        //post: allows direct access to the chars in the c string
        char& operator [] (int index);
        //pre:gets a mystring.
        //post: allows direct access to the chars in the c string

        friend MyString operator + (const MyString leftOp, const MyString rightOp);
        //pre:gets two mystrings
        //post: cats the c strings together with in the two mystring variables. returns results a my string
        MyString operator += (const MyString rightOp);
        //pre:gets two mystrings
        //post: cats the c strings together with in the two mystring variables. returns results a my string
    private:
        char *str;
    };
}
#endif
/*
Project#4: MyString class (ADT) client program to test CLASS INVARIANT
The class has one private data member defined as follows:
char *str;
str always represents a valid null-terminated c-string for each instance
of a MyString class object class.
The client code provides an interface to test correct operations on MyString
objects

Here is a list of tests and the order in which the tests will be conducted
1. BasicTest
2. RelationTest
3. ConcatTest
4. CopyTest

***********************************************************************
* Basic Test: Testing various member constructor options and nonmember*
* friend ostream << operator for basic MyString object creation &     *
* printing                                                            *
***********************************************************************
string [0] = Wow
string [1] = C++ is neat!
string [2] =
string [3] = a-z

***********************************************************************
* Basic Test: Testing nonmember friend istream >> and ostream <<      *
* operators for reading and display of MyString objects from data file*
***********************************************************************

----- first, word by word
Read string = The
Read string = first
Read string = time
Read string = we
Read string = will
Read string = read
Read string = individual
Read string = words,
Read string = next
Read string = we
Read string = read
Read string = whole
Read string = lines

*************************************************************************
* Basic Test: Testing member function readline read, a nonmember friend *
* istream >> and ostream <<operators for reading and display of MyString*
* objects from data file                                                *
* ***********************************************************************

----- now, line by line
Read string = The  first  time  we  will
Read string =     read individual words, next
Read string = we read whole lines

****************************************************************************
* Basic Test: Testing access to characters (using const and non const)     *
* using constructors, member function length that returns a cstring length,*
* the square bracket [] overloaded operator and a nonmember friend         *
* istream >> for display of MyString objects content                       *
* **************************************************************************

----- Testing access to characters (using const)
Whole string is abcdefghijklmnopqsrtuvwxyz
now char by char: abcdefghijklmnopqsrtuvwxyz

----- Testing access to characters (using non-const)
Start with abcdefghijklmnopqsrtuvwxyz and convert to ABCDEFGHIJKLMNOPQSRTUVWXYZ

***********************************************************************
* RelationTest: Testing nonmember friend binary Boolean <, <=, >, >=, *
*  ==, != relational operators between MyString objects               *
***********************************************************************
Comparing app to apple
        Is left < right? true
        Is left <= right? true
        Is left > right? false
        Is left >= right? false
        Does left == right? false
        Does left != right ? true
Comparing apple to
        Is left < right? false
        Is left <= right? false
        Is left > right? true
        Is left >= right? true
        Does left == right? false
        Does left != right ? true
Comparing  to Banana
        Is left < right? true
        Is left <= right? true
        Is left > right? false
        Is left >= right? false
        Does left == right? false
        Does left != right ? true
Comparing Banana to Banana
        Is left < right? false
        Is left <= right? true
        Is left > right? false
        Is left >= right? true
        Does left == right? true
        Does left != right ? false

***********************************************************************
* RelationTest: Testing nonmember friend binary Boolean <, <=, >, >=, *
*  ==, != relational operators between MyString objects and char      *
***********************************************************************
Comparing he to hello
        Is left < right? true
        Is left <= right? true
        Is left > right? false
        Is left >= right? false
        Does left == right? false
        Does left != right ? true
Comparing why to wackity
        Is left < right? false
        Is left <= right? false
        Is left > right? true
        Is left >= right? true
        Does left == right? false
        Does left != right ? true

************************************************************************
* ConcatTest: Testing nonmember friend binary arithmetic + operator    *
* that do concatenation on MyString objects                            *
************************************************************************

----- Testing concatenation on MyStrings
outrageous + milk = outrageousmilk
milk +  = milk
 + cow = cow
cow + bell = cowbell

************************************************************************
* ConcatTest: Testing nonmember friend binary arithmetic + operator    *
* that do concatenation between MyString objects and char*             *
************************************************************************

----- Testing concatenation between MyString and char *
abcde + XYZ = abcdeXYZ
XYZ + abcde = XYZabcde

************************************************************************
* ConcatTest: Testing member binary arithmetic += operator             *
* that do concatenation between MyString objects and char*             *
************************************************************************

----- Testing shorthand concat/assign using MyString and char *
I love  += programming = I love programming

*****************************************************************************
* CopyTest: Testing default constructor, copy constructor and member        *
* assignment = operator on MyStrings to check for memberwise shallow copy   *
* the member square bracket [] overloaded operator and a nonmember friend   *
* ostream << for display of MyString objects content                        *
* ***************************************************************************

----- Testing copy constructor and operator= on MyStrings
original is cake, copy is fake
original is cake, copy is fake
after self assignment, copy is Copy Cat
Testing pass & return MyStrings by value and ref
after calling Append, sum is BinkyBoo
val is winky
after assign,  val is BinkyBoo

Project#4 -MyString class (ADT) testing now concluded.
MyString class destructor has been invoked and memory from the heap deallocated
Check output for correct results from the MyString class (ADT) implementation.

Process returned 0 (0x0)   execution time : 0.083 s
Press any key to continue.
*/
