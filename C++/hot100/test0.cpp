#include <bits\stdc++.h>
using namespace std;
class Solution01
{
public:
	vector<int> findDisappearedNumbers(vector<int> &nums)
	{
		std::unordered_set<int> uset(nums.begin(), nums.end());
		vector<int> result;
		for (int i = 1; i <= nums.size(); i++)
		{
			if (uset.count(i) == 0)
				result.push_back(i);
		}
		return result;
	}
};
class Solution02
{
private:
	unordered_set<int> uset;

public:
	bool is_true(string s, string p)
	{
		if (s.size() != p.size())
			return false;
		else if (s == p)
			return true;
		unordered_map<char, int> umap;
		for (int i = 0; i < s.size(); i++)
		{
			umap[s[i]]++;
			umap[p[i]]--;
		}
		for (auto it = umap.begin(); it != umap.end(); it++)
		{
			if (it->second != 0)
				return false;
		}
		return true;
	}
	void bt(string s, string p, int index)
	{
		if (s.size() == index)
			return;
		for (int i = index; i < s.size(); i++)
		{
			string temp = s.substr(index, i - index + 1);
			if (is_true(temp, p))
				uset.insert(index);
			bt(s, p, i + 1);
		}
	}
	vector<int> findAnagrams(string s, string p)
	{
		bt(s, p, 0);
		vector<int> result(uset.begin(), uset.end());
		return result;
	}
};

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int _val) : val(_val), left(NULL), right(NULL) {};
};
class Solution03
{
private:
	int sum = 0;
	int result = 0;

public:
	void func(TreeNode *root, int target)
	{
		if (root == NULL || sum > target)
			return;
		cout << sum << " ";
		if (sum == target)
			result++;
		if (root->left)
		{
			sum += root->left->val;
			func(root->left, target);
			sum -= root->left->val;
		}
		if (root->right)
		{
			sum += root->right->val;
			func(root->right, target);
			sum -= root->right->val;
		}
	}
	int pathSum(TreeNode *root, int targetSum)
	{
		if (root == NULL)
			return 0;
		if (root->val <= targetSum)
			sum += root->val;
		func(root, targetSum);
		return result;
	}
};
class Solution04
{
private:
	unordered_map<int, int> umap;
	int result = 0;

public:
	void dfs(TreeNode *root, int cur_sum, int targetSum)
	{
		if (root == NULL)
			return;
		cur_sum += root->val;
		if (umap[cur_sum - targetSum])
			result += umap[cur_sum - targetSum];
		umap[cur_sum]++;
		dfs(root->left, cur_sum, targetSum);
		dfs(root->right, cur_sum, targetSum);
		umap[cur_sum]--;
	}
	int pathSum(TreeNode *root, int targetSum)
	{
		umap[0] = 1;
		dfs(root, 0, targetSum);
		return result;
	}
};
class Solution05
{
public:
	static bool cmp(const vector<int> &a, const vector<int> &b)
	{
		if (a[0] == b[0])
			return a[1] < b[1];
		return a[0] > b[0];
	}
	vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
	{
		sort(people.begin(), people.end(), cmp);
		vector<vector<int>> result;
		for (int i = 0; i < people.size(); i++)
		{
			result.insert(result.begin() + people[i][1], people[i]);
		}
		return result;
	}
};
class Solution06
{
public:
	string decodeString(string s)
	{
		string result;
		int record = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '[' || s[i] == ']')
				continue;
			else if (s[i] > '0' && s[i] < 9) // 符合整数条件1-300
				record = s[i] - '0';
			else if (s[i] >= 'a' && s[i] <= 'z') // 符合字符条件
			{
				if (record != 0)
				{
					while (record--)
					{
						result.push_back(s[i]);
					}
				}
				else
					result.push_back(s[i]);
			}
		}
		return result;
	}
};
class Solution07
{
private:
	stack<int> nums;
	stack<string> strs;
	int num;
	string cur;

public:
	string decodeString(string s)
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] > '0' && s[i] <= '9')
				num = s[i] - '0';
			else if (s[i] >= 'a' && s[i] <= 'z')
				cur += s[i];
			else if (s[i] == '[')
			{
				nums.push(num);
				strs.push(cur);
				cur = "";
			}
			else
			{
				int val = nums.top();
				nums.pop();
				for (int i = 0; i < val; i++)
					strs.top() += cur;
				cur = strs.top();
				strs.pop();
			}
		}
		return cur;
	}
};
class Solution08
{
public:
	static bool cmp(const pair<int, int> &a, const pair<int, int> &b)
	{
		return a.second > b.second;
	}
	vector<int> topKFrequent(vector<int> &nums, int k)
	{
		unordered_map<int, int> umap;
		for (int num : nums)
		{
			umap[num]++;
		}
		vector<pair<int, int>> record;
		for (auto &it : umap)
		{
			record.push_back({it.first, it.second});
		}
		sort(record.begin(), record.end(), cmp);
		vector<int> result;
		for (int i = 0; i < k; i++)
		{
			result.push_back(record[i].first);
		}
		return result;
	}
};
class Solution09
{
public:
	int get_value(int num)
	{
		int result = 0;
		while (num / 2 || num % 2)
		{
			result += num % 2;
			num /= 2;
		}
		return result;
	}
	vector<int> countBits(int n)
	{
		vector<int> result;
		for (int i = 0; i <= n; i++)
		{
			result.push_back(get_value(i));
		}
		return result;
	}
};
class Solution10
{
public:
	int maxProfit(vector<int> &prices)
	{
		vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
		dp[0][0] = -prices[0];
		dp[0][1] = 0;
		for (int i = 1; i < prices.size(); i++)
		{
			dp[i][0] = max(dp[i - 1][0], -prices[i]);
			dp[i][1] = max(dp[i - 1][0] + prices[i], dp[i - 1][1]);
		}
		return dp[prices.size() - 1][1];
	}
};
class Solution11
{
public:
	int maxProfit(vector<int> &prices)
	{
		vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
		dp[0][0] = -prices[0];
		for (int i = 1; i < prices.size(); i++)
		{
			dp[i][0] = max({dp[i - 1][0], dp[i][2] - prices[i], dp[i - 1][3] - prices[i]});
			dp[i][1] = dp[i - 1][0] + prices[i];
			dp[i][2] = max(dp[i - 1][2], dp[i - 1][3]);
			dp[i][3] = dp[i - 1][1];
		}
		return max(dp[prices.size() - 1][1], dp[prices.size() - 1][2]);
	}
};
class Solution12
{
public:
	int lengthOfLIS(vector<int> &nums)
	{
		vector<int> dp(nums.size(), 1);
		for (int i = 1; i < nums.size(); i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (nums[j] < nums[i])
					dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		sort(dp.begin(), dp.end());
		return dp[nums.size() - 1];
	}
};
class Solution13
{
public:
	vector<int> get_nums(int n)
	{
		vector<int> result;
		int val = 1;
		while (val * val <= n)
		{
			result.push_back(val * val);
			val++;
		}
		return result;
	}
	int numSquares(int n)
	{
		vector<int> nums = get_nums(n);
		vector<int> dp(n + 1, INT_MAX);
		dp[0] = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			cout << nums[i] << " ";
			for (int j = nums[i]; j <= n; j++)
			{
				if (dp[j - nums[i]] != INT_MAX)
					dp[j] = min(dp[j], dp[j - nums[i]] + 1);
			}
		}
		return dp[n];
	}
};
class Solution14
{
public:
	int offset[2][2] = {{1, 0}, {0, 1}};
	void dfs(vector<vector<int>> &matrix, vector<vector<bool>> &visited, int x, int y, bool &result, int target)
	{
		visited[x][y] = true;
		if (matrix[x][y] == target)
		{
			result = true;
			return;
		}
		for (int i = 0; i < 2; i++)
		{
			int nextx = x + offset[i][0];
			int nexty = y + offset[i][1];
			if (nextx < 0 || nextx >= matrix.size() || nexty < 0 || nexty >= matrix[0].size())
				continue;
			if (matrix[nextx][nexty] <= target && visited[nextx][nexty] == false)
				dfs(matrix, visited, nextx, nexty, result, target);
		}
	}
	bool searchMatrix(vector<vector<int>> &matrix, int target)
	{
		vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));
		bool result = false;
		dfs(matrix, visited, 0, 0, result, target);
		return result;
	}
};

class Codec
{
public:
	// Encodes a tree to a single string.
	string serialize(TreeNode *root)
	{
		if (root == NULL)
			return "X";
		queue<TreeNode *> que;
		que.push(root);
		string strs;
		while (!que.empty())
		{
			auto it = que.front();
			que.pop();
			if (it)
			{
				strs += to_string(it->val);
				que.push(it->left);
				que.push(it->right);
			}
			else
			{
				strs += "X";
			}
		}
		return strs;
	}

	// Decodes your encoded data to tree.
	TreeNode *deserialize(string data)
	{
		if (data == "X")
			return NULL;
		TreeNode *root = new TreeNode(data[0] - '0');
		queue<TreeNode *> que;
		que.push(root);
		int index = 1;
		while (!que.empty())
		{
			auto it = que.front();
			que.pop();
			if (data[index] != 'X')
			{
				TreeNode *left = new TreeNode(data[index] - '0');
				it->left = left;
				que.push(left);
			}
			if (data[index + 1] != 'X')
			{
				TreeNode *right = new TreeNode(data[index + 1] - '0');
				it->right = right;
				que.push(right);
			}
			index += 2;
		}
		return root;
	}
};
class Solution15
{
private:
	vector<string> result;
	string path;

public:
	void dfs(int n, int left, int right)
	{
		if (path.size() == 2 * n)
		{
			result.push_back(path);
			return;
		}
		if (left <= n)
		{
			path += "(";
			dfs(n, left + 1, right);
			path.pop_back();
		}
		if (right < left)
		{
			path += ")";
			dfs(n, left, right + 1);
			path.pop_back();
		}
	}
	vector<string> generateParenthesis(int n)
	{
		dfs(n, 1, 1);
		return result;
	}
};
class Solution16
{
public:
	void rotate(vector<vector<int>> &matrix)
	{
		int n = matrix.size();
		vector<vector<int>> temp = matrix;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				matrix[j][n - 1 - i] = temp[i][j];
			}
		}
	}
};
class Solution17
{
private:
	vector<vector<int>> result;
	vector<int> path;

public:
	void bt(vector<int> nums, vector<bool> &visited)
	{
		if (path.size() == nums.size())
		{
			result.push_back(path);
			return;
		}
		for (int i = 0; i < nums.size(); i++)
		{
			if (visited[i] == false)
			{
				path.push_back(nums[i]);
				visited[i] = true;
				bt(nums, visited);
				visited[i] = false;
				path.pop_back();
			}
		}
	}
	vector<vector<int>> permute(vector<int> &nums)
	{
		vector<bool> visited(nums.size(), false);
		bt(nums, visited);
		return result;
	}
};
class Solution18
{
public:
	int trap(vector<int> &height)
	{
		int sum = 0;
		for (int i = 1; i < height.size() - 1; i++)
		{
			int left_index = i - 1, left_max = 0;
			while (left_index >= 0)
			{
				left_max = max(left_max, height[left_index]);
				left_index--;
			}
			int right_index = i + 1, right_max = 0;
			while (right_index < height.size())
			{
				right_max = max(right_max, height[right_index]);
				right_index++;
			}
			cout << left_max << " " << right_max << " " << height[i] << endl;
			sum += max(0, min(left_max, right_max) - height[i]);
		}
		return sum;
	}
};
class Solution
{
public:
	void nextPermutation(vector<int> &nums)
	{
		for (int i = nums.size() - 1; i > 0; i--)
		{
			if (nums[i] > nums[i - 1])
			{
				// i-1 i
				for (int j = nums.size() - 1; j >= 0; i--)
				{
					if (nums[j] > nums[i - 1])
					{
						swap(nums[j], nums[i - 1]);
						sort(nums.begin() + i, nums.end());
						return;
					}
				}
			}
		}
		sort(nums.begin(), nums.end());
		return;
	}
};
int main()
{
	stack<string> strs;
	strs.push("aaa");
	strs.top() += "bb";
	cout << strs.top() << endl;
	return 0;
}