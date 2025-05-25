#include <pruefer/pruefer.hpp>
#include <pruefer/conversion.hpp>

typedef long long ll;
typedef std::vector<ll> vll;
typedef std::vector<vll> vvll;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

vll Pruefer::encode(const vpll &edge)
{
	ll n = edge.size() + 1;
	vll code(n - 2);
	vvll adjacent = getAdjacentFromEdge(edge);
	vll parent = getParentFromAdjacent(adjacent, n - 1);

	std::vector<long long> degree(n);
	for(ll i = 0; i < n; i++)
		degree[i] = adjacent[i].size();

	ll pointer = 0, leaf = 0;
	for(ll i = 0; i < n - 2; i++)
	{
		while(leaf > pointer || degree[leaf] != 1)
			leaf = ++pointer;

		code[i] = parent[leaf];

		degree[leaf]--;
		degree[parent[leaf]]--;

		leaf = parent[leaf];
	}

	return code;
}

vpll Pruefer::decode(const vll &code)
{
	ll n = code.size() + 2;

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
		}
	}

	return edge;
}
