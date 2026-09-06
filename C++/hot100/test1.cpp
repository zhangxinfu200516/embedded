#include <bits\stdc++.h>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int _val) : val(_val), next(NULL) {};
};
class Solution01
{
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
		map<ListNode *, int> mp;
		ListNode *cur = headA;
		while (cur)
		{
			mp[cur]++;
			cur = cur->next;
		}
		cur = headB;
		while (cur)
		{
			mp[cur]++;
			if (mp[cur] > 1)
				return cur;
			cur = cur->next;
		}
		return NULL;
	}
};
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int _val) : val(_val), left(NULL), right(NULL) {};
};
class Solution
{
public:
	TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
	{
		if (root == NULL || root == q || root == p)
			return root;
		TreeNode *left = lowestCommonAncestor(root->left, p, q);
		TreeNode *right = lowestCommonAncestor(root->right, p, q);
		if (left != NULL && right != NULL)
			return root;
		else if (left == NULL && right != NULL)
			return right;
		else if (left != NULL && right == NULL)
			return left;
		return NULL;
	}
};
int main()
{
}