#include <iostream>
#include <vector>
#include <algorithms/prefix_sum.hpp>

typedef long long ll;
typedef std::vector<ll> vll;

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    ll n, q;
    std::cin >> n >> q;

    vll array(n);
    for(ll i = 0; i < n; i++)
        std::cin >> array[i];

    vll prefix_sum = PrefixSum::get_prefix_sum(array);

    for(ll i = 0; i < q; i++)
    {
        ll left, right;
        std::cin >> left >> right;
        left--;

        ll sum = PrefixSum::get_range_sum(prefix_sum, left, right);
        std::cout << sum << '\n';
    }
}
