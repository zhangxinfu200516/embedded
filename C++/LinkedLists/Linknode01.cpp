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
	ListNode *removeElements(ListNode *head, int val)
	{
		if (head == NULL)
			return head;
		ListNode *cur = head, *pre = NULL;
		while (cur != NULL)
		{
			if (cur->val == val)
			{
				if (cur == head)
					head = cur->next;
				else
					pre->next = cur->next;
			}
			pre = cur;
			cur = cur->next;
		}
		return head;
	}
};
class Solution02
{
public:
	ListNode *reverseList(ListNode *head)
	{
		ListNode *cur = head, *next = NULL, *pre = NULL;
		while (cur)
		{
			next = cur->next;
			if (cur == head)
				cur->next = NULL;
			else
				cur->next = pre;
			pre = cur;
			cur = next;
		}
		return pre;
	}
};
class Solution03
{
public:
	ListNode *removeNthFromEnd(ListNode *head, int n)
	{
		int num = 0;
		ListNode *cur = head, *pre = NULL;
		while (cur)
		{
			num++;
			cur = cur->next;
		}
		int target = num - n;
		cur = head;
		while (target > 0)
		{
			pre = cur;
			cur = cur->next;
			target--;
		}
		if (cur != head)
			pre->next = cur->next;
		else
			head = cur->next;
		return head;
	}
};
class Solution04
{
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
		std::map<ListNode *, int> map;
		ListNode *cur = headA;
		while (cur)
		{
			map[cur]++;
			cur = cur->next;
		}
		cur = headB;
		while (cur)
		{
			map[cur]++;
			cur = cur->next;
		}
		for (auto it = map.begin(); it != map.end(); it++)
		{
			if (it->second >= 2)
				return it->first;
		}
		return NULL;
	}
};
class Solution
{
public:
	ListNode *detectCycle(ListNode *head)
	{
		std::map<ListNode *, int> map;
		ListNode *cur = head;
		while (cur)
		{
			map[cur]++;
			if (map[cur] >= 2)
				return cur;
			cur = cur->next;
		}
		return NULL;
	}
};
int main()
{
}