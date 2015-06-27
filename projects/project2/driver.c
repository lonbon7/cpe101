/**
 * Moonlander function driver program.
 *
 * The purpose of this program is to test the functions in landerFuncs.c.
 * I have partially implemented some test cases for you.  Implement many
 * more test cases!  (And flesh out the test cases that I have given you.)
 */

#include "landerFuncs.h"
#include <stdio.h>

#define GRAVITY 1.62

int testGetFuel();
void testUpdateVelocity();
int compareDoubles(double d1, double d2, double epsilon);
void testGetAltitude();
int testGetFuelRate(int currentFuel);
void testDisplayLMState(int elapsedTime, double altitude, double velocity, int fuelAmount, int fuelRate);

int main()
{
   int currentFuel = testGetFuel();
   printf("\n");
   testUpdateVelocity();
   printf("\n");
   testGetAltitude();
   printf("\n");
   testGetFuelRate(currentFuel);
   printf("\n");
   
  
   return 0;
}

/*void testDisplayLMState(int elapsedTime, double altitude, double velocity, int fuelAmount, int fuelRate)
{
   
   
   printf("Testing Display LMS state:\n");
   printf("Inputting numbers: 1, 2.0, 3.0, 4, 5");
   displayLMState(1, 2.0, 3.0, 4, 5);
   
}*/

int testGetFuelRate(int currentFuel)
{
   int fuelRate;

   printf("***Testing getFuelRate...***\n\n");

   printf("TEST 1: When prompted, input a number between 0 and 9, inclusive. You should not see an error.\n\n");
   fuelRate = getFuelRate(currentFuel);
   printf("\nFule rate returned was: %d\n", fuelRate);
   
   printf("\nTEST 2: When prompted, input a number less than 0. You should see an error and then be prompted again.\n");
   printf("Then enter a number greater than 9. You should see the same error message and be prompted again.\n");
   printf("\nFinally, eter a number between 0 and 9, inclusive.\n");
   fuelRate = getFuelRate(currentFuel);
   printf("\nFuel rate returned was: %d\n", fuelRate);
   
   return fuelRate;
}

void testGetAltitude()
{
   int altitude;
   
   printf("***Testing getAltitude... ***\n\n");

   printf("TEST 1: When prompted, input a number between 1 and 9999, inclusive. You should not see an error.\n\n");
   altitude = getAltitude();
   printf("\nAltitude returned was: %d\n", altitude);

   printf("\nTEST 2: When prompted, input a number less than 1. You should see an error and then be prompted again.\n");
   printf("Then enter a number greater than 9999. You should see the same error message and be prompted again.\n");
   printf("\nFinally, enter a number between 1 and 9999, inclusive.\n");
   altitude = getAltitude();
   printf("\nAltitude returned was: %d\n", altitude);
}   

int testGetFuel()
{
   int fuel;

   printf("*** Testing getFuel... ***\n\n");

   /* Test 1: Enter a valid number */
   printf("TEST 1: When prompted, input a number greater than 0.  You should not see an error.\n\n");
   fuel = getFuel();
   printf("\nFuel returned was: %d\n", fuel);

   /* Test 2: First enter 0, then a negative number, then a valid number */
   printf("\nTEST 2: When prompted, input 0.  You should see an error and then be prompted again.\n");
   printf("Then enter a negative number.  You should see the same error message and be \n");
   printf("prompted again.  Finally, enter a number greater than 0.\n\n");
   fuel = getFuel();
   printf("\nFuel returned was: %d\n", fuel);

   return fuel;
}

void testUpdateVelocity()
{
   double velocity;

   printf("*** Testing updateVelocity... ***\n\n");
   
   /* Test 1: -1.0 and -0.5 */
   printf("TEST 1: Inputing -1 and -0.5\n");
   velocity = updateVelocity(-1.0, -0.5);
   printf("      Expect: %f\n", -1.5);
   printf("      Got: %f\n", velocity);
   /* Compare to see if output velocity and the expected are equal.
    * See the description of the compareDoubles function below. */
   if (compareDoubles(velocity, -1.5, .000001))
   {
      printf("      Pass\n");
   }
   else
   {
      printf("      FAIL\n");
   }

   /* Test 2: 0.0 and 0.0 */
   printf("TEST 2: Inputing 0.0 and 0.0\n");
   velocity = updateVelocity(0.0, 0.0);
   printf("      Expect: %f\n", 0.0);
   printf("      Got: %f\n", velocity);
   if (compareDoubles(velocity, 0.0, .000001))
   {
      printf("      Pass\n");
   }
   else
   {
      printf("      FAIL\n");
   }

   /* Test 3: -100.23 and 1.1 */
   printf("TEST 3: Inputing -100.23 and 1.1\n");
   velocity = updateVelocity(-100.23, 1.1);
   printf("      Expect: %f\n", -99.13);
   printf("      Got: %f\n", velocity);
   if (compareDoubles(velocity, -99.13, .000001))
   {
      printf("      Pass\n");
   }
   else
   {
      printf("      FAIL\n");
   }
}

/* You cannot compare two doubles using == because they are not stored exactly.
 * Use this function to compare doubles to see if they are equivalent to a certain
 * "close enough" epsilon.
 * 
 * For example to compare two doubles (x and y) and see if there are equivalent to
 * 0.000001, you would call the function like this: 
 * compareDoubles(x, y, 0.000001);
 *
 * Return Value: 0 or 1 (a boolean value)
 */
int compareDoubles(double d1, double d2, double epsilon)
{
   return (d1-d2 > -epsilon && d1-d2 < epsilon);
}
   

