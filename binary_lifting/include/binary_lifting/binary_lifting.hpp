#pragma once
#include <vector>

namespace BinaryLifting
{
	class BinaryLifting
	{
	public:
		BinaryLifting(const std::vector<std::vector<long long>> &adjacent);
		long long getDistance(long long u, long long v);

	private:
		long long n, m;
		std::vector<long long> depth;
		std::vector<std::vector<long long>> ancestor;
		long long getAncestor(long long u, long long k);
		void depthFirstSearch(long long u, long long p, const std::vector<std::vector<long long>> &adjacent);
	};
}
