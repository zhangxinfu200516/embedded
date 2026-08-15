#include <bits\stdc++.h>
using namespace std;

class Solution01
{
public:
	int fib(int n)
	{
		vector<int> dp(n + 1, 0);
		dp[1] = 1;
		for (int i = 2; i <= n; i++)
			dp[i] = dp[i - 1] + dp[i - 2];
		return dp[n];
	}
};
class Solution02
{
public:
	int climbStairs(int n)
	{
		vector<int> dp(n + 1, 0);
		dp[1] = 1;
		dp[2] = 2;
		for (int i = 3; i <= n; i++)
			dp[i] = dp[i - 1] + dp[i - 2];
		return dp[n];
	}
};
class Solution03
{
public:
	int minCostClimbingStairs(vector<int> &cost)
	{
		int n = cost.size();
		vector<int> dp(n, 0);
		dp[1] = cost[0];
		for (int i = 2; i < n; i++)
			dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
		return dp[n - 1];
	}
};
class Solution04
{
public:
	int uniquePaths(int m, int n)
	{
		vector<vector<int>> dp(m, vector<int>(n, 0));
		for (int i = 0; i < m; i++)
			dp[i][0] = 1;
		for (int j = 0; j < n; j++)
			dp[0][j] = 1;
		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		return dp[m - 1][n - 1];
	}
};
class Solution05
{
public:
	int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
	{
		int m = obstacleGrid.size(), n = obstacleGrid[0].size();
		vector<vector<int>> dp(m, vector<int>(n, 0));
		for (int i = 0; i < m; i++)
			dp[i][0] = 1 * (!obstacleGrid[i][0]);
		for (int j = 0; j < n; j++)
			dp[0][j] = 1 * (!obstacleGrid[0][j]);
		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				dp[i][j] = dp[i - 1][j] * (!obstacleGrid[i][j]) + dp[i][j - 1] * (!obstacleGrid[i][j]);
			}
		}
		return dp[m - 1][n - 1];
	}
};
class Solution06
{
public:
	int numTrees(int n)
	{
		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				dp[i] += dp[j] * dp[i - 1 - j];
			}
		}
		return dp[n];
	}
};
class Solution07
{
public:
	int integerBreak(int n)
	{
		vector<int> dp(n + 1, 0);
		dp[2] = 1;
		for (int i = 3; i <= n; i++)
		{
			for (int j = 1; j <= i / 2; j++)
			{
				dp[i] = max({dp[i], j * (i - j), j * dp[i - j]});
			}
		}
		return dp[n];
	}
};

void func01(int n, int max_w, vector<int> value, vector<int> weight)
{
	vector<int> dp(max_w + 1, 0);
	for (int i = 0; i < n; i++)
	{
		for (int j = max_w; j >= weight[i]; j--)
			dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
		for (int j = 0; j <= max_w; j++)
			cout << dp[j] << " ";
		cout << endl;
	}
}
class Solution08
{
public:
	bool canPartition(vector<int> &nums)
	{
		int sum = 0, target = 0;
		for (int i = 0; i < nums.size(); i++)
			sum += nums[i];
		if (sum % 2 != 0)
			return false;
		target = sum / 2;
		vector<int> dp(target + 1, 0);
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = target; j >= nums[i]; j--)
			{
				dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
			}
		}
		if (dp[target] == target)
			return true;
		else
			return false;
	}
};
class Solution09
{
public:
	int lastStoneWeightII(vector<int> &stones)
	{
		int sum = 0, target = 0;
		for (int i = 0; i < stones.size(); i++)
			sum += stones[i];
		target = sum / 2;
		vector<int> dp(target + 1, 0);
		for (int i = 0; i < stones.size(); i++)
		{
			for (int j = target; j >= stones[i]; j--)
			{
				dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
			}
			for (int j = 0; j <= target; j++)
				cout << dp[j] << " ";
			cout << endl;
		}
		return sum - 2 * dp[target];
	}
};
class Solution10
{
public:
	int findTargetSumWays(vector<int> &nums, int target)
	{
		int sum = 0;
		for (int i = 0; i < nums.size(); i++)
			sum += nums[i];
		int b = (target + sum) / 2;
		vector<vector<int>> dp(nums.size(), vector<int>(b + 1, 0));
		for (int i = 0; i < nums.size(); i++)
			dp[i][0] = 1;
		dp[0][nums[0]] = 1;
		for (int i = 1; i < nums.size(); i++)
		{
			for (int j = 1; j <= b; j++)
			{
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i]];
			}
		}
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = 0; j <= b; j++)
				cout << dp[i][j] << " ";
			cout << endl;
		}
		return dp[nums.size() - 1][b];
	}
};
class Solution
{
public:
	int findMaxForm(vector<string> &strs, int m, int n)
	{
		int result = 0;
		for (int i = 0; i < strs.size(); i++)
		{
			map<char, int> map;
			for (int j = 0; j < strs[i].size(); j++)
			{
				map[strs[i][j]]++;
			}
            cout << map['0'] << " " << map['1'] << endl;
			if (map['0'] <= m && map['1'] <= n)
			{
				int val = strs[i].size();
				result = max(result, val);
			}
		}
		return result;
	}
};
int main()
{
	int n, max_w;
	cin >> n >> max_w;
	vector<int> weight(n, 0);
	vector<int> value(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> weight[i] >> value[i];
	}
	func01(n, max_w, value, weight);
	// vector<vector<int>> dp(n, vector<int>(max_w + 1, 0));
	// for (int j = weight[0]; j <= max_w; j++)
	// 	dp[0][j] = value[0];
	// for (int i = 1; i < n; i++)
	// {
	// 	for (int j = 1; j <= max_w; j++)
	// 	{
	// 		if (j - weight[i] >= 0)
	// 			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
	// 		else
	// 			dp[i][j] = dp[i - 1][j];
	// 	}
	// }
	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j <= max_w; j++)
	// 	{
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	return 0;
}
