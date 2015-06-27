/*
* CPE 101 Lab6 Part 2
*
* Instructor: Julie Workman
*
* Name: Lonnie Bissmeyer
*/

#include <stdio.h>
#include <stdlib.h>

#define DIM 4
#define VOWELS 6

void makeBoard(char board[][DIM]);
void printBoard(char board[][DIM]);
int isValid(char board[][DIM]);

int main(void)
{
   char board[DIM][DIM], choice = 'y';
   int valid, seed;

   printf("Enter seed: ");
   scanf("%d", &seed);
   srand(seed);         

   while(choice == 'y')
   {
      makeBoard(board);
      valid = isValid(board);
      while(valid == -1)
      {
         makeBoard(board);
         valid = isValid(board);
      }
      printBoard(board);
      printf("Again (y/n)? ");
      scanf(" %c", &choice);
   }
   return 0;
}

void makeBoard(char board[DIM][DIM])
{
   int i, j;
  
   for(i = 0; i < DIM; i++)
   {
      for(j = 0; j < DIM; j++)
      {
         board[i][j] = rand() % 26 + 65;
      }
   }
}

void printBoard(char board[DIM][DIM])
{
   int i, j;

   for(i = 0; i < DIM; i++)
   {
      for(j = 0; j < DIM; j++)
      {
         printf("%c", board[i][j]);
      }
      printf("\n");
   }
}

int isValid(char board[DIM][DIM])
{
   int i, j, count = 0;

   for(i = 0; i < DIM; i++)
   {
      for(j = 0; j < DIM; j++)
      {
         if(board[i][j] == 'A' || board[i][j] == 'E' || board[i][j] == 'I' || board[i][j] == 'O' || board[i][j] == 'U')
         {
            count += 1;
         }
      }
   }
   if(count >= VOWELS)
   {
      return 0;
   }
   else
   {
      return -1;
   }
}
