#include <iostream>
using namespace std;

#define fast                 \
	ios::sync_with_stdio(0); \
	cin.tie(0);              \
	cout.tie(0);

#define test  \
	int t;    \
	cin >> t; \
	while (t--)

#define fr(i, n) for (int i = 0; i < n; i++)
#define vi vector<int>
using ll = long long;

void solve()
{
	ll m, c;
	cin >> m >> c;

	if (m % c == 0)
		cout << 0 << endl;
	else
	{
		ll v = m / c;
		v++;
		ll tm = v * c;
		ll mn = tm - m;
		cout << mn << endl;
	}
}

int main()
{
	fast;
	solve();
	return 0;
}
