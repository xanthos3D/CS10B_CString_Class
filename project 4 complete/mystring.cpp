//xander maniaci
/* class definitions for the my string data type.
 contains all functions declarations needed for working with a dynamic c string */
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <cassert>
#include <string>
#include "mystring.h"
using namespace std;

namespace cs_mystring{
    int MyString::length() const
    {
    //pre:gets a mystring
    //post: returns the c strings length
       return strlen(str);
    }
    MyString::MyString()
    {
    //pre:gets a mystring
    //post: creates a empty dynamic c string within the mystring
        str = new char[1];
        strcpy(str, "");

    }

    MyString::MyString(const char* inString)
    {
        //pre:gets a mystring
        //post: creates a dynamic  c string within the mystring
        str = new char[strlen(inString)+1];
        strcpy(str, inString);
    }

    MyString::~MyString()
    {
        //pre:gets a mystring
        //post: deallocates and clears a dynamic c string.
        delete []str;
        str = nullptr;
    }
     MyString MyString::operator =(const MyString& right)
     {
        //pre:gets a two mystrings
        //post: sets them equal to each other by creating two spaces in memory so that each char pointer point to different places. prevents creation of shallow copy
         if(this != &right)
         {
             delete []str;
             str = right.str;
             str = new char[strlen(right.str)+1];
             for(int counter = 0; counter< strlen(right.str)+1;counter++)
            {
                str[counter] = right.str[counter];
            }
             }

     }
      MyString::MyString(const MyString& copyMe)
      {
        //pre:gets a two mystrings
        //post: sets two mystrings equal to each other without creating a memberwise copy
        str = copyMe.str;
        str = new char[strlen(copyMe.str)+1];
        for(int counter = 0; counter< strlen(copyMe.str)+1;counter++)
        {
            str[counter] = copyMe.str[counter];
        }
      }
    ostream& operator<<(ostream& out, const MyString& source)
        {
        //pre:gets a mystring
        //post: displays the mystring
            out << source.str;
            return out;
        }
    istream& operator>>(istream& in, MyString& target)
        {
        //pre:gets a mystring
        //post: fills that my string with data read by the insertion operator. ignores white space.
        //include customized input validation
            char temp[MyString::MAX_INPUT_SIZE+1];

             while(isspace(in.peek())){ //needed to ignore leading whitespaces
                in.ignore();
            }
            in >> temp;//read input of characters store in temp
            delete [] target.str; //delete memory space
            target.str = new char[strlen(temp) + 1]; //create new memory space
            strcpy(target.str,temp); //swap from temp to target.description
            return in;
        }

    void MyString::readline(std::istream& in ,char getMe)
    {
        //pre:gets a mystring
        //post: fills that my string with data read by the insertion operator.fills c string with entire line.
                   char tempStr[MyString::MAX_INPUT_SIZE + 1];
                    in.getline(tempStr, MyString::MAX_INPUT_SIZE + 1, '\n');
                    delete [] str;
                    str = new char[strlen(tempStr) + 1];
                    strcpy(str, tempStr);
    }

    char MyString::operator[](int index)const
        {
        //pre:gets a mystring.
        //post: allows direct access to the chars in the c string
            assert(index >= 0 && index < strlen(str));
            return str[index];
        }

    char& MyString::operator[](int index)
        {
        //pre:gets a mystring.
        //post: allows direct access to the chars in the c string

            assert(index >= 0 && index < strlen(str));
            return str[index];
        }
    bool operator < (const MyString leftOp, const MyString rightOp)
    {
        //pre:gets a two mystrings
        //post: compares them by using the value strcat(left,right) with zero.
        bool temp = false;
        if(strcmp(leftOp.str,rightOp.str) < 0)
        {
            temp = true;
        }else
        temp = false;
        {
    }
       return temp;
    }
    bool operator <= (const MyString leftOp, const MyString rightOp)
    {
        //pre:gets a two mystrings
        //post: compares them by using the value strcat(left,right) with zero.
        bool temp = false;
        if(strcmp(leftOp.str,rightOp.str) <= 0)
        {
            temp = true;
        }else
        temp = false;
        {
    }
       return temp;
    }
    bool operator > (const MyString leftOp, const MyString rightOp)
    {
        //pre:gets a two mystrings
        //post: compares them by using the value strcat(left,right) with zero.
        bool temp = false;
        if(strcmp(leftOp.str,rightOp.str) > 0)
        {
            temp = true;
        }else
        temp = false;
        {
    }
       return temp;

    }
    bool operator >= (const MyString leftOp, const MyString rightOp)
    {
        //pre:gets a two mystrings
        //post: compares them by using the value strcat(left,right) with zero.
        bool temp = false;
        if(strcmp(leftOp.str,rightOp.str) >= 0)
        {
            temp = true;
        }else
        temp = false;
        {
    }
       return temp;

    }
    bool operator == (const MyString leftOp, const MyString rightOp)
    {
        //pre:gets a two mystrings
        //post: compares them by using the value strcat(left,right) with zero.
        bool temp = false;
        if(strcmp(leftOp.str,rightOp.str) == 0)
        {
            temp = true;
        }else
        temp = false;
        {
    }
       return temp;

    }
    bool operator != (const MyString leftOp, const MyString rightOp)
    {
        //pre:gets a two mystrings
        //post: compares them by using the value strcat(left,right) with zero.
        bool temp = false;
        if(strcmp(leftOp.str,rightOp.str) != 0)
        {
            temp = true;
        }else
        temp = false;
        {
    }
       return temp;

    }
    MyString operator + (const MyString leftOp, const MyString rightOp)
    {
        //pre:gets two mystrings
        //post: cats the c strings together with in the two mystring variables. returns  a my string
        MyString temp;
        temp.str = new char[strlen(leftOp.str)+strlen(rightOp.str)+1];
        temp.str = strcat(leftOp.str,rightOp.str);
        return temp;
    }

    MyString MyString::operator += (const MyString rightOp)
    {
      //pre:gets two mystrings
        //post: cats the c strings together with in the two mystring variables. returns  a my string
     MyString temp;
     temp = *this + rightOp;
     return  temp;
    }
}
