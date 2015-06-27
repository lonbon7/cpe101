/* Section 03 */
/* Lonnie Bissmeyer */

#include <stdio.h>
#include <math.h>

double distance(double x1, double x2, double y1, double y2);

int main(void)
{
   double x1, x2, y1, y2, result;
   
   printf("Enter x1: ");
   scanf("%lf", &x1);
   printf("Enter y1: ");
   scanf("%lf", &y1);
   printf("Enter x2: ");
   scanf("%lf", &x2);
   printf("Enter y2: ");
   scanf("%lf", &y2);

   result = distance(x1, x2, y1, y2);

   printf("The distance between (%.2f, %.2f) and (%.2f, %.2f) is %.2f\n", x1, y1, x2, y2, result);

   return 0;
}

double distance(double x1, double x2, double y1, double y2)
{
   double d;
   
   d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

   return d;
}
