/*
   Lonnie Bissmeyer
   CPE 101-03
*/

#include <stdio.h>

int main(void)
{
   int num1, num2, result;
   printf("Enter a number: ");
   scanf("%d", &num1);
   printf("Enter another number: ");
   scanf("%d", &num2);

   result = num1 + num2;

   printf("%d + %d = %d\n", num1, num2, result);

   return 0;
}
