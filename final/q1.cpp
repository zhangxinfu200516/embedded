#ifdef Q1
#include <bits/stdc++.h>
using namespace std;
// 搜索范围错误：当 n < h 时，代码仅从 tasks[0]（最小值）遍历到，倍数关系没有考虑到
// 判断条件：获取结果集时，sum < h 也是有解的。
// 无解处理错误：当n > h下，遍历结束未找到sum == h的k时，代码要用处理下并返回错误。
// 嵌套for循环，效率较低
int main()
{
	// 处理输入
	int n, h;
	cin >> n;
	vector<int> tasks(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> tasks[i];
	}
	cin >> h;
	// 处理样例1 for遍历所有找最大值
	int result = 0;
	// for (int i = 0; i < n; i++)
	// {
	// 	result = max(result, tasks[i]);
	// }
	// cout << result;
	if (n > h)
	{
		cout << -1;
		return -1;
	}
	else if (n == h)
	{
		for (int i = 0; i < n; i++)
		{
			result = max(result, tasks[i]);
		}
		cout << result;
	}
	else
	{
		int result = INT_MAX;
		sort(tasks.begin(), tasks.end());
		for (int i = tasks[0]; i < tasks[tasks.size() - 1]; i++)
		{
			int sum = 0;
			for (int j = 0; j < tasks.size(); j++)
			{
				if (tasks[j] < i)
					sum++;
				else
				{
					for (int k = 1; tasks[j] - k * i > 0; k++)
					{
						sum++;
					}
					sum++;
				}
			}
			// cout << i << " " <<sum << endl;
			if (sum == h)
			{
				result = min(result, i);
			}
		}
		cout << result;
	}
}
#endif
#ifdef Q11
#include <bits/stdc++.h>
using namespace std;

bool check(int k, const vector<int> &tasks, int h)
{
	long long hours = 0; // 防止溢出
	for (int t : tasks)
	{
		hours += (t + k - 1) / k;
		if (hours > h)
			return false;
	}
	return true;
}

int main()
{
	// 处理输入
	int n, h;
	cin >> n;
	vector<int> tasks(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> tasks[i];
	}
	cin >> h;
	// 判断n 与 h大小
	if (n > h)
	{
		cout << -1;
		return 0;
	}
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += tasks[i];
	}
	if (sum <= h)
	{
		cout << 1;
		return 0;
	}
	sort(tasks.begin(), tasks.end());
	int l = 1, r = tasks[n - 1];
	while (l < r)
	{
		int mid = l + (r - l) / 2;
		if (check(mid, tasks, h))
			r = mid;
		else
			l = mid + 1;
		cout << l << " " << r << endl;
	}
	cout << l;
}
#endif
#include <bits\stdc++.h>
using namespace std;
int func(int val, vector<int> nums)
{
	int result = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		int k = 1;
		while (val * k - nums[i] < 0)
			k++;
		result += k;
	}
	return result;
}
int main()
{
	int n, h;
	cin >> n;
	vector<int> nums(n, 0);
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	cin >> h;
	sort(nums.begin(), nums.end());
	int min_val = nums[0];
	int max_val = nums[nums.size() - 1];
	if (n > h)
		return -1;
	else if (n == h)
	{
		cout << max_val;
		return 0;
	}
	int result = INT_MAX;
	for (int j = min_val; j <= max_val; j++)
	{
		int record = func(j, nums);
		if (record <= h)
			result = min(result, j);
	}
	if(result == INT_MAX)
		return -1;
	cout << result;
	return 0;
}