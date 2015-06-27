/* CPE 101 Lab 8
 * Name: Lonnie Bissmeyer
 * Instructor: Julie Workman
*/

#include <stdio.h>
#include <string.h>

#define SECS_PER_HOUR 3600
#define SECS_PER_MIN 60
#define MAX_RUNS 30

typedef struct
{
   char name[20];
   double distance;
   int prSec;
   int count;
} Run;

void secsToHMS(int totalSecs, int *h, int *m, int *s);
void findRun(Run r[], int numRuns, char name[], int *index);
void writeFile(Run r[], int numRuns);
int readFile(Run r[]);
void displayRuns(Run r[], int numRuns);
void addRun(Run r[], int numRuns);

int main(void)
{
   Run r[MAX_RUNS];
   int numRuns;
   
   numRuns = readFile(r);
   displayRuns(r, numRuns);
   addRun(r, numRuns);
   printf("\nHappy trails!\n");

   return 0;
}
void addRun(Run r[], int numRuns)
{
   char answer, name[20];
   int index, h, m, s, totalSecs;

   printf("(a)dd run or (q)uit: ");
   scanf(" %c", &answer);
   while(answer == 'a')
   {
      printf("\nRun Name: ");
      scanf("%s", name);      
      findRun(r, numRuns, name, &index);
     
      if(index == -1)
      {
         numRuns += 1;
         strcpy(r[numRuns - 1].name, name);
         
         printf("Distance in Miles: ");
         scanf("%lf", &r[numRuns - 1].distance);
         printf("Time (hh mm ss): ");
         scanf("%2d %2d %2d", &h, &m, &s);

         totalSecs = s + m * SECS_PER_MIN + h * SECS_PER_HOUR;
         r[numRuns - 1].prSec = totalSecs;
         r[numRuns - 1].count = 1;
      }
      else
      {
         printf("Time (hh mm ss): ");
         scanf("%2d %2d %2d", &h, &m, &s);

         totalSecs = s + m * SECS_PER_MIN + h * SECS_PER_HOUR;
         if(totalSecs < r[index].prSec)
         {
            r[index].prSec = totalSecs;
         }
         r[index].count += 1;
      }
      
      displayRuns(r, numRuns);
      printf("(a)dd run or (q)uit: ");
      scanf(" %c", &answer);
   }
  writeFile(r, numRuns);
  return;   
}
void displayRuns(Run r[], int numRuns)
{
   int pace, i, h, m ,s, paceH, paceM, paceS;
     
   printf("\nRun Report:\n\n");
   printf("Name                 Distance   PR       Pace    Count\n");
   printf("------------------------------------------------------\n");
  
   for(i = 0; i < numRuns; i++)
   {
      secsToHMS(r[i].prSec, &h, &m, &s);
      pace = r[i].prSec/r[i].distance;
      secsToHMS(pace, &paceH, &paceM, &paceS);
      printf("%-21s %8.2f %2d:%02d:%02d %3d:%02d %7d\n", r[i].name, r[i].distance, h, m, s, paceM, paceS, r[i].count);      
   }
}

int readFile(Run r[])
{  
   int i = 0;

   FILE *fp;
   fp = fopen("run.data", "r");
   if(fp == NULL)
   {
      printf("Couldn't open file.\n");
      return 0;
   }
   
   while(fscanf(fp, "%s", r[i].name) != EOF)
   {
      fscanf(fp, "%lf", &r[i].distance);
      fscanf(fp, "%d", &r[i].prSec);
      fscanf(fp, "%d", &r[i].count);
      i++;
   }
   return i;
}

void secsToHMS(int totalSecs, int *h, int *m, int *s)
{
   *h = totalSecs/3600;
   totalSecs = totalSecs % 3600;
   *m = totalSecs/60;
   totalSecs = totalSecs % 60;
   *s = totalSecs;
}

void findRun(Run runs[], int numRuns, char name[], int *index)
{
   int i;

   *index = -1;

   for (i=0; i<numRuns && *index==-1; i++)
      if (!strcmp(name, runs[i].name))
         *index = i;
}

void writeFile(Run runs[], int numRuns)
{
   FILE *fp = NULL;
   int i = 0;

   fp = fopen("run.data", "w");

   for (i = 0; i<numRuns; i++) {
      fprintf(fp, "%s %.2f %d %d\n", runs[i].name, runs[i].distance,
       runs[i].prSec, runs[i].count);
   }
   fclose(fp);
}
