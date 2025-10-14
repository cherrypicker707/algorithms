#pragma once
#include <vector>

typedef long long ll;
typedef std::vector<ll> vll;
typedef std::vector<vll> vvll;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

namespace Pruefer
{
    vll encode(const vvll &adjacent);
    vvll decode(const vll &code);
};
