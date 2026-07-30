#include <bits\stdc++.h>
using namespace std;

class Solution01
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
		for (auto it = map.begin(); it != map.end(); it++)
		{
			if (it->second != 0) // 检查每个键对应的值
				return false;
		}
		return true;
	}
};
class Solution
{
public:
	vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
	{
		std::unordered_map<int, int> map;
		vector<int> result;
		for (int i = 0; i < nums1.size(); i++)
			map[nums1[i]]++;
		for (int j = 0; j < nums2.size(); j++)
		{
			if (map[nums2[j]] > 0)
			{
				result.push_back(nums2[j]);
				map[nums2[j]] = 0;
			}
		}
		return result;
	}
};
int main()
{
	std::unordered_map<int, int> map;
	cout << map[0] << endl;
	return 0;
}