#pragma once
#include <vector>

typedef long long ll;
typedef std::vector<ll> vll;
typedef std::vector<vll> vvll;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

/*
 * `edge` - array of pairs of integers in form of (u, v) where u and v are vertices of an unrooted tree between which there is an edge.
 * `adjacent` - adjacency list describing an unrooted tree.
 * `parent` - array of integers describing a rooted tree in which the parent of a vertex u is the vertex parent[u]. The parent of the root is always -1.
*/

namespace Tree
{
    vpll get_edge(const vvll &adjacent);
    vvll get_adjacent(const vpll &edge);
    vll get_parent(const vpll &edge, ll root);
    vll get_parent(const vvll &adjacent, ll root);

    void set_parent_with_dfs(vll &parent, const vvll &adjacent, ll u, ll p);
};
