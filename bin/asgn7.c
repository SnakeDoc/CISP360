/*************************************************************
* File:   asgn7.c                                            *
* Course: cisp360 Folsom Lake College  (2013)                *
* Author: Jason Sipula                                       *
* Date:   10/03/2013                                         *      
*                                                            *
* Assignment Description:                                    *
*    Write a program that simulates the rolling of two       *
*    dice. The program should use rand to roll the first die *
*    and should use rand again to roll the second die.       *
*    The sum of the two values shuld then be calculated.     *
*    [Note: Since each die can show an integer value from    *
*    1 to 6, then the sum of the two values will vary from   *
*    2 to 12, with 7 being the most frequent sum and 2 and   *
*    12 the least frequent.] Figure 6.23 shows the 36        *
*    possible combinations of the two dice. Your program     *
*    should roll the two dice 36,000 times. Use a            *
*    single-subscripted array to tally the numbers of times  *
*    each possible sum appears. Print the results in a       *
*    tabular format. Also, determine if the totals are       *
*    reasonable, i.e., there are siz ways to roll a 7, so    *
*    approximately one-sixth of all rolls should be 7.       *
*************************************************************/

#include <stdio.h>  //standard Input/Output library
#include <stdlib.h> // standard library
#include <time.h>   // time library

#define SIZE 36000  // define size of array for 36,000 rolls
#define NUM_RSLT 11  // define number of possible results for roll sum totals

/* function prototypes */
int rollDie( void );    // rolls die and returns value
void displayResults( int _results[], int arraySize );  // displays results of calculations
void bubbleSort( int _results[], int arraySize );      // sorts array values
int binarySearch( const int b[], int searchKey, int low, int high); // searches array for value and returns number of occurances
void tallyResults( int _results[], int _resultsArraySize, int tally[], int tallyArraySize );    // tally's results of roll

int main( void ) { /* begin function main */

   /* declare variables and describe purpose*/
   int first_die;              //first die value
   int second_die;             //second die value
   int sum;                    //sum of die values
   int i;                      //counter for loop
   int results[SIZE] = {0};    //array for storing roll results
   int tally[NUM_RSLT] = {0};  //array for storing tally results

   srand(time(NULL));          //seed random numbr generator

   /* set loop to roll die */
   for (i = 0; i < SIZE; i++) {
      first_die = rollDie();
      second_die = rollDie();

      sum = first_die + second_die;

      results[i] = sum;
   }

   /* sort results */
   bubbleSort(results, SIZE);

   /* tally results */
   tallyResults(results, SIZE, tally, NUM_RSLT);

   /* display tallied results */
   displayResults(tally, NUM_RSLT);

   return 0;
} /* End function main */

int rollDie( void ) { /* begin function rollDie */

   return (1 + rand() % 6); // return random number between 1 and 6 inclusive

} /* End function rollDie */

void displayResults( int tallyResults[], int arraySize ) { /* begin function displayResults */
   
   /* declare working variables */
   int q;              // counter for loop
   float percentage;   // percentage that result occured
   
   for (q = 0; q < arraySize; q++) {
      percentage = ( ( (float)tallyResults[q] / SIZE ) * 100 );
      printf("Number: %d - Times: %d - Percentage: %.2f\%\n", (q + 2), tallyResults[q], percentage);
   }

} /* End function displayResults */

/* fucntion bubbleSort adapted from fig 6.15 */
void bubbleSort( int _results[], int arraySize ) { /* begin function bubbleSort */

   /* declare working variables */
   int pass;   // value of current pass on array
   int temp;   // value of current temp number
   int j;      // counter for inner loop
   
   /* loop to control number of passes */
   for ( pass = 1; pass < arraySize; pass++) {
      /* loop to control number of comparisons per pass */
      for ( j = 0; j < arraySize - 1; j++) {
         /* compare adjacent elements and swap them if first element is greater than second element */
         if ( _results[j] > _results[ j + 1 ] ) {
            temp = _results[j];
            _results[j] = _results[ j + 1 ];
            _results[ j + 1 ] = temp;
         } /* end if */
      } /* end inner for */
   } /* end outter for */

} /* end function bubbleSort */

void tallyResults( int _results[], int _resultsArraySize, int tally[], int tallyArraySize ) { /* begin function tallyResult */
   
   /* declare working variables */
   int k;                        // counter for loop

   for (k = 0; k < _resultsArraySize; k++) {
      
      switch ( _results[k] ) {
         case 2:
            tally[0]++;
            break;
         case 3:
            tally[1]++;
            break;
         case 4:
            tally[2]++;
            break;
         case 5:
            tally[3]++;
            break;
         case 6:
            tally[4]++;
            break;
         case 7:
            tally[5]++;
            break;
         case 8:
            tally[6]++;
            break;
         case 9:
            tally[7]++;
            break;
         case 10:
            tally[8]++;
            break;
         case 11:
            tally[9]++;
            break;
         case 12:
            tally[10]++;
            break;
      }
   }   

} /* end function tallyResult */

