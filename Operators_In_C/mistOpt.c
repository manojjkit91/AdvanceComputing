/**
 * To demonstrate the & , *, and sizeof() operator
 */
#include<stdio.h>
int main ( int argc, char **argv )
{
   long int x = 10;
   long int *ptr = &x;
   printf ( "Value of x = %d\n ",x );
   printf ( "Address of x = %d\n", &x );
   printf ( "Address of x = %d\n", ptr );
   printf ( "Value of x = %d\n", *ptr );
   printf ( "Size of the x = %d ( in Bytes )\n", sizeof ( x ) );
   return 0;
}
