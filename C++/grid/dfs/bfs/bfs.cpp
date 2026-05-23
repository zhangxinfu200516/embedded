#ifdef Q1
#include <bits/stdc++.h>

using namespace std;

int main()
{
	// 处理输入
	int n;
	cin >> n;
	string begin_str, end_str;
	cin >> begin_str >> end_str;
	std::unordered_set<string> str_set;
	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		str_set.insert(tmp);
	}
	str_set.insert(end_str); // 添加目标元素
	std::unordered_map<string, int> str_map;
	// string 字符串 int 记录路径上的节点个数
	// bfs搜索路径
	std::queue<string> que;
	que.push(begin_str);
	str_map.insert(std::make_pair(begin_str, 1));
	while (!que.empty())
	{
		string cur = que.front();
		que.pop(); // 出队
		for (int i = 0; i < cur.size(); i++)
		{
			string new_str = cur;
			// 遍历每一个字符串 依次替换 查找
			for (int j = 0; j < 26; j++)
			{
				new_str[i] = j + 'a';
				if (str_set.count(new_str) && !str_map[new_str]) // 路径不能回头
				{
					que.push(new_str);
					str_map[new_str] = str_map[cur] + 1; // 添加
				}
			}
		}
	}
	if (str_map[end_str])
		cout << str_map[end_str];
	else
		cout << 0;
}
#endif
#ifdef Q3
#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &graph, vector<bool> &visited, int x, int n)
{
	if (visited[x])
		return;
	visited[x] = true;
	for (int i = 1; i < n + 1; i++)
	{
		if (graph[x][i]) // 注意递归条件
			dfs(graph, visited, i, n);
	}
}
int main()
{
	int n, k;
	cin >> n >> k;
	vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
	for (int i = 0; i < k; i++)
	{
		int s, t;
		cin >> s >> t;
		graph[s][t] = 1;
	}
	vector<bool> visited(n + 1, false);
	// 从1开始深搜遍历所有节点 能访问到的置为true
	dfs(graph, visited, 1, n);

	bool result = true;
	for (int i = 1; i < n + 1; i++)
	{
		result &= visited[i];
	}
	if (result)
		cout << 1;
	else
		cout << -1;
}
#endif
#ifdef Q3
#include <bits/stdc++.h>

using namespace std;

void dfs(vector<list<int>> &graph, vector<bool> &visited, int x)
{
	if (visited[x])
		return;
	visited[x] = true;
	list<int> lists = graph[x];
	for (auto it : lists)
	{
		dfs(graph, visited, it);
	}
}
int main()
{
	int n, k;
	cin >> n >> k;
	vector<list<int>> graph(n + 1); // 链表的下标与节点一一对应（从1开始）
	while (k--)
	{
		int s, t;
		cin >> s >> t;
		graph[s].push_back(t);
	}

	vector<bool> visited(n + 1, false);

	dfs(graph, visited, 1);

	bool result = true;

	for (int i = 1; i < n + 1; i++)
	{
		result &= visited[i];
	}
	if (result)
		cout << 1;
	else
		cout << -1;
}
#endif
#include <bits/stdc++.h>
using namespace std;

int main()
{
	// 处理输入
	int n, k, m, s, t, e, maxE;
	cin >> n >> k >> m >> s >> t >> e >> maxE;
	vector<list<vector<int>>> graph(m);
	for (int i = 0; i < m; i++)
	{
		vector<int> record(4, 0);
		for (int j = 0; j < 4; j++)
		{
			cin >> record[j];
		}
		graph[i].push_back(record);
	}
	vector<int> CPK(k, 0);
	for (int i = 0; i < k; i++)
	{
		cin >> CPK[i];
	}
	

}
