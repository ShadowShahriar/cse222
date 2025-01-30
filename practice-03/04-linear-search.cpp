#include <iostream>
using namespace std;

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
	cin >> data;

	int result = linearSearch(array, data);
	if (result)
		cout << "NOT found";
	else
		cout << data << " was found at index " << result;

	return 0;
}