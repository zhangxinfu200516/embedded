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
class Solution
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
class Solution
{
public:
	ListNode *removeNthFromEnd(ListNode *head, int n)
	{
		int num = 0;
		ListNode *cur = head,*pre = NULL;
		while (cur)
		{
			num++;
			cur = cur->next;
		}
		int target = num - n;
		cur = head;
		while(target > 0)
		{
			pre = cur;
			cur = cur->next;
			target--;
		}
		if(cur != head)
			pre->next = cur->next;
		else 
			head = cur->next;
		return head;
	}
};
int main()
{
}