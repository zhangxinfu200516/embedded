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
class Solution
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
class Solution
{
public:
	vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
	{
		vector<int> result(nums1.size(),-1);
		for(int i = 0; i < nums1.size() ; i++)
		{
			static bool access = false;

			for(int j = 0; j < nums2.size(); j++)
			{
				if(nums1[i] == nums2[j])
					access = true;

				if(access)
				{
					if(nums1[i] < nums2[j])
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
int main()
{
}