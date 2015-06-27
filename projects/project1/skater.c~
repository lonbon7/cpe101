/* Project 1

   Name: Lonnie Bissmeyer
   Instructor: J. Workman
   Section: 03
*/

#include <stdio.h>
#include <math.h>

#define GRAVITY 9.8
#define POUNDS_TO_KG 0.4536
#define PIE 1.0
#define TOMATO 0.1
#define ROCK 3.0

double getWeight(char letter);
double getVelObject(int distance);
double getVelSkater(int skater_weight, double object_weight, double object_velocity);

int main(void)
{
   double object_weight, skater_velocity, object_velocity;
   int distance, skater_weight;
   char letter;
   
   printf("How much do you weigh (pounds)? ");
   scanf("%d", &skater_weight);
   
   printf("How far away is your professor (meters)? ");
   scanf("%d", &distance);

   printf("Will you throw a rotten (t)omato, banana cream (p)ie, (r)ock, or (o)ther? ");
   scanf(" %c", &letter);
   
   object_velocity = getVelObject(distance);

   object_weight = getWeight(letter);
     
   printf("\nNice throw!  "); 

   if(object_weight <= 0.1)
   {
      printf("You're going to get an F!\n");
   }
   else if(object_weight > 0.1 && object_weight <= 1.0)
   {
      printf("Make sure your professor is OK.\n");
   }
   else if(object_weight > 1.0)
   {
      if(distance < 20)
      {
         printf("How far away is the hospital?\n");
      }
      else
      {
         printf("RIP professor.\n");
      }
   }
   
   skater_velocity = getVelSkater(skater_weight, object_weight, object_velocity);

   printf("Velocity of skater: %.3f m/s\n", skater_velocity);

   if(skater_velocity < 0.2)
   {
      printf("My grandmother skates faster than you!\n");
   }
   else if(skater_velocity >= 1.0)
   {
      printf("Look out for that railing!!!\n");
   }
   
   return 0;
}

double getWeight(char letter)
{
   double weight;  

   if(letter == 'p')
   {
      weight = PIE;
   }
   else if(letter == 't')
   {
      weight = TOMATO;
   }
   else if(letter == 'r')
   {
      weight = ROCK;
   }
   else if(letter == 'o')
   {
      printf("Enter the weight of the object in KG: ");
      scanf("%lf", &weight);
   }
   
   return weight;
}

double getVelObject(int distance)
{
   double object_velocity;

   object_velocity = sqrt((GRAVITY * distance)/2);

   return object_velocity;
}

double getVelSkater(int skater_weight, double object_weight, double object_velocity)
{
   double skater_velocity;
   double weight;   
   
   weight = skater_weight * POUNDS_TO_KG;

   skater_velocity = (object_weight * object_velocity)/weight;

   return skater_velocity;
}


