#include<stdio.h>
#include<time.h>

int main()
{
	srand(time(0));
	int r = rand() % 100;
	printf("%d\n", r);
	return 0;
}