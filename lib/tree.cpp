#include <algorithms/tree.hpp>
#include <cassert>

typedef long long ll;
typedef std::vector<ll> vll;
typedef std::vector<vll> vvll;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;
typedef std::vector<bool> vbool;

static void setParentWithDFS(vll &parent, const vvll &adjacent, ll u, ll p);

static void setSubtreeSizeWithDFS(vll &subtreeSize, const vvll &adjacent, ll u, ll p);

static void setSubtreeSizeWithDFS(vll &subtreeSize, const vvll &adjacent, const vbool &removed, ll u, ll p);

vvll Algorithms::Tree::getAdjacent(const vpll &edge)
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

vpll Algorithms::Tree::getEdge(const vvll &adjacent)
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

vll Algorithms::Tree::getParent(const vvll &adjacent, ll root)
{
	ll n = adjacent.size();
	vll parent(n);

	setParentWithDFS(parent, adjacent , root, -1);
	return parent;
}

vll Algorithms::Tree::getSubtreeSize(const vvll &adjacent, ll root)
{
	ll n = adjacent.size();
	vll subtreeSize(n);

	setSubtreeSizeWithDFS(subtreeSize, adjacent, root, -1);
	return subtreeSize;
}

vll Algorithms::Tree::getSubtreeSize(const vvll &adjacent, const vbool &removed, ll root)
{
	ll n = adjacent.size();
	assert(removed.size() == n);
	vll subtreeSize(n);

	setSubtreeSizeWithDFS(subtreeSize, adjacent, removed, root, -1);
	return subtreeSize;
}

void Algorithms::Tree::setParentWithDFS(vll &parent, const vvll &adjacent, ll u, ll p)
{
	parent[u] = p;

	for(ll v : adjacent[u])
		if(v != p)
			setParentWithDFS(parent, adjacent, v, u);
}

void Algorithms::Tree::setSubtreeSizeWithDFS(vll &subtreeSize, const vvll &adjacent, ll u, ll p)
{
	subtreeSize[u] = 1;

	for(ll v : adjacent[u])
	{
		if(v == p)
			continue;

		setSubtreeSizeWithDFS(subtreeSize, adjacent, v, u);
		subtreeSize[u] += subtreeSize[v];
	}
}

void Algorithms::Tree::setSubtreeSizeWithDFS(vll &subtreeSize, const vvll &adjacent, const vbool &removed, ll u, ll p)
{
	subtreeSize[u] = 1;

	for(ll v : adjacent[u])
	{
		if(v == p || removed[v])
			continue;

		setSubtreeSizeWithDFS(subtreeSize, adjacent, removed, v, u);
		subtreeSize[u] += subtreeSize[v];
	}
}
