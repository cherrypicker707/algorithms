#pragma once
#include <vector>

namespace Algorithm
{
	namespace Tree
	{
		std::vector<std::vector<long long>> getAdjacent(const std::vector<std::pair<long long, long long>> &edge);

		std::vector<std::pair<long long, long long>> getEdge(const std::vector<std::vector<long long>> &adjacent);

		std::vector<long long> getParent(const std::vector<std::vector<long long>> &adjacent, long long root);

		std::vector<long long> getSubtreeSize(const std::vector<std::vector<long long>> &adjacent, long long root);

		std::vector<long long> getSubtreeSize(const std::vector<std::vector<long long>> &adjacent, const std::vector<bool> &removed, long long root);

		void sortEdge(std::vector<std::pair<long long, long long>> edge);
	}
}
