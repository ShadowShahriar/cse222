#include <iostream>
#include <vector>
typedef long long int lli;
using namespace std;

int main()
{
	lli N, K;
	cin >> N >> K;
	vector<int> arr(N);

	const int MAX = N + 1;
	vector<int> occ(MAX, 0);

	for (lli i = 0; i < N; i++)
	{
		lli x;
		cin >> x;
		arr[i] = x;
		occ[x]++;
	}

	for (lli d = MAX; d >= 1; d--)
	{
		lli multiples = 0;
		for (lli j = d; j < MAX; j += d)
			multiples += occ[j];

		if (multiples >= K)
		{
			cout << d << endl;
			break;
		}
	}

	return 0;
}
