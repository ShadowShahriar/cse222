#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> stores(n);
	for (int i = 0; i < n; i++)
		cin >> stores[i];

	int tSum = 0;
	int jSum = 0;

	for (int i = 0; i < n; i++)
	{
		if ((i + 1) % 2 == 0)
			jSum += stores[i];
		else
			tSum += stores[i];
	}

	cout << (tSum > jSum ? "YES" : "NO") << endl;
	return 0;
}
