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
class Solution
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
int main()
{
}