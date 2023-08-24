#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
   int **board;

   int rows, columns;

   cout << "Let us fill a 2D Board for an upcoming game of numbers\n";
   cout << "\nEnter the number of rows for the board: "; cin >> rows;
   cout << "Enter the number of columns for the board: "; 
   cin >> columns;
   cout << endl;

   //create the rows of board
   board = new int*[rows];

   //Create the columns of board
   for(int row = 0; row < rows; row++)
    board [row]= new int [columns];

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


  return 0;

}
