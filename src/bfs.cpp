#include <vector>
#include <queue>
#include <climits>
#include <algorithms/bfs.hpp>

typedef long long ll;
typedef std::vector<ll> vll;
typedef std::vector<vll> vvll;
typedef std::queue<ll> qll;

vll BFS::get_shortest_paths(const vvll adjacent, ll u)
{
    vll previous;
    return get_shortest_paths(adjacent, previous, u);
}

vll BFS::get_shortest_paths(const vvll adjacent, vll &previous, ll u)
{
    ll n = adjacent.size();

    previous = vll(n, -1);
    vll distance(n, LLONG_MAX);
    qll queue;

    distance[u] = 0;
    queue.push(u);

    while(!queue.empty())
    {
        ll v = queue.front();
        queue.pop();

        for(ll w : adjacent[v])
        {
            if(distance[w] < LLONG_MAX)
                continue;

            previous[w] = v;
            distance[w] = distance[v] + 1;
            queue.push(w);
        }
    }

    return distance;
}
