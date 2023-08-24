// This is the file "invitem.h" - Featuring a class with a dynamic memory component
/* Note: There are 4 issues that come up when you use a pointer as a data member.
   You must include the following in your class:
        // (1) ASSIGNMENT OPERATOR 
        // (2) COPY CONSTRUCTOR
        // (3) DESTRUCTOR
        // (4) DEFAULT CONSTRUCTOR
   The first three make up what is known as the "Big Three". 
   Expect some updates to this sometime in future versions of C++..... */

    #ifndef INVITEM_H
    #define INVITEM_H
    #include <iostream>

    class InventoryItem {
        public:
            static const int MAX_INPUT_SIZE = 127; //arbitrary char array length set
            
            // various constructors/ and a desstructor
            InventoryItem();                    //default constructor
            InventoryItem(const char *inDesc);  //constructor with const pointer parameter
            InventoryItem(const InventoryItem& right); 	//copy constructor
            ~InventoryItem();  				//a destructor

            // setter functions
            void setInfo(const char *inDesc, int inUnits); //setter function
            void setUnits(int inUnits);                    //another setter function
            
	    // various operator overload functions
	    InventoryItem operator=(const InventoryItem& right); //overloading assignment= operator      
            friend std::ostream& operator<<(std::ostream& out, const InventoryItem& source); //to overload <<
            friend std::istream& operator>>(std::istream& in, InventoryItem& target);//to overload >>
            char operator[](int index) const; 	//square bracket overload with const -lvalue
            char& operator[](int index);	//square bracket overload return reference -rvalue

        private:
            char *description; // Dynamic char array for characters in the string
                               // see constructor for dynamic memory allocation to a *
                               //issues crop up with member-wise allocation (shallow verses deep copy concepts)
            int units; 	       //a regular int value as a data member
    };

    #endif



   /* program output
   // This is the output:

    item1 is 0
    item2 is 0 hammer
    item1 is 5 screwdriver
    item2 is 9 hammer

    after item1 = item2,
    item1 is 9 hammer
    item2 is 9 hammer

    after item2.setInfo("lawn mower", 14),
    item1 is 9 hammer
    item2 is 14 lawn mower

    after item1 = item1, item1 is 9 hammer
    after being used as an argument to pass-by-value parameter,
    item1 is still 9 hammer

    after InventoryItem item3 = item1;
    item1 is 9 hammer
    item3 is 9 hammer

    after item3.setInfo("ice cream", 962);
    item1 is 9 hammer
    item3 is 962 ice cream

   */
