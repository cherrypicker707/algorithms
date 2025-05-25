#include <pruefer/pruefer.hpp>
#include <iostream>

typedef long long ll;
typedef std::vector<ll> vll;
typedef std::vector<vll> vvll;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

int main()
{
	vpll edge = {{0, 1}, {0, 2}, {2, 3}, {2, 4}};
	ll n = edge.size() + 1;
	vll code = Pruefer::encode(edge);

	for(ll i = 0; i < n - 2; i++)
		std::cout << (code[i] + 1) << ' ';
	std::cout << '\n';
}
