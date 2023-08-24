//boolarray.cpp demonstrates how to read data from a file into a 2D array

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class boolMatrix{
 public:
     static const int SIZE = 20;
     boolMatrix(); //a default constructor
     void print() const; //observers
     void set(int row,int col, bool val);
     int totalCount()const;
     int rowCount(int row)const;
     int colCount(int col)const;
     int neighborCount(int row, int col)const;

 private:
  bool matrix[SIZE][SIZE];
};

boolMatrix::boolMatrix()
{
    //initialize array - HINT source code below should be an initialize function
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            matrix[row][col] = false;
        }
    }
}

void boolMatrix::print() const
{
    //print contents of array after initialization - HINT source code below should be a print function
    //	cout << "  01234" << endl;
     cout << "  ";
     for(int col = 0; col < SIZE; col++)
     {
         cout << col % 10;
     }
     cout << endl;
    for (int row = 0; row < SIZE; row++)
    {
        cout << setw(2) << row % 10;
        for (int col = 0; col < SIZE; col++)
        {
           if (matrix[row][col])
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

    cout << endl;
}

void boolMatrix::set(int row,int col, bool val)
{
    matrix[row][col] = val;
}

int boolMatrix::totalCount()const
{
    int count = 0;
    for(int row = 0; row < SIZE; row++)
    {
        for(int col = 0; col < SIZE; col++)
        {
            if(matrix[row][col])
                count++;
        }
    }
    return count;
}
int boolMatrix::rowCount(int row)const
{
    //assert
    int count = 0;

    for(int col = 0; col < SIZE; col++)
    {
        if(matrix[row][col])
                count++;
    }
    return count;
}
int boolMatrix::colCount(int col)const
{
    //assert
    int count = 0;

    for(int row = 0; row < SIZE; row++)
    {
        if(matrix[row][col])
                count++;
    }
    return count;
}

int boolMatrix::neighborCount(int row, int col)const
{
    int count = 0;

    return count;
}

const int SIZE = 20;

void initialize(bool[][SIZE]);
void print(bool[][SIZE]);
void print2(bool[][SIZE]);
void readFile(bool[][SIZE]);
void readFile(boolMatrix&);
int totalCountLive(bool[][SIZE]);
int totalCountEmpty(bool[][SIZE]);
int rowCount(bool[][SIZE], int);
int colCount(bool[][SIZE], int);
void printResults(/*in*/ const boolMatrix& life);

int main()
{

   boolMatrix life;
   life.print();
   readFile(life);
   life.print();

   printResults(life);

   cout<<"Total alive in matrix " << life.totalCount()<< endl;
    cout<<"Total alive in row 10 " << life.rowCount(10) << endl;
    cout<<"Total alive in column 10 " << life.colCount(10) << endl;

 /*  bool shape[SIZE][SIZE];
   int row, col;

    initialize(shape);
    print(shape);
    readFile(shape);
    print2(shape);
    cout<<"Total alive in matrix " << totalCountLive(shape) << endl;
    cout<<"Total empty cells in matrix " << totalCountEmpty(shape) << endl;
    cout<<"Total alive in row 10 " << rowCount(shape,10) << endl;
    cout<<"Total alive in column 10 " << colCount(shape,10) << endl;
*/

    return 0;
}

//NOTE: CHANGE THE ABOVE 2D ARRAY PROCESSING RELATED PROCEDURES INTO FUNCTIONS
void initialize(bool matrix[][SIZE])
{
   //initialize array - HINT source code below should be an initialize function
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            matrix[row][col] = false;
        }
    }
}


void print(bool matrix[][SIZE])
{

       //print contents of array after initialization - HINT source code below should be a print function
    //	cout << "  01234" << endl;
     cout << "  ";
     for(int col = 0; col < SIZE; col++)
     {
         cout << col % 10;
     }
     cout << endl;
    for (int row = 0; row < SIZE; row++)
    {
        cout << setw(2) << row % 10;
        for (int col = 0; col < SIZE; col++)
        {
           cout<<matrix[row][col];
        }
        cout << endl;
    }

    cout << endl;
}

void printResults(/*in*/ const boolMatrix& life)
{
    life.print();

    cout<<"Total alive in matrix " << life.totalCount()<< endl;
    cout<<"Total alive in row 10 " << life.rowCount(10) << endl;
    cout<<"Total alive in column 10 " << life.colCount(10) << endl;


}

void print2(bool matrix[][SIZE])
{

  //print contents of two-dimensional array  - HINT source code below should be a print function
	//cout << "  01234" << endl;
	cout << "  ";
     for(int col = 0; col < SIZE; col++)
     {
         cout << col % 10;
     }
     cout << endl;
    for (int row = 0; row < SIZE; row++)
    {
        cout << setw(2) << row % 10;
        for (int col = 0; col < SIZE; col++)
        {
            if (matrix[row][col])
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

}

void readFile(bool matrix[][SIZE]) //parameter refers to client code bool array
{
    int row, col;
    //readGrid - HINT source code below should be a read or get_input function
    ifstream infile("lifedata.txt");

    infile >> row >> col;
    while (infile)
    {
        matrix[row][col] = true;

        infile >> row >> col;
    }
    infile.close();
}


void readFile(boolMatrix& life)
{
    int row, col;
    //readGrid - HINT source code below should be a read or get_input function
    ifstream infile("lifedata.txt");

    infile >> row >> col;
    while (infile)
    {
        //matrix[row][col] = true;
        life.set(row,col,true); //a setter class member function is needed here
        infile >> row >> col;
    }
    infile.close();
}

int totalCountLive(bool matrix[][SIZE])
{
    int count = 0;
    for(int row = 0; row < SIZE; row++)
    {
        for(int col = 0; col < SIZE; col++)
        {
            if(matrix[row][col])
                count++;
        }
    }
    return count;
}

int totalCountEmpty(bool matrix[][SIZE])
{
    int count = 0;
    for(int row = 0; row < SIZE; row++)
    {
        for(int col = 0; col < SIZE; col++)
        {
            if(!matrix[row][col])
                count++;
        }
    }
    return count;
}

int rowCount(bool matrix[][SIZE], int row)
{
    int count = 0;

    for(int col = 0; col < SIZE; col++)
    {
        if(matrix[row][col])
                count++;
    }
    return count;
}
int colCount(bool matrix[][SIZE], int col)
{
     int count = 0;

    for(int row = 0; row < SIZE; row++)
    {
        if(matrix[row][col])
                count++;
    }
    return count;
}


