
#include <bits/stdc++.h>
using namespace std;
#ifdef Q1
int main()
{
	// 处理输入
	int m, n;
	cin >> m >> n;
	vector<int> weight(m + 1, 0);
	vector<int> value(m + 1, 0);
	for (int i = 1; i < m + 1; i++)
	{
		cin >> weight[i];
	}
	for (int i = 1; i < m + 1; i++)
	{
		cin >> value[i];
	}
	vector<int> dp(n + 1, 0);
	for (int i = 1; i < m + 1; i++)
	{
		for (int j = n; j >= weight[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
		}
		// for(int j = 0;j < n+1;j++)
		// cout << dp[j] << " ";
		// cout << endl;
	}
	cout << dp[n];
	// return dp[n];
}

class Solution
{
public:
	bool canPartition(vector<int> &nums)
	{
		int sum = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			sum += nums[i];
		}
		int target;
		if (sum % 2 == 0)
			target = sum / 2;
		else
			return false;

		vector<int> dp(target + 1, 0);
		for (int i = nums[0]; i < target + 1; i++)
			dp[i] = i;
		for (int i = 1; i < nums.size(); i++)
		{
			for (int j = target; j >= nums[i]; j--)
			{
				dp[j] = max(dp[j - 1], dp[j - nums[i]] + nums[i]);
				if (dp[target] == target)
					return true;
			}
		}
		return false;
	}
};
#endif
#ifdef Q2
vector<vector<int>> result;
vector<int> path;
void back_tracking(vector<int> &nums, int &sum, int target)
{
	if (sum > target)
	{
		return;
	}
	if (sum == target)
	{
		result.push_back(path);
		return;
	}
	for (int i = 0; i < nums.size(); i++)
	{
		path.push_back(nums[i]);
		sum += nums[i];
		back_tracking(nums, sum, target);
		path.pop_back();
		sum -= nums[i];
	}
}
int main()
{
	// 处理输入
	int n, target;
	cin >> n >> target;
	vector<int> nums(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}
	int sum = 0;
	// 回溯查找所有满足sum = target的子集
	back_tracking(nums, sum, target);
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j];
			if (j != result[i].size() - 1)
				cout << " ";
		}
		cout << endl;
	}
	cout << "个数为:" << " " << result.size();
}
#endif
#ifdef Q3
int main()
{
	int n, m;
	cin >> n >> m; // n阶到达楼顶 m每次爬最大的台阶数
	vector<int> steps(m, 0);
	for (int i = 0; i < steps.size(); i++)
	{
		steps[i] = i + 1;
	}
	vector<int> dp(n + 1, 0);
	// 初始化
	dp[0] = 1;
	for (int j = 0; j < n + 1; j++)
	{
		for (int i = 0; i < m; i++)
		{
			if (j - steps[i] >= 0)
				dp[j] = dp[j] + dp[j - steps[i]];
		}
	}
	// return dp[n];
	cout << dp[n];
}
#endif

int main()
{
	int c, n; // c表示容量 n表示种类
	cin >> c >> n;
	vector<int> weight(n, 0), value(n, 0), nums(n, 0);
	for (int i = 0; i < n; i++)
		cin >> weight[i];
	for (int i = 0; i < n; i++)
		cin >> value[i];
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	vector<vector<int>> dp(n, vector<int>(c + 1, 0));

	for (int j = weight[0]; j < c + 1; j++)
	{
		int i = 0;
		for (int k = 1; k <= nums[i] && (j - k * weight[i] >= 0); k++)
		{
			dp[i][j] = k * value[i];
		}
	}
	for (int j = 0; j < c + 1; j++) // 容量
	{
		for (int i = 1; i < n; i++) // 商品
		{
			dp[i][j] = dp[i - 1][j];
			for (int k = 1; k <= nums[i] && (j - k * weight[i] >= 0); k++)
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j - k * weight[i]] + k * value[i]);
			}
		}
	}
	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < c + 1; j++)
	// 	{
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	cout << dp[n - 1][c];
}
class Solution
{
public:
	int maxProfit(vector<int> &prices)
	{
		int n = prices.size();
		vector<vector<int>> dp(n, vector<int>(2, 0));
		dp[0][0] = -prices[0];
		dp[0][1] = 0;
		for (int i = 1; i < n; i++)
		{
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
		}
		for (int i = 0; i < n; i++)
		{
			cout << dp[i][0] << " ";
		}
		cout << endl;
		for (int i = 0; i < n; i++)
		{
			cout << dp[i][1] << " ";
		}

		int result = max(dp[n - 1][0], dp[n - 1][1]);
		return result;
	}
};
class Solution
{
public:
	int lengthOfLIS(vector<int> &nums)
	{
		int n = nums.size();
		vector<int> dp(n, 1);
		int result = 1;
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (nums[i] > nums[j])
					dp[i] = max(dp[i], dp[j] + 1);
			}
			result = max(result, dp[i]);
		}
		return result;
	}
};
class Solution
{
public:
	int findLengthOfLCIS(vector<int> &nums)
	{
		int result = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			int j = i;
			int sum = 1;
			while (nums[j + 1] > nums[j] && j + 1 < nums.size())
			{
				sum++;
				j++;
			}
			result = max(result, sum);
		}
	}
};

class Solution
{
public:
	int findLength(vector<int> &nums1, vector<int> &nums2)
	{
		int n = nums1.size();
		int m = nums2.size();
		vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
		for (int i = 1; i < n + 1; i++)
		{
			for (int j = 1; j < m + 1; j++)
			{
				if (nums1[i - 1] == nums2[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
		return dp[n][m];
	}
};
