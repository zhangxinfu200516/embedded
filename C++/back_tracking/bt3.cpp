#ifdef Q1
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	vector<vector<int>> result;
	vector<int> path;
	int sum = 0;
	void back_tracking(vector<int> &candidates, int start_index, int target)
	{
		if (sum > target)
			return;
		if (sum == target)
		{
			result.push_back(path);
			return;
		}
		for (int i = start_index; i < candidates.size(); i++)
		{
			path.push_back(candidates[i]);
			sum += candidates[i];
			back_tracking(candidates, i, target);
			path.pop_back();
			sum -= candidates[i];
		}
	}
};
int main()
{
	// 处理输入
	int n, target;
	cin >> n >> target;
	vector<int> candidates(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> candidates[i];
	}
	// 回溯
	Solution s;
	s.back_tracking(candidates, 0, target);
	if (s.result.empty())
		cout << " ";
	for (int i = 0; i < s.result.size(); i++)
	{
		for (int j = 0; j < s.result[i].size(); j++)
		{
			cout << s.result[i][j];
			if (j != s.result[i].size() - 1)
				cout << " ";
		}
		cout << endl;
	}
}
#endif
#ifdef Q1
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	vector<vector<string>> result;
	vector<string> path;
	void back_tracking(string &s, int start_index)
	{
		if (start_index == s.size())
		{
			result.push_back(path);
			return;
		}
		for (int i = start_index; i < s.size(); i++)
		{
			string tmp = s.substr(start_index, i - start_index + 1);
			if (!Is_true(tmp))
				continue;
			path.push_back(tmp);
			back_tracking(s, i + 1);
			path.pop_back();
		}
	}

	bool Is_true(string s)
	{
		int n = s.size();
		if (n == 1)
			return true;
		bool result = true;
		for (int i = 0, j = n - 1; i < j; i++, j--)
		{
			if (s[i] == s[j])
				result &= true;
			else
				result &= false;
		}
		return result;
	}
};
int main()
{
	string s;
	cin >> s;
	Solution s_obj;
	// cout << s_obj.Is_true(s);
	s_obj.back_tracking(s, 0);
	if (s_obj.result.empty())
		return -1;
	for (int i = 0; i < s_obj.result.size(); i++)
	{
		for (int j = 0; j < s_obj.result[i].size(); j++)
		{
			cout << s_obj.result[i][j];
			if (j != s_obj.result[i].size() - 1)
				cout << " ";
		}
		cout << endl;
	}
}
#endif
#ifdef Q1
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	vector<string> result;
	string path;
	void back_tracking(int n, int left, int right)
	{
		if (path.size() == 2 * n)
		{
			result.push_back(path);
			return;
		}
		if (left < n)
		{
			path.push_back('(');
			back_tracking(n, left + 1, right);
			path.pop_back();
		}
		if (right < left)
		{
			path.push_back(')');
			back_tracking(n, left, right + 1);
			path.pop_back();
		}
	}
	vector<string> generateParenthesis(int n)
	{
		back_tracking(n, 0, 0);
		return result;
	}
};

int main()
{
}
#endif

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	vector<vector<int>> result;
	vector<int> path;
	void back_tracking(vector<int> &nums, vector<int> &visited)
	{
		if (path.size() == nums.size())
		{
			result.push_back(path);
			return;
		}
		for (int i = 0; i < nums.size(); i++)
		{
			if (visited[i])
				continue;
			visited[i] = true;
			path.push_back(nums[i]);
			back_tracking(nums, visited);
			path.pop_back();
			visited[i] = false;
		}
	}
	vector<vector<int>> permute(vector<int> &nums)
	{
		vector<int> visited(nums.size(), false);
		back_tracking(nums, visited);
		return result;
	}
};

class Solution
{
public:
	string path;
	bool result = false;
	int offest[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	void dfs(vector<vector<char>> &board, string word, vector<vector<bool>> &visited, int x, int y, int index)
	{
		if (visited[x][y] || board[x][y] != word[index])
			return;
		visited[x][y] = true;
		path.push_back(word[index]);
		if (path.size() == word.size())
		{
			result = true;
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			int nextx = x + offest[i][0];
			int nexty = y + offest[i][1];
			if (nextx < 0 || nexty < 0 || nextx >= board.size() || nexty >= board[0].size())
				continue;

			dfs(board, word, visited, nextx, nexty, index + 1);
		}
		path.pop_back();
		visited[x][y] = false;
	}
	void back_tracking(vector<vector<char>> &board, string word, vector<vector<bool>> &visited, int x, int y, int index)
	{
		if (path.size() == word.size())
		{
			result = true;
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			int nextx = x + offest[i][0];
			int nexty = y + offest[i][1];
			if (nextx < 0 || nexty < 0 || nextx >= board.size() || nexty >= board[0].size())
				continue;
			if (board[x][y] == word[index] && !visited[x][y])
			{
				visited[x][y] = true;
				path.push_back(word[index]);
				back_tracking(board, word, visited, nextx, nexty, index + 1);
				path.pop_back();
				visited[x][y] = false;
			}
		}
	}
	bool exist(vector<vector<char>> &board, string word)
	{
		int m = board.size();
		int n = board[0].size();
		vector<vector<bool>> visited(m, vector<bool>(n, false));
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!visited[i][j] && board[i][j] == word[0])
				{
					// dfs
					dfs(board, word, visited, i, j, 0);
				}
			}
		}
		return result;
	}
};
class Solution
{
public:
	vector<vector<int>> result;
	vector<int> path;
	void back_tracking(int n, int k, int start_index)
	{
		if (path.size() == k)
		{
			result.push_back(path);
			return;
		}
		for (int i = start_index; i <= n && (n - start_index + 1 >= k); i++)
		{
			path.push_back(i);
			back_tracking(n, k, i + 1);
			path.pop_back();
		}
	}
	vector<vector<int>> combine(int n, int k)
	{
		back_tracking(n, k, 1);
		return result;
	}
};
class Solution
{
public:
	vector<vector<int>> result;
	vector<int> path;
	int sum = 0;
	void back_tracking(vector<int> &candidates, vector<bool> &visited, int target, int start_index)
	{
		if (sum > target)
			return;
		if (sum == target)
		{
			result.push_back(path);
			return;
		}
		for (int i = start_index; i < candidates.size(); i++)
		{
			if (i > start_index && candidates[i] == candidates[i - 1])
				continue;
			sum += candidates[i];
			path.push_back(candidates[i]);
			back_tracking(candidates, visited, target, i + 1);
			path.pop_back();
			sum -= candidates[i];
		}
	}
	vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
	{
		vector<bool> visited(candidates.size(), false);
		sort(candidates.begin(), candidates.end());
		back_tracking(candidates, visited, target, 0);
		return result;
	}
};
class Solution
{
public:
	vector<vector<string>> result;
	vector<string> path;
	void back_tracking(string s, int start_index)
	{
		if (start_index == s.size())
		{
			result.push_back(path);
			return;
		}
		for (int i = start_index; i < s.size(); i++)
		{
			string tmp = s.substr(start_index, i - start_index + 1);
			if (!isPalindrome(tmp, 0, tmp.size() - 1))
				continue;
			path.push_back(tmp);
			back_tracking(s, i + 1);
			path.pop_back();
		}
	}
	bool isPalindrome(const string &s, int start, int end)
	{
		for (int i = start, j = end; i < j; i++, j--)
		{
			if (s[i] != s[j])
				return false;
		}
		return true;
	}
	vector<vector<string>> partition(string s)
	{
		back_tracking(s, 0);
		return result;
	}
};
class Solution
{
public:
	vector<vector<int>> result;
	vector<int> path;
	void back_tracking(vector<int> &nums, int start_index)
	{
		result.push_back(path);
		if (start_index == nums.size())
			return;
		for (int i = start_index; i < nums.size(); i++)
		{
			path.push_back(nums[i]);
			back_tracking(nums, i + 1);
			path.pop_back();
		}
	}
	vector<vector<int>> subsets(vector<int> &nums)
	{
		back_tracking(nums, 0);
		return result;
	}
};
class Solution
{
public:
	vector<vector<int>> result;
	vector<int> path;
	void back_tracing(vector<int> &nums, int start_index)
	{
		result.push_back(path);
		if (start_index == nums.size())
			return;
		for (int i = start_index; i < nums.size(); i++)
		{
			if (i > start_index && nums[i] == nums[i - 1])
				continue;
			path.push_back(nums[i]);
			back_tracing(nums, i + 1);
			path.pop_back();
		}
	}
	vector<vector<int>> subsetsWithDup(vector<int> &nums)
	{
		// 回溯-子集问题:在路径上收集结果
		sort(nums.begin(), nums.end());
		back_tracing(nums, 0);
		return result;
	}
};
class Solution
{
public:
	vector<vector<int>> result;
	vector<int> path;
	void back_tracking(vector<int> &nums, vector<bool> &used)
	{
		if (path.size() == nums.size())
		{
			result.push_back(path);
			return;
		}

		std::unordered_set<int> set;
		for (int i = 0; i < nums.size(); i++)
		{
			if (used[i])
				continue;
			if(!set.empty() && set.find(nums[i]) != set.end())
				continue;
			set.insert(nums[i]);
			used[i] = true;
			path.push_back(nums[i]);
			back_tracking(nums,used);
			path.pop_back();
			used[i] = false;
		}
	}
	vector<vector<int>> permuteUnique(vector<int> &nums)
	{
		vector<bool> used(nums.size(), false);
		// 全排列：递归不需要start_index，每次遍历所有，此外处理两个方向上的去重
		//sort(nums.begin(), nums.end());
		back_tracking(nums, used);
		return result;
	}
};