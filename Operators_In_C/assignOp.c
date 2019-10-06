/**
 * To demonstrate the assignment operators
 */
#include<stdio.h>
int main ( int argc, char **argv )
{
  int x = 10;
  int y = 12;
  int res = 0;
  /* x += y is same as x = x + y */
  printf ( " x += y : %d \n", x += y );
  x = 10;
  y = 12;
  /* x -= y is same as x = x - y */
  printf ( " x -= y : %d \n", x -= y );
  x = 10;
  y = 12;
  /* x *= y is same as x = x * y */
  printf ( " x *= y : %d \n", x *= y );
  x = 10;
  y = 12;
  /* x /= y is same as x = x / y */
  printf ( " x /= y : %d \n", x /= y );
  /* x %= y is same as x = x % y */
  printf ( " x %%= y : %d \n", x %= y );
  return 0;
}
