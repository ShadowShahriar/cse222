#include <iostream>
#include <vector>
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

const ll N = 10e6 + 1;
vector<bool> isprime(N, 1);

void sieve()
{
	isprime[0] = isprime[1] = false;
	for (ll i = 2; i < N; i++)
		if (isprime[i])
			for (ll j = 2 * i; j < N; j += i)
				isprime[j] = false;
}

int main()
{
	fast;
	sieve();

	string s, a = "";
	cin >> s;

	for (ll i = 0; i < s.length(); i++)
		if (!isprime[i + 1])
			a += s[i];

	cout << a << endl;
	return 0;
}
