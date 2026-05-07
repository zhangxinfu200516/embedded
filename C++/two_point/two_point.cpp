#include <bits/stdc++.h>
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
class Solution3
{
public:
	int lengthOfLongestSubstring(string s)
	{
		std::unordered_set<int> set;
		int n = s.size();
		int j = 0, ans = 0;
		for (int i = 0; i < n; i++)
		{
			while (j < n && !set.count(s[j]))
			{
				set.insert(s[j]);
				j++;
				if (j == n)
					break;
			}
			ans = max(ans, j - i);
			set.erase(s[i]);
		}
		return ans;
	}
};
class Solution4
{
public:
	int maxArea(vector<int> &height)
	{
		int __max = 0;
		for (int i = 0; i < height.size(); i++)
		{
			for (int j = i + 1; j < height.size(); j++)
			{
				__max = max(__max, (j - i) * min(height[i], height[j]));
				if (height[i] <= height[j])
					break;
			}
		}
		return __max;
	}
};
class Solution
{
public:
	int trap(vector<int> &height)
	{
		int sum = 0, left = 0, right = height.size() - 1;
		int max_left = height[left], max_right = height[right];
		while (left < right)
		{
			max_left = max(max_left, height[left]);
			max_right = max(max_right, height[right]);
			if (height[left] < height[right])
			{
				sum += max_left - height[left];
				left++;
			}
			else
			{
				sum += max_right - height[right];
				right--;
			}
		}
		return sum;
	}
};

int main01()
{
	int n;
	cin >> n;
	vector<int> input(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
	}
	int left = 0, right = 0, ans = 0;
	for (int mid = 0; mid < n; mid++)
	{
		left = mid;
		right = mid;
		while (left > 0 && input[left] > input[left - 1])
			left--;
		while (right < n - 1 && input[right] > input[right + 1])
			right++;
		if (mid > left && mid < right)
		{
			// cout << input[mid]<<endl;
			// cout << min(input[left], input[right]) <<endl;
			ans = max(ans, (input[mid] - min(input[left], input[right])));
		}
	}
	cout << ans;
}
int main()
{
	int n, num;
	cin >> n >> num;
	vector<vector<int>> input(n, vector<int>(2, 0));
	for (int i = 0; i < n; i++)
	{
		cin >> input[i][0] >> input[i][1];
	}
	int max_cost = 0;
	for (int i = 0; i < n; i++)
	{
		int j = i;
		int sum = 0, cost = 0;
		while (sum <= num && j < n)
		{
			if (sum + input[j][1] > num)
				break;
			else
			{
				sum += input[j][1];
				cost += input[j][0];
				j++;
			}
		}
		//cout << cost << " "; 
		max_cost = max(max_cost, cost);
	}
	cout  << max_cost;
}