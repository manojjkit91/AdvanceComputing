/**
 * To demonstrate the conditional ( Ternary ) operator 
 */
#include<stdio.h>
int main ( int argc, char **argv )
{
  int x = 10;
  int y = 12;
  int res = 0;
  /* if x is greater than y, it will return x,
   * otherwise returns y
   */
  res = ( x > y ) ? x : y;
  printf (" Result = %d\n", res );
  /* If x is less than y, it will return x,
   * otherwise returns y.
   */
  res = ( x < y ) ? x : y;
  printf (" Result = %d\n", res );
  return 0;
}
