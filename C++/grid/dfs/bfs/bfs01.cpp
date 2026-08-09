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
int main()
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
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (grad[i][j] == 1 && visited[i][j] == false)
			{
				result++;
				// bfs(grad, visited, i, j);
				dfs(grad, visited, i, j);
			}
		}
	}

	cout << result;
	return 0;
}