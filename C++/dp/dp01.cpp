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
class Solution
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
class Solution
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
int main()
{
}