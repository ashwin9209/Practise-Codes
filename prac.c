#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char *str = malloc (128*sizeof(char));
	int length, i, j, flag = 0;

	printf("\n\nEnter string: ");
	fgets(str, 20, stdin);
	printf("You entered: %s", str);

	length = strlen(str);
	printf("Length: %d\n", length);

	j = length - 2;

	for(i = 0; i < length/2; i++)
	{
		if (str[i] == str[j])
		{
			j--;
			continue;
		}

		else
		{
			flag = 1;
			break;
		}
	}

	if(flag == 0)
		printf("\n\nPalindrome.");
	else
		printf("\n\n!Palindrome.");

	return 0;
}