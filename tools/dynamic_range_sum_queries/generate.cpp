#include <iostream>
#include <random>
#include <vector>

#define RANDOM(X, Y) std::uniform_int_distribution<ll>(X, Y)(mersenne_twister)

typedef long long ll;
typedef std::vector<ll> vll;

std::random_device device;
std::mt19937_64 mersenne_twister(device());

int main(int argc, char **argv)
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    const ll n = std::atoll(argv[1]);
    const ll q = std::atoll(argv[2]);
    const ll min_array_value = std::atoll(argv[3]);
    const ll max_array_value = std::atoll(argv[4]);

    std::cout << n << ' ' << q << '\n';

    for(ll i = 0; i < n; i++)
        std::cout << RANDOM(min_array_value, max_array_value) << ' ';
    std::cout << '\n';

    for(ll i = 0; i < q; i++)
    {
        ll type = RANDOM(1, 2);

        if(type == 1)
        {
            ll position = RANDOM(1, n);
            ll value = RANDOM(min_array_value, max_array_value);

            std::cout << type << ' ' << position << ' ' << value << '\n';

            continue;
        }

        ll left = RANDOM(1, n);
        ll right = RANDOM(1, n);

        if(left > right)
            std::swap(left, right);

        std::cout << type << ' ' << left << ' ' << right << '\n';
    }
}
