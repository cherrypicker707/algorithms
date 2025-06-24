#include <algorithms/centroid.hpp>
#include <algorithms/binary_lifting.hpp>
#include <iostream>
#include <climits>
#include <cmath>
#include <cassert>

typedef long long ll;
typedef std::vector<ll> vll;
typedef std::vector<vll> vvll;

vll centroidDecomposition, a;
Algorithms::BinaryLifting binaryLifting;

void paintRed(ll u);

ll getDistanceToTheNearestRed(ll u);

int main()
{
	ll n, m;
	std::cin >> n >> m;

	vvll adjacent(n);
	for(ll i = 0; i < n - 1; i++)
	{
		ll u, v;
		std::cin >> u >> v;
		u--;
		v--;

		adjacent[u].push_back(v);
		adjacent[v].push_back(u);
	}

	a = vll(n, LLONG_MAX);
	centroidDecomposition = Algorithms::Centroid::decompose(adjacent);
	binaryLifting = Algorithms::BinaryLifting(adjacent);

	paintRed(0);
	for(ll i = 0; i < m; i++)
	{
		ll t, u;
		std::cin >> t >> u;
		u--;

		if(t == 1)
		{
			paintRed(u);
			continue;
		}

		std::cout << getDistanceToTheNearestRed(u) << '\n';
	}
}

void paintRed(ll u)
{
	ll v = u;
	while(v != -1)
	{
		a[v] = std::min(a[v], binaryLifting.getDistance(u, v));
		v = centroidDecomposition[v];
	}
}

ll getDistanceToTheNearestRed(ll u)
{
	ll v = u, distance = LLONG_MAX;
	while(v != -1)
	{
		if(a[v] != LLONG_MAX)
			distance = std::min(distance, binaryLifting.getDistance(u, v) + a[v]);
		v = centroidDecomposition[v];
	}

	return distance;
}
