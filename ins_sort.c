#include<stdio.h>

int main()
{
	int i, j, arr[5], temp;

	printf("\n\nEnter array of 5 numbers: ");
	for (i = 0; i < 5; i++)
		scanf("%d", &arr[i]);

	for (i = 0; i < 5; i++)
	{
			j = i;

			while(j > 0 && arr[j] < arr[j-1])
			{
				temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;;
				j = j-1;
			}
				
	}

	printf("\n\nSorted array is : ");
	for (i = 0; i < 5; i++)
		printf("%d ", arr[i]);
	return 0;
}