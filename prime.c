#include <stdio.h>


int isprime(int x)
{

	int i, check, result = 1;
	for (i = 2; i <= x/2; i++)
	{
		check = x % i;

		if (check == 0)
		{
			result = 0;
			break;
		}

	}
	return result;
}


int main()
{
	int i, result;
	printf("\n\nEnter a number to check whether it is prime or not: ");
	scanf("%d", &i);

	result = isprime(i);
	
	if(result == 1)
		printf("\nThe number is prime.");
	else
		printf("\nThe number is not prime.");

	return 0;

}