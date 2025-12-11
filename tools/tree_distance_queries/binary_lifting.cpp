#include <vector>
#include <iostream>
#include <algorithms/binary_lifting.hpp>

typedef long long ll;
typedef std::vector<ll> vll;
typedef std::vector<vll> vvll;

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    ll n, q;
    std::cin >> n >> q;

    vvll adjacent(n);
    for(ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        std::cin >> u >> v;
        u--;
        v--;

        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
    }

    BinaryLifting binary_lifting(adjacent);

    for(ll i = 0; i < q; i++)
    {
        ll u, v;
        std::cin >> u >> v;
        u--;
        v--;

        ll distance = binary_lifting.get_distance(u, v);
        std::cout << distance << '\n';
    }

    return 0;
}
