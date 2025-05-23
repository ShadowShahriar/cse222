#include <iostream>
#include <vector>
typedef long long int lli;
using namespace std;

int main()
{
	lli n, i;
	cin >> n;
	vector<int> a(n);

	for (i = 0; i < n; ++i)
		cin >> a[i];

	a.insert(a.end(), a.begin(), a.end());

	lli maxRest = 0;
	lli currentRest = 0;
	for (i = 0; i < 2 * n; i++)
	{
		if (a[i] == 1)
			currentRest++;
		else
		{
			maxRest = max(maxRest, currentRest);
			currentRest = 0;
		}
	}

	maxRest = max(maxRest, currentRest);
	cout << min(maxRest, n) << endl;
	return 0;
}
