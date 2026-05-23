#include <bits/stdc++.h>
using namespace std;

int main()
{
	// 处理输入
	int n, t;
	cin >> n >> t;
	vector<vector<int>> input(n);
	for (int i = 0; i < n; i++)
	{
		int nums, time, power, k;
		cin >> nums >> time >> power >> k;
		input[i].push_back(nums);
		input[i].push_back(time);
		input[i].push_back(power);
		input[i].push_back(k);
		if (k == 1)
		{
			int kk;
			cin >> kk;
			input[i].push_back(kk);
		}
	}
	// 处理样例1
	bool result = true;
	for (int i = 0; i < n; i++)
	{
		if (input[i][1] > t)
			result &= true;
		else
			result = false;
	}
	if (result == true)
	{
		cout << 0;
		return 0;
	}
	vector<int> dp(t + 1, 0);
	for (int i = 0; i < n; i++)
	{
		for (int j = t; j >= input[i][1]; j--)
		{
			dp[j] = max(dp[j], dp[j - input[i][1]] + input[i][2]);
		}
		// for(int j = 0 ; j< t+1;j++)
		// {
		// 	cout << dp[j] << " ";
		// }
		// cout << endl;
	}
	cout << dp[t];
}