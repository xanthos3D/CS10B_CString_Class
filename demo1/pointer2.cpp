//Review#2: Client code with a pointer to a class object
//pointer access to class member function using the this -> operator

#include<iostream>
using namespace std;

//class specification
class classExample
{
    public:
        void setX(/*in*/int a);
        //Function to set the value of x
        //Postcondition: x = a;
        void print() const;
        //Function to output the value of x
    private:
        int x;
};

//class implementation
void classExample::setX(/*in*/int a)
{
    x = a;
}

void classExample::print() const
{
    cout << "x = " << x << endl;
}


int main()
{
   classExample *cExpPtr;
   classExample cExpObject;

    cExpPtr = &cExpObject;

    cExpPtr->setX(5);
    cExpPtr->print();

//   cExpPtr.setX(5);   //? why not
//   cExpPtr.print();   //? why not

  return 0;
}
