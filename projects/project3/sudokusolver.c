/* CPE 101 Project 3
 *
 * Name: Lonnie Bissmeyer
 *
 * Instructor: Julie Workman
*/

#include <stdio.h>
#include "sudokusolver.h"

int main(void)
{
   int puzzle[9][9], row, col, solved, singleCanCount = 0, changed = 1, singleCanVal, numFail = 0, numBackTracks = 0, i, j, solveVal;

   readSudoku(puzzle);
   printf("\n\nInput puzzle:\n\n");
   printSudoku(puzzle);
   
   while (isSolved(puzzle) != 1 && changed == 1)
   {
      changed = 0;
      for(row = 0; row < 9; row++)
      {
         for(col = 0; col < 9; col++)
         {
            singleCanVal = singleCandidate(puzzle, row, col);
            if(singleCanVal == 1)
            {
               changed = 1;
               singleCanCount += 1;
            }
         }
      }
   }  
   solved = isSolved(puzzle);  
   if(solved == 1)
   {
      solveVal = 1;
   }
      
   bruteForce(puzzle, &numFail, &numBackTracks);

   solved = isSolved(puzzle);
   if(solved == -1)
   {
      printf("\nPuzzle is not solvable.\n");
   }   
   if(solved == 1 && solveVal != 1)
   {
      solveVal = 2;
   }
   if(solveVal == 2 && numBackTracks > 0)
   {
      solveVal = 3;
   }
   if(solveVal == 1)
   {
      printf("\nSolved by single candidate technique.\n");
   }
   else if(solveVal == 2)
   {
      printf("\nSolved by brute force with no backtracking.\n");
   }
   else if(solveVal == 3)
   {
      printf("\nSolved by brute force with backtracking.\n");
   }

   printf("Single candidates found: %d\n", singleCanCount);
   printf("Failed attempts: %d\n", numFail);
   printf("Backtracks: %d\n", numBackTracks);
   if(solved == 1)
   {
      printf("\nSolution:\n\n");
   
   
      for(i = 0; i < 9; i++)
      {
         for(j = 0; j < 9; j++)
         {
            printf("%d", puzzle[i][j]);
            if(j == 2 || j == 5)
            {
               printf(" | ");
            }
         }
         if(i == 2 || i == 5)
         {
            printf("\n---------------");
         }
         printf("\n");
      }
   } 

   return 0;
}

void printSudoku(int puzzle[][9])
{
   int i, j;
   
   for(i = 0; i < 9; i++)
   {
      for(j = 0; j < 9; j++)
      {
         printf("%d", puzzle[i][j]);
      }
      printf("\n");
   }
}

int isSolved(int puzzle[][9])
{
   int i, j;

   for(i = 0; i < 9; i++)
   {
      for(j = 0; j < 9; j++)
      {
         if(puzzle[i][j] == 0)
         {
            return -1;
         }
      }
   }
   return 1;
}

int singleCandidate(int puzzle[][9], int row, int col)
{
   int num, validNum, validCount = 0, tmpNum;  
   
   for(num = 1; num < 10; num++)
   {
      validNum = checkValid(puzzle, row, col, num);
      if(validNum == 1)
      {
         tmpNum = num;
         validCount += 1;         
      }
   }
   if(validCount == 1)
   {
      puzzle[row][col] = tmpNum;
      return 1;
   }
   return 0;      
}

void bruteForce(int puzzle[][9], int *attempts, int *backTracks)
{
   int i, j, temp, validNum, num, backtrack[9][9];
   
   for(i = 0; i < 9; i++)
   {
      for(j = 0; j < 9; j++)
      {
         backtrack[i][j] = puzzle[i][j];
      }
   }
   for(i = 0; i < 9; i++)
   {
      for(j = 0; j < 9; j++)
      {
         if(backtrack[i][j] == 0)
         {
            temp = puzzle[i][j] + 1;
            puzzle[i][j] = 0;
            for(num = temp; num < 10; num++)
            {
               validNum = checkValid(puzzle, i, j, num);
               if(validNum == 1)
               {
                  puzzle[i][j] = num;
                  break;
               }
               else
               {
                  *attempts += 1;
               }
            }
               if(num == 10)
               {  
                  *backTracks += 1;
                  j--;
                  if(j < 0)
                  {
                     i--;
                     j = 8;
                  }
                  while(backtrack[i][j] != 0 && i >= 0)
                  {
                     j--;
                     if(j < 0)
                     {
                        i--;
                        j = 8;
                     }
                  }
                  if(i < 0)
                  {
                     return;
                  }
                  j--;
                  if(j < 0)
                  {
                     i--;
                     j = 8;
                  }                  
               }
         }
      }
   }     
}
