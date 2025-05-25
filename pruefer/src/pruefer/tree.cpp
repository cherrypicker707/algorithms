#include <pruefer/tree.hpp>

typedef long long ll;
typedef std::vector<ll> vll;
typedef std::vector<vll> vvll;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

static void constructParentFromAdjacent(const vvll &adjacent, ll u, ll p, vll &parent);

vpll Pruefer::getEdgeFromAdjacent(const vvll &adjacent)
{
	ll n = adjacent.size();

	vpll edge;
	edge.reserve(n - 1);

	for(ll u = 0; u < n; u++)
		for(ll v : adjacent[u])
			if(u < v)
				edge.push_back({u, v});

	return edge;
}

vvll Pruefer::getAdjacentFromEdge(const vpll &edge)
{
	ll n = edge.size() + 1;

	vll degree(n, 0);
	for(ll i = 0; i < n - 1; i++)
	{
		ll u = edge[i].first;
		ll v = edge[i].second;

		degree[u]++;
		degree[v]++;
	}

	vvll adjacent(n);
	for(ll i = 0; i < n; i++)
		adjacent[i].reserve(degree[i]);

	for(ll i = 0; i < n - 1; i++)
	{
		ll u = edge[i].first;
		ll v = edge[i].second;

		adjacent[u].push_back(v);
		adjacent[v].push_back(u);
	}

	return adjacent;
}

vll Pruefer::getParentFromAdjacent(const vvll &adjacent, ll root)
{
	ll n = adjacent.size();
	vll parent(n);

	constructParentFromAdjacent(adjacent, root, -1, parent);

	return parent;
}

static void constructParentFromAdjacent(const vvll &adjacent, ll u, ll p, vll &parent)
{
	parent[u] = p;

	for(ll v : adjacent[u])
		if(v != p)
			constructParentFromAdjacent(adjacent, v, u, parent);
}
