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
// 通过后续遍历计算根节点的高度 - 》 得到最大深度
class Solution
{
public:
	int get_maxdepth(TreeNode *root)
	{
		if (root == NULL)
			return 0;
		int left_depth = get_maxdepth(root->left);
		int right_depth = get_maxdepth(root->right);
		int now_maxdepth = max(left_depth, right_depth) + 1;
		return now_maxdepth;
	}
	int maxDepth(TreeNode *root)
	{
		return get_maxdepth(root);
	}
};
// 应用后续遍历 判断是否为二叉平衡树
class Solution
{
public:
	int Get_isBalanced(TreeNode *root, bool &result)
	{
		if (root == NULL)
			return 0;
		int l = Get_isBalanced(root->left, result);
		int r = Get_isBalanced(root->right, result);
		if (abs(l - r) > 1)
			result = false;
		int H = max(l, r) + 1;
		return H;
	}
	bool isBalanced(TreeNode *root)
	{
		bool result = true;
		Get_isBalanced(root, result);
		return result;
	}
};
// 从中序和后续中构造二叉树
class Solution
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
		// 舍弃尾元素
		postorder.resize(postorder.size() - 1);
		//[0,leftInorder.size) [leftInorder.size,end)
		vector<int> leftpostorder(postorder.begin(), postorder.begin() + leftInorder.size());
		vector<int> rightpostorder(postorder.begin() + leftInorder.size(), postorder.end());
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
//判断是否为二叉搜索数：注意定义指针一定要进行初始化
class Solution
{
public:
	TreeNode *searchBST(TreeNode *root, int val)
	{
		if (root == NULL)
			return NULL;
		if (root->val == val)
			return root;

		TreeNode *result = nullptr;
		if (root->left && root->val > val)
		{
			result = searchBST(root->left, val);
		}
		if (root->right && root->val < val)
		{
			result = searchBST(root->right, val);
		}
		return result;
	}
};