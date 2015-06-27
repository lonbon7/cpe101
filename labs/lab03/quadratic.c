/* Section 03 */
/* Lonnie Bissmeyer */

#include <stdio.h>
#include <math.h>

double quadratic(double a, double b, double c);
double getDouble(char letter);

int main(void)
{
   double a, b, c, x;  
  
   a = getDouble('a');
   b = getDouble('b');
   c = getDouble('c');

   x = quadratic(a, b, c);

   printf("One x-value for this equation is %.3f\n", x);

   a = getDouble('a');
   b = getDouble('b');
   c = getDouble('c');

   x = quadratic(a, b, c);

   printf("One x-value for this equation is %.3f\n", x);

   a = getDouble('a');
   b = getDouble('b');
   c = getDouble('c');

   x = quadratic(a, b, c);

   printf("One x-value for this equation is %.3f\n", x);

   return 0;
}

double quadratic(double a, double b, double c)
{
   double x;

   x = ((-b + sqrt((b * b) - (4 * a * c)))/(2 * a));
   
   return (x);
}

double getDouble(char letter)
{
      double var;
       
       printf("Enter value %c: ", letter );
       scanf("%lf", &var);

      return var;
}
       
   
