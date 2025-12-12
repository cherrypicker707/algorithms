#include <cmath>
#include <algorithms/binary_lifting.hpp>

typedef long long ll;
typedef std::vector<ll> vll;
typedef std::vector<vll> vvll;

BinaryLifting::BinaryLifting(const vvll &adjacent)
{
    n = adjacent.size();
    m = std::log2(n - 1) + 1;
    depth = vll(n);
    ancestor = vvll(n, vll(m));

    construct_with_dfs(0, -1, adjacent);
}

ll BinaryLifting::get_distance(ll u, ll v) const
{
    ll lca = get_lca(u, v);
    return depth[u] + depth[v] - 2 * depth[lca];
}

ll BinaryLifting::get_lca(ll u, ll v) const
{
    if(depth[u] < depth[v])
        std::swap(u, v);

    u = get_ancestor(u, depth[u] - depth[v]);

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

    u = ancestor[u][0];
    v = ancestor[v][0];

    return u;
}

ll BinaryLifting::get_ancestor(ll u, ll k) const
{
    for(ll i = 0; i < m; i++)
        if(k & (1 << i))
            u = ancestor[u][i];
    return u;
}

void BinaryLifting::construct_with_dfs(ll u, ll p, const vvll &adjacent)
{
    depth[u] = (p > -1 ? depth[p] + 1 : 0);

    ancestor[u][0] = p;
    for(ll i = 1; i < m; i++)
    {
        if(ancestor[u][i - 1] == -1)
        {
            ancestor[u][i] = -1;
            continue;
        }

        ancestor[u][i] = ancestor[ancestor[u][i - 1]][i - 1];
    }

    for(ll v : adjacent[u])
    {
        if(v == p)
            continue;

        construct_with_dfs(v, u, adjacent);
    }
}
