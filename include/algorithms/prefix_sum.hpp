#include <vector>

typedef long long ll;
typedef std::vector<ll> vll;

namespace PrefixSum
{
    vll get_prefix_sum(const vll &array);
    ll get_range_sum(const vll &prefix_sum, ll left, ll right);
};
