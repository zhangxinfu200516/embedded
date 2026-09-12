#include <bits\stdc++.h>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int _val) : val(_val), next(NULL) {};
};
class Solution01
{
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
		map<ListNode *, int> mp;
		ListNode *cur = headA;
		while (cur)
		{
			mp[cur]++;
			cur = cur->next;
		}
		cur = headB;
		while (cur)
		{
			mp[cur]++;
			if (mp[cur] > 1)
				return cur;
			cur = cur->next;
		}
		return NULL;
	}
};
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int _val) : val(_val), left(NULL), right(NULL) {};
};
class Solution02
{
public:
	TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
	{
		if (root == NULL || root == q || root == p)
			return root;
		TreeNode *left = lowestCommonAncestor(root->left, p, q);
		TreeNode *right = lowestCommonAncestor(root->right, p, q);
		if (left != NULL && right != NULL)
			return root;
		else if (left == NULL && right != NULL)
			return right;
		else if (left != NULL && right == NULL)
			return left;
		return NULL;
	}
};
class Solution03
{
public:
	bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
	{
		map<int, int> mp;
		for (int i = 0; i < prerequisites.size(); i++)
			mp[prerequisites[i][0]] = prerequisites[i][1];
		for (int i = 0; i < prerequisites.size(); i++)
		{
			int target = prerequisites[i][1];
			while (mp.find(target) != mp.end())
			{
				if (mp[target] == prerequisites[i][0])
					return false;
				target = mp[target];
			}
		}
		return true;
	}
};
class Solution04
{
public:
	ListNode *reverseList(ListNode *head)
	{
		ListNode *cur = head, *pre = NULL, *next = NULL;
		while (cur)
		{
			next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		return pre;
	}
};
class Solution05
{
public:
	ListNode *sortList(ListNode *head)
	{
		vector<int> record;
		ListNode *cur = head;
		while (cur)
		{
			record.push_back(cur->val);
			cur = cur->next;
		}
		if (record.size() == 0)
			return NULL;
		sort(record.begin(), record.end());
		ListNode *new_head = new ListNode(record[0]);
		cur = new_head;
		for (int i = 1; i < record.size(); i++)
		{
			cur->next = new ListNode(record[i]);
			cur = cur->next;
		}
		return new_head;
	}
};
class LRUCache
{
private:
	int capacity_size;
	map<int, int> mp;
	list<pair<int, int>> ls;

public:
	LRUCache(int capacity)
	{
		capacity_size = capacity;
	}

	int get(int key)
	{
		if (mp.find(key) != mp.end())
		{
			auto it = find(ls.begin(), ls.end(), pair(key, mp[key]));
			ls.splice(ls.begin(), ls, it);
			return mp[key];
		}
		return -1;
	}

	void put(int key, int value)
	{
		if (mp.find(key) != mp.end())
		{
			mp[key] = value;
			auto it = find(ls.begin(), ls.end(), pair(key, mp[key]));
			ls.splice(ls.begin(), ls, it);
		}
		mp[key] = value;
		ls.push_front(pair(key, mp[key]));

		if (mp.size() > capacity_size)
		{
			auto it = ls.back();
			mp.erase(it.first);
			ls.pop_back();
		}
	}
};
class Solution06
{
public:
	ListNode *detectCycle(ListNode *head)
	{
		map<ListNode *, int> mp;
		ListNode *cur = head;
		while (cur)
		{
			mp[cur]++;
			if (mp[cur] > 1)
				return cur;
			cur = cur->next;
		}
		return NULL;
	}
};
class Solution07
{
public:
	bool hasCycle(ListNode *head)
	{
		map<ListNode *, int> mp;
		ListNode *cur = head;
		while (cur)
		{
			mp[cur]++;
			if (mp[cur] > 1)
				return true;
			cur = cur->next;
		}
		return false;
	}
};
class Solution08
{
private:
	vector<string> st;
	inline bool is_true(string s)
	{
		for (int i = 0, j = s.size() - 1; i < j; i++, j--)
		{
			if (s[i] != s[j])
				return false;
		}
		return true;
	}

public:
	void bt(string s, int start_index)
	{
		if (start_index == s.size())
			return;
		for (int i = start_index; i < s.size(); i++)
		{
			string temp = s.substr(start_index, i - start_index + 1);
			if (is_true(temp))
				st.push_back(temp);
			bt(s, i + 1);
		}
	}
	int countSubstrings(string s)
	{
		bt(s, 0);
		for (string it : st)
			cout << it << " ";
		return st.size();
	}
};
class Solution09
{
private:
	set<int> st;

public:
	int longestConsecutive(vector<int> &nums)
	{
		for (auto num : nums)
			st.insert(num);
		int result = 1;
		for (int i = 0; i < nums.size(); i++)
		{
			if (st.find(nums[i] - 1) == st.end())
			{
				int count = 0;
				int target = nums[i];
				while (st.find(target + 1) != st.end())
				{
					count++;
					target++;
				}
				result = max(result, count);
			}
		}
		return result;
	}
};
class Solution10
{
public:
	int coinChange(vector<int> &coins, int amount)
	{
		vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, INT_MAX));
		for (int i = 0; i < coins.size(); i++)
			dp[i][0] = 0;
		for (int j = coins[0]; j <= amount; j++)
		{
			if (j % coins[0] == 0)
				dp[0][j] = j / coins[0];
		}
		for (int i = 1; i < coins.size(); i++)
		{
			for (int j = 1; j <= amount; j++)
			{
				if (j >= coins[i] && dp[i][j - coins[i]] != INT_MAX)
					dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i]] + 1);
				else
					dp[i][j] = dp[i - 1][j];
			}
		}
		if (dp[coins.size() - 1][amount] == INT_MAX)
			return -1;
		else
			return dp[coins.size() - 1][amount];
	}
};
class Solution11
{
public:
	int findTargetSumWays(vector<int> &nums, int target)
	{
		int sum = 0;
		for (auto num : nums)
			sum += num;
		if ((sum + target) % 2)
			return 0;
		int n = (sum + target) / 2;
		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = n; j >= nums[i]; j--)
				dp[j] = dp[j] + dp[j - nums[i]];
			for (int j = 0; j <= n; j++)
				cout << dp[j] << " ";
			cout << endl;
		}
		return dp[n];
	}
};
class Solution12
{
public:
	bool is_true(string s1, string s2)
	{
		if (s1.size() != s2.size())
			return false;
		map<char, int> mp;
		for (int i = 0; i < s1.size(); i++)
		{
			mp[s1[i]]++;
			mp[s2[i]]--;
		}
		for (auto &it : mp)
		{
			if (it.second != 0)
				return false;
		}
		return true;
	}
	vector<int> findAnagrams(string s, string p)
	{
		vector<int> result;
		for (int i = 0; i < s.size(); i++)
		{
			for (int j = i; j < s.size(); j++)
			{
				string temp = s.substr(i, j - i + 1);
				if (is_true(temp, p))
					result.push_back(i);
			}
		}
		return result;
	}
};
class Solution13
{
public:
	void dfs(TreeNode *root, int &sum, int targetSum, int &result)
	{
		if (root == NULL)
			return;
		sum += root->val;
		if (sum == targetSum)
			result++;
		dfs(root->left, sum, targetSum, result);
		dfs(root->right, sum, targetSum, result);
		sum -= root->val;
	}
	int pathSum(TreeNode *root, int targetSum)
	{
		int sum1 = 0, sum2 = 0;
		int result1 = 0, result2 = 0;
		dfs(root->left, sum1, targetSum, result1);
		dfs(root->right, sum2, targetSum, result2);
		return result1 + result2;
	}
};
class Solution14
{
private:
	unordered_map<int, int> umap;
	int result;

public:
	void dfs(TreeNode *root, int sum, int targetSum)
	{
		if (root == NULL)
			return;
		sum += root->val;
		if (umap[sum - targetSum] != 0)
			result += umap[sum - targetSum];
		umap[sum]++;
		dfs(root->left, sum, targetSum);
		dfs(root->right, sum, targetSum);
		umap[sum]--;
	}
	int pathSum(TreeNode *root, int targetSum)
	{
		umap[0] = 1;
		int sum = 0;
		dfs(root, sum, targetSum);
		return result;
	}
};
class Solution15
{

public:
	static bool func(const vector<int> &a, const vector<int> &b)
	{
		if (a[0] == b[0])
			return a[1] < b[1];
		return a[0] > b[0];
	}
	vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
	{
		sort(people.begin(), people.end(), func);
		vector<vector<int>> result;
		for (int i = 0; i < people.size(); i++)
		{
			result.insert(result.begin() + people[i][1], people[i]);
		}
		return result;
	}
};
class Solution
{
public:
	vector<int> topKFrequent(vector<int> &nums, int k)
	{
		map<int, int> mp;
		for (int num : nums)
			mp[num]++;
		vector<vector<int>> record;
		for (auto &it : mp)
		{
			record.push_back({it.second, it.first});
		}
		sort(record.begin(), record.end());
		vector<int> result;
		for (int i = 0; i < k; i++)
			result.push_back(record[i][1]);
		return result;
	}
};
class Solution16
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
			if (s[i] - '0' > 0 && s[i] - '0' <= 9)
				count = s[i] - '0' + count * 10;
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
class Solution17
{
public:
	vector<int> topKFrequent(vector<int> &nums, int k)
	{
		map<int, int> mp;
		for (int num : nums)
			mp[num]++;
		vector<vector<int>> record;
		for (auto &it : mp)
		{
			record.push_back({it.second, it.first});
		}
		sort(record.begin(), record.end());
		for (int i = 0; i < record.size(); i++)
		{
			cout << record[i][0] << " " << record[i][1] << endl;
		}
		vector<int> result;
		for (int i = record.size() - k; i < record.size(); i++)
			result.push_back(record[i][1]);
		return result;
	}
};
class Solution18
{
public:
	int rob(TreeNode *root)
	{
		queue<TreeNode *> que;
		que.push(root);
		int count = 0, sum1 = 0, sum2 = 0;
		while (!que.empty())
		{
			int size = que.size();
			for (int i = 0; i < size; i++)
			{
				auto it = que.front();
				que.pop();
				if (count % 2)
					sum1 += it->val;
				else
					sum2 += it->val;
				if (it->left)
					que.push(it->left);
				if (it->right)
					que.push(it->right);
			}
			count++;
		}
		return max(sum1, sum2);
	}
};
class Solution19
{
public:
	pair<int, int> dfs(TreeNode *root)
	{
		if (root == NULL)
			return {0, 0};
		auto left = dfs(root->left);
		auto right = dfs(root->right);
		int cur_use = root->val + left.second + right.second;
		int cur_notuse = max(left.first, left.second) + max(right.first, right.second);
		return {cur_use, cur_notuse};
	}
	int rob(TreeNode *root)
	{
		auto it = dfs(root);
		return max(it.first, it.second);
	}
};
int main()
{
}