/*

CodeChef Problem 1: (Sort by successful submissions, descending)

Life, the Universe, and Everything

Your program is to use the brute-force approach
in order to find the Answer to Life, the Universe,
and Everything. More precisely... rewrite small
numbers from input to output. Stop processing
input after reading in the number 42. All
numbers at input are integers of one or
two digits.

Example


Input:
1
2
88
42
99

Output:
1
2
88

*/

#include <stdio.h>
int main()
{
	int input;
	do
	{
		scanf("%d", &input);
		if (input == 42)
			break;
		else
			printf("\n%d", input);
	}while(1);

	return 0;
}