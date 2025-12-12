#pragma once
#include <vector>

typedef std::vector<bool> vbool;
typedef long long ll;
typedef std::vector<ll> vll;
typedef std::vector<vll> vvll;

namespace CentroidDecomposition
{
    vll decompose(const vvll &adjacent);
    void decompose_with_recursion(vll &decomposition, vll &subtree_size, vbool &removed, ll u, ll p, const vvll &adjacent);
    void set_subtree_size(vll &subtree_size, ll u, ll p, const vvll &adjacent, const vbool &removed);
    ll find_centroid(ll u, ll p, ll n, const vvll &adjacent, const vll &subtree_size, const vbool &removed);
};
