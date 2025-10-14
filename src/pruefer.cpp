#include <vector>
#include <algorithms/pruefer.hpp>
#include <algorithms/tree.hpp>

typedef long long ll;
typedef std::vector<ll> vll;
typedef std::vector<vll> vvll;

vll Pruefer::encode(const vvll &adjacent)
{
    const ll n = adjacent.size();

    vll degree(n);
    for(ll u = 0; u < n; u++)
        degree[u] = adjacent[u].size();

    const vll parent = Tree::get_parent(adjacent, n - 1);

    vll code(n - 2);
    for(ll i = 0, j = 0, u = 0; i < n - 2; i++)
    {
        while(degree[u] != 1 || u > j)
            u = ++j;

        const ll v = parent[u];
        code[i] = v;
        degree[u]--;
        degree[v]--;
        u = v;
    }

    return code;
}

vvll Pruefer::decode(const vll &code)
{
    const ll n = code.size() + 2;

    vll degree(n, 1);
    for(ll i = 0; i < n - 2; i++)
        degree[code[i]]++;

    vvll adjacent(n);
    for(ll u = 0; u < n; u++)
        adjacent[u].reserve(degree[u]);

    for(ll i = 0, j = 0, u = 0; i < n - 1; i++)
    {
        while(degree[u] != 1 || u > j)
            u = ++j;

        const ll v = (i < n - 2 ? code[i] : n - 1);
        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
        degree[u]--;
        degree[v]--;
        u = v;
    }

    return adjacent;
}
