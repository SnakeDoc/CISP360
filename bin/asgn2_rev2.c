/*************************************************************
* File:   asgn2.c                                            *
* Course: cisp360 Folsom Lake College  (2013)                *
* Author: Jason Sipula                                       *
* Date:   02/02/2013                                         *      
*                                                            *
* Assignment Description:                                    *
*    Write a program that inputs three different integers    *
*    from the keyboard,then prints the sum, the average,     *
*    the product, the smallest and the largest of these      *
*    numbers. Use only the single selection form of the if   *
*    statement you learned in this chapter.                  *
*************************************************************/

#include <stdio.h>  //standard Input/Output library

int main( void ) { /* begin function main */

   /* declare variables and describe purpose*/
   int firstInt;              // first value input from user
   int secondInt;             // second value input from user
   int thirdInt;              // third value input from user

   /* Asks user to input three different integer numbers from the keyboard
      and assigns their value to the different integer variables  */
   printf("Input three different integers: ");
   scanf("%d%d%d", &firstInt, &secondInt, &thirdInt);

   /* Calculate and display the Sum of the three numbers */
   printf("Sum is %d\n", (firstInt + secondInt + thirdInt));

   /* Calculate and display the Average of the three numbers  */
   printf("Average is %d\n", ((firstInt + secondInt + thirdInt) / 3));

   /* Calculate and display the Product of the three numbers  */
   printf("Product is %d\n", (firstInt * secondInt * thirdInt));

   /* Calculate and display the smallest of the three numbers  */
   printf("Smallest is ");
   if (firstInt < secondInt && firstInt < thirdInt) {
      printf("%d\n", firstInt);
   }
   if (secondInt < firstInt && secondInt < thirdInt) {
      printf("%d\n", secondInt);
   }
   if (thirdInt < firstInt && thirdInt < secondInt) {
      printf("%d\n", thirdInt);
   }

   /* Calculate and display the largest of the three numbers  */
   printf("Largest is ");
   if (firstInt > secondInt && firstInt > thirdInt) {
      printf("%d\n", firstInt);
   }
   if (secondInt > firstInt && secondInt > thirdInt) {
      printf("%d\n", secondInt);
   }
   if (thirdInt > firstInt && thirdInt > secondInt) {
      printf("%d\n", thirdInt);
   }

   return 0;
} /* End function main */
