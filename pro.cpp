
#include<iostream>
#include<cstring>
using namespace std;


char square[3][3];
const char YOU = 'X';
const char COMPUTER = 'O';

void resetBoard();
void printBoard();
int checkFreeSpaces();
void YourMove();
void computerMove();
char checkWinner();
void printWinner(char);

int main()
{
   char winner = ' ';
   char temp[4];
   char p[4] ="yes";

   do
   {
      winner = ' ';
      resetBoard();

      while(winner == ' ' && checkFreeSpaces() != 0)
      {
         printBoard();

         YourMove();
         winner = checkWinner();
         if(winner != ' ' || checkFreeSpaces() == 0)
         {
            break;
         }

         computerMove();
         winner = checkWinner();
         if(winner != ' ' || checkFreeSpaces() == 0)
         {
            break;
         }
      }

      printBoard();
      printWinner(winner);
      cout<<endl<<"Would you like to play again? (yes/no): ";
      cin>>temp;
      
   } while (!strcmp(temp,p));

   cout<<"Thanks for playing game. Hope you enjoy it!";
   return 0;
}

void resetBoard()
{
   for(int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 3; j++)
      {
         square[i][j] = ' ';
      }
   }
}
void printBoard()
{  
   cout<<"   "<<square[0][0]<<"   |   "<<square[0][1]<<"   |   "<<square[0][2]<<endl;
   cout<<"_______|_______|_______"<<endl;
   cout<<"       |       |"<<endl;
   cout<<"   "<<square[1][0]<<"   |   "<<square[1][1]<<"   |   "<<square[1][2]<<endl;
   cout<<"_______|_______|______"<<endl;
   cout<<"       |       |"<<endl;
   cout<<"   "<<square[2][0]<<"   |   "<<square[2][1]<<"   |   "<<square[2][2]<<endl;
   
}
int checkFreeSpaces()
{
   int freeSpaces = 9;

   for(int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 3; j++)
      {
         if(square[i][j] != ' ')
         {
            freeSpaces--;
         }
      }
   }
   return freeSpaces;
}
void YourMove()
{
   int x;
   int y;

   do
   {
      cout<<"Enter row no. from(1-3): ";
      cin>>x;
      x--;
      cout<<"Enter column no. from(1-3): ";
      cin>>y;
      y--;

      if(square[x][y] != ' ')
      {
         cout<<"Invalid move!"<<endl;
      }
      else
      {
         square[x][y] = YOU;
         break;
      }
   } while (square[x][y] != ' ');
   
}
void computerMove()
{
  
   srand(time(0));
   int x;
   int y;

   if(checkFreeSpaces() > 0)
   {
      do
      {
         x = rand() % 3;
         y = rand() % 3;
      } while (square[x][y] != ' ');
      
      square[x][y] = COMPUTER;
   }
   else
   {
      printWinner(' ');
   }
}
char checkWinner()
{
   //check whether all the elements in a row are same
   for(int i = 0; i < 3; i++)
   {
      if(square[i][0] == square[i][1] && square[i][0] == square[i][2])
      {
         return square[i][0];
      }
   }
   //check whether all the elements in a column are same
   for(int i = 0; i < 3; i++)
   {
      if(square[0][i] == square[1][i] && square[0][i] == square[2][i])
      {
         return square[0][i];
      }
   }
   //check whether all the elements in a diagpnal are same
   if(square[0][0] == square[1][1] && square[0][0] == square[2][2])
   {
      return square[0][0];
   }
   if(square[0][2] == square[1][1] && square[0][2] == square[2][0])
   {
      return square[0][2];
   }

   return ' ';
}
void printWinner(char winner)
{
   if(winner == YOU)
   {
      cout<<"YOU HAVE WON THE GAME!";
   }
   else if(winner == COMPUTER)
   {
      cout<<"YOU HAVE LOST THE GAME!";
   }
   else{
      cout<<"IT'S A TIE!";
   }
}


