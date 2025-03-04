#include <iostream>
using namespace std;

int main()
{
	int array[100] = {122, 147, 148, 154, 408};
	int count = 5;

	int elm, pos;
	cout << "Enter the element and its position: " << endl;
	cin >> elm >> pos;

	if (pos > count)
		pos = count;

	for (int i = count - 1; i >= pos; i--)
		array[i + 1] = array[i];

	array[pos] = elm;
	count++;

	cout << "The element " << elm << " was inserted at index " << pos << endl;
	cout << "New size of the Array: " << count << endl;
	cout << "The elements of the Array:" << endl;

	for (int i = 0; i < count; i++)
	{
		cout << array[i];
		if (i != count - 1)
			cout << " ";
	}
	return 0;
}