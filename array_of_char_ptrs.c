#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *names_list[10];
	/* names_list contains 10 elements wherein each element points to a char */
	int i;
	char names[10][10];

	for (i = 0; i < 2; i++)
	{
		printf("\nEnter name %d", i + 1);
		fgets(names, 10, stdin);
		strcpy(names_list[i], names);
	}

	printf("\nThe names are: %s and %s", *(names_list), *(names_list + 1));

	//free (names_list);
	return 0;
}