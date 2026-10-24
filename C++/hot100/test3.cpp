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