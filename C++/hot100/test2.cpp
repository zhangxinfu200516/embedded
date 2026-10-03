#include <bits\stdc++.h>
using namespace std;

class Solution01
{
public:
	bool isValid(string s)
	{
		if (s.size() % 2)
			return false;
		stack<char> sta;
		for (int i = 0; i < s.size(); i++)
		{
			char c = s[i];
			if (c == '(' || c == '{' || c == '[')
				sta.push(c);
			else
			{
				if (sta.size() == 0)
					return false;
				char it = sta.top();
				sta.pop();
				if ((it == '(' && c != ')') || (it == '{' && c != '}') ||
					(it == '[' && c != ']'))
					return false;
			}
		}
		if (sta.size() > 0)
			return false;
		return true;
	}
};
class MinStack
{
private:
	vector<int> nums;
	stack<int> small_sta;

public:
	MinStack()
	{
	}

	void push(int value)
	{
		nums.push_back(value);
		if (small_sta.empty() || value <= small_sta.top())
			small_sta.push(value);
	}

	void pop()
	{
		if (nums.back() == small_sta.top())
			small_sta.pop();
		nums.pop_back();
	}

	int top()
	{
		return nums[nums.size() - 1];
	}

	int getMin()
	{
		return small_sta.top();
	}
};
class Solution02
{
public:
	string decodeString(string s)
	{
		stack<int> sta_i;
		stack<string> sta_s;
		int count = 0;
		string cur = "";
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] - '0' >= 0 && s[i] - '0' <= 9)
				count = s[i] - '0' + 10 * count;
			else if (s[i] - 'a' >= 0 && s[i] - 'z' <= 0)
				cur += s[i];
			else if (s[i] == '[')
			{
				sta_i.push(count);
				sta_s.push(cur);
				count = 0;
				cur = "";
			}
			else
			{
				int val = sta_i.top();
				sta_i.pop();
				for (int i = 0; i < val; i++)
					sta_s.top() += cur;
				cur = sta_s.top();
				sta_s.pop();
			}
		}
		return cur;
	}
};
class Solution03
{
public:
	vector<int> dailyTemperatures(vector<int> &temperatures)
	{
		int n = temperatures.size();
		vector<int> result(n, 0);
		stack<int> sta_index;
		for (int i = 0; i < n; i++)
		{
			while (!sta_index.empty() && temperatures[i] > temperatures[sta_index.top()])
			{
				result[sta_index.top()] = i - sta_index.top();
				sta_index.pop();
			}
			sta_index.push(i);
		}
		return result;
	}
};
class Solution04
{
public:
	int findKthLargest(vector<int> &nums, int k)
	{
		sort(nums.begin(), nums.end());
		return nums[nums.size() - k];
	}
};

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution05
{
public:
	TreeNode *invertTree(TreeNode *root)
	{
		if (root == NULL)
			return NULL;
		swap(root->left, root->right);
		invertTree(root->left);
		invertTree(root->right);
		return root;
	}
};

class Solution06
{
public:
	TreeNode *dfs(vector<int> nums, int left, int right)
	{
		if (left > right)
			return NULL;
		int mid = (left + right) / 2;
		TreeNode *root = new TreeNode(nums[mid]);
		root->left = dfs(nums, left, mid - 1);
		root->right = dfs(nums, mid + 1, right);
		return root;
	}
	TreeNode *sortedArrayToBST(vector<int> &nums)
	{
		return dfs(nums, 0, nums.size() - 1);
	}
};
class Solution07
{
private:
	int result = -1;
	;

public:
	void getSmall(TreeNode *root, int &k)
	{
		if (root == NULL)
			return;
		getSmall(root->left, k);
		k--;
		if (k == 0)
			result = root->val;
		else if (k < 0)
			return;
		getSmall(root->right, k);
	}
	int kthSmallest(TreeNode *root, int k)
	{
		getSmall(root, k);
		return result;
	}
};
class Solution08
{
public:
	vector<int> getNums(TreeNode *root)
	{
		if (!root)
			return {};
		vector<int> nums;
		queue<TreeNode *> que;
		que.push(root);
		while (!que.empty())
		{
			int size = que.size();
			for (int i = 0; i < size; i++)
			{
				auto it = que.front();
				que.pop();
				if (i == size - 1)
					nums.push_back(it->val);
				if (it->left)
					que.push(it->left);
				if (it->right)
					que.push(it->right);
			}
		}
		return nums;
	}
	vector<int> rightSideView(TreeNode *root)
	{
		vector<int> result = getNums(root);
		return result;
	}
};