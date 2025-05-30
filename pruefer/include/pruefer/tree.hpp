#pragma once
#include <vector>

namespace Pruefer
{
	std::vector<std::pair<long long, long long>> getEdgeFromAdjacent(const std::vector<std::vector<long long>> &adjacent);

	std::vector<std::vector<long long>> getAdjacentFromEdge(const std::vector<std::pair<long long, long long>> &edge);

	std::vector<long long> getParentFromAdjacent(const std::vector<std::vector<long long>> &adjacent, long long root);

	void sortEdge(std::vector<std::pair<long long, long long>> edge);
}
