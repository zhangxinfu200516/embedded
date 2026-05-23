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
			back_tracking(nums, used);
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
	int result = 5.435f * 0.5f * (1.f - 0.868f / 0.5f + 0.184f / 0.5f / 0.5f) / (1.0f - 0.282f / 0.5f - 0.718f / 0.5f / 0.5f);
	cout << result;
}

class Solution
{
public:
	// unordered_map<出发机场, map<到达机场, 航班次数>> targets
	unordered_map<string, map<string, int>> targets;
	void backtracking(vector<vector<string>> &tickets, vector<string> &result)
	{
		if (result.size() == tickets.size() + 1)
		{
			return;
		}
		string cur = result.back();
		for (auto &target : targets[cur])
		{
			if (target.second > 0)
			{
				target.second--;
				result.push_back(target.first);
				backtracking(tickets, result);
			}
		}
	}
	vector<string> findItinerary(vector<vector<string>> &tickets)
	{
		targets.clear();
		vector<string> result;
		for (vector<string> &vec : tickets)
		{
			targets[vec[0]][vec[1]]++;
		}
		result.push_back("JFK");
		backtracking(tickets, result);
		return result;
	}
};
class Solution
{
public:
	vector<vector<int>> result;
	vector<int> path;
	int sum;
	void back_tracking(vector<int> &candidates, int &target, int &sum, int start_index)
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
			sum += candidates[i];
			path.push_back(candidates[i]);
			back_tracking(candidates, target, sum, i);
			sum -= candidates[i];
			path.pop_back();
		}
	}
	vector<vector<int>> combinationSum(vector<int> &candidates, int target)
	{
		result.clear();
		path.clear();
		sum = 0;
		back_tracking(candidates, target, sum, 0);
		return result;
	}
};
class Solution
{
public:
	vector<vector<int>> result;
	vector<int> path;
	void back_tracing(vector<int> &nums, int start_index)
	{
		result.push_back(path);
		if (start_index == nums.size())
			return;
		for (int i = start_index; i < nums.size(); i++)
		{
			if (i > start_index && nums[i] == nums[i - 1])
				continue;
			path.push_back(nums[i]);
			back_tracing(nums, i + 1);
			path.pop_back();
		}
	}
	vector<vector<int>> subsetsWithDup(vector<int> &nums)
	{
		// 回溯-子集问题:在路径上收集结果
		sort(nums.begin(), nums.end());
		back_tracing(nums, 0);
		return result;
	}
};
class Solution
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
		for (int i = 0; i < nums.size(); i++)
		{
			// 树层去重
			if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == true)
				continue;
			// 树枝去重
			if (!used[i])
			{
				used[i] = true;
				path.push_back(nums[i]);
				back_tracking(nums, used);
				path.pop_back();
				used[i] = false;
			}
		}
	}
	vector<vector<int>> permuteUnique(vector<int> &nums)
	{
		vector<bool> used(nums.size(), false);
		// 全排列：递归不需要start_index，每次遍历所有，此外处理两个方向上的去重
		back_tracking(nums, used);
		return result;
	}
};