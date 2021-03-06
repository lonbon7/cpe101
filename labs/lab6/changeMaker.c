/* CPE 101 Lab 6 Part1
*
*  Instructor: Julie Workman
*
*  Name: Lonnie Bissmeyer
*/

#include <stdio.h>

int bills(double paid, double price, int *twenties, int *tens, int *fives, int *ones);
void coins(int change, int *quarters, int *dimes, int *nickels, int *pennies);

int main(void)
{
   double price, paid;
   int denomination, numDenom, twenties, tens, fives, ones, quarters, dimes, nickels, pennies, change;
   
   printf("Enter amount due for merchandise: ");
   scanf("%lf", &price);
   printf("Enter denomination of bills used for payment: ");
   scanf("%d", &denomination);
   while(denomination != 1 && denomination != 5 && denomination != 10 && denomination != 20)
   {
      printf("Enter denomination of bills used for payment: ");
      scanf("%d", &denomination);
   }
   printf("Enter number of bills of this denomination: ");
   scanf("%d", &numDenom);
  
   paid = denomination * numDenom;
   while(paid < price)
   {
      printf("Your payment is insufficient!\n");
      printf("Enter denomination of bills used for payment: ");
      scanf("%d", &denomination);
      while(denomination != 1 && denomination != 5 && denomination != 10 && denomination != 20)
      {
         printf("Enter denomination of bills used for payment: ");
         scanf("%d", &denomination);
      }
      printf("Enter number of bills of this denomination: ");
      scanf("%d", &numDenom);
      paid = denomination * numDenom;
   }
   change = bills(paid, price, &twenties, &tens, &fives, &ones);
   coins(change, &quarters, &dimes, &nickels, &pennies);
   
   printf("\nChange should be\n");
   if(twenties > 0)
   {
      printf("%d 20 dollar bill(s)\n", twenties);
   }
   if(tens > 0)
   {
      printf("%d 10 dollar bill(s)\n", tens);
   }
   if(fives > 0)
   {
      printf("%d 5 dollar bill(s)\n", fives);
   }
   if(ones > 0)
   {
      printf("%d 1 dollar bill(s)\n", ones);
   }
   if(quarters > 0)
   {
      printf("%d quarters\n", quarters);
   }
   if(dimes > 0)
   {
      printf("%d dimes\n", dimes);
   }
   if(nickels > 0)
   {
      printf("%d nickels\n", nickels);
   }
   if(pennies > 0)
   {
      printf("%d pennies\n", pennies);
   }
   return 0;
}

int bills(double paid, double price, int *twenties, int *tens, int *fives, int *ones)
{
   int total = (paid - price + .00000001) * 100;

   *twenties = total/2000;
   total %= 2000;
   *tens = total/1000;
   total %= 1000;
   *fives = total/500;
   total %= 500;
   *ones = total/100;
   total %= 100;
   
   return total;
}

void coins(int change, int *quarters, int *dimes, int *nickels, int *pennies)
{
   *quarters = change/25;
   change %= 25;
   *dimes = change/10;
   change %= 10;
   *nickels = change/5;
   change %= 5;
   *pennies = change;
}
