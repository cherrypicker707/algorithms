#include <iostream>
#include <vector>
#include <climits>

typedef long long ll;
typedef std::vector<ll> vll;
typedef std::vector<vll> vvll;
typedef std::vector<bool> vbool;

vvll adjacent;
vbool red;

ll getDistanceToTheNearestRedWithDFS(ll u, ll p);

int main()
{
	ll n, m;
	std::cin >> n >> m;

	adjacent = vvll(n);
	for(ll i = 0; i < n - 1; i++)
	{
		ll u, v;
		std::cin >> u >> v;
		u--;
		v--;

		adjacent[u].push_back(v);
		adjacent[v].push_back(u);
	}

	red = vbool(n, false);
	red[0] = true;

	for(ll i = 0; i < m; i++)
	{
		ll t, u;
		std::cin >> t >> u;
		u--;

		if(t == 1)
		{
			red[u] = true;
			continue;
		}

		std::cout << getDistanceToTheNearestRedWithDFS(u, -1) << '\n';
	}
}

ll getDistanceToTheNearestRedWithDFS(ll u, ll p)
{
	if(red[u])
		return 0;

	ll result = LLONG_MAX;
	for(ll v : adjacent[u])
	{
		if(v == p)
			continue;

		ll child = getDistanceToTheNearestRedWithDFS(v, u);

		if(child != LLONG_MAX)
			result = std::min(result, child + 1);
	}

	return result;
}
