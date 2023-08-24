#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;


const int SIZE = 5;
void populate(bool **b, int rowSize, int columnSize);
void initialize(bool **b, int rowSize, int columnSize);
void readFileData(bool **b, int rowSize, int columnSize);
void readFile(bool[][SIZE]);
void print(bool **b, int rowSize, int columnSize);


int main()
{
    cout <<fixed <<showpoint;
   bool **board;

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


  delete[] board;
  board = nullptr;

  return 0;

}

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
{  //note last to parameter variables are not needed here
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
   int row, col; //notice local variables used
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
}

void readFile(bool[][SIZE])
{
    //update and use this algorithm
}
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
