#include <bits\stdc++.h>
using namespace std;

class Solution
{
public:
	std::unordered_map<char, int> map;
	bool isAnagram(string s, string t)
	{
		for (int i = 0; i < s.size(); i++)
		{
			map[s[i]]++;
			map[t[i]]--;
		}
		for (auto it = map.begin(); it != map.end(); ++it)
		{
			if (it->second != 0) // 检查每个键对应的值
				return false;
		}
		return true;
	}
};
int main()
{
	Solution s;
	s.isAnagram("s", "s");
	return 0;
}