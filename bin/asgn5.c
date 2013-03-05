/*************************************************************
* File:   asgn5.c                                            *
* Course: cisp360 Folsom Lake College  (2013)                *
* Author: Jason Sipula                                       *
* Date:   24/02/2013                                         *      
*                                                            *
* Assignment Description:                                    *
*    Write a function that takes an integer value and        *
*    returns the number with its digits reversed. For        *
*    example, given the number 7631, the function should     *
*    return 1367.                                            *
*                                                            *
* Modifications:                                             *
*    a) Prompt the user for an integer between 1 and         *
*       10,000 inclusive ( from main() )                     *
*                                                            *
*    b) Pass the input value to a function that returns the  *
*       number with the digits reversed (a call from main()  *
*       calls your function and passes the value input by    *
*       the user).                                           *
*                                                            *
*    c) Display the result from main(). Leading zeros can be *
*       eliminated. For example, if 2020 is input, the       *
*       reverse is 0202 but the program may display 202.     *
*                                                            *
*************************************************************/

#include <stdio.h>  //standard Input/Output library

int reverseUserInt( int input ); /* function prototype */

int main( void ) { /* begin function main */

   /* declare variables and describe purpose*/
   int user_int;              // value input from user
   int rev_user_int;          // reversed input from user

   /* Get user input */
   printf("Please enter a number between 1 and 10,000 (inclusive): ");
   scanf("%d", &user_int);
  
   /* Start WHILE loop to validate user input  */
   while ((!(user_int <= 10000)) || (!(user_int >= 1)))
   {
      printf("Please enter a number between 1 and 10,000 (inclusive): ");
      scanf("%d", &user_int);
   }
   /* End WHILE loop  */

   /* call function to reverse user input integer */
   rev_user_int = reverseUserInt(user_int);

   /* display reversed user input */
   printf("Reverse is: %d\n", rev_user_int);

   return 0;
} /* End function main */

int reverseUserInt( int input ) { /* begin function reverseUserInt */
                                  /* reverses the input integer value
                                      and returns this number */

   int output = 0;           // Output value that is returned from function

   while (input > 0)
   {
      output *= 10;
      output += input % 10;
      input /= 10;
   }

   return output;
} /* End function reverseUserInt */
