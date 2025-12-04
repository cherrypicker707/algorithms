#include <algorithm>
#include <iostream>
#include <vector>
#include <algorithms/binary_search.hpp>

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
    std::sort(array.begin(), array.end());

    for(ll i = 0; i < q; i++)
    {
        ll k;
        std::cin >> k;

        ll answer = BinarySearch::find_first(0, n, [&array, &k](ll index) { return array[index] >= k; });
        std::cout << answer << '\n';
    }

    return 0;
}
