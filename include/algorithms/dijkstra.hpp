#pragma once
#include <vector>

typedef long long ll;
typedef std::vector<ll> vll;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;
typedef std::vector<vpll> vvpll;

namespace Dijkstra
{
    vll get_shortest_paths(const vvpll &adjacent, ll u = 0);
}
