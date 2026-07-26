#include <bits\stdc++.h>
using namespace std;

class Solution01
{
public:
	vector<vector<int>> result;
	vector<int> path;
	void bt(int n, int k, int index)
	{
		if (path.size() >= k)
		{
			result.push_back(path);
			return;
		}
		for (int i = index; i < n + 1; i++)
		{
			path.push_back(i);
			bt(n, k, i + 1);
			path.pop_back();
		}
	}
	vector<vector<int>> combine(int n, int k)
	{
		bt(n, k, 1);
		return result;
	}
};
class Solution02
{
public:
	vector<vector<int>> result;
	vector<int> path;
	int sum = 0;
	void bt(int n, int k, int start_index)
	{
		if (sum > n || path.size() > k)
			return;
		if (sum == n && path.size() == k)
		{
			result.push_back(path);
			return;
		}
		for (int i = start_index; i <= 9; i++)
		{
			path.push_back(i);
			sum += i;
			bt(n, k, i + 1);
			sum -= i;
			path.pop_back();
		}
	}
	vector<vector<int>> combinationSum3(int k, int n)
	{
		bt(n, k, 1);
		return result;
	}
};
class Solution03
{
public:
	vector<string> result;
	string path;
	void bt(vector<string> record, int k, int start_index)
	{
		if (path.size() == k)
		{
			result.push_back(path);
			return;
		}
		for (int i = start_index; i < record.size(); i++)
		{
			for (int j = 0; j < record[i].size(); j++)
			{
				path.push_back(record[i][j]);
				bt(record, k, i + 1);
				path.pop_back();
			}
		}
	}
	vector<string> letterCombinations(string digits)
	{
		vector<string> record;
		for (int i = 0; i < digits.size(); i++)
		{
			if (digits[i] == '2')
				record.push_back("abc");
			else if (digits[i] == '3')
				record.push_back("def");
		}
		bt(record, digits.size(), 0);
		return result;
	}
};
class Solution04
{
private:
	const string letterMap[10] = {
		"",	   // 0
		"",	   // 1
		"abc", // 2
		"def", // 3
	};

	void bt(string digits, int index)
	{
		if (index == digits.size())
		{
			result.push_back(s);
			return;
		}
		string letter = letterMap[digits[index] - '0'];
		for (int i = 0; i < letter.size(); i++)
		{
			s.push_back(letter[i]);
			bt(digits, index + 1);
			s.pop_back();
		}
	}

public:
	vector<string> result;
	string s;
	vector<string> letterCombinations(string digits)
	{
		bt(digits, 0);
		return result;
	}
};
class Solution05
{
public:
	vector<vector<int>> result;
	vector<int> path;
	int sum = 0;
	void bt(vector<int> &candidates, int target, int start_index)
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
			bt(candidates, target, i);
			sum -= candidates[i];
			path.pop_back();
		}
	}
	vector<vector<int>> combinationSum(vector<int> &candidates, int target)
	{
		bt(candidates, target, 0);
		return result;
	}
};
class Solution06
{
public:
	vector<vector<int>> result;
	vector<int> path;
	int sum = 0;
	void bt(vector<int> &candidates, int target, int start_index)
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
			path.push_back(candidates[i]);
			sum += candidates[i];
			bt(candidates, target, i + 1);
			sum -= candidates[i];
			path.pop_back();
		}
	}
	vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
	{
		sort(candidates.begin(), candidates.end());
		bt(candidates, target, 0);
		return result;
	}
};
class Solution07
{
public:
	bool is_true(string s)
	{
		bool result = true;
		for (int i = 0, j = s.size() - 1; i < j; i++, j--)
		{
			if (s[i] != s[j])
			{
				result = false;
				break;
			}
		}
		return result;
	}
	vector<vector<string>> result;
	vector<string> path;
	void bt(string s, int start_index)
	{
		if (start_index == s.size())
		{
			result.push_back(path);
			return;
		}
		for (int i = start_index; i < s.size(); i++)
		{
			string temp = s.substr(start_index, i - start_index + 1);
			if (is_true(temp))
			{
				path.push_back(temp);
				bt(s, i + 1);
				path.pop_back();
			}
		}
	}
	vector<vector<string>> partition(string s)
	{
		bt(s, 0);
		return result;
	}
};
class Solution
{
public:
	bool is_true(string s)
	{
		if (s.size() == 0 || s.size() > 3)
			return false;
		if (stoi(s) - 0 > 255)
			return false;
		if(stoi(s) != 0 && s[0] == '0')
			return false;
		return true;
	}
	vector<string> result;
	string path;
	int count = 0;
	void bt(string s, int start_index)
	{
		if(count > 4)
			return;
		if (start_index == s.size() && count == 4)
		{
			result.push_back(path.substr(0,path.size() - 1));
			return;
		}
		for (int i = start_index; i < s.size(); i++)
		{
			string temp = s.substr(start_index, i - start_index + 1);
			if (is_true(temp))
			{
				path += temp;
				path += '.';
				count++;
				bt(s, i + 1);
				path.resize(path.size() - temp.size() - 1);
				count--;
			}
			else
			{
				break;
			}
		}
	}
	vector<string> restoreIpAddresses(string s)
	{
		bt(s, 0);
		return result;
	}
};
int main()
{
	string s = "255";
	cout << stoi(s) - 0 << endl;
	return 0;
}