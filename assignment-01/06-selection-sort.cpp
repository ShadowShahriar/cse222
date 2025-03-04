#include <iostream>
using namespace std;

void selectionSort(int array[], int n, bool ascending)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (array[min] > array[j] && ascending || array[min] < array[j] && !ascending)
				min = j;
		int temp = array[i];
		array[i] = array[min];
		array[min] = temp;
	}
}

void display(int array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << array[i];
		if (i != n - 1)
			cout << ", ";
	}
}

int main()
{
	int array[5] = {0};
	int n = sizeof(array) / sizeof(array[0]);
	for (int i = 0; i < n; i++)
		cin >> array[i];

	cout << "Array : ";
	display(array, n);
	selectionSort(array, n, true);

	cout << "\nSorted: ";
	display(array, n);
	return 0;
}