#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution1
{
public:
	bool isAnagram(string s, string t)
	{
		vector<int> record(26, 0);
		for (int i = 0; s[i] != '\0'; i++)
		{
			int index = s[i] - 'a';
			record[index]++;
		}
		for (int i = 0; t[i] != '\0'; i++)
		{
			int index = t[i] - 'a';
			record[index]--;
		}
		for (int j = 0; j < 26; j++)
		{
			if (record[j] != 0)
				return false;
		}
		return true;
	}
};
class Solution2
{
public:
	vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
	{
		int _max = max(nums1.size(), nums2.size());
		vector<int> record(_max, 0);
		int num = 0;
		for (int i = 0; i < nums1.size(); i++)
		{

			for (int j = 0; j < nums2.size(); j++)
			{
				if (nums1[i] == nums2[j])
				{
					record[num++] = nums1[i];
					break;
				}
			}
		}
		int i;
		for (int j = 0; j < num; j++)
		{
			if (record[i] != record[j])
				record[++i] = record[j];
		}
		i++;
		vector<int> result(i, 0);
		for (int k = 0; k < i; k++)
			result[k] = record[k];

		return result;
	}
};
class Solution3
{
public:
	vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
	{
		unordered_set<int> result;
		unordered_set<int> nums_set(nums1.begin(), nums1.end()); // 映射到哈希表中
		for (int i = 0; i < nums2.size(); i++)
		{
			if (nums_set.find(nums2[i]) != nums_set.end()) // 通过元素值查找哈希表
			{
				result.insert(nums2[i]);
			}
		}
		return vector<int>(result.begin(), result.end()); // 转换类型
	}
};
class Solution4
{
public:
	int get_sum(int n)
	{
		int sum = 0;
		while (n)
		{
			sum += (n % 10) * (n % 10);
			n /= 10;
		}
		return sum;
	}
	bool isHappy(int n)
	{
		unordered_set<int> record;
		int sum = get_sum(n);
		if (sum == 1)
			return true;
		while (1)
		{
			record.insert(sum);
			sum = get_sum(sum);
			cout << sum << endl;
			if (sum == 1)
				return true;
			if (record.find(sum) != record.end())
				return false;
		}
	}
};
class Solution5 // 暴力算法解决两数之和
{
public:
	vector<int> twoSum(vector<int> &nums, int target)
	{
		int sum = 0;
		vector<int> result(2, 0);
		for (int i = 0; i < nums.size(); i++)
		{
			if (sum == target)
				break;
			for (int j = i + 1; j < nums.size(); j++)
			{
				sum = nums[i] + nums[j];
				if (sum == target)
				{
					result[0] = i;
					result[1] = j;
					break;
				}
			}
		}
		return result;
	}
};
class Solution6
{
public:
	vector<int> twoSum(vector<int> &nums, int target)
	{
		unordered_map<int, int> map; // 键为元素值、值为索引
		for (int i = 0; i < nums.size(); i++)
		{
			auto it = map.find(target - nums[i]);
			if (it != map.end())
				return {it->second, i};
			map.insert(std::make_pair(nums[i], i));
		}
		return {};
	}
};
class Solution7
{
public:
	int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
	{
		std::unordered_map<int, int> map;
		for (int i = 0; i < nums1.size(); i++)
		{
			for (int j = 0; j < nums2.size(); j++)
			{
				int sum = nums1[i] + nums2[j];
				// cout << sum << endl;
				auto ita = map.find(sum);
				if (ita != map.end())
					ita->second++;
				else
					map.insert(std::make_pair(sum, 1));
			}
		}
		// cout << "---------------------"<<endl;
		int count = 0;
		for (int i = 0; i < nums3.size(); i++)
		{
			for (int j = 0; j < nums4.size(); j++)
			{
				int sum = nums3[i] + nums4[j];
				// cout << sum << endl;
				auto ita = map.find(0 - sum);
				if (ita != map.end())
					count += ita->second;
			}
		}
		return count;
	}
};

class Solution8
{
public:
	vector<vector<int>> threeSum(vector<int> &nums)
	{
		sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		int left = 0, right = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			left = i + 1;
			right = nums.size() - 1;

			if (nums[i] > 0)
				continue;

			if (i > 0 && nums[i] == nums[i - 1])
				continue;

			while (left < right)
			{
				int sum = nums[i] + nums[left] + nums[right];

				if (sum > 0)
					right--;
				else if (sum < 0)
					left++;
				else
				{
					cout << nums[i] << nums[left] << nums[right] << endl;
					result.push_back(vector<int>{nums[i], nums[left], nums[right]});

					while (left < right && nums[left] == nums[left + 1])
						left++;
					while (left < right && nums[right] == nums[right - 1])
						right--;
					left++;
					right--;
				}
			}
		}
		return result;
	}
};
class Solution9
{
public:
	bool canConstruct(string ransomNote, string magazine)
	{
		std::unordered_map<char, int> map;
		for (int i = 0; magazine[i] != '\0'; i++)
		{
			auto ita = map.find(magazine[i]);
			if (ita != map.end())
				ita->second++;
			else
				map.insert(std::make_pair(magazine[i], 1));
		}

		for (int j = 0; ransomNote[j] != '\0'; j++)
		{
			auto ita = map.find(ransomNote[j]);
			if (ita != map.end())
			{
				if (ita->second == 0)
					return false;
				else
					ita->second--;
			}
			else
				return false;
		}

		return true;
	}
};
class Solution
{
public:
	vector<vector<int>> fourSum(vector<int> &nums, int target)
	{
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] > target)
				break;
			if (i > 0 && nums[i] == nums[i - 1])
				continue;

			for (int j = i + 1; j < nums.size(); j++)
			{
				if (nums[j] + nums[i] > target)
					break;
				if (j > i + 1 && nums[j] == nums[j - 1])
					continue;

				int left = j + 1, right = nums.size() - 1;
				while (left < right)
				{
					cout << nums[i] << " " << nums[j] << " " << nums[left] << " " << nums[right] << endl;
					int sum = nums[i] + nums[j] + nums[left] + nums[right];
					if (sum > target)
						right--;
					else if (sum < target)
						left++;
					else
					{
						result.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});

						while (left < right && nums[left] == nums[left + 1])
							left++;
						while (left < right && nums[right] == nums[right - 1])
							right--;

						left++;
						right--;
					}
				}
			}
		}
		return result;
	}
};
int main()
{
	vector<int> nums = {2, 2, 2, 2, 2};
	Solution s;
	s.fourSum(nums, 8);
}