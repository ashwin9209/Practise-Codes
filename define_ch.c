//This program does not work. You cannot re-assign values that have already been set by #define directives.

#include<stdio.h>

#define defo 5

int main()
{
	printf ("%d", defo);
	printf("Changing defo to 8...\n");
	defo = 8;
	printf("Success.");
	return 0;
}