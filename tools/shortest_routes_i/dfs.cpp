#include <iostream>
#include <climits>
#include <vector>

typedef std::vector<bool> vbool;
typedef long long ll;
typedef std::vector<ll> vll;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;
typedef std::vector<vpll> vvpll;

vvpll adjacent;
vbool active;
vll distance;

void dfs(ll u, ll p, ll d);

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    ll n, m;
    std::cin >> n >> m;

    adjacent = vvpll(n);
    for(ll i = 0; i < m; i++)
    {
        ll u, v, weight;
        std::cin >> u >> v >> weight;
        u--;
        v--;

        adjacent[u].push_back({v, weight});
    }

    active = vbool(n, false);
    distance = vll(n, LLONG_MAX);
    dfs(0, -1, 0);

    for(ll i = 0; i < n; i++)
        if(distance[i] == LLONG_MAX)
            distance[i] = -1;

    for(ll i = 0; i < n; i++)
        std::cout << distance[i] << ' ';
    std::cout << '\n';
}

void dfs(ll u, ll p, ll d)
{
    distance[u] = std::min(distance[u], d);

    active[u] = true;

    for(pll edge : adjacent[u])
    {
        ll v = edge.first;
        ll weight = edge.second;

        if(v == p || active[v])
            continue;

        dfs(v, u, d + weight);
    }

    active[u] = false;
}
