#include <climits>
#include <iostream>
#include <vector>
#include <algorithms/bfs.hpp>

typedef long long ll;
typedef std::vector<ll> vll;
typedef std::vector<vll> vvll;

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    ll n, m;
    std::cin >> n >> m;

    vvll adjacent(n);
    for(ll i = 0; i < m; i++)
    {
        ll u, v;
        std::cin >> u >> v;
        u--;
        v--;

        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
    }

    vll previous;
    vll distance = BFS::get_shortest_paths(adjacent, previous, n - 1);

    if(distance[0] == LLONG_MAX)
    {
        std::cout << "IMPOSSIBLE\n";
        return 0;
    }

    std::cout << (distance[0] + 1) << '\n';

    ll u = 0;
    do
    {
        std::cout << (u + 1) << ' ';
        u = previous[u];
    } while(u != -1);

    return 0;
}
