#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	vector<vector<int>> result;
	vector<int> path;
	void back_tracking(vector<int> &nums, int start_index)
	{
		if (start_index == nums.size())
		{
			return;
		}

		for (int i = start_index; i < nums.size(); i++)
		{
			path.push_back(nums[i]);
			result.push_back(path);
			back_tracking(nums, i + 1);
			path.pop_back();
		}
	}
	vector<vector<int>> subsets(vector<int> &nums)
	{
		result.push_back({});
		back_tracking(nums, 0);
		return result;
	}
};
class Solution1
{
public:
	vector<vector<int>> result;
	vector<int> path;
	void back_tracking(vector<int> &nums, int start_index)
	{
		if (start_index == nums.size())
		{
			return;
		}

		for (int i = start_index; i < nums.size(); i++)
		{
			if (i > start_index && nums[i] == nums[i - 1])
				continue;
			path.push_back(nums[i]);
			result.push_back(path);
			back_tracking(nums, i + 1);
			path.pop_back();
		}
	}
	vector<vector<int>> subsetsWithDup(vector<int> &nums)
	{
		result.push_back({});
		sort(nums.begin(), nums.end());
		back_tracking(nums, 0);
		return result;
	}
};
class Solution2
{
public:
	vector<vector<int>> result;
	vector<int> path;
	void back_tracking(vector<int> &nums, int start_index)
	{
		if (path.size() > 1)
			result.push_back(path);
		// 不需要 if (start_index == size) return; 因为循环条件不满足时会自然返回
		std::unordered_set<int> set;
		for (int i = start_index; i < nums.size(); i++)
		{
			if (set.find(nums[i]) != set.end())
				continue;
			if (!path.empty() && path.back() > nums[i])
				continue;
			set.insert(nums[i]);
			path.push_back(nums[i]);
			back_tracking(nums, i + 1);
			path.pop_back();
		}
	}
	vector<vector<int>> findSubsequences(vector<int> &nums)
	{
		// sort(nums.begin(), nums.end());
		back_tracking(nums, 0);
		return result;
	}
};
// 全排列（无重复元素）、通过set对数值选取
class Solution3
{
public:
	vector<vector<int>> result;
	vector<int> path;
	std::unordered_set<int> used;
	void back_tracking(vector<int> &nums, int start_index)
	{
		if (start_index == nums.size())
		{
			result.push_back(path);
			return;
		}
		for (int i = 0; i < nums.size(); i++)
		{
			if (used.find(nums[i]) != used.end())
				continue;
			used.insert(nums[i]);
			path.push_back(nums[i]);
			back_tracking(nums, start_index + 1);
			path.pop_back();
			used.erase(nums[i]);
		}
	}
	vector<vector<int>> permute(vector<int> &nums)
	{
		back_tracking(nums, 0);
		return result;
	}
};
// 全排列（有重复元素）、对树层去重
class Solution4
{
public:
	vector<vector<int>> result;
	vector<int> path;
	std::unordered_map<int, int> map;
	void back_tracking(vector<int> &nums)
	{
		if (path.size() == nums.size())
		{
			result.push_back(path);
			return;
		}
		std::unordered_set<int> set;
		for (int i = 0; i < nums.size(); i++)
		{
			// 树层去重
			if (!set.empty() && set.find(nums[i]) != set.end())
				continue;
			// 查询map、map中存储的是无序的不重复的nums元素
			// 判断map中元素的个数、如果有则--，次数为0的时候则continue
			if (map[nums[i]] == 0)
				continue;
			else
				map[nums[i]]--;
			set.insert(nums[i]);
			path.push_back(nums[i]);
			back_tracking(nums);

			path.pop_back();
			map[nums[i]]++;
		}
	}
	vector<vector<int>> permuteUnique(vector<int> &nums)
	{
		for (int num : nums)
		{
			map[num]++;
		}
		back_tracking(nums);
		return result;
	}
};
// 对于有重复元素的全排列：used做树枝去重 、 unordered_set做树层去重
class Solution5
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
			if (!set.empty() && set.find(nums[i]) != set.end())
				continue;
			if (used[i] == true)
				continue;
			
			set.insert(nums[i]);
			path.push_back(nums[i]);
			used[i] = true;
			back_tracking(nums,used);
			path.pop_back();
			used[i] = false;
		}
	}
	vector<vector<int>> permuteUnique(vector<int> &nums)
	{
		vector<bool> used(nums.size(), false);
		back_tracking(nums, used);
		return result;
	}
};
int main()
{
	int result = 5.435f * 0.5f * ( 1.f - 0.868f / 0.5f  + 0.184f / 0.5f / 0.5f) / ( 1.0f - 0.282f/0.5f - 0.718f / 0.5f / 0.5f);
	cout << result ;
}