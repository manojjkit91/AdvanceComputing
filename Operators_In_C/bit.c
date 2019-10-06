/** 
 * To demonstrate use of bitwise operators 
 */
#include<stdio.h> 
int main ( int argc, char **argv ) 
{ 
	unsigned char x = 10; 
        unsigned char y = 12;   
	printf("x = %d, y = %d\n", x, y); 
        /** Bit-wise AND
         *  x = 10,     ( 00001010 )
         *  &
         *  y = 12,     ( 00001100 )
         *  x & y = 8,  ( 00001000 )  
         */
	printf("x & y = %d\n", x & y);
        /** Bit-wise OR
         *  x = 10,      ( 00001010 )
         *  |
         *  y = 12,      ( 00001100 )
         *  x | y = 14,  ( 00001110 )  
         */
	printf("x | y = %d\n", x | y);
        /** Bit-wise XOR
         *  x = 10,     ( 00001010 )
         *  &
         *  y = 12,     ( 00001100 )
         *  x ^ y= 6,   ( 00000110 )  
         */
	printf("x ^ y = %d\n", x ^ y);
        /** Bit-wise NOT
         *  x = 10,     ( 00001010 )
         *  ~x = 245,   ( 11110101 )
         */
	printf("~x = %d\n", x = ~x);
        /*  Bit-wise left shift
         *  y = 12,      ( 00001100 )
         *  y << 1 = 24, ( 00011000 )
         */
	printf("y << 1 = %d\n", y << 1);
        /*  Bit-wise right shift
         *  y = 12,     ( 00001100 )
         *  y >> 1 = 6, ( 00000110 )
         */
	printf("y >> 1 = %d\n", y >> 1);
	return 0; 
} 

