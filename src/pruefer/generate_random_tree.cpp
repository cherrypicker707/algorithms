#include <algorithms/pruefer.hpp>
#include <random>
#include <iostream>
#include <algorithm>

typedef long long ll;
typedef std::vector<ll> vll;
typedef std::vector<vll> vvll;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

std::random_device device;
std::mt19937_64 mersenne_twister(device());

int main()
{
	ll n;
	std::cin >> n;

	vll code(n - 2);
	for(ll i = 0; i < n - 2; i++)
		code[i] = std::uniform_int_distribution<ll>(0, n - 1)(mersenne_twister);

	std::cout << n << '\n';

	vpll edge = Algorithm::Pruefer::decode(code);

	for(ll i = 0; i < n - 1; i++)
		if(std::uniform_int_distribution<ll>(0, 1)(mersenne_twister))
			std::swap(edge[i].first, edge[i].second);
	std::shuffle(edge.begin(), edge.end(), mersenne_twister);

	for(ll i = 0; i < n - 1; i++)
		std::cout << (edge[i].first + 1) << ' ' << (edge[i].second + 1) << '\n';
}
