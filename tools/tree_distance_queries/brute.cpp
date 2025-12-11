#include <climits>
#include <vector>
#include <iostream>

typedef long long ll;
typedef std::vector<ll> vll;
typedef std::vector<vll> vvll;

ll get_distance(ll u, ll p, ll dst, const vvll &adjacent);

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

    for(ll i = 0; i < q; i++)
    {
        ll u, v;
        std::cin >> u >> v;
        u--;
        v--;

        ll distance = get_distance(u, -1, v, adjacent);
        std::cout << distance << '\n';
    }

    return 0;
}

ll get_distance(ll u, ll p, ll dst, const vvll &adjacent)
{
    if(u == dst)
        return 0;

    for(ll v : adjacent[u])
    {
        if(v == p)
            continue;

        ll current_distance = get_distance(v, u, dst, adjacent);

        if(current_distance == LLONG_MAX)
            continue;

        return current_distance + 1;
    }

    return LLONG_MAX;
}
