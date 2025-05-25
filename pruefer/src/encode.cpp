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

	vpll edge(n - 1);
	for(ll i = 0; i < n - 1; i++)
	{
		std::cin >> edge[i].first >> edge[i].second;

		edge[i].first--;
		edge[i].second--;
	}

	std::cout << n << '\n';

	vll code = Pruefer::encode(edge);
	for(ll i = 0; i < n - 2; i++)
		std::cout << (code[i] + 1) << ' ';
	std::cout << '\n';
}
