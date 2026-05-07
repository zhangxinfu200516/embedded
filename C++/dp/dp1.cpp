#include <iostream>
#include <vector>
#include <algorithm>
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
int main()
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