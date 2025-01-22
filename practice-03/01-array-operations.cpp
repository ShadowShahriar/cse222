#include <iostream>
#define count 5
using namespace std;

int main()
{
	// [1]. array declaration
	char grades[count];

	// [2]. taking user input
	for (int i = 0; i < count; i++)
		cin >> grades[i];

	// [3]. printing array elements
	for (int i = 0; i < count; i++)
		cout << "Index " << i << ": " << grades[i] << endl;

	// [4]. get array size
	cout << "   Size: " << sizeof(grades) / sizeof(grades[0]) << endl;
	return 0;
}