#include <vector>
#include <algorithms/tree.hpp>

typedef long long ll;
typedef std::vector<ll> vll;
typedef std::vector<vll> vvll;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

vpll Tree::get_edge(const vvll &adjacent)
{
    const ll n = adjacent.size();

    vpll edge;
    edge.reserve(n - 1);

    for(ll u = 0; u < n; u++)
    {
        for(ll v : adjacent[u])
        {
            if(v < u)
                continue;

            edge.push_back({u, v});
        }
    }

    return edge;
}

vvll Tree::get_adjacent(const vpll &edge)
{
    const ll n = edge.size() + 1;

    vll degree(n, 0);
    for(ll i = 0; i < n - 1; i++)
    {
        ll u = edge[i].first;
        ll v = edge[i].second;

        degree[u]++;
        degree[v]++;
    }

    vvll adjacent(n);
    for(ll u = 0; u < n; u++)
        adjacent[u].reserve(degree[u]);

    for(ll i = 0; i < n - 1; i++)
    {
        ll u = edge[i].first;
        ll v = edge[i].second;

        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
    }

    return adjacent;
}

vll Tree::get_parent(const vpll &edge, ll root)
{
    vvll adjacent = get_adjacent(edge);
    return get_parent(adjacent, root);
}

vll Tree::get_parent(const vvll &adjacent, ll root)
{
    const ll n = adjacent.size();

    vll parent(n);
    set_parent_with_dfs(parent, adjacent, root, -1);

    return parent;
}

void Tree::set_parent_with_dfs(vll &parent, const vvll &adjacent, ll u, ll p)
{
    parent[u] = p;

    for(ll v : adjacent[u])
    {
        if(v == p)
            continue;

        set_parent_with_dfs(parent, adjacent, v, u);
    }
}
