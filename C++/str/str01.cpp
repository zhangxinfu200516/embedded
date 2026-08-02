#include <bits\stdc++.h>
using namespace std;
class Solution01
{
public:
	void swap_s(string &s, int left, int right)
	{
		while (left < right)
		{
			swap(s[left], s[right]);
			++left;
			--right;
		}
	}
	string reverseStr(string s, int k)
	{
		int start_index = 0;
		static bool lock = false;
		for (int i = 0; i < s.size(); i++)
		{
			int val = i - start_index + 1;
			if (val >= 2 * k)
			{
				swap_s(s, start_index, start_index + k - 1);
				start_index = i + 1;
				lock = true;
			}
			if (lock == true)
			{
				if (s.size() - start_index < 2 * k && s.size() - start_index >= k)
					swap_s(s, start_index, start_index + k - 1);
				else if (s.size() - start_index < k)
					swap_s(s, start_index, s.size() - 1);
				break;
			}
		}
		return s;
	}
};
class Solution02
{
public:
	string reverseStr(string s, int k)
	{
		for (int i = 0; i < s.size(); i += (2 * k))
		{
			// 1. 每隔 2k 个字符的前 k 个字符进行反转
			// 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
			if (i + k <= s.size())
			{
				reverse(s.begin() + i, s.begin() + i + k);
			}
			else
			{
				// 3. 剩余字符少于 k 个，则将剩余字符全部反转。
				reverse(s.begin() + i, s.end());
			}
		}
		return s;
	}
};

class Solution03
{
public:
	string delete_space(string s)
	{
		string result;
		bool space_flag = false, word_flag = false;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == ' ')
			{
				if (word_flag)
					space_flag = true;
			}
			else
			{
				if (space_flag)
				{
					result.push_back(' ');
					space_flag = false;
				}
				result.push_back(s[i]);
				word_flag = true;
			}
		}
		return result;
	}
	string reverseWords(string s)
	{
		string result;
		vector<string> record;
		int start_index = 0;
		string str = delete_space(s);
		for (int i = 0; i <= str.size(); i++)
		{
			if (str[i] == ' ' || i == str.size())
			{
				record.push_back(str.substr(start_index, i - start_index));
				start_index = i + 1;
			}
		}
		for (int j = record.size() - 1; j >= 0; j--)
		{
			result += record[j];
			if (j != 0)
				result += ' ';
		}
		return result;
	}
	#ifdef Q1
	string reverseWords(string s)
	{
		string str = delete_space(s);
		reverse(str.begin(), str.end());
		int start_index = 0;
		for (int i = 0; i <= str.size(); i++)
		{
			if (str[i] == ' ' || i == str.size())
			{
				reverse(str.begin() + start_index, str.begin() + i);
				start_index = i + 1;
			}
		}
		return str;
	}
	#endif
};
class Solution04
{
public:
	int strStr(string haystack, string needle)
	{
		int val = 0, needle_index = 0;
		bool lock = false;
		for (int i = 0; i < haystack.size(); i++)
		{
			if (haystack[i] == needle[0] && val == 0)
				lock = true;
			if (lock && haystack[i] == needle[needle_index++])
				val++;
		}
		if (val == needle.size())
			return 0;
		else
			return -1;
	}
};
class Solution
{
public:
	bool is_true(string s1, string s2)
	{
		if (s1.size() != s2.size())
			return false;
		for (int i = 0; i < s1.size(); i++)
		{
			if (s1[i] != s2[i])
				return false;
		}
		return true;
	}
	bool repeatedSubstringPattern(string s)
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (i > 0 && s[0] == s[i])
			{
				string temp = s.substr(0, i);
				int count = s.size() / temp.size();
				string record;
				record.resize(0);
				while (count > 0)
				{
					record += temp;
					count--;
				}
				if (is_true(record, s))
					return true;
			}
		}
		return false;
	}
};
int main()
{
	Solution s;
	cout << s.repeatedSubstringPattern("abaabd") << endl;

	return 0;
}