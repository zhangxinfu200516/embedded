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
class Solution02
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
class Solution03
{
public:
	bool isHappy(int n)
	{
		vector<int> record;
		int val = n;
		std::unordered_set<int> set;
		while (true)
		{
			int sum = 0;
			while (val > 0)
			{
				sum += (val % 10) * (val % 10);
				val = val / 10;
			}
			if (sum == 1)
				return true;
			if (set.count(sum) > 0)
				return false;
			set.insert(sum);
			val = sum;
		}
	}
};
class Solution04
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
		return {};
	}
};
class Solution05
{
public:
	int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
	{
		int result = 0;
		for (int i = 0; i < nums1.size(); i++)
		{
			for (int j = 0; j < nums2.size(); j++)
			{
				for (int m = 0; m < nums3.size(); m++)
				{
					for (int n = 0; n < nums4.size(); n++)
					{
						if (nums1[i] + nums2[j] + nums3[m] + nums4[n] == 0)
						{
							result++;
						}
					}
				}
			}
		}
		return result;
	}
};
class Solution
{
public:
	bool canConstruct(string ransomNote, string magazine)
	{
		std::unordered_map<char, int> map;
		for (int i = 0; i < magazine.size(); i++)
			map[magazine[i]]++;
		for (int j = 0; j < ransomNote.size(); j++)
		{
			map[ransomNote[j]]--;
			if (map[ransomNote[j]] < 0)
				return false;
		}
		return true;
	}
};
int main()
{
	// Solution s;

	// cout << s.isHappy(19) << endl;
	// std::unordered_set<int> set;
	// set.insert(1);
	// set.insert(2);

	// cout << set.count(3) << endl;
	std::unordered_map<char, int> map;
	cout << map['s'] << endl;
	map['s']--;
	cout << map['s'] << endl;
	return 0;
}