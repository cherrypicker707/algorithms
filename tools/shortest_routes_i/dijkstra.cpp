#include <algorithms/dijkstra.hpp>
#include <climits>
#include <iostream>
#include <vector>

typedef long long ll;
typedef std::vector<ll> vll;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;
typedef std::vector<vpll> vvpll;

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    ll n, m;
    std::cin >> n >> m;

    vvpll adjacent(n);
    for(ll i = 0; i < m; i++)
    {
        ll u, v, weight;
        std::cin >> u >> v >> weight;
        u--;
        v--;

        adjacent[u].push_back({v, weight});
    }

    vll distance = Dijkstra::get_shortest_paths(adjacent);

    for(ll i = 0; i < n; i++)
        if(distance[i] == LLONG_MAX)
            distance[i] = -1;

    for(ll i = 0; i < n; i++)
        std::cout << distance[i] << ' ';
    std::cout << '\n';
}
