#include <algorithms/pruefer.hpp>
#include <algorithms/tree.hpp>
#include <vector>
#include <random>
#include <algorithm>
#include <iostream>

#define RANDOM(X, Y) std::uniform_int_distribution<ll>(X, Y - 1)(mersenne_twister)

typedef long long ll;
typedef std::vector<ll> vll;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

std::random_device device;
std::mt19937_64 mersenne_twister(device());

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    ll n;
    std::cin >> n;

    vll code(n - 2);
    for(ll i = 0; i < 2; i++)
        code[i] = RANDOM(0, n);

    vvll adjacent = Pruefer::decode(code);
    vpll edge = Tree::get_edge(adjacent);

    for(ll i = 0; i < n - 1; i++)
        if(RANDOM(0, 2))
            std::swap(edge[i].first, edge[i].second);
    std::shuffle(edge.begin(), edge.end(), mersenne_twister);

    std::cout << n << '\n';
    for(ll i = 0; i < n - 1; i++)
        std::cout << (edge[i].first + 1) << ' ' << (edge[i].second + 1) << '\n';

    return 0;
}
