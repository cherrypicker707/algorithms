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

long long BinaryLifting::BinaryLifting::getDistance(long long u, long long v)
{
	if(depth[u] < depth[v])
		std::swap(u, v);

	ll depthDifference = depth[u] - depth[v];

	u = getAncestor(u, depthDifference);

	ll distanceToLCA = -1;
	ll left = 0, right = n;
	while(left < right)
	{
		ll middle = (left + right) / 2;

		if(getAncestor(u, middle) == getAncestor(v, middle))
		{
			distanceToLCA = middle;
			right = middle;
			continue;
		}

		left = middle + 1;
	}

	return depthDifference + 2 * distanceToLCA;
}

long long BinaryLifting::BinaryLifting::getAncestor(long long u, long long k)
{
	if(u == -1)
		return -1;

	for(ll i = m - 1; i >= 0; i--)
		if((1 << i) <= k)
			return getAncestor(ancestor[u][i], k - (1 << i));

	return u;
}

void BinaryLifting::BinaryLifting::depthFirstSearch(ll u, ll p, const vvll &adjacent)
{
	if(p == -1)
	{
		depth[u] = 0;

		for(ll i = 0; i < m; i++)
			ancestor[u][i] = -1;
	}
	else
	{
		depth[u] = depth[p] + 1;

		for(ll i = 0; i < m; i++)
			ancestor[u][i] = getAncestor(p, (1 << i) - 1);
	}

	for(ll v : adjacent[u])
	{
		if(v == p)
			continue;

		depthFirstSearch(v, u, adjacent);
	}
}
