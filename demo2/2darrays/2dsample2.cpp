#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

void populate(int **b, int rowSize, int columnSize);
void readFileData(int **b, int rowSize, int columnSize);
void print(int **b, int rowSize, int columnSize);

int main()
{
   int **board;

   int rows, columns;

   cout << "Let us fill a 2D Board for an upcoming game of numbers\n";
   cout << "\nEnter the number of rows for the board: "; cin >> rows;
   cout << "Enter the number of columns for the board: "; cin >> columns;
   cout << endl;

   //create the rows of board
   board = new int*[rows];

   //Create the columns of board
   for(int row = 0; row < rows; row++)
    board [row]= new int [columns];

  // populate(board, rows, columns);
   readFileData(board, rows, columns);
   print(board, rows, columns);


/*
   // fill board
   for(int row = 0; row < rows; row++)
   {
       cout << "Enter " << columns << " number(s) for row "
           << " number " << row+1 << ": "<< endl;
       for (int col = 0; col < columns; col++)
        cin >> board[row][col];
       cout << endl;
   }


    // print board
    cout << setw(17) << "GAMEBOARD\n";
    cout << setw(22) << "------------------\n";
   for(int row = 0; row < rows; row++)
   {
       for (int col = 0; col < columns; col++)
        cout << setw(5) << board[row][col];
       cout << endl;
   }
   cout << setw(22) << "------------------\n";
*/

  delete[] board;
  board = nullptr;

  return 0;

}


void populate(int **b, int rowSize, int columnSize)
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

void readFileData(int **b, int rowSize, int columnSize)
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

     // fill board
   for(int row = 0; row < rowSize; row++)
   {
       for (int col = 0; col < columnSize; col++)
        in >> b[row][col];
   }
}
void print(int **b, int rowSize, int columnSize)
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
