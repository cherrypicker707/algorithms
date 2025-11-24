#include <algorithms/dijkstra.hpp>
#include <climits>
#include <queue>

typedef std::vector<bool> vbool;
typedef std::priority_queue<pll, vpll, std::greater<pll>> pqpll;

vll Dijkstra::get_shortest_paths(const vvpll &adjacent, ll u)
{
    ll n = adjacent.size();
    vll distance(n, LLONG_MAX);
    vbool marked(n, false);
    pqpll queue;

    distance[u] = 0;
    queue.push({0, u});

    while(!queue.empty())
    {
        ll v = queue.top().second;
        queue.pop();

        if(marked[v])
            continue;

        for(pll edge : adjacent[v])
        {
            ll w = edge.first;
            ll weight = edge.second;

            if(!marked[w] && distance[v] + weight < distance[w])
            {
                distance[w] = distance[v] + weight;
                queue.push({distance[w], w});
            }
        }

        marked[v] = true;
    }

    return distance;
}
