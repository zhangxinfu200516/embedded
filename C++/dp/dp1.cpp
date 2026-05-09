#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// 前缀和的方法(error)
int Get_Result(vector<int> input)
{
	vector<int> sum(input.size(), 0);
	int __sum = 0, min_sum = INT_MAX, max_sum = -INT_MAX;
	for (int i = 0; i < input.size(); i++)
	{
		__sum += input[i];
		sum[i] = __sum;
		min_sum = min(sum[i], min_sum);
		max_sum = max(sum[i], max_sum);
	}
	return max_sum - min_sum;
}
// 动态规划
int maxSubArraySum(vector<int> &nums)
{
	if (nums.size() == 0)
		return 0;
	vector<int> dp(nums.size(), 0);
	dp[0] == nums[0];
	int max_sum = -INT_MAX;
	for (int i = 1; i < nums.size(); i++)
	{
		dp[i] = max(dp[i - 1] + nums[i], nums[i]);
		max_sum = max(dp[i], max_sum);
	}
	return max_sum;
}
int main01()
{
	int n;
	cin >> n;
	vector<int> input(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
	}
// for (int i = 0; i < n; i++)
// {
// 	cout << input[i] <<" ";
// }
// vector<vector<int>> dp(n, vector<int>(n, 0));
#ifdef DISABLE
	int i = 0, j = 0, max_cost = 0;
	for (i = 0; i < n; i++)
	{
		int sum = 0, max_sum = 0;
		for (j = i; j < n; j++)
		{
			// dp[i][j] = max(dp[i][j - 1], dp[i][j - 1] + input[j]);
			sum += input[j];
			max_sum = max(sum, max_sum);
		}
		// max_cost = max(max_cost, dp[i][j]);
		max_cost = max(max_sum, max_cost);
	}
	cout << max_cost;
#endif
	int result = maxSubArraySum(input);
	cout << result;
}

int main02()
{
	int areaRequirement, budget, n;
	cin >> areaRequirement >> budget >> n;
	vector<vector<int>> coverage_cost(n, vector<int>(2, 0));
	for (int i = 0; i < n; i++)
	{
		cin >> coverage_cost[i][0] >> coverage_cost[i][1];
	}

	int i = 0, j = 0;
	int min_cost = INT_MAX, max_area = 0;
	for (i = 0; i < n; i++)
	{
		int sum_area = 0, sum_cost = 0;
		j = i;
		while (j < n)
		{
			sum_area += coverage_cost[j][0];
			sum_cost += coverage_cost[j][1];

			if (sum_area >= areaRequirement)
			{
				if (min_cost > sum_cost && sum_cost <= budget)
				{
					min_cost = sum_cost;
					max_area = sum_area;
				}
				// cout << sum_cost << " " << sum_area << endl;
				break;
			}
			else
				j++;
		}
	}
	min_cost = (min_cost == INT_MAX) ? 0 : min_cost;
	cout << min_cost << " " << max_area;
}

int main03()
{
	int N, M;
	cin >> N >> M;
	vector<int> input(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> input[i];
	}
	vector<int> dp(N + 1, 0);
	dp[1] = input[0];
	int min_cost = INT_MAX;
	if (N > M)
	{
		for (int i = 2; i < N + 1; i++)
		{
			min_cost = INT_MAX;
			int j = max(i - M, 0);
			while (j < i)
			{
				if (min_cost > dp[j])
					min_cost = dp[j];
				j++;
			}
			dp[i] = min_cost + input[i - 1];
		}

		min_cost = INT_MAX;
		for (int i = N - M + 1; i < N + 1; i++)
		{
			min_cost = min(min_cost, dp[i]);
		}
	}
	else
	{
		min_cost = INT_MAX;
		for (int i = 1; i < N + 1; i++)
		{
			min_cost = min(input[i - 1], min_cost);
		}
	}
	cout << min_cost;
}
#ifdef DISABLE
int main04()
{
	string s1, s2;
	cin >> s1 >> s2;
	vector<int> result1(26, 0);
	vector<int> result2(26, 0);
	// cout << std::to_string('a') << " " << std::to_string('b'); // a为97 、 b为98
	int left = 0;
	for (int j = 0; j < s1.size(); j++)
	{
		if (s1[left] == s1[j])
		{
			// 不处理
		}
		else
		{
			// 记录该字母的最大个数并更新到result1中
		}
	}
	int left = 0;
	for (int j = 0; j < s2.size(); j++)
	{
		if (s2[left] == s2[j])
		{
			// 不处理
		}
		else
		{
			// 记录该字母的最大个数并更新到result2中
		}
	}

	for (int i = 0; i < 26; i++)
	{
		// 对比result1与result2 得到最长的字符串结果并输出
	}
}
#endif
int main04()
{
	string s1, s2;
	cin >> s1 >> s2;
	int n = s1.size(), m = s2.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

	int max_dp = -INT_MAX;
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				max_dp = max(dp[i][j], max_dp);
			}
		}
	}
	cout << max_dp;
}
void test_umap()
{
	std::unordered_map<int, int> umap;
	umap.insert(std::make_pair(1, 1));
	umap[2] = 1;
	for (auto it = umap.begin(); it != umap.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}
}
// 01背包问题：每个物品的数量只有一个:按照选与不选考虑递归公式
int main05()
{
	int n, max_weight;
	cin >> n >> max_weight;
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
	vector<vector<int>> dp(n, vector<int>(max_weight + 1, 0));
	for (int i = weight[0]; i <= max_weight; i++)
	{
		dp[0][i] = value[0];
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= max_weight; j++)
		{
			if (j - weight[i] < 0)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << dp[n - 1][max_weight];
}
//01背包问题，滚动数组方式，减小空间复杂度。
int main()
{
	int n, max_weight;
	cin >> n >> max_weight;
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

	vector<int> dp(max_weight + 1, 0);
	for (int i = 0; i < n; i++)
	{
		for (int j = max_weight; j >= weight[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
			//cout << dp[j] << " ";
		}
		//cout << endl;
	}
	cout << dp[max_weight];
}