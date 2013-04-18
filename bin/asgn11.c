/*************************************************************
* File:   asgn11.c                                           *
* Course: cisp360 Folsom Lake College  (2013)                *
* Author: Jason Sipula                                       *
* Date:   14/04/2013                                         *      
*                                                            *
* Assignment Description:                                    *
*    (Reversing the Order of an Integer's Bits) Write a      *
*    program that reverses the order of the bits in an       *
*    unsigned integer value. The program should input the    *
*    value from the user and call function reverseBits to    *
*    print the bits in reverse order. Print the value in     *
*    bits both before and after the bits are reversed to     *
*    confirm that the bits are reversed properly.            *
*************************************************************/

#include <stdio.h>  //standard Input/Output library

/* prototypes */
int main( void );
void bitBuilder( char arry[], unsigned num );
void reverseBits( char revArry[], char origArry[] );

int main( void ) { /* begin function main */

   /* declare variables and describe purpose*/
   unsigned userInt;              // user input positive (unsigned) number
   char bits[32] = { 0 };         // init an array to store bits of orig number
   char revBits[32] = { 0 };  // init an array to store reversed bits
   unsigned i = 1;                // counter for loop

   /* prompt user for input */
   printf("Please enter a positive number: ");
   scanf("%u", &userInt);

   /* display original input and bits */
   printf("User input integer: %u\n", userInt);

   printf("In bits this is: ");

   /* get bits and store in array */
   bitBuilder( bits, userInt );

   /* display bits */
   for (; i <= 32; i++) {
      printf("%c", bits[i - 1]);
      if ( i % 8 == 0 ) {
         printf(" ");
      }
   }
   printf("\n");

   reverseBits( revBits, bits );

   printf("The reverse bit order is: ");

   // reset counter for loop
   i = 1;

   /* display bits */
   for (; i <= 32; i++) {
      printf("%c", revBits[i - 1]);
      if ( i % 8 == 0 ) {
         printf(" ");
      }
   }
   printf("\n");

   return 0;
} /* End function main */

void bitBuilder( char arry[], unsigned num ) { /* begin function bitBuilder */

   unsigned i = 1;                    // counter for loop
   unsigned displayMask = 1 << 31;    // define displayMask and left shift 31 bits

   /* loop through all bits and add to array */
   for (; i <= 32; i++) {
      arry[i - 1] = (num & displayMask ? '1' : '0');
      num <<= 1; /* shift value left by 1 */
   }
} /* End function bitBuilder */

void reverseBits( char revArry[], char origArry[] ) { /* begin function reverseBits */

   unsigned i = 1;    // counter for loop

   for (; i <= 32; i++) {
      revArry[32 - i] = origArry[i - 1];
   }

} /* End function reverseBits */

