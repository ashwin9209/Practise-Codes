#include<stdio.h>

int main(void)
{
	char *str = "ashwin";
	char *temp;
	int i, j = 0, k, len;

	for(i = 0; (str[i]) != '\0'; i++)
		;

	i--;
	len = i/2;

	for(k = 0; k < len/2; k++)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		j++;
		i--;
	}

	printf("String is %s", str);

return 0;
}