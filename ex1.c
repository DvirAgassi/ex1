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
  scanf("%d", &x);
  scanf("%d", &y);

  // make it from decimal to binary
  while (x > 0) {
      bit = bit * 10 + x % 2;
      x /= 2;
  }
  // reverse from bit to bitwise (without the 1 at the start)
  while (bit > 1) {
      bitwise = bitwise * 10 + bit % 10;
      bit = bit / 10;
  }
  // delete the rightest num until you get the position (like >> right shift)
  while (y > 0) {
      bitwise = bitwise / 10;
      y--;
  }
  printf("%d\n", bitwise%10);

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // Set bit
  printf("\nSet bit:\n");
  /*Scan two integers (representing number and a position)
  Make sure the bit in this position is "on" (equal to 1)
  Print the output
  Now make sure it's "off" (equal to 0)
  Print the output */
  // same as before, rem is remainder, pows is like 1/10/100/1000 etc. + reset
  x = 0, y = 0, bit = 1, bitwise = 0;
  int pows = 1, rem = 0;
  scanf("%d", &x);
  scanf("%d", &y);
    
  while (x > 0) {
    bit = bit * 10 + x % 2;
    x = x / 2;
  }
  while (bit > 1) {
    bitwise = bitwise * 10 + bit % 10;
    bit = bit / 10;
  }
  // get the pows for the position
  while (y > 0) {
    pows *= 10;
    y--;
  }
  // get the num after the pow - for example the number is 256 with pow 100, the rem will be 56
  rem = bitwise % pows;
  bitwise /= pows;

  // two - to make it decimal you need to multiply with 2 pow num (0, 1, 2...), dec is the final decimal
  int the_bitwise, two = 1, dec;
  // you asked to print the num with 1 first so we are checking if the num is "odd" - has 1 at the end (turned on)
  if (bitwise % 2 == 1) {
    // make it the final binary num, if multiply by the pow and add the rem to get it
    the_bitwise = bitwise * pows + rem;
    // check num num and multiply it by the 2 pow, add to the decimal. after that double the two for next number
    while (the_bitwise > 0) {
      dec += (the_bitwise % 10) * two;
      two *= 2;
      the_bitwise /= 10;
    }
    printf("%d\n", dec);
    // reset the variables to not make an error
    dec = 0;
    two = 1;
    // make the bit 0 (turned off)
    bitwise -= 1;
    the_bitwise = bitwise * pows + rem;
    while (the_bitwise > 0) {
      dec += (the_bitwise % 10) * two;
      two *= 2;
      the_bitwise /= 10;
    }
    printf("%d\n", dec);
    dec = 0;
    two = 1;
  } else {
    // if the num from before was actually 0 and not 1, add 1 cause we need to print the turned on num first
    bitwise += 1;
    the_bitwise = bitwise * pows + rem;
    while (the_bitwise > 0) {
      dec += (the_bitwise % 10) * two;
      two *= 2;
      the_bitwise /= 10;
    }
    printf("%d\n", dec);
    dec = 0;
    two = 1;
    bitwise -= 1;
    the_bitwise = bitwise * pows + rem;
    while (the_bitwise > 0) {
      dec += (the_bitwise % 10) * two;
      two *= 2;
      the_bitwise /= 10;
    }
    printf("%d\n", dec);
    dec = 0;
    two = 1;
  }

  

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // Toggle bit
  printf("\nToggle bit:\n");
  /*Scan two integers (representing number and a position)
  Toggle the bit in this position
  Print the new number */
  x = 0, y = 0, pows = 1, bit = 1, bitwise = 0, rem = 0;
  scanf("%d", &x);
  scanf("%d", &y);
    
  while (x > 0) {
    bit = bit * 10 + x % 2;
    x = x / 2;
  }
  //printf("%d\n", bit);
  while (bit > 1) {
    bitwise = bitwise * 10 + bit % 10;
    bit = bit / 10;
  }

  while (y > 0) {
    pows *= 10;
    y--;
  }
  
  rem = bitwise % pows;
  bitwise /= pows;

  the_bitwise = 0, two = 1, dec = 0;
  // check if the rightest num is 0/1
  if (bitwise % 2 == 1) {
    // if 1, make it 0
    bitwise -= 1;
    the_bitwise = bitwise * pows + rem;
    while (the_bitwise > 0) {
      dec += (the_bitwise % 10) * two;
      two *= 2;
      the_bitwise /= 10;
    }
    printf("%d\n", dec);
    dec = 0;
    two = 1;
  } else {
    // if 0, make it 1
    bitwise += 1;
    the_bitwise = bitwise * pows + rem;
    while (the_bitwise > 0) {
      dec += (the_bitwise % 10) * two;
      two *= 2;
      the_bitwise /= 10;
    }
    printf("%d\n", dec);
    dec = 0;
    two = 1;
  }


  
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // Even - Odd
  printf("\nEven - Odd:\n");
  /* Scan an integer
  If the number is even - print 1, else - print 0. */
  x = 0;
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
  long num1, num2, bit=1, bitwise=0;
  // get the nums in octal
  scanf("%o", &num1);
  scanf("%o", &num2);
  
  long x  = num1 + num2;
  // print as hex
  printf("%X\n", x);

  // make it as binary num
  while (x > 0) {
      bit = bit * 10 + x % 2;
      x = x / 2;
  }
  while (bit > 1) {
      bitwise = bitwise * 10 + bit % 10;
      bit = bit / 10;
  }

  // amount = 4 because this is the amount of nums we need to print
  int count = 0, amount = 4;
  while (bitwise > 0) {
    if (count == 3 || count == 5 || count == 7 || count == 11)
    {
      printf("%d", bitwise % 10);
      amount--;
    }
    bitwise /= 10;
    count++;
  }
  count = 0;

  // it the num i shorter than 11 digits, print 0 for the rest of the nums
  while (amount > 0) {
      printf("0");
      amount--;
  }

  
  printf("Bye!\n");
  
  return 0;
}
