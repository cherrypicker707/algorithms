#pragma once
#include <vector>

namespace Algorithms
{
	namespace Pruefer
	{
		std::vector<long long> encode(const std::vector<std::pair<long long, long long>> &edge);
		std::vector<std::pair<long long, long long>> decode(const std::vector<long long> &code);
	}
}
