#include <algorithms/prefix_sum.hpp>

typedef long long ll;
typedef std::vector<ll> vll;

vll Algorithms::PrefixSum::getPrefixSum(const vll &array)
{
	ll n = array.size();
	vll prefixSum = vll(n + 1);

	prefixSum[0] = 0;
	for(ll i = 1; i <= n; i++)
		prefixSum[i] = prefixSum[i - 1] + array[i - 1];

	return prefixSum;
}

ll Algorithms::PrefixSum::getSubarraySum(const vll &prefixSum, ll left, ll right)
{
	return prefixSum[right] - prefixSum[left];
}
