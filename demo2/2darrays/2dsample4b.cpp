#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

class boolMatrix{
 public:
     static const int SIZE = 20;
     boolMatrix(); //a default constructor
     void initialize();
     void print() const; //observers
     void set(int row,int col, bool val);
     int totalCount()const;
     int rowCount(int row)const;
     int colCount(int col)const;
     int neighborCount(int row, int col)const;
     void readFileData();

 private:
 // bool matrix[SIZE][SIZE];
   bool **board;
};
boolMatrix::boolMatrix()
{
    //initialize array - HINT source code below should be an initialize function

   //create the rows of board
   board = new bool*[SIZE];

   //Create the columns of board
   for(int row = 0; row < SIZE; row++)
    board [row]= new bool [SIZE];
}

void boolMatrix::initialize()
{
    // fill board
   for(int row = 0; row < SIZE; row++)
   {
       for (int col = 0; col < SIZE; col++)
        board[row][col] = false;
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
           if (board[row][col])
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

void boolMatrix::readFileData()
{
     string fileName;
     ifstream in;

     cout << "Enter filename with game board data: ";
     cin >> fileName;
     in.open(fileName);

     while(!in)
     {
        in.ignore(200,'\n');
        in.clear();
        cout <<"Data file not found. " <<endl;
        cout << "Enter filename with game board data: ";
        cin >> fileName;
        in.open(fileName);
     }
   int row, col;
     // fill board
     in>>row>>col;

    while (in)
    {
        board[row][col] = true;

        in >> row >> col;
    }
    in.close();
   /*for(int row = 0; row < rowSize; row++)
   {
       for (int col = 0; col < columnSize; col++)
        in >> b[row][col];
   }*/
}
const int SIZE = 5;
void populate(bool **b, int rowSize, int columnSize);
void initialize(bool **b, int rowSize, int columnSize);
void readFileData(bool **b, int rowSize, int columnSize);
void readFileData2(bool **b, int rowSize, int columnSize);
void readFile(bool[][SIZE]);
void print(bool **b, int rowSize, int columnSize);


int main()
{
    cout <<fixed <<showpoint;

    boolMatrix life;
    life.initialize();
    life.print();
    life.readFileData();
    life.print();

 /*  bool **board;

   int rows, columns;

   cout << "Let us fill a 2D Board for an upcoming game of numbers\n";
   cout << "\nEnter the number of rows for the board: "; cin >> rows;
   cout << "Enter the number of columns for the board: "; cin >> columns;
   cout << endl;

   //create the rows of board
   board = new bool*[rows];

   //Create the columns of board
   for(int row = 0; row < rows; row++)
    board [row]= new bool [columns];

    initialize(board, rows, columns);
    print(board, rows, columns);

  // populate(board, rows, columns);
   readFileData(board, rows, columns);
   print(board, rows, columns);
*/

//  delete[] board;
//  board = nullptr;

  return 0;

}
/*
void initialize(bool **b, int rowSize, int columnSize)
{
    // fill board
   for(int row = 0; row < rowSize; row++)
   {
       for (int col = 0; col < columnSize; col++)
        b[row][col] = false;
   }
}
void populate(bool **b, int rowSize, int columnSize)
{
    // fill board
   for(int row = 0; row < rowSize; row++)
   {
       cout << "Enter " << columnSize << " number(s) for row "
           << " number " << row+1 << ": "<< endl;
       for (int col = 0; col < columnSize; col++)
        cin >> b[row][col];
       cout << endl;
   }
}

void readFileData(bool **b, int rowSize, int columnSize)
{
     string fileName;
     ifstream in;

     cout << "Enter filename with game board data: ";
     cin >> fileName;
     in.open(fileName);

     while(!in)
     {
        in.ignore(200,'\n');
        in.clear();
        cout <<"Data file not found. " <<endl;
        cout << "Enter filename with game board data: ";
        cin >> fileName;
        in.open(fileName);
     }
   int row, col;
     // fill board
     in>>row>>col;

    while (in)
    {
        b[row][col] = true;

        in >> row >> col;
    }
    in.close();
   /*for(int row = 0; row < rowSize; row++)
   {
       for (int col = 0; col < columnSize; col++)
        in >> b[row][col];
   }*/
//}
void print(bool **b, int rowSize, int columnSize)
{
     // print board
    cout << setw(17) << "GAMEBOARD\n";
    cout << setw(22) << "------------------\n";
   for(int row = 0; row < rowSize; row++)
   {
       for (int col = 0; col < columnSize; col++)
        cout << setw(5) << b[row][col];
       cout << endl;
   }
   cout << setw(22) << "------------------\n";
}
