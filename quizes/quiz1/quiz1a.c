/***********************************************************
 * Lab Quiz 1 - May 7th, 2012
 *
 * Name: Lonnie Bissmeyer
 * Professor: Julie Workman
 * ********************************************************/

#include <stdio.h>
#include <math.h>

double calcNumPizzas(int numKids, int numAdults);

int main(void)
{
   int kids, adults;
   double pizzaCost, numPizza, totalCost;

   printf("How many kids at the party: ");
   scanf("%d", &kids);
   printf("How many adults at the party: ");
   scanf("%d", &adults);
   printf("Cost of each pizza: ");
   scanf("%lf", &pizzaCost);
   numPizza = calcNumPizzas(kids, adults);
   totalCost = pizzaCost * numPizza;
   printf("\nYou need to order %.0f pizza(s).\n", numPizza);
   printf("This will cost $%.2f.\n", totalCost);

   return 0;
}

double calcNumPizzas(int numKids, int numAdults)
{
   double numPizzas, totalSlices;

   totalSlices = (numKids * 1) + (numAdults * 3);
   numPizzas = totalSlices/8;

   return ceil(numPizzas);
}


