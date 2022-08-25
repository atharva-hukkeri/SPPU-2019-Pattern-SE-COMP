#include <iostream>
using namespace std;
 
const int ROWS = 3;
const int COLS = 3;

void displayBoard(char [][COLS]);
void playerTurn(char [][COLS], char);
bool gameOver(char [][COLS]);
bool playerWins(char [][COLS], char);
bool playerCanWin(char [][COLS], char);
void displayWinner(char [][COLS]);
 
int main()
{
   char gameBoard[ROWS][COLS] = { '*', '*', '*',
                                  '*', '*', '*',
                                  '*', '*', '*'
                                 };
    
   do
   {
      displayBoard(gameBoard);
      playerTurn(gameBoard, 'X');
      displayBoard(gameBoard);
      if (!gameOver(gameBoard))
         playerTurn(gameBoard, 'O');
          
   } while (!gameOver(gameBoard));
   displayBoard(gameBoard);
   displayWinner(gameBoard);
 
   return 0;
}

void displayBoard(char board[][COLS])
{
   cout << "       Columns\n";
   cout << "        1 2 3\n";
   for (int row = 0; row < ROWS; row++)
   {
      cout << "Row " << (row + 1)<< ":  ";
      for (int col = 0; col < COLS; col++)
      {
         cout << board[row][col] << " ";
      }
      cout << endl;
   }
}

void playerTurn(char board[][COLS], char symbol)
{
   bool isAvailable = false;
   int row; 
   int col;  
   cout << "Player " << symbol << "'s turn.\n";
   cout << "Enter a row and column to place an "
        << symbol << ".\n";
   while (!isAvailable)
   {
      cout << "Row: "; cin >> row;
      while (row < 1 || row > ROWS)
      {
         cout << "Invalid Row!\n";
         cout << "Row: "; cin >> row;
      }
      cout << "Column: "; cin >> col;
      while (col < 1 || col > COLS)
      {
         cout << "Invalid Column!\n";
         cout << "Column: "; cin >> col;
      }
      if (board[row - 1][col - 1] == '*')
         isAvailable = true;
      else
      {
         cout << "That location is not available. "
              << "Select another location.\n";
      }
   }
   board[row - 1][col - 1] = symbol;
}

bool gameOver(char board[][COLS])
{
   if (playerWins(board, 'X') || playerWins(board, 'O'))
      return true;
   else if (playerCanWin(board, 'X') || playerCanWin(board, 'O'))
      return false;
   else
      return true;
}
 
bool playerWins(char board[][COLS], char symbol)
{
   if (board[0][0] == symbol && board[0][1] == symbol &&
       board[0][2] == symbol)
      return true;
   if (board[1][0] == symbol && board[1][1] == symbol && 
       board[1][2] == symbol)
      return true;
   if (board[2][0] == symbol && board[2][1] == symbol && 
       board[2][2] == symbol)
      return true;
   if (board[0][0] == symbol && board[1][0] == symbol && 
       board[2][0] == symbol)
      return true;
   if (board[0][1] == symbol && board[1][1] == symbol && 
       board[2][1] == symbol)
      return true;
   if (board[0][2] == symbol && board[1][2] == symbol && 
       board[2][2] == symbol)
      return true;
   if (board[0][0] == symbol && board[1][1] == symbol && 
       board[2][2] == symbol)
      return true;
   return false;
}
 
bool playerCanWin(char board[][COLS], char symbol)
{
   if ((board[0][0] == symbol || board[0][0] == '*') && 
       (board[0][1] == symbol || board[0][1] == '*') &&
       (board[0][2] == symbol || board[0][2] == '*'))
      return true;
   if ((board[1][0] == symbol || board[1][0] == '*') && 
       (board[1][1] == symbol || board[1][1] == '*') &&
       (board[1][2] == symbol || board[1][2] == '*'))
      return true;
   if ((board[2][0] == symbol || board[2][0] == '*') && 
       (board[2][1] == symbol || board[2][1] == '*') &&
       (board[2][2] == symbol || board[2][2] == '*'))
      return true;
   if ((board[0][0] == symbol || board[0][0] == '*') && 
       (board[1][0] == symbol || board[1][0] == '*') &&
       (board[2][0] == symbol || board[2][0] == '*'))
      return true;
   if ((board[0][1] == symbol || board[0][1] == '*') && 
       (board[1][1] == symbol || board[1][1] == '*') &&
       (board[2][1] == symbol || board[2][1] == '*'))
      return true;
   if ((board[0][2] == symbol || board[0][2] == '*') && 
       (board[1][2] == symbol || board[1][2] == '*') &&
       (board[2][2] == symbol || board[2][2] == '*'))
      return true;
   if ((board[0][0] == symbol || board[0][0] == '*') && 
       (board[1][1] == symbol || board[1][1] == '*') &&
       (board[2][2] == symbol || board[2][2] == '*'))
      return true;
   return false;
}

void displayWinner(char board[][COLS])
{
   if (playerWins(board, 'X'))
      cout << "Player 1 (X) WINS!!!!!\n\n";
   else if (playerWins(board, 'O'))
      cout << "Player 2 (O) WINS!!!!!\n\n";
   else
      cout << "Game Over... it's a TIE.\n\n";
}