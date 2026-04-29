#include <iostream>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
    ListNode(int x) : data(x), next(NULL) {}; // 节点的构造函数
};
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *dummy = new ListNode(0); // 创建一个虚拟头节点
        dummy->next = head;                // 将虚拟头节点指向原链表的头节点
        ListNode *current = dummy;         // 从虚拟头节点开始遍历链表
        while (current->next != NULL)
        {
            if (current->next->data == val)
            {
                ListNode *temp = current->next;      // 保存要删除的节点
                current->next = current->next->next; // 删除节点
                delete temp;                         // 释放内存
            }
            else
            {
                current = current->next; // 继续遍历
            }
        }
        ListNode *newHead = dummy->next; // 新链表的头节点
        delete dummy;                    // 删除虚拟头节点
        return newHead;
    };

    ListNode *createLinkedList(int arr[], int size)
    {
        if (size == 0)
            return NULL;                       // 如果数组为空，返回NULL
        ListNode *head = new ListNode(arr[0]); // 创建头节点
        ListNode *current = head;              // 当前节点指向头节点
        for (int i = 1; i < size; i++)
        {
            current->next = new ListNode(arr[i]); // 创建新节点并连接
            current = current->next;              // 移动当前节点指针
        }
        return head; // 返回链表头节点
    }
};
int main(int argc, const char **argv)
{

    Solution s;
    ListNode *head = s.createLinkedList(new int[5]{6, 6, 6, 6, 6}, 5);
    ListNode *current = head;
    for (auto i = 0; i < 5; i++)
    {
        /* code */
        cout << current->data << endl;
        current = current->next;
    }
    cout << "-----------------" << endl;
    current = s.removeElements(head, 6);

    if (current == NULL)
    {
        cout << "[]" << endl;
    }
    else
    {
        while (current->next != NULL)
        {
            cout << current->data << endl;
            current = current->next;
        }
    }
    return 0;
}