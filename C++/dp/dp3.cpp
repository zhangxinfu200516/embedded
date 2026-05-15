#include <bits/stdc++.h>
using namespace std;
// 命令行提示
int main01()
{
	// 处理输入
	int D, N;
	cin >> D >> N;
	vector<string> strings(N);
	for (int i = 0; i < N; i++)
	{
		cin >> strings[i];
	}
	string target;
	cin >> target;
	vector<string> result;
	// dp处理替换 + 删除1的情况
	for (int i = 0; i < N; i++)
	{
		vector<int> dp(25 + 1, 6);
		dp[0] = 0;
		int offest = 0;
		for (int j = 1; j < strings[i].size() + 1; j++)
		{
			if (target[j - 1] != strings[i][j - 1 + offest] && target[j - 1] == strings[i][j + offest] && j + offest < strings[i].size())
			{
				dp[j] = dp[j - 1] + 1;
				offest++;
			}
			else if (target[j - 1] != strings[i][j - 1 + offest])
				dp[j] = dp[j - 1] + 1;
			else
				dp[j] = dp[j - 1];
		}
		if (dp[strings[i].size()] <= D)
			result.push_back(strings[i]);
	}
	// 输出结果
	if (result.size() != 0)
	{
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i];
			if (i != result.size() - 1)
				cout << " ";
		}
	}
	else
	{
		cout << "None";
	}
}
// 编辑距离
class Solution1
{
public:
	int minDistance(string word1, string word2)
	{
		// 初始化dp
		vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
		for (int i = 0; i < word1.size() + 1; i++)
			dp[i][0] = i;
		for (int i = 0; i < word2.size() + 1; i++)
			dp[0][i] = i;
		for (int i = 1; i < word1.size() + 1; i++)
		{
			for (int j = 1; j < word2.size() + 1; j++)
			{
				if (word1[i - 1] == word2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else
					dp[i][j] = min(dp[i - 1][j - 1] + 2, min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
			}
		}

		for (int i = 0; i < word1.size() + 1; i++)
		{
			for (int j = 0; j < word2.size() + 1; j++)
			{
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
		return dp[word1.size()][word2.size()];
	}
};
class Solution2
{
public:
	int minDistance(string word1, string word2)
	{
		// 初始化dp
		vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
		for (int i = 0; i < word1.size() + 1; i++)
			dp[i][0] = i;
		for (int i = 0; i < word2.size() + 1; i++)
			dp[0][i] = i;
		for (int i = 1; i < word1.size() + 1; i++)
		{
			for (int j = 1; j < word2.size() + 1; j++)
			{
				if (word1[i - 1] == word2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else
					dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
			}
		}
		return dp[word1.size()][word2.size()];
	}
};
// 命令行提示 ： 编辑距离
// 迭代公式：
int main02()
{
	// 处理输入
	int D, N;
	cin >> D >> N;
	vector<string> strings(N);
	for (int i = 0; i < N; i++)
	{
		cin >> strings[i];
	}
	string target;
	cin >> target;
	vector<string> result;
	// 通过二维dp解决
	for (int i = 0; i < N; i++)
	{
		vector<vector<int>> dp(target.size() + 1, vector<int>(strings[i].size() + 1, 0));
		for (int k = 0; k <= target.size(); k++)
			dp[k][0] = k;
		for (int k = 0; k <= strings[i].size(); k++)
			dp[0][k] = k;
		// 外层为target 内层为strings成员
		for (int m = 1; m <= target.size(); m++)
		{
			for (int n = 1; n <= strings[i].size(); n++)
			{
				if (target[m - 1] == strings[i][n - 1])
					dp[m][n] = dp[m - 1][n - 1];
				else
					dp[m][n] = min({dp[m - 1][n - 1], dp[m][n - 1], dp[m - 1][n]}) + 1;
			}
		}
		if (dp[target.size()][strings[i].size()] <= D)
			result.push_back(strings[i]);
	}
	// 输出结果
	if (result.size() != 0)
	{
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i];
			if (i != result.size() - 1)
				cout << " ";
		}
	}
	else
	{
		cout << "None";
	}
}
// 打家劫舍
class Solution3
{
public:
	int rob(vector<int> &nums)
	{
		if (nums.size() == 1)
			return nums[0];

		vector<int> dp(nums.size());
		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);
		for (int i = 2; i < nums.size(); i++)
		{
			dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
		}
		return dp[nums.size() - 1];
	}
};
// 环形打家劫舍
class Solution4
{
public:
	int get_rob(vector<int> &nums)
	{
		if (nums.size() == 1)
			return nums[0];

		vector<int> dp(nums.size());
		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);
		for (int i = 2; i < nums.size(); i++)
		{
			dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
		}
		return dp[nums.size() - 1];
	}
	int rob(vector<int> &nums)
	{
		if (nums.size() == 1)
		{
			return nums[0];
		}
		vector<int> nums1(nums.begin(), nums.end() - 1);
		vector<int> nums2(nums.begin() + 1, nums.end());
		int result1 = get_rob(nums1);
		int result2 = get_rob(nums2);
		return max(result1, result2);
	}
};

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution5
{
public:
	int get_maxdepth(TreeNode *root)
	{
		if (root == NULL)
			return 0;
		int left = get_maxdepth(root->left);
		int right = get_maxdepth(root->right);
		int result = max(left, right) + 1;
		return result;
	}
	int rob(TreeNode *root)
	{
		// 求得深度
		int max_depth = get_maxdepth(root);
		// dp[i] 选取0 - i -1 层中能得到的最高金额
		vector<int> dp(max_depth, 0);
		dp[0] = root->val;
		// if()
	}
};
class Solution6
{
public:
	int rob(TreeNode *root)
	{
		vector<int> result(2, 0);
		result = get_maxrob(root);
		return max(result[0], result[1]);
	}
	// 维护长度为2的dp数组，存放已遍历所有的节点{"不偷" 、 "偷"}的最大值
	vector<int> get_maxrob(TreeNode *root)
	{
		// 终止条件
		if (root == NULL)
			return vector<int>{0, 0};
		// 初始化

		// 后续遍历
		vector<int> l = get_maxrob(root->left);
		vector<int> r = get_maxrob(root->right);
		// 不偷父节点
		int result1 = max(l[0], l[1]) + max(r[0], r[1]);
		// 偷父节点
		int result2 = root->val + l[0] + r[0];

		return vector<int>{result1, result2};
	}
};
// 暴力递归
class Solution
{
public:
	int rob(TreeNode *root)
	{
		if (root == NULL)
			return 0;
		// if(root->left && root.le)
		// 不偷父节点
		int result1 = rob(root->left) + rob(root->right);
		// 偷
		int result2 = root->val;
		if (root->left)
			result2 += rob(root->left->left) + rob(root->left->right);
		if (root->right)
			result2 += rob(root->right->left) + rob(root->right->right);
		return max(result1, result2);
	}
};
// 通过层序存储 写出 链式形式
class Sloution
{
public:
	TreeNode *get_tree_node(vector<int> arr, int index)
	{
		if (arr[index] == NULL || index >= arr.size())
			return NULL;
		TreeNode *node = new TreeNode(arr[index]);
		node->left = get_tree_node(arr, 2 * index + 1);
		node->right = get_tree_node(arr, 2 * index + 2);
		return node;
	}
	// 前序遍历链式二叉树得到 数组结果
	void get_arr(TreeNode *root, vector<int> &result)
	{
		if (root == NULL)
			return;
		result.push_back(root->val);
		get_arr(root->left, result);
		get_arr(root->right, result);
	}
};
int main()
{
	int n;
	cin >> n;
	vector<int> input(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
	}
	// 将其转成
	Sloution s;
	TreeNode *root = s.get_tree_node(input, 0);
	vector<int> result;
	s.get_arr(root, result);
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";
}
// 买股票
// 暴力for
class Solution
{
public:
	int maxProfit(vector<int> &prices)
	{
		if (prices.size() == 1)
			return 0;
		int max_prices = -INT_MAX;
		for (int i = 0; i <= prices.size() - 2; i++)
		{
			for (int j = i + 1; j <= prices.size() - 1; j++)
			{
				int now_price;
				if (prices[i] < prices[j])
					now_price = prices[j] - prices[i];
				else
					now_price = 0;
				max_prices = max(max_prices, now_price);
			}
		}
		return max_prices;
	}
};
// 动态规划
class Solution
{
public:
	int maxProfit(vector<int> &prices)
	{
		if (prices.size() == 1)
			return 0;
		vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
		dp[0][0] = -prices[0]; // 持有
		dp[0][1] = 0;		   // 不持有
		for (int i = 1; i < prices.size(); i++)
		{
			dp[i][0] = max(dp[i - 1][0], -prices[i]);
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
		}
		for (int i = 0; i < prices.size(); i++)
		{
			for (int j = 0; j < 2; j++)
			{
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
		return dp[prices.size() - 1][1];
	}
};
// 买股票的最佳时机II
class Solution
{
public:
	int maxProfit(vector<int> &prices)
	{
		if (prices.size() == 1)
			return 0;
		vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
		dp[0][0] = -prices[0]; // 持有
		dp[0][1] = 0;		   // 不持有
		for (int i = 1; i < prices.size(); i++)
		{
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
		}
		for (int i = 0; i < prices.size(); i++)
		{
			for (int j = 0; j < 2; j++)
			{
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
		return dp[prices.size() - 1][1];
	}
};
// 买股票的最佳时机III
class Solution
{
public:
	int maxProfit(vector<int> &prices)
	{
		if (prices.size() == 1)
			return 0;
		vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
		dp[0][0] = -prices[0]; // 第一次交易持有
		dp[0][1] = 0;		   // 第一次交易不持有
		dp[0][2] = -prices[0]; // 第二次交易持有
		dp[0][3] = 0;		   // 第二次交易不持有
		for (int i = 1; i < prices.size(); i++)
		{
			dp[i][0] = max(dp[i - 1][0], -prices[i]);
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
			dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] - prices[i]);
			dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] + prices[i]);
		}
		for (int i = 0; i < prices.size(); i++)
		{
			for (int j = 0; j < 4; j++)
			{
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
		return dp[prices.size() - 1][3];
	}
};
// 买股票的最佳时机含冷冻期
class Solution
{
public:
	int maxProfit(vector<int> &prices)
	{
		if (prices.size() == 1)
			return 0;

		vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
		dp[0][0] = -prices[0]; // 持有股票（买入股票、保持买入股票）
		dp[0][1] = 0;		   // 保持卖出股票（这次不卖）
		dp[0][2] = 0;		   // 卖出股票（这次卖出股票）
		dp[0][3] = 0;		   // 冷冻状态
		for (int i = 1; i < prices.size(); i++)
		{
			dp[i][0] = max({dp[i - 1][0], dp[i - 1][1] - prices[i], dp[i - 1][3] - prices[i]});
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
			dp[i][2] = dp[i - 1][0];
			dp[i][3] = dp[i - 1][2];
		}
		for (int i = 0; i < prices.size(); i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
		return dp[prices.size() - 1][3];
	}
};
class Solution
{
public:
	int maxProfit(vector<int> &prices, int fee)
	{
		if (prices.size() == 1)
			return 0;
		vector<vector<int>> dp(prices.size(), vector<int>(3, 0));
		dp[0][0] = -prices[0];
		dp[0][1] = 0;
		dp[0][2] = 0;
		for (int i = 1; i < prices.size(); i++)
		{
			dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]) - prices[i]);
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][2]);
			dp[i][2] = dp[i - 1][0] + prices[i] - fee;
		}
		for (int i = 0; i < prices.size(); i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
		return max({dp[prices.size() - 1][0], dp[prices.size() - 1][1], dp[prices.size() - 1][2]});
	}
};
// 最长递增子序列
class Solution
{
public:
	int lengthOfLIS(vector<int> &nums)
	{
		if (nums.size() == 1)
			return 1;
		vector<int> dp(nums.size(), 0);
		dp[0] = 1;
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] > nums[i - 1])
				dp[i] = dp[i - 1] + 1;
			else
				dp[i] = dp[i - 1];
		}
		return dp[nums.size() - 1];
	}
};
// 暴力for
class Solution
{
public:
	int findLengthOfLCIS(vector<int> &nums)
	{
		if (nums.size() == 1)
			return 1;
		int max_l = -INT_MAX;
		for (int i = 0; i < nums.size(); i++)
		{
			int j = i;
			while (nums[j] < nums[j + 1] && j + 1 < nums.size())
			{
				j++;
			}
			max_l = max(max_l, j - i + 1);
		}
		return max_l;
	}
};
class Solution
{
public:
	int findLength(vector<int> &nums1, vector<int> &nums2)
	{
		vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
		for (int i = 1; i < nums1.size() + 1; i++)
		{
			for (int j = 1; j < nums2.size() + 1; j++)
			{
				if (nums2[j - 1] == nums1[i - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		for (int i = 0; i < nums1.size() + 1; i++)
		{
			for (int j = 0; j < nums2.size() + 1; j++)
			{
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
		return dp[nums1.size()][nums2.size()];
	}
};
class Solution
{
public:
	int longestCommonSubsequence(string text1, string text2)
	{
		vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
		for (int i = 1; i < text1.size() + 1; i++)
		{
			for (int j = 1; j < text2.size() + 1; j++)
			{
				if (text2[j - 1] == text1[i - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		for (int i = 0; i < text1.size() + 1; i++)
		{
			for (int j = 0; j < text2.size() + 1; j++)
			{
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
		return dp[text1.size()][text2.size()];
	}
};
class Solution
{
public:
	int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
	{
		vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
		for (int i = 1; i < nums1.size() + 1; i++)
		{
			for (int j = 1; j < nums2.size() + 1; j++)
			{
				if (nums2[j - 1] == nums1[i - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		for (int i = 0; i < nums1.size() + 1; i++)
		{
			for (int j = 0; j < nums2.size() + 1; j++)
			{
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
		return dp[nums1.size()][nums2.size()];
	}
};
class Solution
{
public:
	int maxSubArray(vector<int> &nums)
	{
		if (nums.size() == 1)
			return nums[0];
		vector<int> dp(nums.size(), 0);
		int max_sum = -INT_MAX;
		dp[0] = nums[0];
		max_sum = max(dp[0], max_sum);
		for (int i = 1; i < nums.size(); i++)
		{
			dp[i] = max(dp[i - 1] + nums[i], nums[i]);
			max_sum = max(dp[i], max_sum);
		}
		return max_sum;
	}
};
class Solution
{
public:
	bool isSubsequence(string s, string t)
	{
		vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
		for (int i = 0; i < s.size() + 1; i++)
			dp[i][0] = i;
		for (int j = 0; j < t.size() + 1; j++)
			dp[0][j] = j;
		for (int i = 1; i < s.size() + 1; i++)
		{
			for (int j = 1; j < t.size() + 1; j++)
			{
				if (s[i - 1] == t[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else
					dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
			}
		}
		for (int i = 0; i < s.size() + 1; i++)
		{
			for (int j = 0; j < t.size() + 1; j++)
			{
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
		int result = s.size() - t.size();
		if (dp[s.size()][t.size()] == abs(result))
			return true;
		else
			return false;
	}
};