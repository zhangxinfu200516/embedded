#include <bits/stdc++.h>
using namespace std;
class Solution1
{
public:
	vector<vector<int>> result;
	vector<int> path;
	void backtracking(int n, int k, int startIndex)
	{
		if (path.size() == k)
		{
			result.push_back(path);
			return;
		}

		for (int i = startIndex; i <= n; i++)
		{
			path.push_back(i);
			backtracking(n, k, i + 1);
			path.pop_back();
		}
	}
	vector<vector<int>> combine(int n, int k)
	{
		backtracking(n, k, 1);
		return result;
	}
};
/*
回溯模板
void backtracking(参数)
{
	if（终止条件）
		return;
	for(选择：本层集合中元素)
	{
		处理节点；
		backtracking(路径，选择列表)；
		回溯，撤销处理结果；
	}
}
*/
class Solution2
{
public:
	vector<vector<int>> result;
	vector<int> path;
	int sum;
	void backtracking(int k, int n, int startIndex, int sum)
	{
		if (path.size() == k)
		{
			if (sum == n)
				result.push_back(path);
			return;
		}

		for (int i = startIndex; i <= 9 - (k - path.size()) + 1; i++)
		{
			sum += i;
			path.push_back(i);
			backtracking(k, n, i + 1, sum);
			path.pop_back();
			sum -= i;
		}
	}
	vector<vector<int>> combinationSum3(int k, int n)
	{
		backtracking(k, n, 1, sum);
		return result;
	}
};
const string letterMap[10] = {
	"",		// 0
	"",		// 1
	"abc",	// 2
	"def",	// 3
	"ghi",	// 4
	"jkl",	// 5
	"mno",	// 6
	"pqrs", // 7
	"tuv",	// 8
	"wxyz", // 9
};
class Solution3
{
public:
	/*
	从index=0开始遍历 -》直到 digits.size()结束 -》 （收获结果）返回
	*/
	vector<string> result;
	string path;
	void backtracking(string digits, int index)
	{
		if (index == digits.size())
		{
			result.push_back(path);
			return;
		}
		// 取出字符串中数字对应的字符串、依次遍历、递归时调整索引值
		string digit = letterMap[digits[index] - '0'];
		for (char c : digit)
		{
			path.push_back(c);
			backtracking(digits, index + 1);
			path.pop_back();
		}
	}
	vector<string> letterCombinations(string digits)
	{
		backtracking(digits, 0);
		return result;
	}
};
// // 完全背包法
// class Solution
// {
// public:
// 	vector<vector<int>> combinationSum(vector<int> &candidates, int target)
// 	{
// 		int n = candidates.size();
// 		vector<int> dp(n+1,0);
// 		for()
// 	}
// };
// 回溯法 - 求组合数 - 给出的日历组合没有重复元素
class Solution4
{
public:
	vector<vector<int>> result;
	vector<int> path;
	int sum = 0;
	void back_tracking(vector<int> &candidates, int target, int index)
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

		for (int i = index; i < candidates.size(); i++)
		{
			sum += candidates[i];
			path.push_back(candidates[i]);
			back_tracking(candidates, target, i);
			sum -= candidates[i];
			path.pop_back();
		}
	}
	vector<vector<int>> combinationSum(vector<int> &candidates, int target)
	{
		back_tracking(candidates, target, 0);
		return result;
	}
};
// 回溯法 - 求组合数 - 给出的日历组合有重复元素、需要去重（树枝去重+树层去重）
class Solution5
{
public:
	vector<vector<int>> result;
	vector<int> path;
	int sum = 0;
	void back_tracking(vector<int> &candidates, int target, int index)
	{
		if (sum > target)
		{
			return;
		}
		if (sum == target)
		{
			result.push_back(path);
		}

		for (int i = index; i < candidates.size() && sum + candidates[i] <= target; i++) // 剪枝
		{
			if (i > index && candidates[i] == candidates[i - 1])
				continue;
			sum += candidates[i];
			path.push_back(candidates[i]);
			back_tracking(candidates, target, i + 1);
			sum -= candidates[i];
			path.pop_back();
		}
	}
	vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
	{
		sort(candidates.begin(), candidates.end());
		back_tracking(candidates, target, 0);
		return result;
	}
};
// 切割字符串 满足回文条件
class Solution6
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
			// 判断是否满足回文条件 不满足则continue 、 满足则push_back;
			if (isPalindrome(s, start_index, i))
				path.push_back(s.substr(start_index, i - start_index + 1));
			else
				continue;
			back_tracking(s, i + 1);
			path.pop_back();
		}
	}
	bool isPalindrome(const string &s, int start, int end)
	{
		for (int i = start, j = end; i < j; i++, j--)
		{
			if (s[i] != s[j])
			{
				return false;
			}
		}
		return true;
	}
	vector<vector<string>> partition(string s)
	{
		back_tracking(s, 0);
		return result;
	}
};
//复原IP地址
class Solution
{
public:
	vector<string> result;
	string path;
	void back_tracking(string s, int start_index, int k)
	{
		// 切割四次 且 最后一次为s串尾
		if (k == 4 && start_index == s.size())
		{
			result.push_back(path);
			return;
		}
		// 切割超过四次
		if (k > 4)
		{
			return;
		}

		for (int i = start_index; i < s.size(); i++)
		{
			// 关键：每个段最多 3 位，超过则 break
			if (i - start_index + 1 > 3)
				break;
			// 满足条件 Push_back 不满足则continue
			if (i - start_index > 0 && s[start_index] == '0')
				continue;
			string seg = s.substr(start_index, i - start_index + 1);
			int count = std::stoi(seg);
			if (count < 0 || count > 255)
				continue;
			int len = path.size();
			path.append(seg);
			if (k < 3)
				path.push_back('.');
			k++;
			back_tracking(s, i + 1, k);
			path.erase(path.begin() + len, path.end()); // 处理回溯
			k--;
		}
	}
	vector<string> restoreIpAddresses(string s)
	{
		back_tracking(s, 0, 0);
		return result;
	}
};
int main()
{
	string s = "hello";
	string s1 = s.substr(0, 4);
	// cout << s1;
	string s2 = "255";
}