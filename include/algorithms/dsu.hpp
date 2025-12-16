#pragma once
#include <vector>

typedef long long ll;
typedef std::vector<ll> vll;

class DSU
{
public:
    DSU(ll n = 0);
    void make(ll u);
    void join(ll u, ll v);
    ll find(ll u);
private:
    vll parent, rank;
};
