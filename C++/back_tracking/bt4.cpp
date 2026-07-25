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
class Solution
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
		for(int i = 0; i < digits.size(); i++)
		{
			if(digits[i] == '2')
				record.push_back("abc");
			else if(digits[i] == '3')
				record.push_back("def");
		}
		bt(record,digits.size(),0);
		return result;
	}
};