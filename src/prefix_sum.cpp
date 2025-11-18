#include <vector>
#include <algorithms/prefix_sum.hpp>

typedef long long ll;
typedef std::vector<ll> vll;

vll PrefixSum::get_prefix_sum(const vll &array)
{
    ll n = array.size();
    vll prefix_sum(n + 1, 0);

    for(ll i = 1; i <= n; i++)
        prefix_sum[i] = prefix_sum[i - 1] + array[i - 1];

    return prefix_sum;
}

ll PrefixSum::get_range_sum(const vll &prefix_sum, ll left, ll right)
{
    return prefix_sum[right] - prefix_sum[left];
}
