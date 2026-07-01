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

class Solution
{
public:
	// 递归翻转二叉树
	void get_result(TreeNode *root)
	{
		if (root == NULL)
			return;
		// 交换左右子树
		swap(root->left, root->right);
		// 递归处理左右子树
		get_result(root->left);
		get_result(root->right);
	}

	TreeNode *invertTree(TreeNode *root)
	{
		get_result(root);
		return root;
	}
};

int main()
{
	// 创建测试二叉树: [4,2,7,1,3,6,9]
	TreeNode *root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->right = new TreeNode(7);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(9);

	Solution s;
	TreeNode *inverted = s.invertTree(root);

	// 输出翻转后的结果
	cout << inverted->val << endl;
	cout << inverted->left->val << " " << inverted->right->val << endl;
	cout << inverted->left->left->val << " " << inverted->left->right->val << " ";
	cout << inverted->right->left->val << " " << inverted->right->right->val << endl;

	return 0;
}

class Solution1
{
public:
	bool istrue(TreeNode *left, TreeNode *right)
	{
		if (left == NULL && right == NULL)
			return true;
		else if (left != NULL && right == NULL)
			return false;
		else if (left == NULL && right != NULL)
			return false;
		else if (left->val != right->val)
			return false;

		bool result1 = istrue(left->left, right->right);
		bool result2 = istrue(left->right, right->left);
		return result1 & result2;
	}

	bool isSymmetric(TreeNode *root)
	{
		return istrue(root->left, root->right);
	}
};
class Solution2
{
public:
	int maxDepth(TreeNode *root)
	{
		if (root == NULL)
			return 0;
		int left_depth = maxDepth(root->left);
		int right_depth = maxDepth(root->right);
		return max(left_depth, right_depth) + 1;
	}
};
class Solution3
{
public:
	int result = 0;
	void get_depth(int &depth, TreeNode *root)
	{
		result = max(result, depth);
		if (root->left == NULL && root->right == NULL)
			return;
		if (root->left != NULL)
		{
			depth++;
			get_depth(depth, root->left);
			depth--;
		}
		if (root->right != NULL)
		{
			depth++;
			get_depth(depth, root->right);
			depth--;
		}
	}
	int maxDepth(TreeNode *root)
	{
		int depth = 1;
		get_depth(depth, root);
		return result;
	}
};
class Solution4
{
public:
	int minDepth(TreeNode *root)
	{
		if (root == NULL)
			return 0;
		int left_depth = minDepth(root->left);
		int right_depth = minDepth(root->right);
		if (root->left == NULL && root->right != NULL)
			return right_depth + 1;
		if (root->left != NULL && root->right == NULL)
			return left_depth + 1;
		return min(left_depth, right_depth) + 1;
	}
};
class Solution5
{
public:
	int result = INT_MAX;
	void get_result(int &depth, TreeNode *root)
	{
		if (root == NULL)
			return;
		if (root->left == NULL && root->right == NULL)
		{
			result = min(result, depth);
			return;
		}
		if (root->left != NULL)
		{
			depth++;
			get_result(depth, root->left);
			depth--;
		}
		if (root->right != NULL)
		{
			depth++;
			get_result(depth, root->right);
			depth--;
		}
	}
	int minDepth(TreeNode *root)
	{
		int depth = 1;
		get_result(depth, root);
		return result;
	}
};
class Solution6
{
public:
	int result = 0;
	void get_result(TreeNode *root)
	{
		if (root == NULL)
			return;
		result++;
		get_result(root->left);
		get_result(root->right);
	}
	int countNodes(TreeNode *root)
	{
		get_result(root);
		return result;
	}
};
class Solution7
{
public:
	bool result = true;
	int get_depth(TreeNode *root)
	{
		if (root == NULL)
			return 0;
		int left_depth = get_depth(root->left);
		int right_depth = get_depth(root->right);
		if (abs(left_depth - right_depth) > 1)
			result = false;
		return max(left_depth, right_depth) + 1;
	}
	bool isBalanced(TreeNode *root)
	{
		get_depth(root);
		return result;
	}
};
class Solution7
{
public:
	vector<string> result;
	string path;
	void get_result(TreeNode *root)
	{

		// path += to_string(root->val);
		if (root->left == NULL && root->right == NULL)
		{
			result.push_back(path);
			return;
		}
		// path += "->";
		if (root->left != NULL)
		{
			path += "->";
			path += to_string(root->left->val);
			get_result(root->left);
			// path.erase(path.size() - 2, 2);
			path.pop_back();
		}
		if (root->right != NULL)
		{
			path += "->";
			path += to_string(root->right->val);
			get_result(root->right);
			// path.erase(path.size() - 2, 2);
			path.pop_back();
		}
	}
	vector<string> binaryTreePaths(TreeNode *root)
	{
		if (root == NULL)
			return result;
		path += to_string(root->val);
		// path += "->";
		get_result(root);
		return result;
	}
};
class Solution8
{
public:
	vector<string> result;
	string path;
	void get_result(string path, vector<string> &result, TreeNode *root)
	{
		path += to_string(root->val);
		if (root->left == NULL && root->right == NULL)
		{
			result.push_back(path);
			return;
		}
		if (root->left != NULL)
		{
			path += "->";
			get_result(path, result, root->left);
			path.pop_back();
			path.pop_back();
		}
		if (root->right != NULL)
		{
			path += "->";
			get_result(path, result, root->right);
			path.pop_back();
			path.pop_back();
		}
	}

	vector<string> binaryTreePaths(TreeNode *root)
	{
		if (root == NULL)
			return result;
		get_result(path, result, root);
		return result;
	}
};
class Solution9
{
public:
	int result = 0;
	void get_result(TreeNode *root)
	{
		if (root == NULL)
			return;
		if (root->left != NULL && root->left->left == NULL && root->left->right == NULL)
		{
			result += root->left->val;
		}
		get_result(root->left);
		get_result(root->right);
	}
	int sumOfLeftLeaves(TreeNode *root)
	{
		get_result(root);
		return result;
	}
};
class Solution10
{
public:
	vector<vector<int>> result;
	int findBottomLeftValue(TreeNode *root)
	{
		queue<TreeNode *> que;
		que.push(root);
		while (!que.empty())
		{
			vector<int> path;
			int size = que.size();
			for (int i = 0; i < size; i++)
			{
				TreeNode *node = que.front();
				que.pop();
				path.push_back(node->val);
				if (node->left != NULL)
					que.push(node->left);
				if (node->right != NULL)
					que.push(node->right);
			}
			result.push_back(path);
		}
		return result[result.size() - 1][0];
	}
};
class Solution11
{
public:
	int result = 0;
	int depth_max = -INT_MAX;
	int depth_now = 1;
	void get_value(TreeNode *root)
	{
		if (root == NULL)
			return;
		if (depth_now > depth_max && root->left == NULL && root->right == NULL)
		{
			result = root->val;
			depth_max = depth_now;
		}
		if (root->left != NULL)
		{
			depth_now++;
			get_value(root->left);
			depth_now--;
		}
		if (root->right != NULL)
		{
			depth_now++;
			get_value(root->right);
			depth_now--;
		}
	}
	int findBottomLeftValue(TreeNode *root)
	{
		get_value(root);
		return result;
	}
};
class Solution12
{
public:
	int sum = 0;
	bool get_result(TreeNode *root, int targetSum)
	{

		if (root == NULL)
			return false;

		if (sum == targetSum && root->left == NULL && root->right == NULL)
			return true;
		if (root->left != NULL)
		{
			sum += root->left->val;
			if (get_result(root->left, targetSum))
				return true;
			sum -= root->left->val;
		}
		if (root->right != NULL)
		{
			sum += root->right->val;
			if (get_result(root->right, targetSum))
				return true;
			sum -= root->right->val;
		}

		return false;
	}
	bool hasPathSum(TreeNode *root, int targetSum)
	{
		if (root == NULL)
			return false;
		sum += root->val;
		return get_result(root, targetSum);
	}
};
class Solution13
{
public:
	vector<vector<int>> result;
	vector<int> path;
	// int sum = 0;
	void func(TreeNode *root, int targetSum, int &sum)
	{
		if (root == NULL)
			return;

		if (sum == targetSum && root->left == NULL && root->right == NULL)
		{
			result.push_back(path);
			return;
		}
		if (root->left != NULL)
		{
			sum += root->left->val;
			path.push_back(root->left->val);
			func(root->left, targetSum, sum);
			sum -= root->left->val;
			path.pop_back();
		}
		if (root->right != NULL)
		{
			sum += root->right->val;
			path.push_back(root->right->val);
			func(root->right, targetSum, sum);
			sum -= root->right->val;
			path.pop_back();
		}
	}
	vector<vector<int>> pathSum(TreeNode *root, int targetSum)
	{
		if (root == NULL)
			return result;
		int sum = root->val;
		path.push_back(root->val);
		func(root, targetSum, sum);
		return result;
	}
};
class Solution14
{
public:
	vector<vector<int>> result;
	vector<int> path;
	void func(TreeNode *root, int targetSum, int &sum)
	{
		if (root == NULL)
			return;

		sum += root->val;
		path.push_back(root->val);

		if (sum == targetSum && root->left == NULL && root->right == NULL)
		{
			result.push_back(path);
			return;
		}
		if (root->left != NULL)
		{
			func(root->left, targetSum, sum);
			sum -= root->left->val;
			path.pop_back();
		}
		if (root->right != NULL)
		{
			func(root->right, targetSum, sum);
			sum -= root->right->val;
			path.pop_back();
		}
	}
	vector<vector<int>> pathSum(TreeNode *root, int targetSum)
	{
		if (root == NULL)
			return result;
		int sum = 0;
		func(root, targetSum, sum);
		return result;
	}
};
class Solution15
{
public:
	TreeNode *func(vector<int> &inorder, vector<int> &postorder)
	{
		// 添加终止条件
		if (inorder.empty() || postorder.empty())
			return nullptr;

		int root_val = postorder.back();
		TreeNode *root = new TreeNode(root_val);
		int root_index = 0;
		for (int i = 0; i < inorder.size(); ++i)
		{
			if (inorder[i] == root_val)
			{
				root_index = i;
				break;
			}
		}

		vector<int> left_inorder(inorder.begin(), inorder.begin() + root_index);
		vector<int> right_inorder(inorder.begin() + root_index + 1, inorder.end());
		vector<int> left_postorder(postorder.begin(), postorder.begin() + left_inorder.size());
		vector<int> right_postorder(postorder.begin() + left_inorder.size(), postorder.end() - 1);

		root->left = func(left_inorder, left_postorder);
		root->right = func(right_inorder, right_postorder);
		return root;
	}
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
	{
		return func(inorder, postorder);
	}
};
class Solution16
{
public:
	TreeNode *constructMaximumBinaryTree(vector<int> &nums)
	{
		if(nums.empty())
			return nullptr;
		
		int max_val = 0;
		int max_index = 0;
		for(int i = 0; i < nums.size(); i++)
		{
			if(nums[i] > max_val)
			{
				max_index = i;
				max_val = nums[i];
			}
		}
		TreeNode *root = new TreeNode(max_val);

		if(max_index > 0)
		{
			vector<int> left_nums(nums.begin(), nums.begin() + max_index);
			root->left = constructMaximumBinaryTree(left_nums);
		}
		if(max_index < nums.size() - 1)
		{
			vector<int> right_nums(nums.begin() + max_index + 1, nums.end());
			root->right = constructMaximumBinaryTree(right_nums);
		}
		return root;
	}
};
class Solution {
public:
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
		if(root1 == NULL && root2 == NULL)
			return nullptr;
		if(root1 == NULL && root2 != NULL)
			return root2;
		if(root1 != NULL && root2 == NULL)
			return root1;
		root1->val += root2->val;

		root1->left = mergeTrees(root1->left, root2->left);
		root1->right = mergeTrees(root1->right, root2->right);

		return root1;
    }
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {

		if(root == NULL)
			return nullptr;
		if(val == root->val)
			return root;
		else if(val < root->val)
		{
			return searchBST(root->left, val);
		}
        else 
		{
			return searchBST(root->right, val);
		}

		return nullptr;
    }
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        
		if(root == NULL || (root->left == NULL && root->right == NULL))
			return true;
		

		if(root->left != NULL)
		{
			if(root->left->val >= root->val)
				return false;
			if(!isValidBST(root->left))
				return false;
		}

		if(root->right != NULL)
		{
			if(root->right->val <= root->val)
				return false;
			if(!isValidBST(root->right))
				return false;
		}

		return true;

    }
};