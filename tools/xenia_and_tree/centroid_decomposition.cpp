#include <climits>
#include <iostream>
#include <vector>
#include <algorithms/binary_lifting.hpp>
#include <algorithms/centroid_decomposition.hpp>

typedef std::vector<bool> vbool;
typedef long long ll;
typedef std::vector<ll> vll;
typedef std::vector<vll> vvll;

ll get_closest(ll u, const vll &decomposition, const vll &closest, const BinaryLifting &binary_lifting);
void mark_red(vll &closest, ll u, const vll &decomposition, const BinaryLifting &binary_lifting);

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
    vll decomposition = CentroidDecomposition::decompose(adjacent);
    vll closest(n, LLONG_MAX);

    mark_red(closest, 0, decomposition, binary_lifting);

    for(ll i = 0; i < q; i++)
    {
        ll type, u;
        std::cin >> type >> u;
        type--;
        u--;

        if(type)
        {
            std::cout << get_closest(u, decomposition, closest, binary_lifting) << '\n';
            continue;
        }

        mark_red(closest, u, decomposition, binary_lifting);
    }

    return 0;
}

ll get_closest(ll u, const vll &decomposition, const vll &closest, const BinaryLifting &binary_lifting)
{
    ll distance = LLONG_MAX;
    ll v = u;

    while(v != -1)
    {
        ll current_distance = closest[v];
        if(closest[v] != LLONG_MAX)
            current_distance += binary_lifting.get_distance(u, v);

        distance = std::min(distance, current_distance);
        v = decomposition[v];
    }

    return distance;
}

void mark_red(vll &closest, ll u, const vll &decomposition, const BinaryLifting &binary_lifting)
{
    ll v = u;

    while(v != -1)
    {
        closest[v] = std::min(closest[v], binary_lifting.get_distance(u, v));
        v = decomposition[v];
    }
}
