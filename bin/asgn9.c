/*************************************************************
* File:   asgn9.c                                            *
* Course: cisp360 Folsom Lake College  (2013)                *
* Author: Jason Sipula                                       *
* Date:   31/03/2013                                         *      
*                                                            *
* Assignment Description:                                    *
*    Exervices 8.36, 8.37, 8.38 on page 352                  *
*                                                            *
*    8.36: Dates are commonly printed in several different   *
*    formats in business correspondence. Two of the more     *
*    common formats are: 07/21/2003 and July 21, 2003        *
*    Write a program that reads a date in the first format   *
*    and prints it in the second format.                     *
*                                                            *
*    8.37: Computers are frequently used in check-writing    *
*    systems, such as payroll and accounts payable           *
*    applications. Many stories circulate regarding weekly   *
*    paychecks being printed (by mistake) for amounts in     *
*    excess of $1 million. Weird amounts are printed by      *
*    computerized check-writing systems because of human     *
*    error and/or machine failure. System designers, of      *
*    course, make every effort to build controls into their  *
*    systems to prevent erroneous checks from being issued.  *
*                                                            *
*    Another serious problem is the intentional alteration   *
*    of a check amount by someone who intends to cash it     *
*    fraudulently. To prevent a dollar amount from being     *
*    altered, most computerized check-writing systems employ *
*    a technique called check protection.                    *
*                                                            *
*    Checks designed for imprinting by computer contain a    *
*    fixed number of spaces in which the computer may print  *
*    an amount. Suppose a paycheck contains nine blank       *
*    spaces in which the computer is supposed to print the   *
*    amount of a weekly paycheck. If the amount is large,    *
*    then all nine of those spaces will be filled -          *
*    for example:                                            *
*    11,230.60 (check amount)                                *
*    123456789 (position numbers)                            *
*    On the other hand, if the amount is less than $1000,    *
*    then serveral of the spaces will ordinarily be left     *
*    blank - for example:                                    *
*        99.89                                               *
*    123456789                                               *
*    Contains four blank spaces. If a cehck is printed with  *
*    blank spaces, it is easier for someone to alter the     *
*    amount of the check. To prevent a check from being      *
*    altered, many check-writing system insert leading       *
*    asterisks to protect the amount as follows:             *
*    ****99.87                                               *
*    123456789                                               *
*    Write a program that inputs a dollor amount to be       *
*    printed on a check and then prints the amount in check- *
*    protected format with leading asterisks if necessary.   *
*    Assume that nine spaces are available for printing      *
*    an amount.                                              *
*                                                            *
*    8.38: Continuing the discussion of the previous example *
*    , we reiterate the importance of designing check-writing*
*    systems to preven alteration of check amounts. One      *
*    common security method requires that the check amount   *
*    be both written in numbers and "spelled out" in words.  *
*    Even if someone is able to alter the numerical amount of*
*    the check, it is extremely difficult to change the      *
*    amount in words.                                        *
*    Many computerized check-writing systems do not print    *
*    the amount of the check in words. Perhaps the main      *
*    reason of this omussion is the fact that most           *
*    high-level languages used in commercial application do  *
*    not contain adequate string-manipulation features.      *
*    Another reason is that the logic for writing word       *
*    equivalents of check amounts is somewhat involved.      *
*    Write a progra that inputs a numeric check amount and   *
*    writes the word equivalent of the amount. For example,  *
*    the amount 112.43 should be written as:                 *
*    ONE HUNDRED TWELVE and 43/100                           *
*                                                            *
*    Instructor modifications:                               *
*    Present the user a menu with the following options:     *
*        1 - Printing Dates in Various Formats               *
*        2 - Check Protection and Writing the Word Equivalent*
*            of a Check Amount                               *
*        3 - Exit                                            *
*                                                            *
*    When the user selects the option Printing Dates in      *
*    Various Formats, follow the instructions in exercise    *
*    8.36.                                                   *
*                                                            *
*    When the user selects the option Check Protection and   *
*    Writing the Word Equivalent of a Check Amount, combine  *
*    exercise 8.37 and 8.38. For example, if the user inputs *
*    the check amount of 1230.60, your program should output *
*    1) **1230.60 and 2) ONE THOUSAND TWO HUNDRED THIRTY and *
*        60/100                                              *
*                                                            *
*     Use function pointers to create the menu-driven system.*
*     Your program must have a minimum of two functions      *
*     the two menu options minus Exit). Also, exit the      *
*     program only when the user selects option 3.           *
*************************************************************/

#include <stdio.h>  //standard Input/Output library
#include <string.h> //standard String library
#include <ctype.h> //standard character library

/* function prototypes */
void programLoop( void );
void init( void );
int menu();
void option1 ( void );
void option2 ( void );
void printDateFormat ( char** in );
char *getMonth( int d);

int main( void ) { /* begin function main */
   
   programLoop();
   
   return 0;
} /* End function main */

void programLoop( void ) { /* begin function programLoop */

   int runProg = 1;    /* 1 - continue to run, 0 - exit */
   int menuOption; /* Chosen menu option by user */

   /* display proram greeting */
   init();

   /* begin program loop */
   while (runProg != 0) {

      /* display menu and get user option */
      menuOption =  menu();

      /* choose program path */
      switch ( menuOption ) {
         case 1:
            option1();   // execute option1()
            runProg = 1; // continue running
            break;
         case 2:
            option2();   // execute option2()
            runProg = 1; // continue running
            break;
         case 3:
            runProg = 0; // exit program
            break;
      }
   }

} /* End function programLoop */

void init( void ) { /* begin function init */

   /* display friendly greeting and state program's purpose */
   printf("\n\nWelcome to Check Software!");
   printf("\n\nCurrently performs the following:\n\t- Prints Dates in Various Formats");
   printf("\n\t- Check protection and Writing the Word Equivalent of a Check Amount");

} /* End function init */

int menu( void ) { /* begin function menu */

   int isValid = 0;      // status of user input vaidation, 0 = invalid, 1 = valid
   int op;               // option number user chose
   const char *menu1 = "Printing Dates in Various Formats";  //Menu option 1
   const char *menu2 = "Check Protection and Writing the Word Equivalent of a Check Amount";  //Menu option 2
   const char *menu3 = "Exit";  //Menu option 3

   /* menu loop begin */
   while (isValid != 1) {

      /* display menu to user */
      printf("\n\nMenu:\n\t1 - %s\n\t2 - %s\n\t3 - %s", menu1, menu2, menu3);
      printf("\n\nOption: ");
      scanf("%d", &op);
      printf("\n");

      /* validate user input */
      if ((int)op > 3 || (int)op < 1) {
         isValid = 0;
      } else {
         isValid = 1;
      }
   }
   /* menu loop end */

   return op;
} /* End function menu */

void option1( void ) { /* begin function option1 */

   char date[32]; /*user input date string */

   printf("\n\nEnter date [Format: MM/dd/yyyy]: ");
   //fgets(date, 12, stdin);

   scanf("%s", &date); 
printf("debug out");
   printDateFormat(date);

//   printf("\n%s", date);

} /* End fucntion option2 */

void option2( void ) { /* begin function option2 */

} /* End function option2 */

void printDateFormat( char** in ) { /* begin function printDateFormat */
   
   char *month;          // month by char
   int month_int;        // month by digit
   char *day;            // day by char
   char *year;           // year by char
   char *dateTkn;        // date token in split
   char formatted[32];   // formatted string

   static const char *months[] = {"January", "February", "March", "April", "May",
            "June", "July", "August", "September", "October", "November", "December"};
printf("made it through vars");
   dateTkn = strtok (in, "/");
   month = dateTkn;
printf("made it through month");
   dateTkn = strtok (NULL, "/");
   day = dateTkn;
printf("made it through day");
   dateTkn = strtok (NULL, "/");
   year = dateTkn;
printf("made it through year");
   sprintf( formatted, "%d %d, %d", months[(int)month], year);

   *in = formatted;

} /* End function printDateFormat */

