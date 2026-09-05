#include <bits/stdc++.h>
using namespace std;

struct Tree_Node
{
	int val;
	Tree_Node *left;
	Tree_Node *right;
	Tree_Node(int __val) : val(__val), left(NULL), right(NULL) {}
	Tree_Node(int __val, Tree_Node *__left, Tree_Node *__right) : val(__val), left(__left), right(__right) {};
};

Tree_Node *get_Tree(vector<int> &forward, vector<int> &middle)
{
	// 第一步：处理叶子节点时，返回空
	if (forward.size() == 0)
		return NULL;
	// 第二部：找到中间节点
	Tree_Node *root = new Tree_Node(forward[0]);
	if (forward.size() == 1)
		return root;
	// 第二步：在中序中找到中间节点
	int i = 0;
	for (; i < middle.size(); i++)
	{
		if (middle[i] == forward[0])
			break;
	}
	// 第三步：切割中序数组为 左子中序 + 右子中序（规则：左闭右开）
	vector<int> left_middle(middle.begin(), middle.begin() + i);
	vector<int> right_middle(middle.begin() + i + 1, middle.end());

	vector<int> left_forward(forward.begin() + 1, forward.begin() + 1 + i);
	vector<int> right_forward(forward.begin() + 1 + i, forward.end());

	root->left = get_Tree(left_forward, left_middle);
	root->right = get_Tree(right_forward, right_middle);

	return root;
}
void back(Tree_Node *root, vector<int> &result)
{
	if (root == NULL)
		return;
	back(root->left, result);
	back(root->right, result);
	result.push_back(root->val);
}
#ifdef Q1
void func2(Tree_Node *root)
{
	if (root->left == NULL && root->right == NULL)
		return;

	if (root->left != NULL && root->right == NULL)
	{
		root->val += root->left->val;
		if (root->left->left)
			root->left = root->left->left;
		if (root->left->right)
			root->right = root->left->right;
	}
	if (root->right != NULL && root->left == NULL)
	{
		root->val += root->right->val;
		if (root->right->left)
			root->left = root->right->left;
		if (root->right->right)
			root->right = root->right->right;
	}
}
#endif
// 剪枝：删除路径和 ≤ 0 的节点及其子树，返回修剪后的根
Tree_Node *prune(Tree_Node *root, int sumFromParent)
{
	if (!root)
		return nullptr;
	int curSum = sumFromParent + root->val;
	if (curSum <= 0)
	{
		// 删除当前节点及其子树（可递归删除，但本题无内存要求）
		// 这里为了简洁，直接返回空，不再释放内存
		return nullptr;
	}
	root->left = prune(root->left, curSum);
	root->right = prune(root->right, curSum);
	return root;
}
Tree_Node *rule1(Tree_Node *root, int sum)//不可使用引用，这样回导致递归完左子树后，sum没有回溯，污染了右子树的处理
{
	if (root == NULL)
		return NULL;
	sum += root->val;
	if (sum <= 0)
		return NULL;
	root->left = rule1(root->left, sum);
	root->right = rule1(root->right, sum);
	return root;
}
Tree_Node *rule2(Tree_Node *root)
{
	if(root == NULL)
		return NULL;
	if(root->left == NULL && root->right != NULL)
	{
		root->right->val += root->val;
		return rule2(root->right);//在不可直接返回root->right，因为规则要求子树也要合并单节点
	}
	if(root->left != NULL && root->right == NULL)
	{
		root->left->val += root->val;
		return rule2(root->left);////在不可直接返回root->right，因为规则要求子树也要合并单节点
	}
	root->left = rule2(root->left);
	root->right = rule2(root->right);
	return root;
}
void func2(Tree_Node *root)
{
	if (!root)
		return;

	// 后序遍历：先处理左右子树
	func2(root->left);
	func2(root->right);

	// 循环处理当前节点，直到它拥有 0 或 2 个子节点
	if (root->left && !root->right)
	{
		// 只有左孩子
		Tree_Node *child = root->left;
		root->val += child->val;
		root->left = child->left;
		root->right = child->right;
		delete child; // 释放被合并的节点（可选）
	}
	if (!root->left && root->right)
	{
		// 只有右孩子
		Tree_Node *child = root->right;
		root->val += child->val;
		root->right = child->right;
		root->left = child->left;
		delete child;
	}
	// 继续循环，检查合并后是否仍为单子节点
}
int main()
{
	// 处理输入
	int n;
	cin >> n;
	vector<int> forward(n, 0);
	for (int i = 0; i < n; i++)
		cin >> forward[i];
	vector<int> middle(n, 0);
	for (int i = 0; i < n; i++)
		cin >> middle[i];

	// // 前序遍历与中序遍历得到树，并返回根节点
	// Tree_Node *root = new Tree_Node(forward[0]);
	Tree_Node *root = get_Tree(forward, middle);
	int sum = 0;
	// 前序遍历处理规则1
	rule1(root, sum);
	// 后续遍历处理规则2
	rule2(root);
	// 后续遍历输出结果
	vector<int> result;
	back(root, result);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
}

