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
        ll k;
        std::cin >> k;

        bool found = false;
        for(ll j = 0; j < n; j++)
        {
            if(array[j] == k)
            {
                found = true;
                break;
            }
        }

        if(found)
        {
            std::cout << "YES\n";
            continue;
        }

        std::cout << "NO\n";
    }

    return 0;
}
