#include <bits\stdc++.h>
using namespace std;
class Solution01
{
public:
	vector<int> dailyTemperatures(vector<int> &temperatures)
	{
		for (int i = 0; i < temperatures.size() - 1; i++)
		{
			for (int j = i + 1; j < temperatures.size(); j++)
			{
				if (temperatures[i] < temperatures[j])
				{
					temperatures[i] = j - i;
					break;
				}
				else if (j == temperatures.size() - 1)
				{
					temperatures[i] = 0;
				}
			}
		}
		temperatures[temperatures.size() - 1] = 0;
		return temperatures;
	}
};
class Solution02
{
public:
	vector<int> dailyTemperatures(vector<int> &temperatures)
	{
		vector<int> result(temperatures.size(), 0);
		for (int i = 0; i < temperatures.size() - 1; i++)
		{
			for (int j = i + 1; j < temperatures.size(); j++)
			{
				if (temperatures[i] < temperatures[j])
				{
					result[i] = j - i;
					break;
				}
			}
		}
		return result;
	}
};
class Solution03
{
public:
	vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
	{
		vector<int> result(nums1.size(), -1);
		for (int i = 0; i < nums1.size(); i++)
		{
			static bool access = false;

			for (int j = 0; j < nums2.size(); j++)
			{
				if (nums1[i] == nums2[j])
					access = true;

				if (access)
				{
					if (nums1[i] < nums2[j])
					{
						result[i] = nums2[j];
						access = false;
						break;
					}
				}
			}
		}
		return result;
	}
};
class Solution04
{
public:
	vector<int> nextGreaterElements(vector<int> &nums)
	{
		vector<int> result(nums.size(), -1);
		int n = nums.size();
		for (int i = 0; i < n; i++)
		{
			nums.push_back(nums[i]);
		}
		for (int j = 0; j < result.size(); j++)
		{

			for (int k = j + 1; k < nums.size(); k++)
			{
				if (nums[j] < nums[k])
				{
					result[j] = nums[k];
					break;
				}
			}
		}
		return result;
	}
};
class Solution05
{
public:
	int trap(vector<int> &height)
	{
		int result = 0;
		for (int i = 1; i < height.size() - 1; i++)
		{

			int left_nums = i - 1, max_left = 0;
			while (left_nums >= 0)
			{
				if (height[left_nums] > max_left)
					max_left = height[left_nums];
				left_nums--;
			}
			int right_nums = i + 1, max_right = 0;
			while (right_nums < height.size())
			{
				if (height[right_nums] > max_right)
					max_right = height[right_nums];
				right_nums++;
			}
			int val = min(max_left, max_right) - height[i];
			result += max(val, 0);
		}
		return result;
	}
};
class Solution06
{
public:
	int largestRectangleArea(vector<int> &heights)
	{
		int result = 0;
		for(int i = 0; i < heights.size(); i++)
		{
			int left_count = i - 1;
			while(left_count >= 0)
			{
				if(heights[left_count] < heights[i])
					break;
				left_count--;
			}
			int right_count = i + 1;
			while(right_count < heights.size())
			{
				if(heights[right_count] < heights[i])
					break;
				right_count++;
			}
			cout << left_count << " " << right_count << " " << heights[i] << endl;
			int s = max(0,(right_count - left_count - 1) * heights[i]);
			if(s > result)
				result = s;
		}
		return result;
	}
};
int main()
{
	Solution06 s;
	vector<int> nums = {2, 4};
	int result = s.largestRectangleArea(nums);
	
	return 0;
}