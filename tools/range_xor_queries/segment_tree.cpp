#include <climits>
#include <iostream>
#include <vector>
#include <algorithms/segment_tree.hpp>

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

    SegmentTree segment_tree(array, std::bit_xor<ll>());

    for(ll i = 0; i < q; i++)
    {
        ll left, right;
        std::cin >> left >> right;
        left--;

        ll sum = segment_tree.get_range_value(left, right);
        std::cout << sum << '\n';
    }
}
