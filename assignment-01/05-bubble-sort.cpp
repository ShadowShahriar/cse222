#include <iostream>
using namespace std;

void bubbleSort(int array[], int n)
{
	for (int pass = 0; pass < n - 1; pass++)
		for (int i = 0; i < n - pass - 1; i++)
			if (array[i] > array[i + 1])
			{
				int temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
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
	bubbleSort(array, n);

	cout << "\nSorted: ";
	display(array, n);
	return 0;
}