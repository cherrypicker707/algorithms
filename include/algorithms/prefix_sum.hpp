#pragma once
#include <vector>

namespace Algorithms
{
	namespace PrefixSum
	{
		std::vector<long long> getPrefixSum(const std::vector<long long> &array);

		// Returns sum on an interval [left, right)
		long long getSubarraySum(const std::vector<long long> &prefixSum, long long left, long long right);
	}
}
