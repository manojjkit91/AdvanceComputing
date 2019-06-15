/* 
 * To Print "Hello World" using a character array
 */
#include <stdio.h> /* For printf() */
int main ( int argc, char **argv )
{
  int i = 0 ;
  /* Assigns "Hello World" string to str [] */
  char str []  = "Hello World";
  /* Prints message on screen character by character */
  while ( str [i] != '\0' )
  {
     printf ( "%c", str[i] );
     i++ ;
  }
  return 0;
}
