#include <vector>
#include <random>
#include <iostream>
#include <algorithm>
#include <set>

typedef long long ll;
typedef std::vector<ll> vll;
typedef std::vector<vll> vvll;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;
typedef std::set<ll> sll;

std::random_device device;
std::mt19937_64 mersenne_twister(device());

ll getRandomElement(sll &set);

int main()
{
	ll n;
	std::cin >> n;

	sll added, unadded;

	for(ll u = 0; u < n; u++)
		unadded.insert(u);

	ll root = std::uniform_int_distribution<ll>(0, n - 1)(mersenne_twister);
	added.insert(root);
	unadded.erase(root);

	vpll edge;
	for(ll i = 0; i < n - 1; i++)
	{
		ll u = getRandomElement(added);
		ll v = getRandomElement(unadded);

		added.insert(v);
		unadded.erase(v);

		edge.push_back({u, v});
	}

	for(ll i = 0; i < n - 1; i++)
		if(std::uniform_int_distribution<ll>(0, 1)(mersenne_twister))
			std::swap(edge[i].first, edge[i].second);
	std::shuffle(edge.begin(), edge.end(), mersenne_twister);

	for(ll i = 0; i < n - 1; i++)
		std::cout << (edge[i].first + 1) << ' ' << (edge[i].second + 1) << '\n';
}

ll getRandomElement(sll &set)
{
	ll i = std::uniform_int_distribution<ll>(0, set.size() - 1)(mersenne_twister);
	auto it = set.begin();
	std::advance(it, i);
	return *it;
}
