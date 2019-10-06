/**
 * To demonstrate logical operator in C
 */
#include<stdio.h>
int main ( int argc, char **argv )
{
   int x = 10;
   int y = 0;
   int z = 15;
   /* Logical AND */
   if ( x && y )
   {
      printf("Logical AND : TRUE\n");
   }
   else 
   {
      printf ("logical AND : FALSE\n");
   }
   /* Logical OR */
   if ( x || y )
   {
      printf("Logical OR : TRUE\n");
   }
   else 
   {
      printf ("logical OR : FALSE\n");
   }
   if ( !y )
   {
      printf("Logical NOT : TRUE\n");
   }
   else 
   {
      printf ("logical NOT : FALSE\n");
   }
   return 0;
}
   
