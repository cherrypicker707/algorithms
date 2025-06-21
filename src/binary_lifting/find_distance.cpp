#include <algorithms/binary_lifting.hpp>
#include <vector>
#include <iostream>

typedef long long ll;
typedef std::vector<ll> vll;
typedef std::vector<vll> vvll;

int main()
{
	ll n;
	std::cin >> n;

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

	Algorithm::BinaryLifting binaryLifting(adjacent);

	for(ll i = 0; i < n; i++)
	{
		ll u, v;
		std::cin >> u >> v;
		u--;
		v--;

		ll distance = binaryLifting.getDistance(u, v);
		std::cout << distance << '\n';
	}

	return 0;
}
