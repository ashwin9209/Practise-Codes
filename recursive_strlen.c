#include <stdio.h>

int str_length(char *name)
{
	if (*name == '\0')
		return 0;
	else
		return 1 + str_length(++name);
}

int main()
{
	char *name = "Ashwin";
	int length;
	length = str_length(name);

	printf("Length: %d", length);
	return 0;
}