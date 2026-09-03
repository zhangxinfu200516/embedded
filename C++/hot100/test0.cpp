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
class Solution19
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
class Solution20
{
public:
	void func(TreeNode *root, int &sum)
	{
		if (root == NULL)
			return;
		func(root->right, sum);
		root->val += sum;
		sum = root->val;
		func(root->left, sum);
	}
	TreeNode *convertBST(TreeNode *root)
	{
		int sum = 0;
		func(root, sum);
		return root;
	}
};
class Solution21
{
public:
	int subarraySum(vector<int> &nums, int k)
	{
		int result;
		for (int i = 0; i < nums.size(); i++)
		{
			int sum = 0;
			for (int j = i; j < nums.size(); j++)
			{
				sum += nums[i];
				if (sum > nums[i])
					break;
				else if (sum == nums[i])
				{
					result++;
					break;
				}
			}
		}
		return result;
	}
};
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int _val) : val(_val), next(NULL) {};
};
class Solution22
{
public:
	vector<int> record;
	void get_arr(ListNode *list)
	{
		ListNode *cur = list;
		while (cur)
		{
			record.push_back(cur->val);
			cur = cur->next;
		}
	}
	ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
	{
		get_arr(list1);
		get_arr(list2);
		sort(record.begin(), record.end());
		if (record.size() == 0)
			return NULL;
		ListNode *head = new ListNode(record[0]);
		ListNode *cur = head;
		for (int i = 1; i < record.size(); i++)
		{
			cur->next = new ListNode(record[i]);
			cur = cur->next;
		}
		return head;
	}
};
class Solution23
{
public:
	bool isValid(string s)
	{
		stack<char> sta;
		for (auto c : s)
		{
			if (c == '(' || c == '[' || c == '{')
				sta.push(c);
			else
			{
				if (sta.size() == 0)
					break;
				auto it = sta.top();
				sta.pop();
				if (it == '(' && c != ')')
					return false;
				else if (it == '[' && c != ']')
					return false;
				else if (it == '{' && c != '}')
					return false;
			}
		}
		return true;
	}
};
class Solution24
{
public:
	int lengthOfLongestSubstring(string s)
	{
		int result = 0;
		for (int i = 0; i < s.size(); i++)
		{
			set<char> st;
			for (int j = i; j < s.size(); j++)
			{
				if (st.find(s[j]) != st.end())
				{
					result = max(result, j - i);
					break;
				}
				st.insert(s[j]);
			}
		}
		return result;
	}
};
class Solution25
{
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
	{
		int val1 = 0, val2 = 0;
		ListNode *cur = l1;
		int k = 1;
		while (cur)
		{
			val1 += cur->val * k;
			k *= 10;
			cur = cur->next;
		}
		cur = l2;
		k = 1;
		while (cur)
		{
			val2 += cur->val * k;
			k *= 10;
			cur = cur->next;
		}
		int val3 = val1 + val2;
		ListNode *head = new ListNode(val3 % 10);
		cur = head;
		val3 = val3 / 10;
		while (val3)
		{
			cur->next = new ListNode(val3 % 10);
			val3 /= 10;
			cur = cur->next;
		}
		return head;
	}
};
class Solution26
{
private:
	int offset[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
	bool result = false;

public:
	void dfs(vector<vector<char>> &board, vector<vector<bool>> &visited, int x, int y, string word, int index)
	{
		if (index == word.size() - 1)
		{
			result = true;
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			int nextx = x + offset[i][0];
			int nexty = y + offset[i][1];
			if (nextx < 0 || nextx >= board.size() || nexty < 0 || nexty >= board[0].size())
				continue;
			if (board[nextx][nexty] == word[index + 1] && visited[nextx][nexty] == false)
			{
				visited[nextx][nexty] = true;
				dfs(board, visited, nextx, nexty, word, index + 1);
				visited[nextx][nexty] = false;
			}
		}
	}
	bool exist(vector<vector<char>> &board, string word)
	{
		vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				if (board[i][j] == word[0])
				{
					visited[i][j] = true;
					dfs(board, visited, i, j, word, 0);
					visited[i][j] = false;
				}
			}
		}
		return false;
	}
};
class Solution27
{
private:
	unordered_set<int> st;

public:
	void get_set(TreeNode *root)
	{
		if (root == NULL)
			return;
		st.insert(root->val);
		get_set(root->left);
		get_set(root->right);
	}
	void flatten(TreeNode *root)
	{
		if (root == NULL)
			return;
		get_set(root);
		vector<int> nums(st.begin(), st.end());
		sort(nums.begin(), nums.end());
		for (auto num : nums)
			cout << num << " ";
		TreeNode *cur = root, *pre = NULL; // 需要pre存储上一个节点：链接right，不然只是创建新节点是不会链接在root中的
		for (int i = 0; i < nums.size(); i++)
		{
			if (cur)
				cur->val = nums[i];
			else
			{
				cur = new TreeNode(nums[i]);
				pre->right = cur;
			}
			cur->left = NULL;
			pre = cur;
			cur = cur->right;
		}
	}
};
class Solution28
{
public:
	int leastInterval(vector<char> &tasks, int n)
	{
		vector<int> nums(26, 0);
		for (auto task : tasks)
		{
			nums[task - 'A']++;
		}
		int N = 0, count = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] > N)
			{
				N = nums[i];
				count = 1;
			}
			if (nums[i] == N)
				count++;
		}
		int val1 = (N - 1) * (n + 1) + count;
		int val2 = tasks.size();
		return max(val1, val2);
	}
};
class Solution29
{
public:
	TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
	{
		if (root1 == NULL && root2 == NULL)
			return NULL;
		if (root1 != NULL && root2 != NULL)
			root1->val += root2->val;
		else if (root1 == NULL && root2 != NULL)
			return root2;
		else if (root1 != NULL && root2 == NULL)
			return root1;
		root1->left = mergeTrees(root1->left, root2->left);
		root1->right = mergeTrees(root1->right, root2->right);
		return root1;
	}
};
class Solution30
{
public:
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
	{
		if (preorder.size() == 0)
			return NULL;
		int root_val = preorder[0];
		TreeNode *root = new TreeNode(root_val);
		int index = 0;
		for (int i = 0; i < preorder.size(); i++)
		{
			if (preorder[i] == root_val)
			{
				index = i;
				break;
			}
		}
		vector<int> pre_left(preorder.begin() + 1, preorder.begin() + 1 + index);
		vector<int> pre_right(preorder.begin() + 1 + index, preorder.end());
		vector<int> ino_left(inorder.begin(), inorder.begin() + index);
		vector<int> ino_right(inorder.begin() + index + 1, inorder.end());
		root->left = buildTree(pre_left, ino_left);
		root->right = buildTree(pre_right, ino_right);
		return root;
	}
};
class Solution31
{
public:
	int maxDepth(TreeNode *root)
	{
		if (root == NULL)
			return NULL;
		int l = maxDepth(root->left);
		int r = maxDepth(root->right);
		return max(l, r) + 1;
	}
};
class Solution32
{
private:
	vector<vector<int>> result;

public:
	vector<vector<int>> levelOrder(TreeNode *root)
	{
		if (root == NULL)
			return {};
		queue<TreeNode *> que;
		que.push(root);
		while (!que.empty())
		{
			int n = que.size();
			vector<int> path;
			for (int i = 0; i < n; i++)
			{
				auto it = que.front();
				que.pop();
				path.push_back(it->val);
				if (it->left)
					que.push(it->left);
				if (it->right)
					que.push(it->right);
			}
			result.push_back(path);
		}
		return result;
	}
};
class Solution33
{
public:
	bool check(TreeNode *left, TreeNode *right)
	{
		if (left == NULL && right == NULL)
			return true;
		if (left != NULL && right == NULL)
			return false;
		if (left == NULL && right != NULL)
			return false;

		if (left->val != right->val)
			return false;
		if (!check(left->left, right->right))
			return false;
		if (!check(left->right, right->left))
			return false;
		return true;
	}
	bool isSymmetric(TreeNode *root)
	{
		return check(root->left, root->right);
	}
};
class Solution34
{
public:
	vector<int> record;
	void get_vector(TreeNode *root)
	{
		if (root == NULL)
			return;
		get_vector(root->left);
		record.push_back(root->val);
		get_vector(root->right);
	}
	bool isValidBST(TreeNode *root)
	{
		get_vector(root);
		if (record.size() == 0)
			return true;
		for (auto num : record)
			cout << num << " ";
		for (int i = 0; i < record.size() - 1; i++)
		{
			if (record[i] > record[i + 1])
				return false;
		}
		return true;
	}
};
class Solution35
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
class Solution36
{
private:
	vector<int> result;

public:
	void get_result(TreeNode *root)
	{
		if (root == NULL)
			return;
		get_result(root->left);
		result.push_back(root->val);
		get_result(root->right);
	}
	vector<int> inorderTraversal(TreeNode *root)
	{
		get_result(root);
		return result;
	}
};
class Solution37
{
public:
	int get_result(vector<vector<int>> &matrix, int i)
	{
		int result = 0;
		for (int j = 0; j < matrix[0].size(); j++)
		{
			int left = j - 1, right = j + 1;
			while (left >= 0)
			{
				if (matrix[i][left] < matrix[i][j])
					break;
				left--;
			}
			while (right < matrix[0].size())
			{
				if (matrix[i][right] < matrix[i][j])
					break;
				right++;
			}
			int val = (right - left - 1) * matrix[i][j];
			result = max(val, result);
		}
		return result;
	}
	int maximalRectangle(vector<vector<char>> &matrix)
	{
		vector<vector<int>> record(matrix.size(), vector<int>(matrix[0].size(), 0));
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[0].size(); j++)
			{
				if (matrix[i][j] == '1')
					record[i][j] = 1;
				else
					record[i][j] = 0;

				if (i > 0)
				{
					if (record[i][j] != 0)
						record[i][j] += record[i - 1][j];
					else
						record[i][j] = 0;
				}
			}
		}
		int result = 0;
		for (int i = 0; i < record.size(); i++)
		{
			result = max(get_result(record, i), result);
		}
		return result;
	}
};
class Solution38
{
public:
	int largestRectangleArea(vector<int> &heights)
	{
		int result = 0;
		for (int j = 0; j < heights.size(); j++)
		{
			int left = j - 1, right = j + 1;
			while (left >= 0)
			{
				if (heights[left] < heights[j])
					break;
				left--;
			}
			while (right < heights.size())
			{
				if (heights[right] < heights[j])
					break;
				right++;
			}
			int val = (right - left - 1) * heights[j];
			result = max(val, result);
		}
		return result;
	}
};
class Solution39
{
public:
	vector<int> twoSum(vector<int> &nums, int target)
	{
		for (int i = 0; i < nums.size() - 1; i++)
		{
			for (int j = i + 1; j < nums.size(); j++)
			{
				if (nums[i] + nums[j] == target)
					return {i, j};
			}
		}
		return {-1, -1};
	}
};
class Solution40
{
private:
	vector<vector<int>> result;
	vector<int> path;

public:
	void dfs(vector<int> &nums, int start_index)
	{
		result.push_back(path);
		for (int i = start_index; i < nums.size(); i++)
		{
			path.push_back(nums[i]);
			dfs(nums, i + 1);
			path.pop_back();
		}
	}
	vector<vector<int>> subsets(vector<int> &nums)
	{
		dfs(nums, 0);
		return result;
	}
};
class Solution41
{
public:
	void sortColors(vector<int> &nums)
	{
		map<int, int> mp;
		for (auto num : nums)
			mp[num]++;
		vector<int> result;
		for (int i = 0; i <= 2; i++)
		{
			while (mp[i]--)
			{
				result.push_back(i);
			}
		}
		for (int i = 0; i < nums.size(); i++)
		{
			nums[i] = result[i];
		}
	}
};
class Solution42
{
public:
	int minDistance(string word1, string word2)
	{
		int m = word1.size(), n = word2.size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (int i = 0; i <= m; i++)
			dp[i][0] = i;
		for (int j = 0; j <= n; j++)
			dp[0][j] = j;
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (word1[i - 1] == word2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else
					dp[i][j] = min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]}) + 1;
			}
		}
		for (int i = 0; i <= m; i++)
		{
			for (int j = 0; j <= n; j++)
				cout << dp[i][j] << " ";
			cout << endl;
		}
		return dp[m][n];
	}
};
class Solution43
{
public:
	int climbStairs(int n)
	{
		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		dp[1] = 1;
		for (int i = 2; i <= n; i++)
			dp[i] = dp[i - 1] + dp[i - 2];
		return dp[n];
	}
};
class Solution44
{
public:
	int findUnsortedSubarray(vector<int> &nums)
	{
		int i = 0, j = nums.size() - 1;
		while (i < nums.size() - 1)
		{
			if (nums[i] > nums[i + 1])
				break;
			i++;
		}
		while (j > 0)
		{
			if (nums[j] < nums[j - 1])
				break;
			j--;
		}
		if (j <= i)
			return 0;
		return j - i + 1;
	}
};
class Solution45
{
public:
	int findUnsortedSubarray(vector<int> &nums)
	{
		int num_max = nums[0], end = -1;
		for(int i = 0; i < nums.size(); i++)
		{
			if(nums[i] >= num_max)
				num_max = nums[i];
			else
				end = i;
		}	
		int num_min = nums[nums.size() - 1], begin = 0;
		for(int j = nums.size() - 1; j >= 0; j--)
		{
			if(nums[j] <= num_min)
				num_min = nums[j];
			else
				begin = j;
		}
		return end - begin + 1;
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