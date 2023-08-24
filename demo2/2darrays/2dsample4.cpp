//boolarray.cpp demonstrates how to read data from a file into a 2D array

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//class specification
class boolMatrix{
 public:
     static const int SIZE = 20;
     boolMatrix();                              //a default constructor
     void print() const;                        //observers
     void set(int row,int col, bool val);       //transformer
     int totalCount()const;                     //observers
     int rowCount(int row)const;                //observers
     int colCount(int col)const;                //observers
     int neighborCount(int row, int col)const;  //observers

     //Big three needed for dynamic memory component
     ~boolMatrix();                                 //(1) Destructor
     boolMatrix operator=(const boolMatrix& right); //(2) Member assignment overload operator =
     boolMatrix(const boolMatrix& right);           //(3) Copy Constructor

 private:
  //bool matrix[SIZE][SIZE]; //static 2D array on the stack
    bool **matrix; //pointer to dynamic memory on the heap - see default constructor/destructor
};

// boolMatrix class implementation details
boolMatrix::boolMatrix()
{
    //create the rows of matrix
   matrix = new bool*[SIZE];
   //Create the columns of matrix
   for(int row = 0; row < SIZE; row++)
    matrix [row]= new bool [SIZE];


    //initialize array
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            matrix[row][col] = false;
        }
    }
}

 boolMatrix::~boolMatrix()
 {
     delete[] matrix;
     matrix = nullptr;
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

//client code testing boolMatrix class ADT
//local client functions with class object parameters
void readFile(boolMatrix& life);
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

    return 0;
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

void printResults(/*in*/ const boolMatrix& life)
{
    life.print();

    cout<<"Total alive in matrix " << life.totalCount()<< endl;
    cout<<"Total alive in row 10 " << life.rowCount(10) << endl;
    cout<<"Total alive in column 10 " << life.colCount(10) << endl;

}

