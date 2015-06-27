/* 
 * timeCalc.c
 * <Your Name Here>
 * Converts time in seconds to days, hours, and minutes
 */
#include <stdio.h>

int main(void)
{
   /* Variable declarations */
   int milliseconds; /* input - number of milliseconds */
   int seconds; /* output - calculated number of seconds */
   int days;    /* output - calculated number of days */
   int hours;   /* output - calculated number of hours */
   int minutes; /* output - calculated number of minutes */

   /* Obtain input */
   printf("Enter number of milliseconds to convert: ");
   scanf("%d", &milliseconds);

   /* Calculate the number of seconds in this number of milliseconds */
   seconds = milliseconds / 1000;
   
   /* Calculate the number of minutes in this number of seconds */
   minutes = seconds / 60;
   seconds = seconds % 60;

   /* Calculate the number of hours in this number of seconds */
   hours = minutes / 60;
   minutes = minutes % 60;
   
   /* Calculate the number of days in this number of seconds */
   days = hours / 24;
   hours = hours % 24;
   
   /* Display output */
   printf("In %d milliseconds, there are:\n%d days, %d hours, %d minutes, and %d seconds\n", 
   milliseconds, days, hours, minutes, seconds);

   return 0;
}
