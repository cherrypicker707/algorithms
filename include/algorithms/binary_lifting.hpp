#pragma once
#include <vector>

typedef long long ll;
typedef std::vector<ll> vll;
typedef std::vector<vll> vvll;

class BinaryLifting
{
public:
    BinaryLifting(const vvll &adjacent);
    BinaryLifting(const vll &parent);
    ll get_distance(ll u, ll v) const;
    ll get_lca(ll u, ll v) const;
    ll get_ancestor(ll u, ll k) const;

private:
    void construct_with_dfs(ll u, ll p, const vvll &adjacent);

    ll n, m;
    vll depth;
    vvll ancestor;
};
