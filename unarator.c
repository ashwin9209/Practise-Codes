#include<stdio.h>

int main( )
{
	float a = 5, b = 2 ;
	int c ;
	c = a % b ; //error: You can only use integers for modulus operator
	printf ( "%d", c ) ;
	return 0;
}