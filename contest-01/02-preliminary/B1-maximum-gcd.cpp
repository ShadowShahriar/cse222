#include <iostream>
#include <vector>
typedef long long int lli;
using namespace std;
const int MAX = 1000000;

int main()
{
	lli N, K;
	cin >> N >> K;
	vector<int> arr(N);
	vector<int> occ(MAX + 1, 0);

	for (lli i = 0; i < N; ++i)
	{
		cin >> arr[i];
		occ[arr[i]]++;
	}

	for (lli d = MAX; d >= 1; --d)
	{
		lli multiples = 0;
		for (lli j = d; j < MAX; j += d)
			multiples += occ[j];

		if (multiples >= K)
		{
			cout << d << endl;
			return 0;
		}
	}
	cout << 1 << endl;
	return 0;
}