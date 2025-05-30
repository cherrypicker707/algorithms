// Code taken from https://cp-algorithms.com/graph/pruefer_code.html.
// Used for testing.

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<int> parent;

void dfs(int v)
{
	for (int u : adj[v])
	{
		if (u != parent[v])
		{
			parent[u] = v;
			dfs(u);
		}
	}
}

vector<int> pruefer_code()
{
	int n = adj.size();
	parent.resize(n);
	parent[n-1] = -1;
	dfs(n-1);

	int ptr = -1;
	vector<int> degree(n);
	for (int i = 0; i < n; i++)
	{
		degree[i] = adj[i].size();
		if (degree[i] == 1 && ptr == -1)
			ptr = i;
	}

	vector<int> code(n - 2);
	int leaf = ptr;
	for (int i = 0; i < n - 2; i++)
	{
		int next = parent[leaf];
		code[i] = next;
		if (--degree[next] == 1 && next < ptr)
		{
			leaf = next;
		}
		else
		{
			ptr++;
			while (degree[ptr] != 1)
				ptr++;
			leaf = ptr;
		}
	}

	return code;
}

int main()
{
	int n;
	std::cin >> n;

	adj.resize(n);
	for(int i = 0; i < n - 1; i++)
	{
		int u, v;
		std::cin >> u >> v;
		u--;
		v--;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	std::cout << n << '\n';

	vector<int> code = pruefer_code();

	for(int i = 0; i < n - 2; i++)
		std::cout << (code[i] + 1) << ' ';
	std::cout << '\n';
}
