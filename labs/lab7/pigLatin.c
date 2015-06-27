#include <stdio.h>

/* You may NOT call any other string functions.
 * Do NOT include string.h */
/* Lonnie Bissmeyer */

void pigLatin(char w[]);

int main ()
{
   char word[10];

   printf("Word: ");
   scanf("%s", word);
   
   pigLatin(word);

   printf("Pig Latin Word: %s\n", word);

  return 0;
}

/* Change word to pig latin.
 * Input word will contain at least one character.
 * Don't worry about words that start with a vowel.
 */
void pigLatin(char w[])
{
   int i, tmpVar;

   tmpVar = w[0];
   for(i = 0; w[i] != '\0'; i++)
   {
      w[i] = w[i + 1];
   }
   w[i - 1] = tmpVar;
   w[i] = 'a';
   w[i + 1] = 'y';
   w[i + 2] = '\0';
}
