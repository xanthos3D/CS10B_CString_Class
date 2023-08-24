// This is the file "invitem.cpp"

    #include <iostream>
    #include <cassert>
    #include <cstring>
    #include "invitem.h"
    using namespace std;

    InventoryItem::InventoryItem()
    {
        units = 0;
        description = new char[1];
        strcpy(description, "");
    }

    InventoryItem::InventoryItem(const char *inDesc)
    {
        units = 0;
        description = new char[strlen(inDesc) + 1];
        strcpy(description, inDesc);
    }

    InventoryItem::InventoryItem(const char *inDesc, int inUnits)
    {
        units = inUnits;
        description = new char[strlen(inDesc) + 1];
        strcpy(description, inDesc);
    }

    InventoryItem::InventoryItem(const InventoryItem& right)
    {
        units = right.units;
        description = new char[strlen(right.description) + 1];
        strcpy(description, right.description);
    }

    InventoryItem::~InventoryItem()
    {
        delete [] description;
    }

    InventoryItem InventoryItem::operator=(const InventoryItem& right)
    {
        if (this != &right){
            units = right.units;
            delete [] description;
            description = new char[strlen(right.description) + 1];
            strcpy(description, right.description);
        }
        return *this;
    }

    void InventoryItem::setInfo(const char *inDesc, int inUnits)
    {
        units = inUnits;
        delete [] description;
        description = new char[strlen(inDesc) + 1];
        strcpy(description, inDesc);
    }

    void InventoryItem::setUnits(int inUnits)
    {
        units = inUnits;
    }

    ostream& operator<<(ostream& out, const InventoryItem& source)
    {
        out << source.units << " " << source.description;
        return out;
    }

    void InventoryItem::readline(std::istream& in, char delimiter)
    {
        if(isalpha(in.peek())) //check alpha character read all characters up to the delimiter and store in tempStr
           {
               char tempStr[InventoryItem::MAX_INPUT_SIZE + 1];
                in.getline(tempStr, InventoryItem::MAX_INPUT_SIZE + 1, delimiter);
                delete [] description;
                description = new char[strlen(tempStr) + 1];
                strcpy(description, tempStr);
           }
           else //if not assume it is a number and store
            in>>units;

    }

    istream& operator>>(istream& in, InventoryItem& target)//not parameter target has two private data items
    {
        //include customized input validation
        char temp[InventoryItem::MAX_INPUT_SIZE + 1];
        cout<<"Enter description: ";

         while (isspace(in.peek())){ //needed to ignore leading whitespaces
            in.ignore();
        }
        in.getline(temp, InventoryItem::MAX_INPUT_SIZE, '\n'); //read input of characters store in temp
        delete [] target.description; //delete memory space
        target.description = new char[strlen(temp) + 1]; //create new memory space
        strcpy(target.description, temp); //swap from temp to target.description
        cout<<"Enter unit: ";
        in >> target.units;   //store input into private data item
        return in;  //? is this needed
    }
/*
    istream& operator>>(istream& in, InventoryItem& target) //another algorithm
    {
        int units;
        char temp[InventoryItem::MAX_INPUT_SIZE + 1];
        cout<<"Enter description: ";

         while (isspace(in.peek())){ //needed to ignore leading whitespaces
            in.ignore();
        }
        in.getline(temp, InventoryItem::MAX_INPUT_SIZE, '\n'); //read input of characters store in temp

        cout<<"Enter unit: ";
        in >> units;   //store input into private data item
        // InventoryItem newitem(temp,units); //call constructor
        // target = newitem;
        target.setInfo(temp,units); //call setInfo to update private data of target
        return in;  //? is this needed
    }
*/
    char InventoryItem::operator[](int index)const
    {
        assert(index >= 0 && index < strlen(description));
        return description[index];
    }

    char& InventoryItem::operator[](int index)
    {
        assert(index >= 0 && index < strlen(description));
        return description[index];
    }

