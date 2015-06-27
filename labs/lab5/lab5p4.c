/* 
 * CPE 101 Lab 5 Part 4
 *
 * Instructor: Julie Workman
 *
 * Name: Lonnie Bissmeyer
*/

#include <stdio.h>

#define SIZE 5

int main(void)
{
   int i, j;

   for(i = 0; i < SIZE; i++)
   {
      for(j = 0; j < SIZE; j++)
      {
         if(i > j)
         {
            printf(" ");
         }
         else
         {
            printf("%d", i + j);
         }
      }
      printf("\n");
   }

   return 0;
}
