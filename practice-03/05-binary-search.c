#include <stdio.h>

int binarySearch(int array[], int data, int n)
{
	int l = 0, r = n - 1, mid;
	while (l < r)
	{
		mid = (l + r) / 2;
		if (array[mid] == data)
			return mid;
		else if (array[mid] < data)
			l = mid - 1;
		else
			r = mid + 1;
	}
	return -1;
}

int main()
{
	int array[] = {5, 10, 15, 16, 18, 32, 37, 44};
	int n = sizeof(array) / sizeof(array[0]);

	int data = 18;
	int result = binarySearch(array, data, n);

	if (result == -1)
		printf("NOT found");
	else
		printf("%d found at index %d", data, result);
	return 0;
}