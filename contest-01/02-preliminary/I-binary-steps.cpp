#include <iostream>
#include <vector>
#include <queue>
typedef long long ll;
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<ll> cost(n);

	for (int i = 1; i <= n; i++)
		cin >> cost[i];

	vector<ll> minCost(n + 1, LLONG_MAX);
	minCost[1] = cost[1];

	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
	pq.push({cost[1], 1});

	while (!pq.empty())
	{
		auto [curCost, pos] = pq.top();
		pq.pop();

		if (curCost > minCost[pos])
			continue;

		for (int j = 1; pos + j <= n; j *= 2)
		{
			int next = pos + j;
			long long newCost = curCost + cost[next];

			if (newCost < minCost[next])
			{
				minCost[next] = newCost;
				pq.push({newCost, next});
			}
		}
	}

	cout << minCost[n] << endl;
	return 0;
}
