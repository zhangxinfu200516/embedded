// 完全背包问题
#include <bits/stdc++.h>
using namespace std;
// 二维形式
int main01()
{
	int n, m;
	cin >> n >> m;
	vector<int> weight(n, 0);
	vector<int> value(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> weight[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> value[i];
	}
	vector<vector<int>> dp(n, vector<int>(m + 1, 0));
	for (int j = weight[0]; j <= m; j++)
	{
		dp[0][j] = dp[0][j - weight[0]] + value[0];
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (j < weight[i])
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - weight[i]] + value[i]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m + 1; j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}
}
// 一维形式
int main02()
{
	int n, m;
	cin >> n >> m;
	vector<int> weight(n, 0);
	vector<int> value(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> weight[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> value[i];
	}
	vector<int> dp(m + 1, 0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m + 1; j++)
		{
			if (j >= weight[i])
				dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
			cout << dp[j] << " ";
		}
		cout << endl;
	}
	cout << "---------------------------" << endl;
}
class Solution
{
public:
	int change(int amount, vector<int> &coins)
	{
		int m = amount;
		int n = coins.size();
		vector<int> dp(m + 1, 0);
		dp[0] = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = coins[i]; j < m + 1; j++)
			{
				dp[j] = dp[j] + dp[j - coins[i]];
				cout << dp[j] << " ";
			}
			cout << endl;
		}
		return dp[m];
	}
};
// 完全背包：for循环调换位置在求总次数上有区别：分别为组合 、 排列数
int main03()
{
	int n, m;
	cin >> n >> m;
	vector<int> weight(n, 0);
	// vector<int> value(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> weight[i];
	}
	// for (int i = 0; i < n; i++)
	// {
	// 	cin >> value[i];
	// }
	vector<int> dp(m + 1, 0);
	dp[0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m + 1; j++)
		{
			if (j >= weight[i])
				dp[j] = dp[j] + dp[j - weight[i]];
			cout << dp[j] << " ";
		}
		cout << endl;
	}
	cout << "---------------------------" << endl;
	vector<int> dp2(m + 1, 0);
	dp2[0] = 1;
	for (int j = 0; j < m + 1; j++)
	{
		for (int i = 0; i < n; i++)
		{
			if (j >= weight[i])
				dp2[j] = dp2[j] + dp2[j - weight[i]];
			cout << dp2[j] << " ";
		}
		cout << endl;
	}
}
//完全背包求 排列类型题
int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> steps(m, 0);
	for (int i = 1; i <= m; i++)
		steps[i - 1] = i;

	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	for (int j = 0; j < n + 1; j++)
	{
		for (int i = 0; i < m; i++)
		{
			if (j >= steps[i])
				dp[j] = dp[j] + dp[j - steps[i]];
			cout << dp[j] << " ";
		}
		cout << endl;
	}
	cout <<  dp[n];
}