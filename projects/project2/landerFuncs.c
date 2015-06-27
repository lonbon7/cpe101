/*
 * CPE 101 Project 2
 * 
 * Name: Lonnie Bissmeyer
 * 
 * Instructor: Julie Workman
 */
#include <stdio.h>

void showWelcome()
{
   printf("\nWelcome aboard the Lunar Module Flight Simulator\n\n   To begin you must specify the LM's initial altitude\n   and fuel level.  To simulate the actual LM use     \n   values of 1300 meters and 500 liters, respectively.\n\n   Good luck and may the force be with you!\n\n");
}

int getFuel()
{
   int fuel;
   
   printf("Enter the initial amount of fuel on board the LM (in liters): ");
   scanf("%d", &fuel);
   while(fuel <= 0)
   {
      printf("ERROR: Amount of fuel must be positive, please try again\n");
      printf("Enter the initial amount of fuel on board the LM (in liters): ");
      scanf("%d", &fuel);
   }
   return fuel;
}

int getAltitude()
{
   int altitude;

   printf("Enter the initial altitude of the LM (in meters): ");
   scanf("%d", &altitude);
   while(altitude < 1 || altitude > 9999)
   {
      printf("ERROR: Altitude must be between 1 and 9999, inclusive, please try again\n");
      printf("Enter the initial altitude of the LM (in meters): ");
      scanf("%d", &altitude);
   }
   return altitude;      
}

void displayLMState(int elapsedTime, double altitude, double velocity, int fuelAmount, int fuelRate)
{
   printf("Elapsed Time:%5d s\n", elapsedTime);
   printf("        Fuel:%5d l\n", fuelAmount);
   printf("        Rate:%5d l/s\n", fuelRate);
   printf("    Altitude:%8.2f m\n", altitude);
   printf("    Velocity:%8.2f m/s\n\n", velocity);
}

int getFuelRate(int currentFuel)
{
   int fuelRate;
   
   printf("Enter fuel rate (0-9, 0=freefall, 5=constant velocity, 9=max thrust): ");
   scanf("%d", &fuelRate);
   while(fuelRate < 0 || fuelRate > 9)
   {
      printf("ERROR: Fuel rate must be between 0 and 9, inclusive\n\n");
      printf("Enter fuel rate (0-9, 0=freefall, 5=constant velocity, 9=max thrust): ");
      scanf("%d", &fuelRate);
   }
   
   if(fuelRate < currentFuel)
   {
      return fuelRate;
   }
   else
   {
      return currentFuel;
   }
}   

double updateAcceleration(double gravity, int fuelRate)
{
   double acceleration;

   acceleration = gravity * (double)((fuelRate/5.0) -1);
   
   return acceleration;
}
   
double updateAltitude(double altitude, double velocity, double acceleration)
{
   double newAltitude;

   newAltitude = altitude + velocity + ((double)acceleration/2.0);
   if(newAltitude < 0)
   {
      return newAltitude = 0;
   }
   
   return newAltitude;   
}

double updateVelocity(double velocity, double acceleration)
{
   double newVelocity;

   newVelocity = velocity + acceleration;

   return newVelocity;
}

int updateFuel(int fuel, int fuelRate)
{
   int newFuel;

   newFuel = fuel - fuelRate;

   return newFuel;
}

void displayLMLandingStatus(double velocity)
{
   if(velocity <= 0 && velocity >= -1)
   {
      printf("Status at landing - The eagle has landed!\n");
   }
   else if(velocity < -1 && velocity > -10)
   {
      printf("Status at landing - Enjoy your oxygen while it lasts!\n");
   }
   else if(velocity <= -10)
   {
      printf("Status at landing - Ouch - that hurt!\n");
   }
}
