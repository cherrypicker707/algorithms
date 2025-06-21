#include <binary_lifting/binary_lifting.hpp>
#include <cmath>

typedef long long ll;
typedef std::vector<ll> vll;
typedef std::vector<vll> vvll;

BinaryLifting::BinaryLifting::BinaryLifting(const vvll &adjacent)
{
	n = adjacent.size();
	m = ceil(log2(n)) + 1;
	depth = vll(n);
	ancestor = vvll(n, vll(m));

	depthFirstSearch(0, -1, adjacent);
}

ll BinaryLifting::BinaryLifting::getDistance(ll u, ll v)
{
	ll w = getLCA(u, v);
	return depth[u] + depth[v] - 2 * depth[w];
}

ll BinaryLifting::BinaryLifting::getLCA(ll u, ll v)
{
	if(depth[u] < depth[v])
		std::swap(u, v);
	u = getAncestor(u, depth[u] - depth[v]);

	if(u == v)
		return u;

	for(ll i = m - 1; i >= 0; i--)
	{
		if(ancestor[u][i] != ancestor[v][i])
		{
			u = ancestor[u][i];
			v = ancestor[v][i];
		}
	}

	return ancestor[u][0];
}

ll BinaryLifting::BinaryLifting::getAncestor(ll u, ll k)
{
	if(k >= n)
		return -1;

	for(ll i = 0; i < m; i++)
	{
		if(u == -1)
			break;

		if(k & (1 << i))
			u = ancestor[u][i];
	}

	return u;
}

void BinaryLifting::BinaryLifting::depthFirstSearch(ll u, ll p, const vvll &adjacent)
{
	depth[u] = 0;
	if(p != -1)
		depth[u] = depth[p] + 1;

	ancestor[u][0] = p;
	for(ll i = 1; i < m; i++)
	{
		if(ancestor[u][i - 1] == -1)
			break;

		ancestor[u][i] = ancestor[ancestor[u][i - 1]][i - 1];
	}

	for(ll v : adjacent[u])
	{
		if(v == p)
			continue;

		depthFirstSearch(v, u, adjacent);
	}
}
