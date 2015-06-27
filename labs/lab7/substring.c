#include <stdio.h>

/* You may NOT call any other string functions.
 * Do NOT include string.h */
/* Lonnie Bissmeyer */
int hasSubstring(char w[], char sub[]);

int main ()
{
   char word[10], substring[10];

   printf("Word: ");
   scanf("%s", word);
   printf("Substring to search for: ");
   scanf("%s", substring);

   if (hasSubstring(word, substring))
   {
      printf("%s contains the substring %s.\n", word, substring);
   }
   else
   {
      printf("%s does NOT contain the substring %s.\n", word, substring);
   }

   return 0;
}

int hasSubstring(char w[], char sub[])
{
   int i, j = 0, lengthString = 0, lengthSub = 0, numTrue;

   for(i = 0; w[i] != '\0'; i++)
   {
      lengthString += 1;
   }
   
   for(i = 0; sub[i] != '\0'; i++)
   {
      lengthSub += 1;
   }

   for(i = 0; i < lengthString; i++)
   {      
      if(w[i] == sub[0])
      {
         numTrue = 0;
         for(j = 0; j < lengthSub; j++)
         {
            if(i + j < lengthString)
            {
               if(w[i + j] == sub[j])
               {
                  numTrue += 1;
               }
            }
            else
            {
               return 0;
            }
          }
          if(numTrue == lengthSub)
          {
             return 1;
          }
      }
   }
   
   return 0;            
}
