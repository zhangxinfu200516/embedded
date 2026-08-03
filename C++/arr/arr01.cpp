#include <bits\stdc++.h>
using namespace std;

class Solution01
{
public:
	int search(vector<int> &nums, int target)
	{
		int left = 0, right = nums.size() - 1;
		while (left < right)
		{
			int mid = (left + right) / 2;
			if (target > nums[mid])
				left = mid + 1;
			else if (target < nums[mid])
				right = mid - 1;
			else
				return mid;
		}
		return -1;
	}
};
class Solution
{
public:
	int minSubArrayLen(int target, vector<int> &nums)
	{
		int result = INT_MAX;
		for (int i = 0; i < nums.size(); i++)
		{
			int sum = 0, index = i;
			while (sum <= target && index < nums.size())
			{
				sum += nums[index];
				if (sum == target)
					result = min(result, index - i + 1);
				index++;
			}
		}
		return (result == INT_MAX ? 0 : result);
	}
};
class Solution
{
public:
	vector<int> sortedSquares(vector<int> &nums)
	{
		for (int i = 0; i < nums.size(); i++)
			nums[i] *= nums[i];
		sort(nums.begin(), nums.end());
		return nums;
	}
};
int main()
{
}