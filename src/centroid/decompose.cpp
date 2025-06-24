#include <algorithms/centroid.hpp>
#include <vector>
#include <iostream>
#include <cmath>
#include <cassert>

typedef long long ll;
typedef std::vector<ll> vll;
typedef std::vector<vll> vvll;

ll n;
vvll adjacent;

int main()
{
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

	vll decomposition = Algorithms::Centroid::decompose(adjacent);

	for(ll i = 0; i < n; i++)
		std::cout << (decomposition[i] + 1) << ' ';
	std::cout << '\n';
}
