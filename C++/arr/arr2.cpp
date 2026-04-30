#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int result = INT_MAX;
	int n, m, sum = 0;
	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			sum += arr[i][j];
		}
	}

	int sum_x = 0; // 计算横向
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			sum_x += arr[i][j];
			if (j == m - 1)
				result = min(result, abs(sum - sum_x - sum_x));
		}
	}

	int sum_y = 0;
	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < n; i++)
		{
			sum_y += arr[i][j];
			if (i == n - 1)
				result = min(result, abs(sum - sum_y - sum_y));
		}
	}

	cout << result << endl;
}
