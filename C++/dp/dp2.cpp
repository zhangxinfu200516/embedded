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
// 完全背包求 排列类型题
int main04()
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
	cout << dp[n];
}
// 多重背包
int main05()
{
	int bagWeight, n;
	cin >> bagWeight >> n;
	vector<int> weight(n, 0);
	vector<int> value(n, 0);
	vector<int> nums(n, 0);
	for (int i = 0; i < n; i++)
		cin >> weight[i];
	for (int i = 0; i < n; i++)
		cin >> value[i];
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	for (int i = 0; i < n; i++)
	{
		cout << weight[i] << " ";
	}
	cout << "--------------";
	for (int i = 0; i < n; i++)
	{
		while (nums[i] > 1)
		{
			weight.push_back(weight[i]);
			value.push_back(value[i]);
			nums[i]--;
		}
	}
	for (int i = 0; i < weight.size(); i++)
	{
		cout << weight[i] << " ";
	}
	cout << "--------------";
}
class Solution3
{
public:
	int coinChange(vector<int> &coins, int amount)
	{
		vector<int> dp(amount + 1, INT_MAX / 2);
		dp[0] = 0;
		for (int i = 0; i < coins.size(); i++)
		{
			for (int j = 0; j < amount + 1; j++)
			{
				if (j >= coins[i] && dp[j - coins[i]] != INT_MAX / 2)
					dp[j] = min(dp[j], dp[j - coins[i]] + 1);
				cout << dp[j] << " ";
			}
			cout << endl;
		}
		if (dp[amount] == INT_MAX / 2)
			return -1;
		else
			return dp[amount];
	}
};
// 最长重复子串
class Solution4
{
public:
	int findLength(vector<int> &nums1, vector<int> &nums2)
	{
		int n1 = nums1.size();
		int n2 = nums2.size();
		vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0)); // 以s1的第几个字符、s2的第几个字符结尾 的最长字符串的长度
		int max_lenght = -INT_MAX;
		for (int i = 1; i < n1 + 1; i++)
		{
			for (int j = 1; j < n2 + 1; j++)
			{
				if (nums1[i - 1] == nums2[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				max_lenght = max(dp[i][j], max_lenght);
			}
		}
		return max_lenght;
	}
};
// 多重背包（组合数：将等价值/重量的商品视为同一商品，此时需要考虑每种只处理一次（可以取多个））- 奖品兑换
int main06()
{
	int n;
	cin >> n;
	vector<int> values(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> values[i];
	}
	int target;
	cin >> target;
	// 统计每种价值的数量
	unordered_map<int, int> freq;
	for (int val : values)
	{
		freq[val]++;
	}
	vector<int> dp(target + 1, 0);
	dp[0] = 1;
	for (auto &p : freq)
		cout << p.first << " ";
	cout << endl;
	for (auto &p : freq)
		cout << p.second << " ";
	cout << endl;
	for (auto &p : freq)
	{
		int val = p.first;	// 奖品价值
		int cnt = p.second; // 该奖品的个数
		for (int j = target; j >= 0; j--)
		{
			// 最后枚举选择该奖品的个数（1 ~ cnt）
			for (int k = 1; k <= cnt && j >= k * val; ++k)
			{
				dp[j] += dp[j - k * val];
			}
			// dp[j] = dp[j] + dp[j - val];
		}
		for (int j = 0; j < target + 1; j++)
			cout << dp[j] << " ";
		cout << endl;
	}
	cout << dp[target];
}
int main()
{
	int k;
	cin >> k;
	vector<vector<int>> cost(k, vector<int>(k, 0));
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k; j++)
			cin >> cost[i][j];
	}
	vector<vector<int>> dp(k, vector<int>(k, INT_MAX));
	// 初始化
	// dp[0][0] = cost[0][0];
	// for (int i = 1; i < k; i++)
	// {
	// 	if (cost[0][i] - cost[0][i - 1] <= 1)
	// 		dp[0][i] = dp[0][i - 1] + cost[0][i];
	// 	else
	// 		break;
	// }
	// for (int i = 1; i < k; i++)
	// {
	// 	if (cost[i][0] - cost[i - 1][0] <= 1)
	// 		dp[i][0] = dp[i - 1][0] + cost[i][0];
	// 	else
	// 		break;
	// }
	// for (int i = 1; i < k; i++)
	// {
	// 	for (int j = 1; j < k; j++)
	// 	{
	// 		int min_cost = INT_MAX;
	// 		if (dp[i - 1][j] != INT_MAX && abs(cost[i][j] - cost[i - 1][j]) <= 1)
	// 			min_cost = min(dp[i - 1][j] + cost[i][j], min_cost);
	// 		if (dp[i][j - 1] != INT_MAX && abs(cost[i][j] - cost[i][j - 1]) <= 1)
	// 			min_cost = min(dp[i][j - 1] + cost[i][j], min_cost);

	// 		dp[i][j] = min_cost;
	// 	}
	// }
	dp[0][0] = cost[0][0];
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (i == 0 && j == 0)
				continue;
			if (i > 0 && dp[i - 1][j] != INT_MAX && abs(cost[i][j] - cost[i - 1][j]) < 2)
				dp[i][j] = min(dp[i][j], dp[i - 1][j] + cost[i][j]);
			if (j > 0 && dp[i][j - 1] != INT_MAX && abs(cost[i][j] - cost[i][j - 1]) < 2)
				dp[i][j] = min(dp[i][j], dp[i][j - 1] + cost[i][j]);
		}
	}
	// 打印测试
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	// 取最右边的最小值
	int min_dp = INT_MAX;
	for (int i = 0; i < k; i++)
	{
		min_dp = min(min_dp, dp[i][k - 1]);
	}
	if (min_dp == INT_MAX)
		cout << -1;
	else
		cout << min_dp;
}