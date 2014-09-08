#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *pi = (int*) malloc(sizeof(int));
	*pi = 5;
	printf("\nAssigning new memory location.");
	free(pi);
	printf("\nMemory freed!");
	//*pi = 6;
	return 0;
}

/*#include<stdio.h>
#include<stdlib.h>

int main()
{
	char *str = (char *) malloc (20);
	printf("Enter string : ");
	scanf("%[^\n]s", str);
	printf("The string you entered : %s\n", str);
	printf("%c\n", str[3]);
	free(str);
	printf("Memory freed!\n");
	printf("The string you entered : %s\n", str);
	return 0;
}*/