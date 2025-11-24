#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <set>

#define RANDOM(X, Y) std::uniform_int_distribution<ll>(X, Y)(mersenne_twister)

typedef long long ll;
typedef std::set<ll> sll;
typedef std::vector<ll> vll;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

std::random_device device;
std::mt19937_64 mersenne_twister(device());

int main(int argc, char **argv)
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    assert(argc == 5);
    ll n = std::atoll(argv[1]);
    ll m = std::atoll(argv[2]);
    ll min_weight = std::atoll(argv[3]);
    ll max_weight = std::atoll(argv[4]);

    sll edge_indices;
    for(ll i = n * (n - 1) - m; i < n * (n - 1); i++)
    {
        ll edge_index = RANDOM(0, i);

        if(edge_indices.count(edge_index))
        {
            edge_indices.insert(i);
            continue;
        }

        edge_indices.insert(edge_index);
    }

    vpll edge;
    edge.reserve(m);
    for(ll edge_index : edge_indices)
    {
        ll u = edge_index / (n - 1);
        ll v = edge_index % (n - 1);

        if(u == v)
            v++;

        edge.push_back({u, v});
    }

    std::shuffle(edge.begin(), edge.end(), mersenne_twister);

    vll weight(m);
    for(ll i = 0; i < m; i++)
        weight[i] = RANDOM(min_weight, max_weight);

    std::cout << n << ' ' << m << '\n';
    for(ll i = 0; i < m; i++)
        std::cout << (edge[i].first + 1) << ' ' << (edge[i].second + 1) << ' ' << weight[i] << '\n';
}
