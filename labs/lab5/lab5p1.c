/*
 * CPE 101 Lab 5 Part 1
 *
 * Name : Lonnie Bissmeyer
 *
 * Instructor: Julie Workman
*/ 

#include <stdio.h>

#define SIZE 35

int getValues(int grades[]);
void printValues(int grades[], int len);

int main(void)
{
   int sum = 0;

   int grades[SIZE];
   sum = getValues(grades);   
   printf("\nNumber of scores entered: %d\n", sum);
   printValues(grades, sum);
   
   return 0;
}

int getValues(int grades[])
{
   int i = 0, score = 0, sum = 0;
  
   while(score != -1 && i < SIZE)
   {
      printf("Enter test score  %d: ", i + 1);
      scanf("%d", &score);
      grades[i] = score;
      i++;
      if(score != -1)
      {
         sum += 1;
      }
   }
  return sum;   
}

void printValues(int grades[], int len)
{
   int i;
   
   printf("Test scores entered     :");
   for(i = 0; i < len; i++)
   {
      printf(" %d", grades[i]);
   }
   printf(" \n");
}
