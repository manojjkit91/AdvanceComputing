/* 
 * To Print "Hello World" using an array of characters
 */
#include <stdio.h> /* For printf() */
int main ( int argc, char **argv )
{
  int i = 0 ;
  char str[12];
  /* Assigns one by one character to each index */
  str [0]  = 'H';
  str [1]  = 'e';
  str [2]  = 'l';
  str [3]  = 'l';
  str [4]  = 'o';
  str [5]  = ' ';
  str [6]  = 'W';
  str [7]  = 'o';
  str [8]  = 'r';
  str [9]  = 'l';
  str [10]  = 'd';
  str [11]  = '\0';

  /* Prints message on screen character by character */
  while ( str [i] != '\0' )
  {
     printf ( "%c", str[i] );
     i++ ;
  }
  return 0;
}
