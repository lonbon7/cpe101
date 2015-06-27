/*
 * CPE 101 Project 2 Part 2
 *
 * Name: Lonnie Bissmeyer
 *
 * Instructor: Julie Workman
*/

#include <stdio.h>
#include "landerFuncs.h"

#define GRAVITY 1.62

int main(void)
{
   int fuelAmount, fuelRate = 0, elapsedTime = 0;
   double altitude, velocity = 0, acceleration;

   showWelcome();
   altitude = getAltitude();
   fuelAmount = getFuel();
   printf("\nLM state at retrorocket cutoff\n");
   displayLMState(elapsedTime, altitude, velocity, fuelAmount, fuelRate); 
   while(altitude > 0)
   {
      elapsedTime += 1;
      fuelRate =  getFuelRate(fuelAmount);
      acceleration = updateAcceleration(GRAVITY, fuelRate); 
      altitude = updateAltitude(altitude, velocity, acceleration);   
      velocity = updateVelocity(velocity, acceleration);
      fuelAmount = updateFuel(fuelAmount, fuelRate);
      while(fuelAmount == 0)
      {
         printf("OUT OF FUEL - Elapsed Time:%4d Altitude:%8.2f Velocity:%8.2f\n", elapsedTime, altitude, velocity);
         elapsedTime += 1;
         fuelRate = 0;
         acceleration = updateAcceleration(GRAVITY, fuelRate); 
         altitude = updateAltitude(altitude, velocity, acceleration);   
         velocity = updateVelocity(velocity, acceleration);
         if(altitude == 0)
         {
             printf("\nLM state at landing/impact\n");
            displayLMState(elapsedTime, altitude, velocity, fuelAmount, fuelRate);
            displayLMLandingStatus(velocity);      
            return 0;  
         }
      }
      if(altitude == 0)
      {
      printf("\nLM state at landing/impact\n");
      displayLMState(elapsedTime, altitude, velocity, fuelAmount, fuelRate);
      displayLMLandingStatus(velocity);      
      return 0;
      }
      displayLMState(elapsedTime, altitude, velocity, fuelAmount, fuelRate);   
   }
   return 0;
}

