#include <vector>
#include <set>
#include <random>
#include <iostream>
#include <algorithm>

#define RANDOM(X, Y) std::uniform_int_distribution<ll>(X, Y - 1)(mersenne_twister)

typedef long long ll;
typedef std::set<ll> sll;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

std::random_device device;
std::mt19937_64 mersenne_twister(device());

ll get_random_element(const sll &set);

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    ll n;
    std::cin >> n;

    sll unadded, added;
    for(ll u = 0; u < n; u++)
        unadded.insert(u);

    ll root = RANDOM(0, n);
    unadded.erase(root);
    added.insert(root);

    vpll edge;
    edge.reserve(n - 1);

    for(ll i = 0; i < n - 1; i++)
    {
        ll u = get_random_element(unadded);
        ll v = get_random_element(added);

        unadded.erase(u);
        added.insert(u);

        edge.push_back({u, v});
    }

    for(ll i = 0; i < n - 1; i++)
        if(RANDOM(0, 2))
            std::swap(edge[i].first, edge[i].second);
    std::shuffle(edge.begin(), edge.end(), mersenne_twister);

    std::cout << n << '\n';
    for(ll i = 0; i < n - 1; i++)
        std::cout << (edge[i].first + 1) << ' ' << (edge[i].second + 1) << '\n';

    return 0;
}

ll get_random_element(const sll &set)
{
    ll n = set.size();
    ll i = RANDOM(0, n);
    auto it = set.begin();
    std::advance(it, i);
    return *it;
}
