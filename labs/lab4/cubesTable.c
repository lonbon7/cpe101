/* CPE 101 Lab 4
   Lonnie Bissmeyer
*/
#include <stdio.h>
#include <math.h>

/* function prototypes */
int get_table_size();
int get_first();
int get_increment();
void show_table(int size, int first, int increment);

int main(void)
{
   int table_size;
   int first;
   int increment;
	  
   /* loop until sentinel is reached */
   table_size = get_table_size();
   while (table_size != 0)
   {
      first = get_first();
      increment = get_increment();
      show_table(table_size, first, increment);
      table_size = get_table_size();
   }
	return 0;
}

/* Obtain a valid table size from the user */
int get_table_size()
{
   int size;
   printf("Enter number of rows in table (0 to end): ");
   scanf("%d", &size);
   while (size < 0)
   {
      printf("Size must be non-negative.\n");
      printf("Enter number of rows in table (0 to end): ");
      scanf("%d", &size);
   }
   return size;
}

/* Obtain the first table entry from the user */
int get_first()
{
   int first;
   printf("Enter the value of the first number in the table: ");
   scanf("%d", &first);
   while (first < 0)
   {
      printf("You must enter a positive value.\n");
      printf("Enter the value of the first number in the table: ");
      scanf("%d", &first);
   }
   return first;
}

/* Display the table of cubes */
void show_table(int size, int first, int increment)
{
   int i, cube, sum = 0;

   printf("A cube table of size %d will appear here starting with %d.\n", 
    size, first);
   printf("Number  Cube\n");
   printf("%d       %d", first, (int)pow(first, 3));
   
   sum = sum + (int)pow(first, 3);   
   
   /* Insert counting loop here */ 
   for (i = 1; i < size; i++)
   {
      cube = (int)pow(first += increment, 3);
      printf("\n%d      %d", first, cube);  
      sum += cube;   
   }
   
printf("\n\nThe sum of cubes is: %d\n\n", sum);
}

int get_increment()
{
   int increment;

   printf("Enter the increment between rows: ");
   scanf("%d", &increment);
   while(increment < 0)
   {
      printf("Please enter a non-negative number: ");
      scanf("%d", &increment);
   }

   return increment;
}
