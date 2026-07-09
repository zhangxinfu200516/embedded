#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void Get_depth(TreeNode *root, int val, int &depth, int &result)
{
	if (root == NULL)
		return;

	if (root->val == val)
	{
		result = depth;
		return;
	}

	if (root->left)
	{
		depth++;
		Get_depth(root->left, val, depth, result);
		depth--;
	}
	if (root->right)
	{
		depth++;
		Get_depth(root->right, val, depth, result);
		depth--;
	}
}
void Get_node(TreeNode *root, int val, TreeNode *&node)
{
	if (root == NULL)
		return;
	if (root->left)
	{
		if (root->left->val == val)
			node = root;
		Get_node(root->left, val, node);
	}
	if (root->right)
	{
		if (root->right->val == val)
			node = root;
		Get_node(root->right, val, node);
	}
}
int main01()
{
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);

	int depth = 1;
	int result = 0;
	Get_depth(root, 5, depth, result);
	cout << depth << endl;
	cout << result << endl;

	TreeNode *node = nullptr;
	Get_node(root, 5, node);
	if (node != nullptr)
		cout << node->val << endl;
}

bool func2(TreeNode *root)
{
	if (root == NULL)
		return true;

	if (root->left)
	{
		if (root->val < root->left->val)
			return false;
		if (func2(root->left) == false)
			return false;
	}
	if (root->right)
	{
		if (root->val > root->right->val)
			return false;
		if (func2(root->right) == false)
			return false;
	}

	return true;
}

int max_val = INT_MIN;
bool func3(TreeNode *root)
{
	if (root == NULL)
		return true;

	bool left_result = func3(root->left);

	if (root->val < max_val)
		return false;
	else
		max_val = root->val;

	bool right_result = func3(root->right);

	return left_result & right_result;
}
int main()
{
	TreeNode *root = new TreeNode(5);
	root->left = new TreeNode(1);
	root->right = new TreeNode(7);
	root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(8);
	cout << func3(root) << endl;
}