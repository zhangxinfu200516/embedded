#include <bits/stdc++.h>
using namespace std;

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
	for (int i = 0; i < n; i++)
	{
		result = max(result, tasks[i]);
	}
	cout << result;
	// if (n > h)
	// {
	// 	cout << -1;
	// 	return -1;
	// }
	// else if (n == h)
	// {
	// 	for (int i = 0; i < n; i++)
	// 	{
	// 		result = max(result, tasks[i]);
	// 	}
	// 	cout << result;
	// }
	// else
	// {
	// int result = INT_MAX;
	// sort(tasks.begin(), tasks.end());
	// for (int i = tasks[0]; i < tasks[tasks.size() - 1]; i++)
	// {
	// 	int sum = 0;
	// 	for (int j = 0; j < tasks.size(); j++)
	// 	{
	// 		if (tasks[j] < i)
	// 			sum++;
	// 		else
	// 		{
	// 			for (int k = 1; tasks[j] - k * i > 0; k++)
	// 			{
	// 				sum++;
	// 			}
	// 			sum++;
	// 		}
	// 	}
	// 	//cout << i << " " <<sum << endl;
	// 	if (sum == h)
	// 	{
	// 		result = min(result, i);
	// 	}
	// }
	// cout << result;
	// }
}