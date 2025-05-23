#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string n;
		cin >> n;
		int dmax = 0;
		for (char c : n)
			dmax = max(dmax, c - '0');
		cout << dmax << endl;
	}
	return 0;
}
