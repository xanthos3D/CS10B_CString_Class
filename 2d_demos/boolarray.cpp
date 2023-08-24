//boolarray.cpp demonstrates how to read data from a file into a 2D array

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int SIZE = 5;

int main()
{
   bool shape[SIZE][SIZE];
   int row, col;

    //initialize array - HINT source code below should be an initialize function
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            shape[row][col] = false;
        }
    }
    //print contents of array after initialization - HINT source code below should be a print function
    	cout << "  01234" << endl;
    for (int row = 0; row < SIZE; row++)
    {
        cout << setw(2) << row;
        for (int col = 0; col < SIZE; col++)
        {
           cout<<shape[row][col];
        }
        cout << endl;
    }

    cout << endl;
    //readGrid - HINT source code below should be a read or get_input function
    ifstream infile("sampledata.txt");

    infile >> row >> col;
    while (infile)
    {
        shape[row][col] = true;
        infile >> row >> col;
    }
    infile.close();

    //print contents of two-dimensional array  - HINT source code below should be a print function

	cout << "  01234" << endl;
    for (int row = 0; row < SIZE; row++)
    {
        cout << setw(2) << row;
        for (int col = 0; col < SIZE; col++)
        {
            if (shape[row][col])
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
}

    return 0;
}

//NOTE: CHANGE THE ABOVE 2D ARRAY PROCESSING RELATED PROCEDURES INTO FUNCTIONS
