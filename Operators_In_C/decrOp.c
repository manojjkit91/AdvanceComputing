/*
 * To demonstrate the decrement operators in C
 */
#include<stdio.h>
int main ( int argc, char **argv )
{
   int x = 10; /* For Pre-decrement */
   int y = 12; /* For Post-decrement */
   /* First decrement the value of x 
    * then assigns it to the variable x 
    */
   printf("Pre-incrment : --x = %d \n", --x );
   /* The value of the variable y is decremented 
    * after assigning it to the variable y 
    */
   printf("Post-incrment : y-- = %d \n", y-- );
   return 0;
}
