#include <bits\stdc++.h>
using namespace std;
class Solution01
{
public:
	int removeElement(vector<int> &nums, int val)
	{
		int i, j = 0;
		for (i = 0; i < nums.size(); i++)
		{
			if (nums[i] != val)
			{
				nums[j] = nums[i];
				j++;
			}
			i++;
		}
		return j;
	}
};
class Solution02
{
public:
	void reverseString(vector<char> &s)
	{
		for (int i = 0, j = s.size() - 1; i < j; i++, j--)
		{
			swap(s[i], s[j]);
		}
	}
};
class Solution03
{
public:
	std::string normalizeSpacesOnly(const std::string &s)
	{
		std::string result;
		bool inWord = false;
		bool spaceAdded = false;

		for (char ch : s)
		{
			if (ch == ' ')
			{
				if (inWord)
				{
					spaceAdded = true; // 标记需要在单词后加空格
				}
			}
			else
			{
				if (spaceAdded)
				{
					result.push_back(' ');
					spaceAdded = false;
				}
				result.push_back(ch);
				inWord = true;
			}
		}
		return result;
	}
	string reverseWords(string s)
	{
		s = normalizeSpacesOnly(s);
		vector<string> record;
		int last_index = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == ' ')
			{
				string tmp = s.substr(last_index, i - last_index);
				record.push_back(tmp);
				last_index = i + 1;
			}
			else if (i == s.size() - 1)
			{
				string tmp = s.substr(last_index, i - last_index + 1);
				record.push_back(tmp);
			}
		}
		string result;
		for (int j = record.size() - 1; j >= 0; j--)
		{
			result += record[j];
			if (j != 0)
				result += ' ';
		}
		return result;
	}
};

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {};
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution04
{
public:
	ListNode *reverseList(ListNode *head)
	{

		vector<int> record;
		while (head != NULL)
		{
			record.push_back(head->val);
			head = head->next;
		}
		if (record.empty())
			return nullptr;
		ListNode *new_head = new ListNode(record[record.size() - 1]);
		ListNode *cur = new_head;
		for (int i = record.size() - 2; i >= 0; i--)
		{
			cur->next = new ListNode(record[i]);
			cur = cur->next;
		}
		return new_head;
	}
};
class Solution
{
public:
	ListNode *reverseList(ListNode *head)
	{
		ListNode *cur = head, *pre = NULL, *temp = NULL;
		while(cur)
		{
			temp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = temp;
		}
		return pre;
	}
};
int main()
{
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	Solution s;
	vector<int> record;
	while (head != NULL)
	{
		record.push_back(head->val);
		head = head->next;
	}
	for (int i = 0; i < record.size(); i++)
	{
		cout << record[i] << " ";
	}
	return 0;
}