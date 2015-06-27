/* Section 03 */
/* Lonnie Bissmeyer */

#include <stdio.h>
#include <math.h>

double quadratic(double a, double b, double c, char d);
double getDouble(char letter);

int main(void)
{
   double a, b, c, added, subtracted;  
  
   a = getDouble('a');
   b = getDouble('b');
   c = getDouble('c');

   if((b * b) - (4 * a * c) >= 0)
   {
      added = quadratic(a, b, c, 'a');
      subtracted = quadratic(a, b, c, 's');   
      printf("The x-values for this equation are %.3f and %.3f\n", added, subtracted);
   }
   else 
   {
      printf("This equation has complex roots\n");
   }
   
   a = getDouble('a');
   b = getDouble('b');
   c = getDouble('c');

   if((b * b) - (4 * a * c) >= 0)
   {
      added = quadratic(a, b, c, 'a');
      subtracted = quadratic(a, b, c, 's');   
      printf("The x-values for this equation are %.3f and %.3f\n", added, subtracted);
   }
   else 
   {
      printf("This equation has complex roots\n");
   }

   a = getDouble('a');
   b = getDouble('b');
   c = getDouble('c');

   if((b * b) - (4 * a * c) >= 0)
   {
      added = quadratic(a, b, c, 'a');
      subtracted = quadratic(a, b, c, 's');   
      printf("The x-values for this equation are %.3f and %.3f\n", added, subtracted);
   }
   else 
   {
      printf("This equation has complex roots\n");
   }
  
   return 0;
}

double quadratic(double a, double b, double c, char d)
{
   double x;

   if(d == 'a')
   {
      x = ((-b + sqrt((b * b) - (4 * a * c)))/(2 * a));      
   }
   else
   {
      x = ((-b - sqrt((b * b) - (4 * a * c)))/(2 * a));      
   }
   
   return x;
}

double getDouble(char letter)
{
      double var;
       
       printf("Enter value %c: ", letter );
       scanf("%lf", &var);

      return var;
}
       
   
