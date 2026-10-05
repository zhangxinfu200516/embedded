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
class Solution09
{
public:
	int orangesRotting(vector<vector<int>> &grid)
	{
		int m = grid.size(), n = grid[0].size();
		queue<pair<int, int>> que;
		int normal_count = 0, result = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (grid[i][j] == 1)
					normal_count++;
				else if (grid[i][j] == 2)
					que.push({i, j});
			}
		}
		while (normal_count > 0 && !que.empty())
		{
			result++;
			int size = que.size();
			for (int i = 0; i < size; i++)
			{
				auto it = que.front();
				que.pop();
				int x = it.first, y = it.second;
				if (x - 1 >= 0 && grid[x - 1][y] == 1)
				{
					grid[x - 1][y] = 2;
					que.push({x - 1, y});
					normal_count--;
				}
				if (x + 1 < m && grid[x + 1][y] == 1)
				{
					grid[x + 1][y] = 2;
					que.push({x + 1, y});
					normal_count--;
				}
				if (y - 1 >= 0 && grid[x][y - 1] == 1)
				{
					grid[x][y - 1] = 2;
					que.push({x, y - 1});
					normal_count--;
				}
				if (y + 1 < n && grid[x][y + 1] == 1)
				{
					grid[x][y + 1] = 2;
					que.push({x, y + 1});
					normal_count--;
				}
				cout << normal_count << " ";
			}
		}
		cout << endl
			 << normal_count;
		if (normal_count > 0)
			return -1;
		else
			return result;
	}
};
class Solution10
{
public:
	bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
	{
		unordered_map<int, int> umap;
		for (int i = 0; i < prerequisites.size(); i++)
		{
			umap[prerequisites[i][0]] = prerequisites[i][1];
		}
		for (int i = 0; i < numCourses; i++)
		{
			int val = 0;
			if (umap.find(i) != umap.end())
				val = umap[i];
			else
				continue;
			while (umap.find(val) != umap.end())
			{
				if (umap[val] == i)
					return false;
				val = umap[val];
			}
		}
		return true;
	}
};
class Solution11
{
public:
	bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
	{
		vector<int> inputDeg(numCourses, 0);
		unordered_map<int, vector<int>> umap;
		for (int i = 0; i < prerequisites.size(); i++)
		{
			inputDeg[prerequisites[i][0]]++;
			umap[prerequisites[i][1]].push_back(prerequisites[i][0]);
		}
		queue<int> que;
		for (int i = 0; i < numCourses; i++)
		{
			if (inputDeg[i] == 0)
				que.push(i);
		}
		int count = 0;
		while (!que.empty())
		{
			auto it = que.front();
			que.pop();
			count++;
			if (umap.find(it) == umap.end())
				continue;
			for (int i = 0; i < umap[it].size(); i++)
			{
				inputDeg[umap[it][i]]--;
				if (inputDeg[umap[it][i]] == 0)
					que.push(umap[it][i]);
			}
		}
		return count == numCourses;
	}
};
class Solution12
{
public:
	TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
	{
		if (root == NULL || root == p || root == q)
			return root;
		TreeNode *left = lowestCommonAncestor(root->left, p, q);
		TreeNode *right = lowestCommonAncestor(root->right, p, q);
		if (left && right)
			return root;
		else if (left && !right)
			return left;
		else if (!left && right)
			return right;
		else
			return NULL;
	}
};
class Solution12
{
public:
	int searchInsert(vector<int> &nums, int target)】
	{
		int left = 0, right = nums.size() - 1;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (nums[mid] < target)
				left = mid + 1;
			else
				right = mid - 1;
		}
		return left;
	}
};
class Solution13
{
private:
	vector<vector<string>> result;
	vector<string> path;

public:
	bool isTrue(string s)
	{
		for (int i = 0, j = s.size() - 1; i < j; i++, j--)
		{
			if (s[i] != s[j])
				return false;
		}
		return true;
	}
	void bt(string s, int start_index)
	{
		if (s.size() == start_index)
		{
			result.push_back(path);
			return;
		}
		for (int i = start_index; i < s.size(); i++)
		{
			string tmp = s.substr(start_index, i - start_index + 1);
			if (!isTrue(tmp))
				continue;
			path.push_back(tmp);
			bt(s, i + 1);
			path.pop_back();
		}
	}
	vector<vector<string>> partition(string s)
	{
		bt(s, 0);
		return result;
	}
};
class Solution14
{
public:
	bool searchMatrix(vector<vector<int>> &matrix, int target)
	{
		int m = matrix.size(), n = matrix[0].size();
		int l = 0, r = m * n - 1;
		while (l <= r)
		{
			int mid = (l + r) / 2, val = matrix[mid / n][mid % n];
			if (val < target)
				l = mid + 1;
			else if (val > target)
				r = mid - 1;
			else
				return true;
		}
		return false;
	}
};
class Solution15
{
public:
	int search(vector<int> &nums, int target)
	{
		int left = 0, right = nums.size() - 1;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (nums[mid] == target)
				return mid;
			if (nums[mid] >= nums[left])
			{
				if (nums[left] <= target && nums[mid] > target)
					right = mid - 1;
				else
					left = mid + 1;
			}
			else
			{
				if (nums[mid] < target && nums[right] >= target)
					left = mid + 1;
				else
					right = mid - 1;
			}
		}
		return -1;
	}
};