/* Program to check whether the equation:

(n^2) + n + 41, n >= 0,

is prime or not.
Ref: Mathematics for Computer Science Pg. 16 */

#include <stdio.h>
#include <math.h>

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
	int n, first = 0, answer = 0, count = 0;
	printf("\n\nChecking for equation falsifiers: ");
	for ( n = 0; n < 50; n++)
	{
		first = pow(n, 2);
		answer = first + n + 41;
		if(!isprime(answer))
		{
			printf("\n%d does not match the equation.", n);
			count++;
		}
	}

	printf("\nDone processing!\n");
}