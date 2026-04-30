#include <iostream>
#include <vector>
using namespace std;
// 双指针法解决区间和问题
int main()
{
#ifdef NORMOL
	// 初始化
	int arr[5] = {5, 1, 2, 3, 4};
	int left = 1, right = 4;
	int i, j, sum = 0;
	int length = 5;
	for (j = 0; j < length; j++)
	{
		if (j == left)
			i = j;
		else if (j == right)
		{
			while (i <= j)
			{
				sum += arr[i];
				i++;
			}
			cout << sum << endl;
			return 0;
		}
	}
#endif
	// // 暴力解法：时间复杂度：O(m * n)
	// int n, a, b;
	// cin >> n;
	// vector<int> arr(n);
	// for (int k = 0; k < n; k++)
	// {
	// 	cin >> arr[k];
	// }
	// // 计算
	// while (cin >> a >> b)
	// {
	// 	int i, j, sum = 0;
	// 	for (i = a; i <= b; i++)
	// 		sum+=arr[i];
	// 	cout << sum << endl;
	// }
	int n, a, b, sum,record_sum = 0;
	cin >> n;
	vector<int> arr(n);//前缀和
	vector<int> p(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		record_sum += arr[i];
		p[i] = record_sum;
		//cout << p[i] << endl;
	}
	while (cin >> a >> b)//时间复杂度O(1)
	{
		if (a == 0)
			sum = p[b];
		else
			sum = p[b] - p[a - 1];
		cout << sum << endl;
	}
}