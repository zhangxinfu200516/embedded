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
class Solution04
{
public:
	ListNode *reverseList(ListNode *head)
	{
		ListNode *cur = head, *pre = NULL, *next = NULL;
		while (cur)
		{
			next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		return pre;
	}
};
class Solution05
{
public:
	ListNode *sortList(ListNode *head)
	{
		vector<int> record;
		ListNode *cur = head;
		while (cur)
		{
			record.push_back(cur->val);
			cur = cur->next;
		}
		if (record.size() == 0)
			return NULL;
		sort(record.begin(), record.end());
		ListNode *new_head = new ListNode(record[0]);
		cur = new_head;
		for (int i = 1; i < record.size(); i++)
		{
			cur->next = new ListNode(record[i]);
			cur = cur->next;
		}
		return new_head;
	}
};
class LRUCache
{
private:
	int capacity_size;
	map<int, int> mp;
	list<pair<int, int>> ls;

public:
	LRUCache(int capacity)
	{
		capacity_size = capacity;
	}

	int get(int key)
	{
		if (mp.find(key) != mp.end())
		{
			auto it = find(ls.begin(), ls.end(), pair(key, mp[key]));
			ls.splice(ls.begin(), ls, it);
			return mp[key];
		}
		return -1;
	}

	void put(int key, int value)
	{
		if (mp.find(key) != mp.end())
		{
			mp[key] = value;
			auto it = find(ls.begin(), ls.end(), pair(key, mp[key]));
			ls.splice(ls.begin(), ls, it);
		}
		mp[key] = value;
		ls.push_front(pair(key, mp[key]));

		if (mp.size() > capacity_size)
		{
			auto it = ls.back();
			mp.erase(it.first);
			ls.pop_back();
		}
	}
};
class Solution06
{
public:
	ListNode *detectCycle(ListNode *head)
	{
		map<ListNode *, int> mp;
		ListNode *cur = head;
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
class Solution07
{
public:
	bool hasCycle(ListNode *head)
	{
		map<ListNode *, int> mp;
		ListNode *cur = head;
		while (cur)
		{
			mp[cur]++;
			if (mp[cur] > 1)
				return true;
			cur = cur->next;
		}
		return false;
	}
};
int main()
{
}