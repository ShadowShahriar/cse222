#include <iostream>
using namespace std;

int main()
{
	int array[] = {122, 147, 148, 408, 154};
	int target = 408;

	int count = sizeof(array) / sizeof(array[0]);

	int i = -1;
	while (array[++i] != target)
		if (i > count)
		{
			i = -1;
			break;
		}

	if (i == -1)
	{
		cout << "Unable to find the target element: " << target << endl;
		return 0;
	}

	for (int j = i; j < count - 1; j++)
		array[j] = array[j + 1];
	count--;

	for (int i = 0; i < count; i++)
	{
		cout << array[i];
		if (i != count - 1)
			cout << " ";
	}

	return 0;
}