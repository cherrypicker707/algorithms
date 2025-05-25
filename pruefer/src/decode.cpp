#include <pruefer/pruefer.hpp>
#include <iostream>

typedef long long ll;
typedef std::vector<ll> vll;
typedef std::vector<vll> vvll;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

int main()
{
	ll n;
	std::cin >> n;

	vll code(n - 2);
	for(ll i = 0; i < n - 2; i++)
	{
		std::cin >> code[i];
		code[i]--;
	}

	std::cout << n << '\n';

	vpll edge = Pruefer::decode(code);
	for(ll i = 0; i < n - 1; i++)
		std::cout << (edge[i].first + 1) << ' ' << (edge[i].second + 1) << '\n';
}
