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

    istream& operator>>(istream& in, InventoryItem& target)
    {
        while (isspace(in.peek())){
            in.ignore();
        }

        char temp[InventoryItem::MAX_INPUT_SIZE + 1];
        in.getline(temp, InventoryItem::MAX_INPUT_SIZE, ':');
        delete [] target.description;
        target.description = new char[strlen(temp) + 1];
        strcpy(target.description, temp);
        in >> target.units;

        return in;
    }

    char InventoryItem::operator[](int index) const
    {
        assert(index >= 0 && index < strlen(description));
        return description[index];
    }

    char& InventoryItem::operator[](int index)
    {
        assert(index >= 0 && index < strlen(description));
        return description[index];
    }

