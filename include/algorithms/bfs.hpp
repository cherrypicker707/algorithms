#pragma once
#include <vector>

typedef long long ll;
typedef std::vector<ll> vll;
typedef std::vector<vll> vvll;

namespace BFS
{
    vll get_shortest_paths(const vvll adjacent, ll u = 0);
    vll get_shortest_paths(const vvll adjacent, vll &previous, ll u = 0);
}
