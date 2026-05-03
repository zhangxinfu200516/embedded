#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution1
{
public:
	TreeNode *getTree(vector<int> &inorder, vector<int> &postorder)
	{
		// 1.如果后续数组不为空的话查找后序数组 得到root
		if (postorder.size() == 0)
			return nullptr;

		int rootvalue = postorder[postorder.size() - 1];
		TreeNode *node = new TreeNode(rootvalue); // root

		if (inorder.size() == 1)
			return node;
		// 2.在中序数组中找到root
		int i = 0; // root索引值delimiterIndex
		for (i = 0; i < inorder.size(); i++)
		{
			if (inorder[i] == node->val)
				break;
		}
		// 3.分割中序数组为左子中序、右子中序
		// 按照左闭右开分割[0，i) 与 [i+1,end)
		vector<int> leftInorder(inorder.begin(), inorder.begin() + i);
		vector<int> rightInorder(inorder.begin() + i + 1, inorder.end());
		// 4.切割后续数组为左、右
		postorder.resize(postorder.size() - 1);
		//[0,leftInorder.size) [leftInorder.size,end)
		vector<int> leftpostorder(postorder.begin(), postorder.begin() + leftInorder.size());
		vector<int> rightpostorder(postorder.begin() + leftInorder.size(), postorder.end());
		// 以下为日志
		cout << "----------" << endl;

		cout << "leftInorder :";
		for (int i : leftInorder)
		{
			cout << i << " ";
		}
		cout << endl;

		cout << "rightInorder :";
		for (int i : rightInorder)
		{
			cout << i << " ";
		}
		cout << endl;

		cout << "leftPostorder :";
		for (int i : leftpostorder)
		{
			cout << i << " ";
		}
		cout << endl;
		cout << "rightPostorder :";
		for (int i : rightpostorder)
		{
			cout << i << " ";
		}
		cout << endl;

		// 5.递归处理左区间与右区间
		node->left = getTree(leftInorder, leftpostorder);
		node->right = getTree(rightInorder, rightpostorder);

		return node;
	}
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
	{
		if (inorder.size() == 0 || postorder.size() == 0)
			return {};
		else
			return getTree(inorder, postorder);
	}
};
class Solution2
{
public:
	TreeNode *get_Tree(vector<int> &nums)
	{
		if (nums.size() == 0)
			return {};
		int max = -INT_MAX;
		int index = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] > max)
			{
				max = nums[i];
				index = i;
			}
		}
		TreeNode *root = new TreeNode(max);
		if (nums.size() == 1)
			return root;
		// 分割[0,i) & [i+1,end)
		vector<int> left(nums.begin(), nums.begin() + index);
		vector<int> right(nums.begin() + index + 1, nums.end());
		root->left = get_Tree(left);
		root->right = get_Tree(right);

		return root;
	}
	TreeNode *constructMaximumBinaryTree(vector<int> &nums)
	{
		return get_Tree(nums);
	}
};
class Solution
{
public:
	TreeNode *get_mergeTrees(TreeNode *root1, TreeNode *root2)
	{
		TreeNode *root;
		if (root1 == nullptr && root2 == nullptr)
			return nullptr;
		else if (root1 != nullptr && root2 == nullptr)
			return root1;
		else if (root1 == nullptr && root2 != nullptr)
			return root2;
		int value = root1->val + root2->val;
		root = new TreeNode(value);

		root->left = get_mergeTrees(root1->left, root2->left);
		root->right = get_mergeTrees(root1->right, root2->right);

		return root;
	}
	TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
	{
		return get_mergeTrees(root1, root2);
	}
};
class Solution
{
public:
	TreeNode *searchBST(TreeNode *root, int val)
	{
		if (root == nullptr || root->val == val)
			return root;

		TreeNode *result = nullptr;

		if (root->left != nullptr && root->val > val)
			result = searchBST(root->left, val);
		else if (root->right != nullptr && root->val < val)
			result = searchBST(root->right, val);

		return result;
	}
};
class Solution
{
public:
	bool isValidBST(TreeNode *root)
	{
		if (root->left && root->left->val > root->val)
			return false;
		if (root->right && root->right->val < root->val)
			return false;
		return true;
		bool result1 = false, result2 = false;
		if (root->left)
			result1 = isValidBST(root->left);
		if (root->right)
			result2 = isValidBST(root->right);
		return result1 & result2;
	}
};
int main()
{
	// vector<int> inorder = {9, 3, 15, 20, 7};
	// vector<int> postorder = {9, 15, 7, 20, 3};
	// Solution s;
	// s.buildTree(inorder, postorder);
}