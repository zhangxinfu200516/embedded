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
class Solution02
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
class Solution03
{
public:
	bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
	{
		map<int, int> mp;
		for (int i = 0; i < prerequisites.size(); i++)
			mp[prerequisites[i][0]] = prerequisites[i][1];
		for (int i = 0; i < prerequisites.size(); i++)
		{
			int target = prerequisites[i][1];
			while (mp.find(target) != mp.end())
			{
				if (mp[target] == prerequisites[i][0])
					return false;
				target = mp[target];
			}
		}
		return true;
	}
};
class Solution
{
public:
	ListNode *reverseList(ListNode *head)
	{
		ListNode *cur = head, *pre = NULL, *next = NULL;
		while(cur)
		{
			next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		return pre;
	}
};
int main()
{
}