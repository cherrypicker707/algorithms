#pragma once
#include <vector>

namespace Algorithms
{
	namespace Centroid
	{
		long long find(const std::vector<std::vector<long long>> &adjacent);

		std::vector<long long> decompose(const std::vector<std::vector<long long>> &adjacent);
	}
}
