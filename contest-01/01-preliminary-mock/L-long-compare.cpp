#include <iostream>
#include <string>
using namespace std;

char shortcutCompare(string a, int pa, string b, int pb)
{
	int lA = a.length() + pa;
	int lB = b.length() + pb;

	if (lA > lB)
		return '>';
	if (lA < lB)
		return '<';

	int maxLen = max(a.length(), b.length());
	for (int i = 0; i < maxLen; ++i)
	{
		char digitA = (i < a.length()) ? a[i] : '0';
		char digitB = (i < b.length()) ? b[i] : '0';
		if (digitA > digitB)
			return '>';
		if (digitA < digitB)
			return '<';
	}

	return '=';
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string x1, x2;
		int p1, p2;
		cin >> x1 >> p1;
		cin >> x2 >> p2;
		cout << shortcutCompare(x1, p1, x2, p2) << endl;
	}

	return 0;
}
