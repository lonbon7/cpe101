/* MASTERMIND
 *
 * Authors: Lonnie Bissmeyer
 * Instructor: Workman
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_DIM 6
#define MIN_DIM 3
#define MAX_GUESSES 12
#define MAXCHAR 'F'

typedef struct
{
   char letters[MAX_DIM];
   int exact;
   int inexact;
} Guess;

/* This function already implemented.
 * Compile with "gcc -Wall -ansi -pedantic mastermind.c util.o" to use it.
 * Otherwise, implement the function yourself and just compile with "gcc -Wall -ansi -pedantic  mastermind.c"
 */
int calcMatches(char answer[], int dim, Guess guess[], int index);

/* Prototypes for functions you must implement */
char getRandChar(char maxchar);
void getGuess(char letters[], int dim, char maxChar);
void printBoard(Guess guesses[], int tries, int dim);

int main(void)
{
   /* TODO - declare variables here */


   /* TODO - get the max letter */


   /* TODO - get the dimension */

   
   /* TODO - get the seed and set up the random number generator */
   

   /* TODO - determine maximum guesses based on max letter and dimension */


   /* TODO - main game loop here */

	
   return 0;
}

/* TODO - Implement this function.
 * Use the rand() function to return a random character
 *    inbetween 'A' and the maxChar.
 */
char getRandChar(char maxChar)
{
   return 'A';  /* CHANGE THIS */
}

/* TODO - Implement this function.
 * Prompt the user for characters to fill in the letters array.
 * Make sure all input characters are between 'A' and maxChar.
 * "dim" indicates how many letters to get.
 */
void getGuess(char letters[], int dim, char maxChar)
{

}
 
/* TODO - Implement this function.
 * Display the mastermind board according to the following example:
 *
 *       XXXX
 *       ----
 * (0,2) ABCD
 * (0,3) ABBD
 * (3,0) BEDE
 *
 * "tries" indicates how many guessess are in the Guess array.
 * "dim" indicates how many letters are in each Guess.
 */
void printBoard(Guess guesses[], int tries, int dim)
{

}
