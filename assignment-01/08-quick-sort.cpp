#include <iostream>
using namespace std;

int partition(int a[], int l, int h)
{
	int pivot = a[l];
	int i = l;
	int j = h;

	while (i < j)
	{
		while (a[i] <= pivot)
			i++;
		while (a[j] > pivot)
			j--;
		if (i < j)
			swap(a[i], a[j]);
	}
	swap(a[l], a[j]);
	return j;
}

void quickSort(int a[], int l, int h)
{
	if (l < h)
	{
		int location = partition(a, l, h);
		quickSort(a, l, location - 1);
		quickSort(a, location + 1, h);
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
	int a[] = {33, 1, 0, 76, 2};
	int n = sizeof(a) / sizeof(a[0]);
	quickSort(a, 0, n - 1);
	display(a, n);
	return 0;
}