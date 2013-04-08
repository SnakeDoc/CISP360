/***************************************************************
* File:   asgn10.c                                             *
* Course: cisp360 Folsom Lake College  (2013)                  *
* Author: Jason Sipula                                         *
* Date:   07/03/2013                                           *      
*                                                              *
* Assignment Description:                                      *
* Write a program that loads a 10-element array with           *
* random integers from 1 to 1000. There is no input from the   *
* user. For each value, print the value, number of characters  *
* in that value, and a running total of the number of          *
* characters printed. Use the %n conversion specifier to       *
* determine the number of characters output for each value.    *
* Your program must generate a different set of values each    *
* time it is run. The output should have the following format: *
*                                                              *
*                       Total                                  *
* Value    Characters   Characters                             *
* 142      3            3                                      *
* 1000     4            7                                      *
* 963      3            10                                     *
* 6        1            11                                     *
* etc.                                                         *
*                                                              *
****************************************************************/

#include <stdio.h>  //standard Input/Output library

#define ARRAY_SIZE 10

/* function prototypes */
int main ( void );
void getArray( int *arry );
void displayHeader( void );
int displayResult( int vals, int total );
void printPadding( int len );

int main( void ) { /* begin function main */

   /* declare variables and describe purpose*/
   int arry[ARRAY_SIZE] = { 0 }; //array of integers initalized all to zero (0)
   int totalChars = 0;           //running total number of characters initalized to zero (0)
   int i = 0;                    //loop counter initialized to zero (0)

   srand(time(NULL));            //seed random number generator

   /* populate array */
   getArray( arry );

   /* display report header */
   displayHeader();

   /* loop and display results */
   for (; i < ARRAY_SIZE; i++)
   {
      totalChars = displayResult( arry[i], totalChars );
   }

   return 0;
} /* End function main */

void printPadding( int len ) /* begin function printPadding */
{
   int max = 9;        //max padded length

   for (; len < max; len++)
   {
      printf(" ");
   }
} /* End function printPadding */

int displayResult( int vals, int total ) /* begin function displayResult */
{
   int chars = 0;      //number of characters in printf statement

   chars = printf("%d", vals);
   printPadding(chars);
   total += chars;
   printf("%-13d", chars);
   printf("%d\n", total);

   return total;
} /* End function displayResult */

void displayHeader( void ) /* begin function displayHeader */
{
   printf("\n%27s\n%-9s%-13s%-14s\n", "Total", "Value", "Characters", "Characters");
} /* End function displayHeader */

void getArray( int *arry ) /* begin function getArray */
{
   /* declare variable and describe purpose */
   int i = 0;              //counter for loop

   /* loop to populate array */
   for (; i < ARRAY_SIZE; i++)
   {
      // get random number between 1 and 1000 inclusive, assign to array
      arry[i] = (1 + rand() % 1000);
   }
} /* End function getArray */
