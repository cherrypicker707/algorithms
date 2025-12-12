#include <climits>
#include <iostream>
#include <vector>

typedef std::vector<bool> vbool;
typedef long long ll;
typedef std::vector<ll> vll;
typedef std::vector<vll> vvll;

ll find_closest(ll u, ll p, const vvll &adjacent, const vbool &red);

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

    vbool red(n, false);
    red[0] = true;
    for(ll i = 0; i < q; i++)
    {
        ll type, u;
        std::cin >> type >> u;
        type--;
        u--;

        if(type)
        {
            ll v = find_closest(u, -1, adjacent, red);
            std::cout << v << '\n';
            continue;
        }

        red[u] = true;
    }
}

ll find_closest(ll u, ll p, const vvll &adjacent, const vbool &red)
{
    if(red[u])
        return 0;

    ll distance = LLONG_MAX;
    for(ll v : adjacent[u])
    {
        if(v == p)
            continue;

        ll current_distance = find_closest(v, u, adjacent, red);
        if(current_distance != LLONG_MAX && current_distance + 1 < distance)
            distance = current_distance + 1;
    }

    return distance;
}
