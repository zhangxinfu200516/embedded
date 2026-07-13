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

int min_absval = INT_MAX;
int pre_val = -1;
int func4(TreeNode *root)
{
	if (root == NULL)
		return 0;
	func4(root->left);

	if (pre_val != -1)
		min_absval = min(min_absval, abs(root->val - pre_val));
	pre_val = root->val;

	func4(root->right);

	return min_absval;
}
unordered_map<int, int> __map;
void func5(TreeNode *root)
{
	if (root == NULL)
		return;
	func5(root->left);

	__map[root->val]++;

	func5(root->right);
}
vector<int> get_result()
{
	int max_count = 0;
	vector<int> result;
	for (auto it = __map.begin(); it != __map.end(); it++)
	{
		if (it->second > max_count)
		{
			max_count = it->second;
		}
	}
	for (auto it = __map.begin(); it != __map.end(); it++)
	{
		if (it->second == max_count)
			result.push_back(it->first);
	}
	return result;
}

TreeNode *func6(TreeNode *root, TreeNode *p, TreeNode *q)
{
	if (root == NULL)
		return nullptr;
	if (root == p || root == q)
		return root;

	TreeNode *left_result = func6(root->left, p, q);
	TreeNode *right_result = func6(root->right, p, q);

	if (left_result != nullptr && right_result != nullptr)
		return root;
	else if (left_result != nullptr && right_result == nullptr)
		return left_result;
	else if (left_result == nullptr && right_result != nullptr)
		return right_result;

	return nullptr;
}

void func7(TreeNode *root, TreeNode *p, TreeNode *q, TreeNode *&result)
{
	if (root == NULL)
		return;
	if (root->val > p->val && root->val < q->val && result == nullptr)
		result = root;
	func7(root->left, p, q, result);
	func7(root->right, p, q, result);
}
//层序遍历
vector<int> level_order(TreeNode *root)
{
	if(root == NULL)
		return {};
	queue<TreeNode *> q;
	q.push(root);
	vector<int> result;
	while(!q.empty())
	{
		TreeNode *node = q.front();
		q.pop();
		result.push_back(node->val);
		if(node->left)
			q.push(node->left);
		if(node->right)
			q.push(node->right);
	}
	return result;
}
int main()
{
	TreeNode *root = new TreeNode(10);
	root->left = new TreeNode(5);
	root->right = new TreeNode(11);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(8);
	root->right->right = new TreeNode(12);
	root->left->left->left = new TreeNode(1);
	root->left->right->left = new TreeNode(6);
	root->left->right->right = new TreeNode(9);
	vector<int> result = level_order(root);
	for(int i = 0;i<result.size();i++)
		cout<<result[i]<<" ";

}

class Solution
{
public:
	TreeNode *insertIntoBST(TreeNode *root, int val)
	{

		if (val < root->val)
		{
			if (root->left == NULL)
				root->left = new TreeNode(val);
			insertIntoBST(root->left, val);
		}
		else if (val > root->val)
		{
			if (root->right == NULL)
				root->right = new TreeNode(val);
			insertIntoBST(root->right, val);
		}

		return root;
	}
};

class Solution1
{
public:
	TreeNode *insertIntoBST(TreeNode *root, int val)
	{
		if (root == NULL)
			return new TreeNode(val);

		if (val < root->val)
			root->left = insertIntoBST(root->left, val);
		else if (val > root->val)
			root->right = insertIntoBST(root->right, val);
		return root;
	}
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) 
	{
		if(root == NULL)
			return root;
        if(root->val == key)
		{
			if(root->left == NULL && root->right == NULL)
			{
				delete root;
				return NULL;
			}
			else if(root->left != NULL && root->right == NULL)
			{
				auto tmp = root->left;
				delete root;
				return tmp;
			}
			else if(root->left == NULL && root->right != NULL)
			{
				auto tmp = root->right;
				delete root;
				return tmp;
			}
			else 
			{
				TreeNode* tmp = root->right;
				TreeNode* cur = root->right;
				while(cur->left != NULL)
					cur = cur->left;
				cur->left = root->left;
				delete root;
				return tmp;
			}
		}

		if(root->val > key)
		{
			root->left = deleteNode(root->left,key);
		}
		else if(root->val < key)
		{
			root->right = deleteNode(root->right,key);
		}

		return root;
    }
};