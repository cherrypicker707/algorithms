#include <iostream>
#include <vector>

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

    for(ll i = 0; i < q; i++)
    {
        ll left, right;
        std::cin >> left >> right;
        left--;

        ll sum = 0;
        for(ll j = left; j < right; j++)
            sum ^= array[j];

        std::cout << sum << '\n';
    }
}
