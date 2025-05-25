#include <iostream>
typedef long long ll;
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		ll K, M, N;
		cin >> K >> M >> N;

		ll fr = N / 7;
		ll milk_days = N - fr;
		ll total_milk = milk_days * K * M;
		cout << total_milk << endl;
	}

	return 0;
}
