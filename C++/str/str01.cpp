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
class Solution
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
int main()
{
	string str = "hello";
	reverse(str.begin(), str.end());
	for(int i = 0; i < str.size(); i++)
		cout << str[i] << " ";
	return 0;
}