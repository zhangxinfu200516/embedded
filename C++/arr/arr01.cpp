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
class Solution02
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
class Solution03
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
class Solution04
{
public:
	vector<vector<int>> generateMatrix(int n)
	{
		vector<vector<int>> result(n, vector<int>(n, 0));
		int val = 1, star = 1, count = n / 2;

		while (count > 0)
		{
			int i, j;
			for (j = star - 1, i = star - 1; j < n - star; j++)
				result[i][j] = val++;
			for (j = n - star, i = star - 1; i < n - star; i++)
				result[i][j] = val++;
			for (j = n - star, i = n - star; j > star - 1; j--)
				result[i][j] = val++;
			for (j = star - 1, i = n - star; i > star - 1; i--)
				result[i][j] = val++;
			star++;
			count--;
		}
		if (n % 2 == 1)
			result[n / 2][n / 2] = n * n;
		return result;
	}
};
class Solution
{
public:
	vector<vector<int>> generateMatrix(int n)
	{
		vector<vector<int>> result(n, vector<int>(n, 0));
		int x = 0, val = 1, offest = 1, count = n / 2;
		while (count > 0)
		{
			int i, j;
			for (i = x, j = x; j < n - offest; j++)
				result[i][j] = val++;
			for (i = x, j = n - offest; i < n - offest; i++)
				result[i][j] = val++;
			for (i = n - offest, j = n - offest; j > x; j--)
				result[i][j] = val++;
			for (i = n - offest, j = x; i > x; i--)
				result[i][j] = val++;
			x++;
			offest++;
			count--;
		}
		if (n % 2 == 1)
			result[n / 2][n / 2] = n * n;
		return result;
	}
};
int main()
{
	Solution s;
	vector<vector<int>> result = s.generateMatrix(4);
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[0].size(); j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}