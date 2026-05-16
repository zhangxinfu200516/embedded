// 岛屿问题
#ifdef Q1
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> offset = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
void dfs(vector<vector<int>> &graph, vector<vector<bool>> &visited, int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int nextx = x + offset[i][0];
		int nexty = y + offset[i][1];
		if (nextx < 0 || nextx >= graph.size() || nexty < 0 || nexty >= graph[0].size())
			continue;
		if (graph[nextx][nexty] == 1 && visited[nextx][nexty] == false)
		{
			visited[nextx][nexty] = true;
			dfs(graph, visited, nextx, nexty);
		}
	}
}
void bfs(vector<vector<int>> &graph, vector<vector<bool>> &visited, int x, int y)
{
	queue<pair<int, int>> que;
	que.push({x, y});
	// 之前已经将xy点置为访问态
	while (!que.empty())
	{
		auto it = que.front();
		que.pop();
		int nowx = it.first;
		int nowy = it.second;
		for (int i = 0; i < 4; i++)
		{
			int nextx = nowx + offset[i][0];
			int nexty = nowy + offset[i][1];
			if (nextx < 0 || nextx >= graph.size() || nexty < 0 || nexty >= graph[0].size())
				continue;
			if (graph[nextx][nexty] == 1 && visited[nextx][nexty] == false)
			{
				que.push({nextx, nexty});
				visited[nextx][nexty] = true;
			}
		}
	}
}
int main()
{
	// 处理输入 行、列
	int m, n;
	cin >> m >> n;
	vector<vector<int>> graph(m, vector<int>(n, 0));
	int temp;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> graph[i][j];
		}
	}

	int result = 0;
	vector<vector<bool>> visited(m, vector<bool>(n, false));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (graph[i][j] == 1 && visited[i][j] == false)
			{
				result++;
				visited[i][j] = true;
				// 利用深度搜索 将与之相连的新大陆都访问一遍
				// dfs(graph, visited, i, j);
				// 广搜
				bfs(graph, visited, i, j);
			}
		}
	}

	cout << result;
}
#endif
#ifdef Q2
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> offset = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
void dfs(vector<vector<int>> &graph, vector<vector<bool>> &visited, int x, int y, int &sum)
{
	for (int i = 0; i < 4; i++)
	{
		int nextx = x + offset[i][0];
		int nexty = y + offset[i][1];
		if (nextx < 0 || nextx >= graph.size() || nexty < 0 || nexty >= graph[0].size())
			continue;
		if (graph[nextx][nexty] == 1 && visited[nextx][nexty] == false)
		{
			visited[nextx][nexty] = true;
			sum++;
			dfs(graph, visited, nextx, nexty, sum);
		}
	}
}
int main()
{
	// 处理输入 行、列
	int m, n;
	cin >> m >> n;
	vector<vector<int>> graph(m, vector<int>(n, 0));
	int temp;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> graph[i][j];
		}
	}

	int result = -INT_MAX;
	vector<vector<bool>> visited(m, vector<bool>(n, false));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (graph[i][j] == 1 && visited[i][j] == false)
			{
				visited[i][j] = true;
				// 利用深度搜索 将与之相连的新大陆都访问一遍
				int sum = 1;
				dfs(graph, visited, i, j, sum);
				result = max(result, sum);
				// 广搜
				// bfs(graph, visited, i, j);
			}
		}
	}

	cout << result;
}
#endif
#ifdef Q3
// 孤岛的最大面积
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> offset = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
void dfs(vector<vector<int>> &graph, vector<vector<bool>> &visited, int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int nextx = x + offset[i][0];
		int nexty = y + offset[i][1];
		if (nextx < 0 || nextx >= graph.size() || nexty < 0 || nexty >= graph[0].size())
			continue;
		if (graph[nextx][nexty] == 1 && visited[nextx][nexty] == false)
		{
			visited[nextx][nexty] = true;
			graph[nextx][nexty] = 0;
			dfs(graph, visited, nextx, nexty);
		}
	}
}
int main()
{
	// 处理输入 行、列
	int m, n;
	cin >> m >> n;
	vector<vector<int>> graph(m, vector<int>(n, 0));
	int temp;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> graph[i][j];
		}
	}

	vector<vector<bool>> visited(m, vector<bool>(n, false));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i > 0 && i < m - 1 && j > 0 && j < n - 1)
				continue;
			if (graph[i][j] == 1 && visited[i][j] == false)
			{
				graph[i][j] = 0;
				visited[i][j] = true;
				// 利用深度搜索 将与之相连的新大陆都访问一遍
				dfs(graph, visited, i, j);
				// 广搜
				// bfs(graph, visited, i, j);
			}
		}
	}
	int result = 0;
	for (int i = 1; i < m - 1; i++)
	{
		for (int j = 1; j < n - 1; j++)
		{
			if (graph[i][j] == 1)
				result++;
		}
	}
	cout << result;
}
#endif
#ifdef Q4
#include <bits/stdc++.h>
using namespace std;
int offest[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void dfs(vector<vector<int>> &graph, vector<vector<bool>> &visited, int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int nextx = x + offest[i][0];
		int nexty = y + offest[i][1];
		if (nextx < 0 || nexty < 0 || nextx >= graph.size() || nexty >= graph[0].size())
			continue;
		if (graph[nextx][nexty] == 1 && !visited[nextx][nexty])
		{
			visited[nextx][nexty] = true;
			dfs(graph, visited, nextx, nexty);
		}
	}
}

int main()
{
	// 处理输入
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> graph[i][j];
		}
	}
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	// for遍历所有的非孤岛
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i > 0 && j > 0 && i < n - 1 && j < m - 1)
				continue;
			if (!visited[i][j] && graph[i][j] == 1)
			{
				visited[i][j] = true;
				// 深度优先遍历所有连接的岛屿
				dfs(graph, visited, i, j);
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (graph[i][j] == 1 && !visited[i][j])
			{
				graph[i][j] = 0;
			}
			cout << graph[i][j];
			if (j != m - 1)
				cout << " ";
		}
		cout << endl;
	}
}
#endif
#ifdef Q5
#include <bits/stdc++.h>
using namespace std;
int offest[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void dfs(vector<vector<int>> &graph, vector<vector<bool>> &visited, int x, int y)
{
	// 逆序遍历
	if (visited[x][y])
		return;
	visited[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int nextx = x + offest[i][0];
		int nexty = y + offest[i][1];
		if (nextx < 0 || nexty < 0 || nextx >= graph.size() || nexty >= graph[0].size())
			continue;
		if (graph[nextx][nexty] >= graph[x][y])
			dfs(graph, visited, nextx, nexty);
	}
}
int main()
{
	// 处理输入
	int n, m;
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
		dfs(graph, first, i, 0);
		dfs(graph, second, i, m - 1);
	}
	for (int j = 0; j < m; j++)
	{
		dfs(graph, first, 0, j);
		dfs(graph, second, n - 1, j);
	}

	// 比较第一、二边界的遍历结果、获取交集
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (first[i][j] == true && second[i][j] == true)
				cout << i << " " << j << endl;
			// cout << first[i][j] << " ";
		}
		// cout << endl;
	}
	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < m; j++)
	// 	{
	// 		// if (first[i][j] == true && second[i][j] == true)
	// 		// 	cout << i << " " << j << endl;
	// 		cout << second[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
}
#endif
#ifdef Q6
#include <bits/stdc++.h>
using namespace std;

int mark = 2; // 初始岛屿的编号从2开始

int offest[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void dfs(vector<vector<int>> &graph, vector<vector<bool>> &visited, int x, int y, int &sum)
{
	if (visited[x][y] || graph[x][y] == 0)
		return;
	visited[x][y] = true;
	sum++;
	graph[x][y] = mark;
	for (int i = 0; i < 4; i++)
	{
		int nextx = x + offest[i][0];
		int nexty = y + offest[i][1];
		if (nextx < 0 || nexty < 0 || nextx >= graph.size() || nexty >= graph[0].size())
			continue;
		dfs(graph, visited, nextx, nexty, sum);
	}
}
int main()
{
	// 处理输入
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> graph[i][j];
		}
	}
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	std::unordered_map<int, int> map;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (graph[i][j] == 1 && !visited[i][j])
			{
				int sum = 0;
				dfs(graph, visited, i, j, sum);
				map[mark] = sum;
				mark++;
			}
		}
	}

	int max_s = 0;
	if (!map.empty())
	{
		// 如果有岛屿，不操作时的最大面积
		for (auto &it : map)
		{
			max_s = max(max_s, it.second);
		}
	}
	else
	{
		// 全为 0，至少可以变一个水为陆地，面积为 1
		max_s = 1;
	}

	std::unordered_set<int> set;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (graph[i][j] == 0)
			{
				int sum = 1;
				set.clear();
				for (int k = 0; k < 4; k++)
				{
					int nextx = i + offest[k][0];
					int nexty = j + offest[k][1];
					if (nextx < 0 || nexty < 0 || nextx >= n || nexty >= m)
						continue;
					if (!set.count(graph[nextx][nexty]) && map.count(graph[nextx][nexty]))
					{
						sum += map[graph[nextx][nexty]];
						set.insert(graph[nextx][nexty]);
					}
				}
				max_s = max(max_s, sum);
			}
		}
	}
	cout << max_s;
}
#endif
#include <bits/stdc++.h>
using namespace std;
int offest[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void bfs(vector<vector<int>> &graph, vector<vector<bool>> &visited, int x, int y)
{
	visited[x][y] = true;
	queue<pair<int, int>> que;
	que.push({x, y});
	while (!que.empty())
	{
		auto it = que.front();
		que.pop();
		int nowx = it.first;
		int nowy = it.second;
		for (int i = 0; i < 4; i++)
		{
			int nextx = nowx + offest[i][0];
			int nexty = nowy + offest[i][1];
			if (nextx < 0 || nexty < 0 || nextx >= graph.size() || nexty >= graph[0].size())
				continue;
			if (graph[nextx][nexty] == 1 && !visited[nextx][nexty])
			{
				que.push({nextx, nexty});
				visited[nextx][nexty] = true;
			}
		}
	}
}
int main()
{
	// 处理输入
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> graph[i][j];
		}
	}

	vector<vector<bool>> visited(n, vector<bool>(m, false));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (graph[i][j] == 1 && !visited[i][j])
			{
				// 只有一个岛屿
				bfs(graph, visited, i, j);
				break;
			}
		}
	}

	int length = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visited[i][j])
			{
				for (int k = 0; k < 4; k++)
				{
					int nextx = i + offest[k][0];
					int nexty = j + offest[k][1];
					if (nextx < 0 || nexty < 0 || nextx >= graph.size() || nexty >= graph[0].size())
						length++;
					else if (!visited[nextx][nexty])
						length++;
				}
			}
		}
	}
	cout << length;
}