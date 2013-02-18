/*************************************************************
* File:   asgn4.c                                            *
* Course: cisp360 Folsom Lake College  (2013)                *
* Author: Jason Sipula                                       *
* Date:   16/02/2013                                         *      
*                                                            *
* Assignment Description:                                    *
*    (Triangle Printing Program) Write a program that prints *
*    the following patterns separately, one below the other. *
*    Use for loops to generate the patterns. All asterisks(*)*
*    should be printed by a single printf statement in the   *
*    form printf("*"); (this causes the asterisks to print   *
*    side by side). [Hint: The last two patterns require     *
*    that each line begin with an appropriate number of      *
*    blanks.]                                                *
*                                                            *
*    Modifications to the exercise:                          *
*                                                            *
*    a. Prompt the user for:                                 *
*       1) an integer between 1 and 20 inclusive. Assume the *
*          user will provide an integer within this range    *
*          of values.                                        *
*       2) the symbol to use to print the patterns.          *
*                                                            *
*    b. Print the patterns one after the other as shown      *
*       below including the (A), (B), etc and only one space *
*       between each set (not as shown in the text).         *
*                                                            *
*    c. Example:                                             *
*                                                            *
*       The user inputs the integer 3 and wants the % as the *
*       symbol. You should print the following patterns:     *
*                                                            *
*       (A)                                                  *
*       %                                                    *
*       %%                                                   *
*       %%%                                                  *
*                                                            *
*       (B)                                                  *
*       %%%                                                  *
*       %%                                                   *
*       %                                                    *
*                                                            *
*       (C)                                                  *
*       %%%                                                  *
*        %%                                                  *
*         %                                                  *
*                                                            *
*       (D)                                                  *
*         %                                                  *
*        %%                                                  *
*       %%%                                                  *
*                                                            *
*************************************************************/

#include <stdio.h>  //standard Input/Output library

int main( void ) { /* begin function main */

   /* declare variables and describe purpose*/
   int userInt;                //integer input from user (1-20)
   int count1;                 //integer counter used in 1st FOR loop
   int count2;                 //integer counter used in 2nd FOR loop
   int tempInt;                //temp integer to hold current print length
   char userChar;              //string input from user (char)

   /* Get user input */
   printf("Please enter a number between 1 and 20 (inclusive): ");
   scanf("%d", &userInt);

   printf("Please enter a character to print the pattern: ");
   scanf("%s", &userChar);
   
   /* (A) loop and print pattern */
   printf("(A)\n");
   for (count1 = 0; count1 < userInt; count1++) {
      for (count2 = 0; count2 < (userInt - (userInt - count1) + 1); count2++) {
         printf("%c", userChar);
      }
      printf("\n");
   }
   printf("\n");

   /* (B) loop and print pattern  */
   printf("(B)\n");
   for (count1 = 0; count1 < userInt; count1++) {
      for (count2 = 0; count2 < (userInt - count1); count2++) {
         printf("%c", userChar);
      }
      printf("\n");
   }
   printf("\n");

   /* (C) loop and print pattern */
   tempInt = userInt;
   printf("(C)\n");
   for (count1 = 0; count1 < userInt; count1++) {
      for (count2 = 0; count2 < (userInt - (userInt - count1)); count2++) {
         printf(" ");
      }
      for (count2 = 0; count2 < tempInt; count2++) {
         printf("%c", userChar);
      }
      tempInt--;
      printf("\n");
   }
   printf("\n");
   
   /* (D) loop and print pattern */
   tempInt = 1;
   printf("(D)\n");
   for (count1 = 0; count1 < userInt; count1++) {
      for (count2 = 1; count2 < (userInt - count1); count2++) {
         printf(" ");
      }
      for (count2 = 0; count2 < tempInt; count2++) {
         printf("%c", userChar);
      }
      tempInt++;
      printf("\n");
   }

   return 0;
} /* End function main */
