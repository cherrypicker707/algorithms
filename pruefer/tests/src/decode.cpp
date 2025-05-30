// Code taken from https://cp-algorithms.com/graph/pruefer_code.html.
// Used for testing.

#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> pruefer_decode(vector<int> const& code)
{
	int n = code.size() + 2;
	vector<int> degree(n, 1);
	for (int i : code)
		degree[i]++;

	int ptr = 0;
	while (degree[ptr] != 1)
		ptr++;
	int leaf = ptr;

	vector<pair<int, int>> edges;
	for (int v : code) 
	{
		edges.emplace_back(leaf, v);
		if (--degree[v] == 1 && v < ptr) 
		{
			leaf = v;
		}
		else
		{
			ptr++;
			while (degree[ptr] != 1)
				ptr++;
			leaf = ptr;
		}
	}
	edges.emplace_back(leaf, n-1);
	return edges;
}

int main()
{
	int n;
	std::cin >> n;

	vector<int> code(n - 2);
	for(int i = 0; i < n - 2; i++)
	{
		std::cin >> code[i];
		code[i]--;
	}

	std::cout << n << '\n';

	vector<pair<int, int>> edge = pruefer_decode(code);
	for(int i = 0; i < n - 1; i++)
		std::cout << (edge[i].first + 1) << ' ' << (edge[i].second + 1) << '\n';
}
