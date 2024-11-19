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
  int x, y, bit = 1, bitwise = 0;
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
  //printf("%d\n", bitwise);
  while (y > 0) {
      bitwise = bitwise / 10;
      //printf("%d\n", bitwise);
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
  int x, y, pows = 1, bit = 1, bitwise = 0, z;
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
  
  z = bitwise % pows;
  bitwise /= pows;

  int the_bitwise, two = 1, dec;
  if (bitwise % 2 == 1) {
    the_bitwise = bitwise * pows + z;
    while (the_bitwise > 0) {
      dec += (the_bitwise % 10) * two;
      two *= 2;
      the_bitwise /= 10;
    }
    printf("%d\n", dec);
    dec = 0;
    two = 1;
    bitwise -= 1;
    the_bitwise = bitwise * pows + z;
    while (the_bitwise > 0) {
      dec += (the_bitwise % 10) * two;
      two *= 2;
      the_bitwise /= 10;
    }
    printf("%d\n", dec);
    dec = 0;
    two = 1;
  } else {
    bitwise += 1;
    the_bitwise = bitwise * pows + z;
    while (the_bitwise > 0) {
      dec += (the_bitwise % 10) * two;
      two *= 2;
      the_bitwise /= 10;
    }
    printf("%d\n", dec);
    dec = 0;
    two = 1;
    bitwise -= 1;
    the_bitwise = bitwise * pows + z;
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
  int x, y, pows = 1, bit = 1, bitwise = 0, z;
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
  
  z = bitwise % pows;
  bitwise /= pows;

  int the_bitwise, two = 1, dec;
  if (bitwise % 2 == 1) {
    bitwise -= 1;
    the_bitwise = bitwise * pows + z;
    while (the_bitwise > 0) {
      dec += (the_bitwise % 10) * two;
      two *= 2;
      the_bitwise /= 10;
    }
    printf("%d\n", dec);
    dec = 0;
    two = 1;
  } else {
    bitwise += 1;
    the_bitwise = bitwise * pows + z;
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
  int x;
  scanf("%d", &x);
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
  scanf("%o", &num1);
  scanf("%o", &num2);
  
  long x  = num1 + num2;
  printf("%X\n", x);
  while (x > 0) {
      bit = bit * 10 + x % 2;
      x = x / 2;
  }
  while (bit > 1) {
      bitwise = bitwise * 10 + bit % 10;
      bit = bit / 10;
  }
  
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
  
  while (amount > 0) {
      printf("0");
      amount--;
  }

  
  printf("Bye!\n");
  
  return 0;
}
