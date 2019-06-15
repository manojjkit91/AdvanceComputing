/* 
 * C program to find maximum of set of given integer numbers
 * using variable number of arguments  
 */
#include <stdarg.h>  
#include <stdio.h>  
/* 
 * Function returns maximum of set of integer numbers passed.  
 * argCount, count the number of argument
 */
int maxNum ( int argCount, ... )  
{ 
  int i;  
  int max, temp;  
  /*
   * va_list is a type to hold information  
   * about variable arguments  
   */
  va_list argList;  
  /*
   * va_start must be called before accessing variable argument list  
   * to initialize the va_list variable to an argument list
   */
  va_start ( argList, argCount );  
  /* 
   * Now arguments can be accessed one by one using va_arg macro.  
   * Initialize max as first argument in list  
   */
  max = va_arg ( argList, int );
  /* Iterate rest of the arguments to find out maximum */
  for ( i = 2; i <= argCount; i++ )  
       if ( ( temp = va_arg ( argList, int ) ) > max )  
            max = temp;  
  /*
   * va_end should be executed before the function returns  
   * to clean up the memory assigned to va_list variable.
   */
  va_end(argList); 
  return max;  
} 
int main()  
{ 
    int count = 5;
    int result = 0;  
    result = maxNum ( count, 10, 20, 50, 30, 70 );
    printf("Maximum number is %d\n", result );  
    result = maxNum ( count, 10, 20, 200, 30, 60 );
    printf("Maximum number is %d\n", result );  
    return 0;  
} 
