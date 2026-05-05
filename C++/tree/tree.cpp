#include <iostream>
#include <vector>
using namespace std;
#define Test1
#ifdef Test1
// 完全二叉数+二叉树数组存储+由底部向上遍历
class Solution
{
public:
	vector<int> Get_Result(vector<int> input, int n)
	{
		int total = (1 << n) - 1;
		while (input.size() <= total)
		{
			input.push_back(-1);
		}
		for (int i = total - 1; i >= 0; i--)
		{
			if (input[i] == -1)
				continue;
			if (i % 2 == 1)
				input[(i - 1) / 2] += input[i];
			else if (i % 2 == 0)
				input[(i - 2) / 2] += input[i];
		}
		while (!input.empty() && input.back() == -1)
			input.pop_back();

		return input;
	}
};
int main()
{
	int n;
	cin >> n;
	vector<int> input;
	int x;
	while (cin >> x)
	{
		input.push_back(x);
		if (cin.peek() == '\n')
			break; // 遇到换行停止
	}
	Solution s;
	vector<int> output = s.Get_Result(input, n);
	for (int i = 0; i < output.size(); i++)
	{
		cout << output[i];
		if (i != output.size() - 1)
			cout << " ";
	}

	return 0;
}
#endif

// struct TreeNode
// {
// 	int val;
// 	TreeNode *left;
// 	TreeNode *right;
// 	TreeNode(int _val) : val(_val), left(NULL), right(NULL) {};
// };

// class Solution
// {
// public:
	
// };
// // #include<iostream>
// using namespace std;
// int main() {
//     int a, b;
//     while (cin >> a >> b) cout << a + b << endl;
// }