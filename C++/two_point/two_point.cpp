#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution1
{
public:
	int removeElement(vector<int> &nums, int val)
	{
		int i = 0, j = 0;
		for (j = 0; j < nums.size(); j++)
		{
			if (nums[j] != val)
			{
				nums[i++] = nums[j];
			}
		}
		return i + 1;
	}
};
class Solution2
{
public:
	vector<vector<int>> threeSum(vector<int> &nums)
	{
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 2; i++)
		{
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			int left = i + 1, right = nums.size() - 1;
			while (left < right)
			{
				int sum = nums[i] + nums[left] + nums[right];
				if (sum < 0)
					left++;
				else if (sum > 0)
					right--;
				else
				{
					result.push_back({nums[i], nums[left], nums[right]});
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
