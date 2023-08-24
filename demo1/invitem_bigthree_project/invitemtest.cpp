// This is the file "invitemtest.cpp"

    #include <iostream>
    #include "invitem.h"
    using namespace std;

    void f(InventoryItem item1);

    int main()
    {
        InventoryItem item1;
        InventoryItem item2("hammer");

        cout << "item1 is " << item1 << endl;
        cout << "item2 is " << item2 << endl;

        item1.setInfo("screwdriver", 5);
        item2.setUnits(9);

        cout << "item1 is " << item1 << endl;
        cout << "item2 is " << item2 << endl << endl;

        // There are 4 issues that come up when you use
        // a pointer as a data member.  You must include
        // in your class:
        // (1) ASSIGNMENT OPERATOR
        // (2) COPY CONSTRUCTOR
        // (3) DESTRUCTOR
        // (4) DEFAULT CONSTRUCTOR


        // (1) ASSIGNMENT OPERATOR

        // If you don't have an overloaded assignment
        // operator, the next 8 lines will give you
        // incorrect results.  Try it!

        item1 = item2;
        cout << "after item1 = item2, " << endl;
        cout << "item1 is " << item1 << endl;
        cout << "item2 is " << item2 << endl << endl;

        item2.setInfo("lawn mower", 14);
        cout << "after item2.setInfo(\"lawn mower\", 14), " << endl;
        cout << "item1 is " << item1 << endl;
        cout << "item2 is " << item2 << endl << endl;


        // The next 3 lines illustrate the need for the
        // if statement in the assignment operator.  Take
        // the if statement out and see what happens.

        item1 = item1;
        cout << "after item1 = item1, ";
        cout << "item1 is " << item1 << endl << endl;


        // (2) COPY CONSTRUCTOR

        // There are three situations in which C++ makes a copy:
        // 1) pass-by-value, 2) return, and 3) initialization.
        // You can supply a copy constructor to override
        // C++'s default copy operation.


        // First pass-by-value.  If you take out the copy constructor,
        // the call to f will change the value of item1, even though
        // pass-by-value was used.

        f(item1);
        cout << "after being used as an argument to pass-by-value parameter, ";
        cout << endl << "item1 is still " << item1 << endl << endl;


        // Now initialization.  C++ makes a distinction between
        // assignment and initialization.  Therefore, if you take
        // out the copy constructor, the next 8 lines will give
        // incorrect results, even if = is overloaded.

        InventoryItem item3 = item1;
        // this is exactly equivalent to: InventoryItem item3(item1);

        cout << "after InventoryItem item3 = item1;" << endl;
        cout << "item1 is " << item1 << endl;
        cout << "item3 is " << item3 << endl << endl;

        item3.setInfo("ice cream", 962);
        cout << "after item3.setInfo(\"ice cream\", 962);" << endl;
        cout << "item1 is " << item1 << endl;
        cout << "item3 is " << item3 << endl << endl;


        // OVERLOADING THE SQUARE BRACKETS

        cout << item1[1] << item1[2] << item1[3] << endl;
        item1[1] = 'c';
        item1[2] = 'i';
        item1[3] = 's';
        cout << item1[1] << item1[2] << item1[3] << endl;
        const InventoryItem item4("chair");
        cout << item4[0] << endl;

         //should cause syntax error:
/*
        item4[1] = 'z';
        cout << item4[1] << endl;*/



        // OVERLOADING THE EXTRACTION OPERATOR - to be updated

        cout << "enter two inventory items: ";
        cin >> item1 >> item2;
        cout << "you entered " << item1 << " and " << item2 << endl << endl;

        return 0;

    }

    void f(InventoryItem item1)
    {
        item1.setInfo("pizza", 67);
    }


