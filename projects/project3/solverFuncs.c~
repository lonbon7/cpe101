/*
 * CPE 101 Project 3
 * 
 * Name: Lonnie Bissmeyer
 *
 * Instructor: Julie Workman
*/

#include <stdio.h>
#include "sudokusolver.h"

void readSudoku(int puzzle[][9])
{
   int i, j;
   
   for(i = 0; i < 9; i++)
   {
      printf("Enter line %d: ", i +1);
      for(j = 0; j < 9; j++)
      {
         scanf("%1d", &puzzle[i][j]);
      }
   }
}

int checkValid(int puzzle[][9], int row, int col, int num)
{
   int i, j, tmpI, tmpJ, tmpSizeI, tmpSizeJ;

   if(puzzle[row][col] != 0)
   {
      return -1;
   }
   for(j = 0; j < 9; j++)
   {
      if(puzzle[row][j] == num)
      {
         return 0;
      }
   }
   for(i = 0; i < 9; i++)
   {
      if(puzzle[i][col] == num)
      {
         return 0;
      }
   }
   tmpI = (row/3) * 3;
   tmpJ = (col/3) * 3;
   tmpSizeI = tmpI + 3;
   tmpSizeJ = tmpJ + 3;
   for(i = tmpI; i < tmpSizeI; i++)
   {
      for(j = tmpJ; j < tmpSizeJ; j++)
      {
         if(puzzle[i][j] == num)
         {
            return 0;
         }
      }
   }
   return 1;
}
