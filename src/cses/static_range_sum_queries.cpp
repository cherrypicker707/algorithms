#include <algorithms/prefix_sum.hpp>
#include <vector>
#include <iostream>

typedef long long ll;
typedef std::vector<ll> vll;

int main()
{
	ll n, q;
	std::cin >> n >> q;

	vll array(n);
	for(ll i = 0; i < n; i++)
		std::cin >> array[i];

	vll prefixSum = Algorithms::PrefixSum::getPrefixSum(array);
	for(ll i = 0; i < q; i++)
	{
		ll left, right;
		std::cin >> left >> right;
		left--;

		std::cout << Algorithms::PrefixSum::getSubarraySum(prefixSum, left, right) << '\n';
	}
}
