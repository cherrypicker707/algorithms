#include <iostream>
#include <vector>
#include <algorithms/lazy_segment_tree.hpp>

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

    LazySegmentTree lazy_segment_tree(array);
    for(ll i = 0; i < q; i++)
    {
        ll type;
        std::cin >> type;

        if(type == 1)
        {
            ll left, right, value;
            std::cin >> left >> right >> value;
            left--;

            lazy_segment_tree.add(left, right, value);
            continue;
        }

        if(type == 2)
        {
            ll left, right, value;
            std::cin >> left >> right >> value;
            left--;

            lazy_segment_tree.set(left, right, value);
            continue;
        }

        ll left, right;
        std::cin >> left >> right;
        left--;

        ll value = lazy_segment_tree.get_range_sum(left, right);
        std::cout << value << '\n';
    }

    return 0;
}
