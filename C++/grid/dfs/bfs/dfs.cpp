#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> result;
vector<int> path;
// x：目前遍历的节点
// graph：存当前的图
// n：终点
void dfs(vector<vector<int>> &graph, int x, int n)
{
	// 终止条件: 终点
	if (x == n)
	{
		result.push_back(path);
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (graph[x][i] == 1)
		{
			path.push_back(i);
			dfs(graph, i, n);
			path.pop_back();
		}
	}
}
void dfs1(vector<list<int>> &graph, int x, int n)
{
	if (x == n)
	{
		result.push_back(path);
		return;
	}
	for (int i : graph[x]) // 遍历该节点挂载的链表
	{
		path.push_back(i);
		dfs1(graph, i, n);
		path.pop_back();
	}
}
int main()
{
	// 用户参数
	int N, M;
	cin >> N >> M;
	int s, t;
	vector<vector<int>> graph(N + 1, vector<int>(N + 1, 0));
	vector<list<int>> graph1(N + 1);
	while (M--)
	{
		cin >> s >> t;
		// 构建邻接矩阵
		graph[s][t] = 1;
		// 构建邻接矩阵
		graph1[s].push_back(t);
	}
	path.push_back(1);
	// dfs(graph, 1, N);
	dfs1(graph1, 1, N);
	if (result.size() == 0)
	{
		cout << -1;
		return 0;
	}
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j];
			if (j != result[i].size() - 1)
				cout << " ";
		}
		cout << endl;
	}
}
