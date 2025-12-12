#include <algorithms/centroid_decomposition.hpp>

typedef std::vector<bool> vbool;
typedef long long ll;
typedef std::vector<ll> vll;
typedef std::vector<vll> vvll;

vll CentroidDecomposition::decompose(const vvll &adjacent)
{
    ll n = adjacent.size();
    vll decomposition = vll(n);
    vll subtree_size = vll(n);
    vbool removed = vbool(n, false);

    decompose_with_recursion(decomposition, subtree_size, removed, 0, -1, adjacent);
    return decomposition;
}

void CentroidDecomposition::decompose_with_recursion(vll &decomposition, vll &subtree_size, vbool &removed, ll u, ll p, const vvll &adjacent)
{
    set_subtree_size(subtree_size, u, -1, adjacent, removed);
    u = find_centroid(u, -1, subtree_size[u], adjacent, subtree_size, removed);
    decomposition[u] = p;

    removed[u] = true;

    for(ll v : adjacent[u])
    {
        if(removed[v])
            continue;

        decompose_with_recursion(decomposition, subtree_size, removed, v, u, adjacent);
    }
}

void CentroidDecomposition::set_subtree_size(vll &subtree_size, ll u, ll p, const vvll &adjacent, const vbool &removed)
{
    subtree_size[u] = 1;

    for(ll v : adjacent[u])
    {
        if(v == p || removed[v])
            continue;

        set_subtree_size(subtree_size, v, u, adjacent, removed);
        subtree_size[u] += subtree_size[v];
    }
}

ll CentroidDecomposition::find_centroid(ll u, ll p, ll n, const vvll &adjacent, const vll &subtree_size, const vbool &removed)
{
    for(ll v : adjacent[u])
    {
        if(v == p || removed[v])
            continue;

        if(subtree_size[v] > n / 2)
            return find_centroid(v, u, n, adjacent, subtree_size, removed);
    }

    return u;
}
