#include <stdio.h>

int linearSearch(int *array, int data)
{
	int n = sizeof(array);
	int i, found = -1;

	for (i = 0; i < n; i++)
		if (array[i] == data)
		{
			found = i;
			break;
		}

	return found;
}

int main()
{
	int array[] = {122, 147, 148, 154, 384, 387, 408, 424};
	int data;
	scanf("%d", &data);

	int result = linearSearch(array, data);
	result == -1 ? printf("NOT found") : printf("%d was found at index %d", data, result);

	return 0;
}