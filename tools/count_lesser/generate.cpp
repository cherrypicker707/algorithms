#include <random>
#include <iostream>
#define RANDOM(X, Y) std::uniform_int_distribution<ll>(X, Y)(mersenne_twister)

typedef long long ll;

std::random_device device;
std::mt19937_64 mersenne_twister(device());

int main(int argc, char **argv)
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    ll min_n = std::atoll(argv[1]);
    ll max_n = std::atoll(argv[2]);
    ll min_q = std::atoll(argv[3]);
    ll max_q = std::atoll(argv[4]);
    ll min_a = std::atoll(argv[5]);
    ll max_a = std::atoll(argv[6]);
    ll min_b = std::atoll(argv[7]);
    ll max_b = std::atoll(argv[8]);

    ll n = RANDOM(min_n, max_n);
    ll q = RANDOM(min_q, max_q);

    std::cout << n << ' ' << q << '\n';

    for(ll i = 0; i < n; i++)
        std::cout << RANDOM(min_a, max_a) << ' ';
    std::cout << '\n';

    for(ll i = 0; i < q; i++)
        std::cout << RANDOM(min_b, max_b) << '\n';

    return 0;
}
