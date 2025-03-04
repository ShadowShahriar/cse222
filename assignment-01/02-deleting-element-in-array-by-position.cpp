#include <iostream>
using namespace std;

int main()
{
	int array[] = {122, 147, 148, 408, 154};
	int loc = 3;

	int count = sizeof(array) / sizeof(array[0]);

	for (int j = loc; j < count - 1; j++)
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