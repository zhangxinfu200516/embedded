#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution1
{
public:
	void digui_qianxu(TreeNode *root, vector<int> &result)
	{
		if (root == NULL)
			return;
		result.push_back(root->val);
		digui_qianxu(root->left, result);
		digui_qianxu(root->right, result);
	}
	void digui_zhongxu(TreeNode *root, vector<int> &result)
	{
		if (root == NULL)
			return;
		digui_zhongxu(root->left, result);
		result.push_back(root->val);
		digui_zhongxu(root->right, result);
	}
	void digui_houxu(TreeNode *root, vector<int> &result)
	{
		if (root == NULL)
			return;
		digui_houxu(root->left, result);
		digui_houxu(root->right, result);
		result.push_back(root->val);
	}
	vector<int> preorderTraversal(TreeNode *root)
	{
		vector<int> result;
		digui_houxu(root, result);
		return result;
	}
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution2
{
public:
	vector<int> preorderTraversal(TreeNode *root)
	{
		vector<int> result;
		stack<TreeNode *> tree_stack;

		if (root == NULL)
			return {};
		tree_stack.push(root);
		while (!tree_stack.empty())
		{
			TreeNode *node = tree_stack.top();
			tree_stack.pop();
			result.push_back(node->val);
			if (node->right)
				tree_stack.push(node->right);
			if (node->left)
				tree_stack.push(node->left);
		}
		return result;
	}
};
class Solution3
{
public:
	vector<int> inorderTraversal(TreeNode *root)
	{
		vector<int> result;
		stack<TreeNode *> st;
		if (root == NULL)
			return {};
		// st.push(root);
		TreeNode *cur = root;
		while (cur != NULL || !st.empty())
		{
			if (cur != NULL)
			{
				st.push(cur); // 压栈
				cur = cur->left;
			}
			else
			{
				TreeNode *tmp = st.top();
				st.pop();
				result.push_back(tmp->val);
				cur = tmp->right;
			}
		}
		return result;
	}
};
class Solution4
{
public:
	void inorder(TreeNode *root, vector<int> &arr)
	{
		if (root == NULL)
			return;
		inorder(root->left, arr);
		arr.push_back(root->val);
		inorder(root->right, arr);
	}
	vector<int> inorderTraversal(TreeNode *root)
	{
		vector<int> result;
		inorder(root, result);
		return result;
	}
};
class Solution5
{
public:
	vector<vector<int>> levelOrder(TreeNode *root)
	{
		vector<vector<int>> final_result;
		queue<TreeNode *> q;
		vector<int> result;
		if (root == nullptr)
			return final_result;
		q.push(root);
		while (!q.empty())
		{
			int size = q.size();
			// vector<int> result;
			for (int i = 0; i < size; i++)
			{
				TreeNode *cur = q.front();
				q.pop();
				result.push_back(cur->val);
				if (cur->left)
					q.push(cur->left);
				if (cur->right)
					q.push(cur->right);
			}
			final_result.push_back(result);
		}
		return final_result;
	}
};
class Solution6
{
public:
	vector<vector<int>> levelOrderBottom(TreeNode *root)
	{
		vector<vector<int>> final_result;
		queue<TreeNode *> que;
		if (root != nullptr)
			que.push(root);
		while (!que.empty())
		{
			int size = que.size();
			vector<int> result;
			for (int i = 0; i < size; i++)
			{
				TreeNode *cur = que.front();
				que.pop();
				result.push_back(cur->val);
				if (cur->left)
					que.push(cur->left);
				if (cur->right)
					que.push(cur->right);
			}
			final_result.push_back(result);
		}

		// int size = final_result.size();
		// int count = size / 2;
		// for (int i = 0; i < count; i++)
		// {
		// 	swap(final_result[i], final_result[size - 1 - i]);
		// }
		reverse(final_result.begin(), final_result.end());
		return final_result;
	}
};
class Solution7
{
public:
	vector<int> rightSideView(TreeNode *root)
	{
		vector<vector<int>> final_result;
		queue<TreeNode *> que;
		if (root != nullptr)
			que.push(root);
		while (!que.empty())
		{
			int size = que.size();
			vector<int> result;
			for (int i = 0; i < size; i++)
			{
				TreeNode *cur = que.front();
				que.pop();
				result.push_back(cur->val);
				if (cur->left)
					que.push(cur->left);
				if (cur->right)
					que.push(cur->right);
			}
			final_result.push_back(result);
		}
		vector<int> result; //
		int size = final_result.size();
		if (root != nullptr)
		{
			for (int i = 0; i < size; i++)
			{
				int cur_size = final_result[i].size();
				result.push_back(final_result[i][cur_size - 1]);
			}
		}
		return result;
	}
};
// // Definition for a Node.
// class Node
// {
// public:
// 	int val;
// 	vector<Node *> children;

// 	Node() {}

// 	Node(int _val)
// 	{
// 		val = _val;
// 	}

// 	Node(int _val, vector<Node *> _children)
// 	{
// 		val = _val;
// 		children = _children;
// 	}
// };
// class Solution8
// {
// public:
// 	vector<vector<int>> levelOrder(Node *root)
// 	{
// 		vector<vector<int>> final_result;
// 		queue<Node *> que;
// 		if (root != nullptr)
// 			que.push(root);
// 		while (!que.empty())
// 		{
// 			int size = que.size();
// 			vector<int> result;
// 			for (int i = 0; i < size; i++)
// 			{
// 				Node *cur = que.front();
// 				que.pop();
// 				result.push_back(cur->val);
// 				for (int j = 0; j < cur->children.size(); j++)
// 				{
// 					que.push(cur->children[j]);
// 				}
// 			}
// 			final_result.push_back(result);
// 		}
// 		return final_result;
// 	}
// };
class Solution9
{
public:
	vector<int> largestValues(TreeNode *root)
	{
		// vector<vector<int>> final_result;
		queue<TreeNode *> que;
		vector<int> result;
		if (root != nullptr)
			que.push(root);
		while (!que.empty())
		{
			int size = que.size();
			// vector<int> result;
			int max_val = -INT_MAX;
			for (int i = 0; i < size; i++)
			{
				TreeNode *cur = que.front();
				que.pop();
				// result.push_back(cur->val);
				if (cur->left)
					que.push(cur->left);
				if (cur->right)
					que.push(cur->right);

				max_val = (max_val != INT_MAX) ? max(cur->val, max_val) : INT_MAX;
				if (i == size - 1)
					result.push_back(max_val);
			}
			// final_result.push_back(result);
		}
		return result;
	}
};
// class Node
// {
// public:
// 	int val;
// 	Node *left;
// 	Node *right;
// 	Node *next;

// 	Node() : val(0), left(NULL), right(NULL), next(NULL) {}

// 	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

// 	Node(int _val, Node *_left, Node *_right, Node *_next)
// 		: val(_val), left(_left), right(_right), next(_next) {}
// };
// class Solution
// {
// public:
// 	Node *connect(Node *root)
// 	{
// 		queue<Node *> que;
// 		if (root == nullptr)
// 			return {};
// 		que.push(root);
// 		while (!que.empty())
// 		{
// 			int size = que.size();
// 			Node *now_node;
// 			Node *Pre_node;
// 			for (int i = 0; i < size; i++)
// 			{
// 				// Node *it = que.front();
// 				// que.pop();
// 				if (i == 0)//在第一次的时候做特殊处理
// 				{
// 					Pre_node = que.front();
// 					que.pop();
// 					now_node = Pre_node;
// 				}
// 				else
// 				{
// 					now_node = que.front();
// 					que.pop();
// 					Pre_node->next = now_node;
// 					Pre_node = now_node;
// 				}

// 				if (now_node->left)
// 					que.push(now_node->left);
// 				if (now_node->right)
// 					que.push(now_node->right);
// 			}
// 		}
// 		return root;
// 	}
// };

// struct TreeNode
// {
// 	int val;
// 	TreeNode *left;
// 	TreeNode *right;
// 	TreeNode() : val(0), left(nullptr), right(nullptr) {}
// 	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// 	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

// class Solution
// {
// public:
// 	int minDepth(TreeNode *root)
// 	{
// 		queue<TreeNode *> que;
// 		if (root == nullptr)
// 			return 0;
// 		que.push(root);
// 		int depth = 0;
// 		int min_depth = INT_MAX;
// 		while (!que.empty())
// 		{
// 			depth++;
// 			int size = que.size();
// 			for (int i = 0; i < size; i++)
// 			{
// 				TreeNode *it = que.front();
// 				que.pop();

// 				if (it->left)
// 					que.push(it->left);
// 				else if (it->right)
// 					que.push(it->right);
// 				else
// 				{
// 					min_depth = min(min_depth,depth);
// 					min_depth = min_depth != INT_MAX ? min_depth : INT_MAX;
// 				}
// 			}
// 		}
// 		return min_depth;
// 	}
// };

// struct TreeNode
// {
// 	int val;
// 	TreeNode *left;
// 	TreeNode *right;
// 	TreeNode() : val(0), left(nullptr), right(nullptr) {}
// 	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// 	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

// class Solution
// {
// public:
// 	void invert(TreeNode *root)
// 	{
// 		if(root == nullptr)
// 			return;
// 		swap(root->left,root->right);
// 		invert(root->left);
// 		invert(root->right);
// 	}
// 	TreeNode *invertTree(TreeNode *root)
// 	{
// 		invert(root);
// 		return root;
// 	}
// };

// Definition for a Node.
// class Node
// {
// public:
// 	int val;
// 	vector<Node *> children;

// 	Node() {}

// 	Node(int _val)
// 	{
// 		val = _val;
// 	}

// 	Node(int _val, vector<Node *> _children)
// 	{
// 		val = _val;
// 		children = _children;
// 	}
// };

// class Solution10
// {
// public:
// 	void pre(Node *root, vector<int> &result)
// 	{
// 		if (root == nullptr)
// 			return;
// 		result.push_back(root->val);
// 		for (int i = 0; i < root->children.size(); i++)
// 		{
// 			pre(root->children[i], result);
// 		}
// 	}
// 	vector<int> preorder(Node *root)
// 	{
// 		vector<int> result;
// 		pre(root, result);
// 		return result;
// 	}
// };
// class Solution
// {
// public:
// 	void post(Node *root, vector<int> &result)
// 	{
// 		if (root == nullptr)
// 			return;
// 		for (int i = 0; i < root->children.size(); i++)
// 		{
// 			post(root->children[i], result);
// 		}
// 		result.push_back(root->val);
// 	}
// 	vector<int> postorder(Node *root)
// 	{
// 		vector<int> result;
// 		post(root, result);
// 		return result;
// 	}
// };

// * Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
	bool sSymme(TreeNode *left, TreeNode *right)
	{
		// 排除空
		if (left == nullptr && right == nullptr)
			return true;
		else if (left == nullptr && right != nullptr)
			return false;
		else if (left != nullptr && right == nullptr)
			return false;
		else if (left->val != right->val)
			return false;
		// 单次递归
		bool result1 = sSymme(left->left, right->right);
		bool result2 = sSymme(left->right, right->left);
		return result1 & result2;
	}
	bool isSymmetric(TreeNode *root)
	{
		return sSymme(root->left, root->right);
	}
};
class Solution
{
public:
	void count(TreeNode *root, int &num)
	{
		// 条件
		if (root == nullptr)
			return;
		// 单次递归
		num++;
		count(root->left, num);
		count(root->right, num);
	}
	int countNodes(TreeNode *root)
	{
		int num = 0;
		count(root, num);
		return num;
	}
};
class Solution
{
public:
	int get_height(TreeNode *root) //-1代表孩子已不是平衡二叉树
	{
		// 条件
		if (root == nullptr)
			return 0;
		// 单次迭代
		int sum1 = get_height(root->left);
		if (sum1 == -1)
			return -1;
		int sum2 = get_height(root->right);
		if (sum2 == -1)
			return -1;
		if (abs(sum2 - sum1) > 1)
			return -1;
		else
		{
			return 1 + max(sum1, sum2);
		}
	}
	bool isBalanced(TreeNode *root)
	{
		return get_height(root) == -1 ? false : true;
	}
};