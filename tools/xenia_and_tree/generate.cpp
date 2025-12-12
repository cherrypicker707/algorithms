#include <algorithms/pruefer.hpp>
#include <algorithms/tree.hpp>
#include <vector>
#include <random>
#include <algorithm>
#include <iostream>

#define RANDOM(X, Y) std::uniform_int_distribution<ll>(X, Y)(mersenne_twister)

typedef long long ll;
typedef std::vector<ll> vll;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

std::random_device device;
std::mt19937_64 mersenne_twister(device());

int main(int argc, char **argv)
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    ll min_n = std::atoll(argv[1]);
    ll max_n = std::atoll(argv[2]);
    ll min_q = std::atoll(argv[3]);
    ll max_q = std::atoll(argv[4]);

    ll n = RANDOM(min_n, max_n);
    ll q = RANDOM(min_q, max_q);

    vll code(n - 2);
    for(ll i = 0; i < n - 2; i++)
        code[i] = RANDOM(0, n - 1);

    vvll adjacent = Pruefer::decode(code);
    vpll edge = Tree::get_edge(adjacent);

    for(ll i = 0; i < n - 1; i++)
        if(RANDOM(0, 1))
            std::swap(edge[i].first, edge[i].second);
    std::shuffle(edge.begin(), edge.end(), mersenne_twister);

    std::cout << n << ' ' << q << '\n';
    for(ll i = 0; i < n - 1; i++)
        std::cout << (edge[i].first + 1) << ' ' << (edge[i].second + 1) << '\n';

    for(ll i = 0; i < q; i++)
        std::cout << RANDOM(1, 2) << ' ' << RANDOM(1, n) << '\n';

    return 0;
}
