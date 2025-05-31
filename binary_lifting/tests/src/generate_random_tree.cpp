#include <iostream>
#include <random>
#include <algorithm>

typedef long long ll;
typedef std::vector<ll> vll;
typedef std::vector<vll> vvll;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

std::random_device device;
std::mt19937_64 mersenne_twister(device());

int main()
{
	ll n;
	std::cin >> n;

	vll code(n - 2);
	for(ll i = 0; i < n - 2; i++)
		code[i] = std::uniform_int_distribution<ll>(0, n - 1)(mersenne_twister);

	vll degree(n, 1);
	for(ll i = 0; i < n - 2; i++)
		degree[code[i]]++;

	vpll edge;
	edge.reserve(n - 1);

	ll pointer = 0, leaf = 0;
	for(ll i = 0; i < n - 2; i++)
	{
		while(leaf > pointer || degree[leaf] != 1)
			leaf = ++pointer;

		edge.push_back({leaf, code[i]});

		degree[leaf]--;
		degree[code[i]]--;

		leaf = code[i];
	}

	for(ll u = 0; u < n - 1; u++)
	{
		if(degree[u] == 1)
		{
			edge.push_back({u, n - 1});

			degree[u]--;
			degree[n - 1]--;

			break;
		}
	}

	for(ll i = 0; i < n - 1; i++)
		if(std::bernoulli_distribution(0.5)(mersenne_twister))
			std::swap(edge[i].first, edge[i].second);

	std::shuffle(edge.begin(), edge.end(), mersenne_twister);

	std::cout << n << '\n';

	for(ll i = 0; i < n - 1; i++)
		std::cout << (edge[i].first + 1) << ' ' << (edge[i].second + 1) << '\n';

	for(ll i = 0; i < n; i++)
		std::cout << std::uniform_int_distribution<ll>(1, n)(mersenne_twister) << ' ' << std::uniform_int_distribution<ll>(1, n)(mersenne_twister) << '\n';

	return 0;
}
