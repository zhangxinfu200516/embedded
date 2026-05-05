#include <iostream>
#include <vector>
using namespace std;

class Solution3
{
public:
	int fib(int n)
	{
		if (n < 2)
			return n;
		vector<int> dp(n + 1, 0);
		dp[0] = 0;
		dp[1] = 1;
		for (int i = 2; i < n + 1; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 2];
			// cout << dp[i] << endl;
		}
		return dp[n];
	}
};
class Solution1
{
public:
	int climbStairs(int n)
	{
		vector<int> dp(n + 1, 0);
		dp[1] = 1;
		dp[2] = 2;
		for (int i = 3; i < n + 1; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 2];
			//cout << dp[i] << " ";
		}
		return dp[n];
	}
};
class Solution4
{
public:
	int minCostClimbingStairs(vector<int> &cost)
	{
		int size = cost.size();
		if (size <= 2)
		{
			return 0;
		}
		vector<int> dp(cost.size() + 1, 0);
		dp[0] = 0;
		dp[1] = 0;
		for (int i = 2; i < cost.size() + 1; i++)
		{
			dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
			cout << dp[i] << endl;
		}
		return dp[cost.size()];
	}
};
class Solution5
{
public:
	int uniquePaths(int m, int n)
	{
		if (m == 1 && n == 1)
			return 1;
		vector<vector<int>> dp(m, vector<int>(n));
		for (int i = 0; i < m; i++)
			dp[i][0] = 1;
		for (int j = 0; j < n; j++)
			dp[0][j] = 1;
		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
		return dp[m - 1][n - 1];
	}
};
class Solution
{
public:
	int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
	{
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();

		vector<vector<int>> dp(m, vector<int>(n));
		for (int i = 0; i < m; i++)
			dp[i][0] = 1 * (!obstacleGrid[i][0]);
		for (int j = 0; j < n; j++)
			dp[0][j] = 1 * (!obstacleGrid[0][j]);
		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				dp[i][j] = dp[i - 1][j] * (!obstacleGrid[i - 1][j]) + dp[i][j - 1] * (!obstacleGrid[i][j - 1]);
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
		return dp[m - 1][n - 1];
	}
};
int main()
{
	Solution1 s;
	s.climbStairs(3);
}