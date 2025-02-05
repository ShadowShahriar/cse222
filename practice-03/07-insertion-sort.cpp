#include <iostream>
using namespace std;

void insertionSort(int array[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int temp = array[i], j = i - 1;
		while (j >= 0 && array[j] > temp)
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = temp;
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
	insertionSort(array, n);

	cout << "\nSorted: ";
	display(array, n);
	return 0;
}