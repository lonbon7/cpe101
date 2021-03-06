#include <stdio.h>
/* You may NOT call any other string functions.
 * Do NOT include string.h */
/* Lonnie Bissmeyer */

void reverseWord(char w[]);

int main ()
{
   char word[10];

   printf("Word: ");
   scanf("%s", word);
   reverseWord(word);
   /*printf("%s\n", word);*/
   printf("Reversed: %s\n", word);

  return 0;
}

void reverseWord(char w[])
{
   int i, length = 0, tmpVar;

   for(i = 0; w[i] != '\0'; i++)
   {
      length += 1;      
   }
   
   for(i = 0; i < length/2; i++)
   {
      tmpVar = w[i];
      w[i] = w[length - i - 1]; 
      w[length - i - 1] = tmpVar;
   }
}
/* We have to subtract "i-1" so we       don't end up placing the null character at the beginning of the string and ruining everything.*/
