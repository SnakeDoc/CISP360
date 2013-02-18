/*************************************************************
* File:   asgn3.c                                            *
* Course: cisp360 Folsom Lake College  (2013)                *
* Author: Jason Sipula                                       *
* Date:   10/2/2013                                          *      
*                                                            *
* Assignment Description:                                    *
*    3.33 - Write a program that reads in the side of a      *
*    square and then prints that square out in asterisks.    *
*    Your program should work for squares of all side sizes  *
*    between 1 and 20. For example, if your program reads    *
*    a size of 4, it should print:                           *
*                                                            *
*    ****                                                    *
*    ****                                                    *
*    ****                                                    *
*    ****                                                    *
*                                                            *
*    3.34 - Modify the program you wrote in Exercise 3.33    *
*    so that it prints a hollow square. For example,         *
*    if your program reads a size of 5, it should print:     *
*                                                            *
*    *****                                                   *
*    *   *                                                   *
*    *   *                                                   *
*    *   *                                                   *
*    *****                                                   *
*                                                            *
*    Instructor Additions: Exercises 3.33 and 3.34 page 94   *
*    of your text. Combine into one solution. Promt the      *
*    user for a value between 1 and 20 inclusive. Do not     *
*    print the square and hollow square if the user does     *
*    not input a valid value. Print a blank line before      *
*    your program terminates so the user has a normal        *
*    comman prompt after executing your program. I will      *
*    run your program and input valid and invalid values.    *
*************************************************************/

#include <stdio.h>  //standard Input/Output library

int main( void ) { /* begin function main */

   /* declare variables and describe purpose*/
   int counter1;               //counter variable for processing outside loop
   int counter2;               //counter variable for processing inside loop
   int userInput;              //input from user prompt
   int bool1;                  //boolean value (1 true, 0 false) for whle loop

   /* initialize variables  */
   counter1 = 0;
   counter2 = 0;
   bool1 = 1;

   /* start user input loop  */
   while (bool1 == 1) {
      /* get user input from command line and initialize userInput variable */
      printf("Please enter an integer number betwen 1 and 20: ");
      scanf("%d", &userInput);

      /* validate userInput variable to be between 1 and 20 inclusive */
      if (userInput < 1) {
         printf("The number you entered is too small.\n");
         bool1 = 1;
      } else if (userInput > 20) {
         printf("The number you entered is too large.\n");
         bool1 = 1;
      } else {
         bool1 = 0;
      }
   }
   /* end while loop userInput validation */

   /* begin program processing of userInput */

   /* begin solid square loop */
   while (counter1 < userInput) {
      while (counter2 < userInput) {
         printf("*");
         counter2++;
      }
      printf("\n");
      counter2 = 0;
      counter1++;
   }
   /* end solid square loop */

   /* reset counter variables */
   counter1 = 0;
   counter2 = 0;

   /* add space line to break-up the output */
   printf("\n");

   /* begin hollow square loop */
   while (counter1 < userInput) {
      printf("*");
      counter1++;
   }
   printf("\n");
   counter1 = 0;
   while (counter1 < (userInput - 2)) {
      printf("*");
      while (counter2 < (userInput - 2)) {
         printf(" ");
         counter2++;
      }
      printf("*\n");
      counter2 = 0;
      counter1++;
   }
   counter1 = 0;
   while (counter1 < userInput) {
      printf("*");
      counter1++;
   }
   /* end program processing of userInput */

   /* add a space line so program terminates on normal cmd prompt line */
   printf("\n");

   return 0;
} /* End function main */
