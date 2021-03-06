/***********************************************************
 * Lab Quiz 2 - June 25, 2012
 *
 * Name: Lonnie Bissmeyer
 * Professor: Julie Workman
 * ********************************************************/
#include <stdio.h>

int main()
{
   int numCans, numP, numR, numC, age, totalAge = 0, count = 0, array[10], i;
   double aveAge;
   char canType;

   printf("Enter the starting amount of cans: ");
   scanf("%d", &numCans);
   numP = numCans;
   numR = numCans;
   numC = numCans;   
   while(numP != 0 && numR != 0 && numC != 0)
   {
      printf("Would you like Pepsi, RC, or Coke (p, r, c)? ");
      scanf(" %c", &canType);
      while(canType != 'p' && canType != 'r' && canType != 'c')
      {
         printf("Invalid selection. Try again.\n");
         printf("Would you like Pepsi, RC, or Coke (p, r, c)? ");
         scanf(" %c", &canType);
      }
      if(canType == 'p')
      {
         numP -= 1;
         printf("How old are you? ");
         scanf("%d", &age);
         totalAge += age;
         array[count] = age;
         count += 1;
         
      }
      else if(canType == 'r')
      {
         numR -= 1;
      }
      else if(canType == 'c')
      {
         numC -= 1;
      }
   }
   aveAge = (double)totalAge/count;
   if(numP == 0)
   {
      printf("\nPepsi wins!\n\n");
   }
   else if(numR == 0)
   {
      printf("\nRC wins!\n\n");
   }
   else if(numC == 0)
   {
      printf("\nCoke wins!\n\n");
   }
   printf("Final count\nCoke: %d\nPepsi: %d\nRC: %d\n", numC, numP, numR);
   printf("\nAverage age of pepsi drinkers: %.1f\n", aveAge);
   printf("Ages: ");
   for(i = 0; i < count; i++)
   {
      printf("%d ", array[i]);
   }
   printf("\n");
   return 0;
}
