/* 
*  CPE 101 Lab 4 Part 3
*  Name: Lonnie Bissmeyer
*  Instructor: Julie Workman 
*/

#include <stdio.h>

int getList(int num_x);
int getNumber(void);
void displayMessage(int occurrences, int num);

int main(void)
{  
   int num = getNumber();
   displayMessage(getList(num), num);
   
   return 0;
}

void displayMessage(int occurrences, int num)
{
   if(occurrences == 0)
   {
      printf("This list contains no occurrences of %d.\n", num);
   }
   else if(occurrences > 10)
   {
      printf("Wow, that's a lot!\n");
   }
   else if(occurrences >= 1  && occurrences <= 5)
   {
      printf("Not too many in this list.\n");
   }
   else if(occurrences >= 6 && occurrences <= 10)
   {
      printf("Quite a few were found!\n");
   }
}

int getNumber(void)
{
   int num;

   printf("Enter a number to find: ");
   scanf("%d", &num);
   while(num < 0)
   {
      printf("Please enter a positive number: ");
      scanf("%d", &num);
   }
   return num;
}
   
int getList(int num_x)
{
   int num, total, first = 0, last, occurrences = 0;
   printf("Enter a list of numbers (negative to quit): ");
   scanf("%d", &num);
   total = 1;
   while(num > 0)
   {
      scanf("%d", &num);
      if(num > 1)
      {
         total += 1;
      }
      if( num == num_x)
      {
         last = total;
         if(first == 0)
         {
            first = total;
         }
         occurrences += 1;
      }      
   }
   printf("\nThis list contains %d numbers.\n", total);
   printf("First occurrence of '%d': %d\n", num_x, first);
   printf("Last occurrence of '%d': %d\n", num_x, last);
   
   return occurrences;
}
