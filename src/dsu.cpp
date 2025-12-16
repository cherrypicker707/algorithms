#include <vector>
#include <algorithms/dsu.hpp>

typedef long long ll;
typedef std::vector<ll> vll;

DSU::DSU(ll n)
{
    parent = vll(n, -1);
    rank = vll(n, -1);
}

void DSU::make(ll u)
{
    if(parent[u] == -1)
    {
        parent[u] = u;
        rank[u] = 0;
    }
}

void DSU::join(ll u, ll v)
{
    u = find(u);
    v = find(v);

    if(u == -1 || v == -1 || u == v)
        return;

    if(rank[u] > rank[v])
        std::swap(u, v);

    parent[u] = v;

    if(rank[u] == rank[v])
        rank[v]++;
}

ll DSU::find(ll u)
{
    if(parent[u] == u || parent[u] == -1)
        return parent[u];
    return parent[u] = find(parent[u]);
}
