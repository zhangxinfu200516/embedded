#include <bits\stdc++.h>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution01
{
public:
	ListNode *reverseList(ListNode *head)
	{
		ListNode *now = head, *pre = NULL;
		while (now)
		{
			ListNode *record = now->next;
			now->next = pre;
			pre = now;
			now = record;
		}
		return pre;
	}
};

class Solution02
{
public:
	ListNode *detectCycle(ListNode *head)
	{
		ListNode *fast = head, *slow = head;
		while (1)
		{
			if (fast && fast->next)
			{
				fast = fast->next->next;
				slow = slow->next;
				if (fast == slow)
					break;
			}
			else
				return NULL;
		}
		fast = head;
		while (fast != slow)
		{
			fast = fast->next;
			slow = slow->next;
		}
		return fast;
	}
};

class Solution03
{
public:
	ListNode *swapPairs(ListNode *head)
	{
		ListNode *newHead = new ListNode(-1), *pre = newHead;
		newHead->next = head;
		while (pre->next && pre->next->next)
		{
			ListNode *first = pre->next;
			ListNode *second = pre->next->next;
			first->next = second->next;
			second->next = first;
			pre->next = second;
			pre = first;
		}
		return newHead->next;
	}
};

class Solution04
{
public:
	ListNode *reverseKGroup(ListNode *head, int k)
	{
		vector<int> nums;
		ListNode *cur = head;
		while (cur)
		{
			nums.push_back(cur->val);
			cur = cur->next;
		}
		int start = 0, end = k - 1;
		while (end < nums.size())
		{
			for (int i = start, j = end; i < j; i++, j--)
				swap(nums[i], nums[j]);
			start += k;
			end += k;
		}
		ListNode *newhead = new ListNode(nums[0]);
		cur = newhead;
		for (int i = 1; i < nums.size(); i++)
		{
			cur->next = new ListNode(nums[i]);
			cur = cur->next;
		}
		return newhead;
	}
};

// Definition for a Node.
class Node
{
public:
	int val;
	Node *next;
	Node *random;

	Node(int _val)
	{
		val = _val;
		next = NULL;
		random = NULL;
	}
};

class Solution05
{
public:
	Node *copyRandomList(Node *head)
	{
		unordered_map<Node *, Node *> umap;
		Node *cur = head;
		while (cur)
		{
			umap[cur] = new Node(cur->val);
			cur = cur->next;
		}
		cur = head;
		while (cur)
		{
			if (cur->next)
				umap[cur]->next = umap[cur->next];
			if (cur->random)
				umap[cur]->random = umap[cur->random];
			cur = cur->next;
		}
		return umap[head];
	}
};

class LRUCache
{
private:
	int maxCapacity;
	list<pair<int, int>> ls;
	unordered_map<int, list<pair<int, int>>::iterator> umap;

public:
	LRUCache(int capacity)
	{
		maxCapacity = capacity;
	}

	int get(int key)
	{
		if (umap.find(key) == umap.end())
			return -1;
		ls.splice(ls.begin(), ls, umap[key]);
		return umap[key]->second;
	}

	void put(int key, int value)
	{
		if (umap.find(key) != umap.end())
		{
			umap[key]->second = value;
			ls.splice(ls.begin(), ls, umap[key]);
			return;
		}
		ls.push_front({key, value});
		umap[key] = ls.begin();
		if (ls.size() > maxCapacity)
		{
			umap.erase(ls.back().first);
			ls.pop_back();
		}
	}
};