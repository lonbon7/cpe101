/*
 * CPE 101 Lab 5 Part 3
 *
 * Name: Lonnie Bissmeyer
 *
 * Instructor: Julie Workman
*/ 

#include <stdio.h>

#define SIZE 35

int getValues(int grades[]);
void printValues(int grades[], int len);
double average(int grades[], int sum);
int search( int nums[], int numScores, int num);

int main(void)
{
   int sum = 0, num, index, grades[SIZE];
   double averageNums;

   sum = getValues(grades);   
   printf("Enter test score to search for: ");
   scanf("%d", &num);
   printf("\nNumber of scores entered: %d\n", sum);
   printValues(grades, sum);
   index = search(grades, sum, num);
   averageNums = average(grades, sum);
   printf("Average test score      : %.1f", averageNums);
   
   if(index != -1)
   {
      printf("\nThe score %d first occurs at index %d.\n", num, index);
   }
   else
   {
      printf("\nThe score %d does not occur in the array.\n", num);
   }
   
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

double average(int grades[], int numScores)
{
   int sum = 0, i;
   double average;

   for(i = 0; i < numScores; i++)
   {
      sum += grades[i];
   }
   average = (double)sum/numScores;

   return average;
}

int search(int nums[], int numScores, int num)
{
   int i = 0;

   while(i < numScores)
   {
      if(nums[i] == num)
      {
         return i;
      }
      i++;
   }
   return -1;
}
