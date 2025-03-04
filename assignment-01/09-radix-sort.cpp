#include <iostream>
using namespace std;

int getLargest(int array[], int n)
{
	int max = array[0];
	for (int i = 1; i < n; i++)
		if (array[i] > max)
			max = array[i];
	return max;
}

void countingSort(int array[], int n, int place)
{
	const int max = 10;
	int output[n];
	int count[max];

	for (int i = 0; i < max; ++i)
		count[i] = 0;

	for (int i = 0; i < n; i++)
		count[(array[i] / place) % 10]++;

	for (int i = 1; i < max; i++)
		count[i] += count[i - 1];

	for (int i = n - 1; i >= 0; i--)
	{
		output[count[(array[i] / place) % 10] - 1] = array[i];
		count[(array[i] / place) % 10]--;
	}

	for (int i = 0; i < n; i++)
		array[i] = output[i];
}

void radixSort(int array[], int n)
{
	int max = getLargest(array, n);
	for (int place = 1; max / place > 0; place *= 10)
		countingSort(array, n, place);
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
	int array[] = {148, 147, 154, 384, 122, 408, 1, 34, 91, 3, 4, 12};
	int n = sizeof(array) / sizeof(array[0]);
	radixSort(array, n);
	display(array, n);
	return 0;
}