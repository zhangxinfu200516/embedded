#ifdef Q1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int num, x;
	cin >> num >> x;
	vector<int> a(num);
	for (int k = 0; k < num; k++)
	{
		cin >> a[k];
	}
	int i = 0; // i 指向当前 <= x 区间的下一个位置
	for (int j = 0; j < num; j++)
	{
		if (a[j] <= x)
		{ // 与 移动零 问题 的唯一区别
			swap(a[i], a[j]);
			i++;
		}
	}
	for (int k = 0; k < num; k++)
	{
		cout << a[k];
		if (k < num - 1)
		{
			cout << " ";
		}
	}
	cout << endl;
	return 0;
}
#endif
#ifdef Q1
#include <bits/stdc++.h>
using namespace std;

void quick_Sort(vector<int> &nums, int l, int r)
{
	if (l >= r)
		return;
	int x = nums[r];
	int i = l;
	for (int j = l; j < r; j++)
	{
		if (nums[j] <= x)
		{
			swap(nums[i], nums[j]);
			i++;
		}
	}
	swap(nums[i], nums[r]);
	// 最后把基准值放到正确位置
	quick_Sort(nums, l, i - 1);
	quick_Sort(nums, i + 1, r);
}
int main()
{
	// 处理输入
	int n;
	cin >> n;
	vector<int> nums(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}
	int l = 0, r = n - 1;
	quick_Sort(nums, l, r);
	for (int k = 0; k < n; k++)
	{
		cout << nums[k];
		if (k != n - 1)
			cout << " ";
	}
}

class Solution
{
public:
	int removeElement(vector<int> &nums, int val)
	{
		int i = 0;
		for (int j = 0; j < nums.size(); j++)
		{
			if (nums[j] != val)
			{
				// swap(nums[i], nums[j]);
				nums[i] = nums[j];
				i++;
			}
		}
		return i;
	}
};
class Solution
{
public:
	void reverseString(vector<char> &s)
	{
		int i = 0, j = s.size() - 1;
		while (i < j)
		{
			swap(s[i], s[j]);
			i++;
			j--;
		}
	}
};

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
	ListNode *reverseList(ListNode *head)
	{
		ListNode *cur = head;
		ListNode *record = NULL;
		while (cur != NULL)
		{
			ListNode *new_node = new ListNode(cur->val);
			new_node->next = record;
			record = new_node;
			cur = cur->next;
		}
		return record;
	}
};
#endif

#include <bits\stdc++.h>
using namespace std;
class Solution
{
public:
	vector<vector<int>> result;
	vector<vector<int>> threeSum(vector<int> &nums)
	{
		sort(nums.begin(), nums.end());
		int sum = 0;
		for (int k = 0; k < nums.size() - 2; k++)
		{
			if (k > 0 && nums[k] == nums[k - 1])
				continue;
			int compare = sum - nums[k];
			int i = k + 1;
			int j = nums.size() - 1;
			while (i < j)
			{
				int sum1 = nums[i] + nums[j];
				if (sum1 < compare)
				{
					i++;
					continue;
				}
				else if (sum1 > compare)
				{
					j--;
					continue;
				}

				if (nums[i] == nums[i - 1] && i > k + 1)
				{
					i++;
					continue;
				}
				if (nums[j] == nums[j + 1] && j + 1 < nums.size())
				{
					j--;
					continue;
				}
				result.push_back({nums[k], nums[i], nums[j]});
				i++;
				j--;
			}
		}
		return result;
	}
};

// int main()
// {
// 	// 处理输入
// 	int n;
// 	cin >> n;
// 	vector<int> nums(n, 0);
// 	for (int i = 0; i < n; i++)
// 	{
// 		cin >> nums[i];
// 	}
// 	Solution s;
// 	s.threeSum(nums);
// 	cout << s.result.size();
// }

class Solution1
{
public:
	int sum;
	int trap(vector<int> &height)
	{
		int n = height.size();
		for (int i = 0; i < n; i++)
		{
			if (i == 0 || i == n - 1)
				continue;
			int height_left = height[i], height_right = height[i];
			for (int left = i - 1; left >= 0; left--)
			{
				if (height[left] > height_left)
					height_left = height[left];
			}

			for (int right = i + 1; right < n; right++)
			{
				if (height[right] > height_right)
					height_right = height[right];
			}

			sum += min(height_left, height_right) - height[i];
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
		int n = height.size();
		// 记录这个雨滴左侧的最大高度、与右侧最大高度
		vector<int> left(n, 0);
		vector<int> right(n, 0);
		int left_max = 0;
		for (int i = 0; i < n; i++)
		{
			left_max = max(left_max, height[i]);
			left[i] = left_max;
		}

		int right_max = 0;
		for (int j = n - 1; j >= 0; j--)
		{
			right_max = max(right_max, height[j]);
			right[j] = right_max;
		}

		for (int i = 1; i < n - 1; i++)
		{
			int out = min(left[i - 1], right[i + 1]) - height[i];
			if (out < 0)
				out = 0;
			sum += out;
		}
		return sum;
	}
};

class Solution
{
public:
	int largestRectangleArea(vector<int> &heights)
	{
		int result = 0;
		int n = heights.size();
		int i = 0, j = n - 1;
		while (i < j)
		{
			if (heights[i] < heights[j])
				i++;
			else if (heights[i] > heights[j])
				j--;
			int s = min(heights[i], heights[j]) * (j - i + 1);
			cout << heights[i] << " " << heights[j] << " " << i << "" << j << endl;
			result = max(result, s);
		}
		return result;
	}
};
class Solution
{
public:
	int largestRectangleArea(vector<int> &heights)
	{
		int result = 0;
		int n = heights.size();
		for (int i = 0; i < n; i++)
		{
			int left_index = i, right_index = i;
			for (left_index = i; left_index >= 0; left_index--)
			{
				if (heights[left_index] < heights[i])
					break;
			}
			for (right_index = i; right_index < n; right_index++)
			{
				if (heights[right_index] < heights[i])
					break;
			}
			int out = (right_index - left_index - 1) * heights[i];
			result = max(out, result);
		}
		return result;
	}
};
class Solution
{
public:
	int largestRectangleArea(vector<int> &heights)
	{
		int result = 0;
		int n = heights.size();
		
	}
};