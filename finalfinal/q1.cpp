#include <bits/stdc++.h>
using namespace std;

#define Q1
#ifdef Q1
struct Tree_Node
{
	int val;
	Tree_Node *left;
	Tree_Node *right;
	Tree_Node(int __val) : val(__val), left(NULL), right(NULL) {}; // 初始化
};

bool Is_true(Tree_Node *left, Tree_Node *right)
{
	if (left == NULL && right == NULL)
		return true;
	else if (left != NULL && right == NULL)
		return false;
	else if (left == NULL && right != NULL)
		return false;
	else if(left->val != right->val)
		return false;
	
	bool result1 = Is_true(left->left, right->right);
	bool result2 = Is_true(left->right, right->left);
	return result1 & result2;
}

int main()
{
	Tree_Node *root = new Tree_Node(1);
	root->left = new Tree_Node(2);
	root->right = new Tree_Node(2);
	root->left->left = new Tree_Node(3);
	root->left->right = new Tree_Node(4);
	root->right->left = new Tree_Node(4);
	//root->right->right = new Tree_Node(3);
	
	bool result = false;
	result = Is_true(root->left, root->right);
	cout << result;
}
#endif
#ifdef Q2
int main()
{
	int n;
	cin >> n;
	vector<int> input(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
	}

	// 处理n = 2
	if (n == 2)
	{
		int result = max(input[0], input[1]);
		cout << result;
		return 0;
	}

	sort(input.begin(), input.end());
	int count = 0;
	int i = 0;
	int result = INT_MAX;
	for (i = 0; i < n; i++)
	{
		result = min(input[i], result);
		if (input[i] > input[i - 1] && i > 0)
		{
			count++;
			if (count == 2)
				break;
		}
	}
	cout << result;
}
#endif