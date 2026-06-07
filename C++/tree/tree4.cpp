#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int __val) : val(__val), left(NULL), right(NULL) {}; // 初始化
};
class Solution
{
public:
	vector<int> result;
	void get_preorderTraversal(TreeNode *root)
	{
		if (root == NULL)
		{
			return;
		}
		result.push_back(root->val);
		get_preorderTraversal(root->left);
		get_preorderTraversal(root->right);
	}
	vector<int> preorderTraversal(TreeNode *root)
	{
		get_preorderTraversal(root);
		return result;
	}
};
class Solution
{
public:
	void Get_invertTree(TreeNode *root)
	{
		if(root == NULL)
		{
			return;
		}
		swap(root->left, root->right);
		Get_invertTree(root->left);
		Get_invertTree(root->right);
	}
	TreeNode *invertTree(TreeNode *root)
	{
		Get_invertTree(root);
		return root;
	}
};