/*************************************************************
* File:   asgn6.c                                            *
* Course: cisp360 Folsom Lake College  (2013)                *
* Author: Jason Sipula                                       *
* Date:   03/03/2013                                         *      
*                                                            *
* Assignment Description:                                    *
*   The Fibonacci series (0,1,1,2,3,5,8,13,21,...)           *
*   begins with the terms 0 and 1 and has the property that  *
*   each succeeding term is the sum of the two preceding     *
*   terms. a) Write a nonrecursive function fibonacci(n)     *
*   that calculates the nth Fibonacci number. b) Determine   *
*   the largest Fibonacci number that can be printed on your *
*   system. Modify the program of part a) to use double      *
*   instead of int to calculate and return Fibonacci numbers *
*   Let the program loop until it fails because of an        *
*   excessively high value.                                  *
*                                                            *
* Modifications:                                             *
*   a) Prompt the user for an integer n that calculates the  *
*      nth fibonacci number from main(). For this problem,   *
*      the 3th Fibonacci number is 1, the 4th is 2, the 5th  *
*      is 3, etc. (The series is: 0,1,1,2,3,5,etc...)        *
*   b) Pass the input value to the function fibanacci(n)     *
*      that returns the value. Display the value to the      *
*      console.                                              *
*   c) Have your program calculate the value of the largest  *
*      fibonacci number. Do not hard-code this into your     *
*      program. The purpose is to be able to take your code  *
*      to another system and discover the value without      *
*      changing your code. If you are unable to do this just *
*      print a statement you do not have a solution for this *
*      part of the assignment.                               *
*                                                            *
*   Example: Which fibanacci number do you want? 5           *
*            The 5th fibonacci number is: 3                  *
*            The largest fibonacci number that can be        *
*               calculated on this system is: xxxxxxx        *
*                                                            *
*************************************************************/

#include <stdio.h>  //standard Input/Output library
#include <limits.h> /* limits library | allows use of INT_MAX 
                    to get the maximum int value */

int fibonacci(int input); /* function prototype */

int main( void ) { /* begin function main */

   /* declare variables and describe purpose*/
   int userVal;              //value input from user

   /* Get user input */
   printf("Which fibonacci number do you want? ");
   scanf("%d", &userVal);
   
   /* Display the nth fibonacci number */
   printf("The %dth fibonacci number is: %ld\n", userVal, fibonacci(userVal));

   /* Display the largest fibonacci number on this system */
   printf("The largest fibonacci number that can be ");
   printf("calculated on this system is: %ld\n", fibonacci(INT_MAX));

   return 0;
} /* End function main */

int fibonacci( int input ) { /* begin function fibonacci */
   int num1 = 0;             // used to store fibonacci number
   int num2 = 1;             // used to store fibonacci number
   int temp;                 // temp. holds fibonacci value
   int last;                 // temp. holds last fibonacci value
   int i;                    // counter for fibonacci loop

   /* calculate fibonacci number */
   for (i = 0; i < input; i++) {
      if (i <= 1) {
         temp = i;
      } else {
         temp = num1 + num2;
         num1 = num2;
         num2 = temp;
         /* Guards against int overflow (32 bits) */
         if (temp < 0) {
            return last; // return last largest fibonacci number if we overflowed
         } else {
            last = temp;
         }
      }
   }
   return temp;
} /* end function fibonacci */
