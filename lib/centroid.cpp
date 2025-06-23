#include <algorithms/centroid.hpp>
#include <algorithms/tree.hpp>

typedef long long ll;
typedef std::vector<ll> vll;
typedef std::vector<vll> vvll;
typedef std::vector<bool> vbool;

static ll findCentroidWithDFS(const vvll &adjacent, const vll &subtreeSize, ll u, ll p, ll n);

static ll findCentroidWithDFS(const vvll &adjacent, const vbool &removed, const vll &subtreeSize, ll u, ll p, ll n);

static void setDecompositionWithDFS(vll &decomposition, const vvll &adjacent, vbool &removed, vll &subtreeSize, ll u, ll p);

ll Algorithms::Centroid::find(const vvll &adjacent)
{
	ll n = adjacent.size();
	vll subtreeSize = Tree::getSubtreeSize(adjacent, 0);

	return findCentroidWithDFS(adjacent, subtreeSize, 0, -1, subtreeSize[0]);
}

vll Algorithms::Centroid::decompose(const vvll &adjacent)
{
	ll n = adjacent.size();
	vll decomposition(n);
	vbool removed(n, false);
	vll subtreeSize(n);

	setDecompositionWithDFS(decomposition, adjacent, removed, subtreeSize, 0, -1);
	return decomposition;
}

static ll findCentroidWithDFS(const vvll &adjacent, const vll &subtreeSize, ll u, ll p, ll n)
{
	for(ll v : adjacent[u])
	{
		if(v == p)
			continue;

		if(subtreeSize[v] > (n / 2))
			return findCentroidWithDFS(adjacent, subtreeSize, v, u, n);
	}

	return u;
}

static ll findCentroidWithDFS(const vvll &adjacent, const vbool &removed, const vll &subtreeSize, ll u, ll p, ll n)
{
	for(ll v : adjacent[u])
	{
		if(v == p || removed[v])
			continue;

		if(subtreeSize[v] > (n / 2))
			return findCentroidWithDFS(adjacent, removed, subtreeSize, v, u, n);
	}

	return u;
}

static void setDecompositionWithDFS(vll &decomposition, const vvll &adjacent, vbool &removed, vll &subtreeSize, ll u, ll p)
{
	subtreeSize = Algorithms::Tree::getSubtreeSize(adjacent, removed, u);
	u = findCentroidWithDFS(adjacent, removed, subtreeSize, u, -1, subtreeSize[u]);
	decomposition[u] = p;

	removed[u] = true;
	for(ll v : adjacent[u])
	{
		if(removed[v])
			continue;

		setDecompositionWithDFS(decomposition, adjacent, removed, subtreeSize, v, u);
	}
}
