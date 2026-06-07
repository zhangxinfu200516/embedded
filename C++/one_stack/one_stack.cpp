#include <bits/stdc++.h>
using namespace std;

int main()
{
}
class Solution
{
public:
	vector<int> dailyTemperatures(vector<int> &temperatures)
	{
		int n = temperatures.size();
		vector<int> answer(n, 0);
		for (int i = 0; i < n; i++)
		{
			int j = i;
			while (j < n)
			{
				if (temperatures[i] < temperatures[j])
				{
					answer[i] = j - i;
					break;
				}
				j++;
			}
		}
		return answer;
	}
};

class Solution
{
public:
	vector<int> dailyTemperatures(vector<int> &temperatures)
	{
		int n = temperatures.size();
		stack<int> sta;
		vector<int> result(n, 0);
		sta.push(0);
		for (int i = 1; i < n; i++)
		{
			// auto it = sta.top();
			while (!sta.empty() && temperatures[i] > temperatures[sta.top()])
			{
				result[sta.top()] = i - sta.top();
				sta.pop();
			}
			sta.push(i);
		}
		return result;
	}
};
class Solution
{
public:
	vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
	{
		vector<int> result(nums1.size(), -1);
		std::unordered_map<int, int> map;
		for (int i = 0; i < nums2.size(); i++)
		{
			map[nums2[i]] = i;
		}
		for (int i = 0; i < nums1.size(); i++)
		{
			auto cur = map.find(nums1[i]);
			int j = cur->second;
			while (j < nums2.size())
			{
				if (nums2[j] > nums2[cur->second])
				{
					result[i] = nums2[j];
					break;
				}
				j++;
			}
		}
		return result;
	}
};
class Solution
{
public:
	vector<int> nextGreaterElements(vector<int> &nums)
	{
		int n = nums.size();
		vector<int> result(n, -1);
		std::stack<int> sta;
		sta.push(0);
		for (int i = 1; i < 3; i++)
		{
			int max_nums = 0;
			for (int j = 1; j < nums.size(); j++)
			{
				max_nums = max(max_nums, nums[j]);
				cout << nums[j] << " ";
				while (!sta.empty() && nums[j] > nums[sta.top()])
				{
					result[sta.top()] = nums[j];
					sta.pop();
					// sta.push(j);
				}
				sta.push(j);
			}
			cout << endl;
		}
		return result;
	}
};

class Solution
{
public:
	int sum = 0;
	int trap(vector<int> &height)
	{
		std::stack<int> sta;
		sta.push(0);
		for (int i = 1; i < height.size(); i++)
		{
			if (height[i] < height[sta.top()])
				sta.push(i);
			else if (height[i] == height[sta.top()])
			{
				sta.pop();
				sta.push(i);
			}
			else
			{
				while (!sta.empty() && height[i] > height[sta.top()])
				{
					int mid_height = height[sta.top()];
					sta.pop();
					if (!sta.empty())
					{
						int get_height = min(height[i], height[sta.top()]) - mid_height;
						sum += get_height * (i - sta.top() - 1);
					}
				}
				sta.push(i);
			}
		}
		return sum;
	}
};

class Solution
{
public:
	int sum = 0;
	int trap(vector<int> &height)
	{
		stack<int> sta;
		sta.push(0);
		for (int i = 0; i < height.size(); i++)
		{
			if (height[i] < height[sta.top()])
			{
				sta.push(i);
			}
			else if (height[i] == height[sta.top()])
			{
				sta.pop();
				sta.push(i);
			}
			else
			{
				while (!sta.empty() && height[i] > height[sta.top()])
				{
					int mid = height[sta.top()];
					sta.pop();
					if (!sta.empty())
					{
						cout << height[sta.top()] << " " << mid << " " << height[i] << endl;
						sum += (min(height[sta.top()], height[i]) - mid) * (i - sta.top() - 1);
					}
				}
				sta.push(i);
			}
		}
		return sum;
	}
};
// class Solution
// {
// public:
// 	int largestRectangleArea(vector<int> &heights)
// 	{
// 		int n = heights.size();
// 		int index_left = 0;
// 		vector<int> left(n,0);
// 		for(int  i = 0; i < n; i++)
// 		{
// 			if()
// 		}
// 		int min_right = 0;
// 		vector<int> right(n,0);
// 		for(int i = 0; i < n; i++)
// 		{
// 			min_right = min(min_right,heights[i]);
// 			right[i] = min_right;
// 		}
// 		int max_sum = 0;
// 		for(int i = 0; i < n ; i++)
// 		{
// 			max_sum = max()
// 		}
// 	}
// };
class Solution
{
public:
	int result = 0;
	int largestRectangleArea(vector<int> &heights)
	{
		stack<int> sta;
		heights.insert(heights.begin(), 0);
		heights.push_back(0);

		sta.push(0);
		for (int i = 1; i < heights.size(); i++)
		{
			if (heights[i] > heights[sta.top()])
			{
				sta.push(i);
			}
			else if (heights[i] == heights[sta.top()])
			{
				sta.pop();
				sta.push(i);
			}
			else
			{
				while (!sta.empty() && heights[i] < heights[sta.top()])
				{
					int mid = sta.top();
					sta.pop();
					if (!sta.empty())
					{
						int out = heights[mid] * (i - sta.top() - 1);
						result = max(out, result);
					}
				}
				sta.push(i);
			}
		}
		return result;
	}
};