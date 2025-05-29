#include <iostream>
typedef long long ll;
using namespace std;

#define fast                 \
	ios::sync_with_stdio(0); \
	cin.tie(0);              \
	cout.tie(0);

int main()
{
	fast;
	ll t;
	cin >> t;
	while (t--)
	{
		ll x, y, z;
		cin >> x >> y;
		z = x * y;

		while (z > 9)
			z /= 10;
		cout << z << "\n";
	}
	return 0;
}
