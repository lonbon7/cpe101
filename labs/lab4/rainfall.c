/* Compute the sum of a list of rainfall measurements. */

#include <stdio.h>

#define SENTINEL 0

int main(void)
{
   int rainfall;   /* input - current rainfall */
   int sum = 0;    /* output - sum of rainfalls input so far */
   int count = 0;
   double average;

   /* Accumulate sum of all rainfalls. */
   printf("Enter first rainfall (or enter a negative number to quit): ");
   scanf("%d", &rainfall);   /* Get first rainfall. */
   
   if(rainfall >= 0)
   { 
      while (rainfall >= SENTINEL)
      {
         sum = sum + rainfall;
         count += 1;      
         printf("Enter next rainfall (or enter a negative number to quit): ");
         scanf("%d", &rainfall);   /* Get next rainfall. */
      }
      
      if(sum > 0)
      {   
         printf("\nSum of rainfall measurements is %d\n", sum);
         printf("The number of rainfall measurements is %d\n", count);
         average = (double)sum/count;
         printf("The average rainfall is %.2f\n", average);
      }
      else
      {
         printf("There is no rainfall.\n");
      }
   }
   else
   {
      printf("There is no rainfall.\n");
   } 
   
   return 0;
}
