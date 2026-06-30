#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int __val) : val(__val), left(NULL), right(NULL) {};
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
		if (root == NULL)
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

class Solution
{
public:
	bool Is_True(TreeNode *left,TreeNode *right )
	{
		if(left == NULL && right == NULL)
			return true;
		else if(left != NULL && right == NULL)
			return false;
		else if(left == NULL && right != NULL)
			return false;
		else if(left->val != right->val)
			return false;
		
		bool result1 = Is_True(left->left,right->right);
		bool result2 = Is_True(left->right,right->left);
		return result1 & result2;

	}
	bool isSymmetric(TreeNode *root)
	{
		return Is_True(root->left,root->right);
	}
};