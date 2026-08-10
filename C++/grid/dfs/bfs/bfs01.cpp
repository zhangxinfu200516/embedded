#include <bits\stdc++.h>
using namespace std;

int offest[4][2] = {0, -1, 0, 1, 1, 0, -1, 0};
int n, m;
void bfs(vector<vector<int>> grad, vector<vector<bool>> &visited, int x, int y)
{
	std::queue<pair<int, int>> que;
	que.push({x, y});
	visited[x][y] = true;
	while (!que.empty())
	{
		pair<int, int> it = que.front();
		que.pop();
		int curx = it.first;
		int cury = it.second;
		for (int i = 0; i < 4; i++)
		{
			int nextx = curx + offest[i][0];
			int nexty = cury + offest[i][1];
			if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= m)
				continue;
			if (grad[nextx][nexty] == 1 && visited[nextx][nexty] == false)
			{
				visited[nextx][nexty] = true;
				que.push({nextx, nexty});
			}
		}
	}
}
void dfs(vector<vector<int>> grad, vector<vector<bool>> &visited, int x, int y)
{
	visited[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int nextx = x + offest[i][0];
		int nexty = y + offest[i][1];
		if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= m)
			continue;
		if (grad[nextx][nexty] == 1 && visited[nextx][nexty] == false)
		{
			visited[nextx][nexty] = true;
			dfs(grad, visited, nextx, nexty);
		}
	}
}
void dfs01(vector<vector<int>> grad, vector<vector<bool>> &visited, int x, int y, int &sum)
{
	visited[x][y] = true;
	sum++;
	for (int i = 0; i < 4; i++)
	{
		int nextx = x + offest[i][0];
		int nexty = y + offest[i][1];
		if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= m)
			continue;
		if (grad[nextx][nexty] == 1 && visited[nextx][nexty] == false)
		{
			dfs01(grad, visited, nextx, nexty, sum);
		}
	}
}
int main01()
{
	cin >> n >> m;
	vector<vector<int>> grad(n, vector<int>(m, 0));
	vector<vector<bool>> visited(n, vector<bool>(m, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> grad[i][j];
		}
	}
	int result = 0, record = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (grad[i][j] == 1 && visited[i][j] == false)
			{
				// result++;
				//  bfs(grad, visited, i, j);
				dfs01(grad, visited, i, j, record);
				result = max(record, result);
				record = 0;
			}
		}
	}

	cout << result;
	return 0;
}
void dfs02(vector<vector<int>> grad, vector<vector<bool>> &visited, int x, int y)
{
	visited[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int nextx = x + offest[i][0];
		int nexty = y + offest[i][1];
		if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= m)
			continue;
		if (grad[nextx][nexty] >= grad[x][y] && visited[nextx][nexty] == false)
		{
			dfs02(grad, visited, nextx, nexty);
		}
	}
}
int main()
{
	// 处理输入
	cin >> n >> m;
	vector<vector<int>> graph(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> graph[i][j];
		}
	}
	vector<vector<bool>> first(n, vector<bool>(m, false));
	vector<vector<bool>> second(n, vector<bool>(m, false));
	// 遍历第一、二组边界
	for (int i = 0; i < n; i++)
	{
		dfs02(graph, first, i, 0);
		dfs02(graph, second, i, m - 1);
	}
	for (int j = 0; j < m; j++)
	{
		dfs02(graph, first, 0, j);
		dfs02(graph, second, n - 1, j);
	}

	// 比较第一、二边界的遍历结果、获取交集
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			 
				cout << i << " " << j << endl;
			// cout << first[i][j] << " ";
		}
		// cout << endl;
	}
	return 0;
}