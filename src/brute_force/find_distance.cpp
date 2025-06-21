#include <vector>
#include <iostream>

typedef long long ll;
typedef std::vector<ll> vll;
typedef std::vector<vll> vvll;

vvll adjacent;

ll getDistance(ll u, ll p, ll destination);

int main()
{
	ll n;
	std::cin >> n;

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

	for(ll i = 0; i < n; i++)
	{
		ll u, v;
		std::cin >> u >> v;
		u--;
		v--;

		ll distance = getDistance(u, -1, v);
		std::cout << distance << '\n';
	}

	return 0;
}

ll getDistance(ll u, ll p, ll destination)
{
	if(u == destination)
		return 0;

	for(ll v : adjacent[u])
	{
		if(v == p)
			continue;

		ll distance = getDistance(v, u, destination);

		if(distance != -1)
			return distance + 1;
	}

	return -1;
}
