/******************
Name: Dvir Agassi
ID: 215786328
Assignment: 1
*******************/
#include <stdio.h>

// REMIDER : YOU CANT USE ANY CONTROL FLOW OPERATIONS OR FUNCTIONS, ONLY BITWISE.

int main() {
  
  // What bit
  printf("What bit:\n");
  /*Scan two integers (representing number and a position)
  Print the bit in this position. */
  // x = number, y = position, bit = revers num with 1 at the start (so it will count the 0), bitwise = the num in binary
  int x, y, bit = 1, bitwise = 0;
  printf("Please enter a number:\n");
  scanf("%d", &x);
  printf("Please enter a position:\n");
  scanf("%d", &y);

  // make it from decimal to binary
  int x2 = x;
  while (x2 > 0) {
      bit = bit * 10 + x2 % 2;
      x2 /= 2;
  }
  // reverse from bit to bitwise (without the 1 at the start)
  while (bit > 1) {
      bitwise = bitwise * 10 + bit % 10;
      bit = bit / 10;
  }
  // delete the rightest num until you get the position (like >> right shift)
  int y1 = y;
  while (y1 > 0) {
      bitwise = bitwise / 10;
      y1--;
  }
  printf("The bit in position %d of number %d is: %d\n", y, x, bitwise%10);

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // Set bit
  printf("\nSet bit:\n");
  /*Scan two integers (representing number and a position)
  Make sure the bit in this position is "on" (equal to 1)
  Print the output
  Now make sure it's "off" (equal to 0)
  Print the output */
  // reset
  x = 0, y = 0, bitwise = 0;
  // power the two with the position
  int two = 1;
  printf("Please enter a number:\n");
  scanf("%d", &x);
  printf("Please enter a position:\n");
  scanf("%d", &y);
    
  y1=y; 
  bitwise = x/10;
  while (y1 > 0) {
      two *= 2;
      bitwise /= 10;
      y1--;
  }

  // you asked to print the num with 1 first so we are checking if the num is "odd" - has 1 at the end (turned on)
  if (bitwise % 2 == 1) {
      printf("Number with bit %d set to 1: %d\n", y, x);
      printf("Number with bit %d set to 0: %d\n", y, x-two);
  } else {    
      printf("Number with bit %d set to 1: %d\n", y, x+two);
      printf("Number with bit %d set to 0: %d\n", y, x);
  }

  

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // Toggle bit
  printf("\nToggle bit:\n");
  /*Scan two integers (representing number and a position)
  Toggle the bit in this position
  Print the new number */
  x = 0, y = 0, bitwise = 0, two = 1;
  printf("Please enter a number:\n");
  scanf("%d", &x);
  printf("Please enter a position:\n");
  scanf("%d", &y);
    
  y1=y; 
  bitwise = x/10;
  while (y1 > 0) {
      two *= 2;
      bitwise /= 10;
      y1--;
  }

  if (bitwise % 2 == 1) {
      printf("Number with bit %d toggled: %d\n", y, x-two);
  } else {    
      printf("Number with bit %d toggled: %d\n", y, x+two);
  }

  
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // Even - Odd
  printf("\nEven - Odd:\n");
  /* Scan an integer
  If the number is even - print 1, else - print 0. */
  x = 0;
  printf("Please enter a number:\n");
  scanf("%d", &x);
  // if modulo 2 == 0 it means the num is even (ends with 0 cause it is binary)
  if (x%2==0) {
    printf("1\n");
  } else {
    printf("0\n");
  }

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // 3, 5, 7, 11
  printf("\n3, 5, 7, 11:\n");
  /* Scan two integers in octal base
  sum them up and print the result in hexadecimal base
  Print only 4 bits, in positions: 3,5,7,11 in the result. */
  long num1, num2, bit1=1, bitwise1=0;
  // get the nums in octal
  printf("Please enter the first number (octal):\n");
  scanf("%lo", &num1);
  printf("Please enter the second number (octal):\n");
  scanf("%lo", &num2);
  
  long x1  = num1 + num2;
  // print as hex
  printf("The sum in hexadecimal: %lX\n", x1);

  // make it as binary num
  while (x1 > 0) {
      bit1 = bit1 * 10 + x1 % 2;
      x1 = x1 / 2;
  }
  while (bit1 > 1) {
      bitwise1 = bitwise1 * 10 + bit1 % 10;
      bit1 = bit1 / 10;
  }

  printf("The 3,5,7,11 bits are: ");
  // amount = 4 because this is the amount of nums we need to print
  int count = 0, amount = 4;
  while (bitwise1 > 0) {
    if (count == 3 || count == 5 || count == 7 || count == 11)
    {
      printf("%ld", bitwise1 % 10);
      amount--;
    }
    bitwise1 /= 10;
    count++;
  }
  count = 0;

  // it the num i shorter than 11 digits, print 0 for the rest of the nums
  while (amount > 0) {
      printf("0");
      amount--;
  }
  printf("\n");
  
  printf("Bye!\n");
  
  return 0;
}
