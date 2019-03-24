#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include<stdlib.h>
int main( void )
{
   char string[80];
   strcpy( string, "Hello world from " );
   strcat( string, "strcpy " );
   strcat( string, "and " );
   strcat( string, "strcat!" );
   printf( "String = %s\n", string );
   system("pause");
   return 0;
}