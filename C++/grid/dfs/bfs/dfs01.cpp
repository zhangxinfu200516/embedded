#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	vector<vector<int>> result;
	vector<int> path;
	vector<vector<bool>> visited;
	void dfs(vector<vector<bool>> grad, int x, int n)
	{
		if (x == n)
		{
			result.push_back(path);
			return;
		}
		for (int i = 1; i <= n; i++)
		{
			if (grad[x][i] != true)
				continue;
			path.push_back(i);
			dfs(grad, i, n);
			path.pop_back();
		}
	}
};

int main()
{
	int n, m;
	cin >> n >> m;
	int a, b;
	vector<vector<bool>> grad(n + 1, vector<bool>(n + 1));
	while (m > 0)
	{
		cin >> a >> b;
		grad[a][b] = true;
		m--;
	}
	Solution s;
	s.path.push_back(1);
	s.dfs(grad, 1, n);	
	for (int i = 0; i < s.result.size(); i++)
	{
		for (int j = 0; j < s.result[i].size(); j++)
		{
			cout << s.result[i][j];
		}
		cout << endl;
	}
	return 0;
}