#pragma once
#include <vector>

namespace Algorithms
{
	namespace Tree
	{
		std::vector<std::vector<long long>> getAdjacent(const std::vector<std::pair<long long, long long>> &edge);

		std::vector<std::pair<long long, long long>> getEdge(const std::vector<std::vector<long long>> &adjacent);

		std::vector<long long> getParent(const std::vector<std::vector<long long>> &adjacent, long long root);

		std::vector<long long> getSubtreeSize(const std::vector<std::vector<long long>> &adjacent, long long root);

		std::vector<long long> getSubtreeSize(const std::vector<std::vector<long long>> &adjacent, const std::vector<bool> &removed, long long root);

		void sortEdge(std::vector<std::pair<long long, long long>> edge);

		void setParentWithDFS(std::vector<long long> &parent, const std::vector<std::vector<long long>> &adjacent, long long u, long long p);

		void setSubtreeSizeWithDFS(std::vector<long long> &subtreeSize, const std::vector<std::vector<long long>> &adjacent, long long u, long long p);

		void setSubtreeSizeWithDFS(std::vector<long long> &subtreeSize, const std::vector<std::vector<long long>> &adjacent, const std::vector<bool> &removed, long long u, long long p);
	}
}
