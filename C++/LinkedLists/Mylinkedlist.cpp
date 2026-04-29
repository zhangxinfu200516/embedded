#include <iostream>
using namespace std;

struct LinkNode
{
    int data;
    LinkNode *next;
    LinkNode(int x) : data(x), next(NULL) {}; // 节点的构造函数
};

class MyLinkedList
{
public:
    LinkNode *addAtHead(int val)
    {
        LinkNode *newNode = new LinkNode(val); // 创建新节点
        newNode->next = head;                  // 将新节点的next指向当前头节点
        head = newNode;                        // 更新头节点为新节点
        return head;                           // 返回新的头节点
    };
    LinkNode *addAtTail(int val)
    {
        LinkNode *newNode = new LinkNode(val); // 创建新节点
        if (head == NULL)
        { // 如果链表为空，直接将新节点作为头节点
            head = newNode;
            return head;
        }
        LinkNode *current = head; // 从头节点开始遍历
        while (current->next != NULL)
        { // 找到链表的最后一个节点
            current = current->next;
        }
        current->next = newNode; // 将最后一个节点的next指向新节点
        return head;             // 返回头节点
    };
    int get(int index)
    {
        if (index < 0)
            return -1;            // 如果索引小于0，返回-1表示无效
        LinkNode *current = head; // 从头节点开始遍历
        int list_index = 0;
        while (current->next != NULL)
        {
            if (list_index == index)
            {
                return current->data; // 如果当前索引等于目标索引，返回节点数据}
            }
            current = current->next; // 移动到下一个节点
            list_index++;
        }
        if (index == list_index)
        {
            return current->data;
        }
        else
        {
            return -1; // 如果索引超出链表长度，返回-1表示无效
        }
    };
    LinkNode *addAtIndex(int index, int val)
    {
        // 处理小于等于0的情况
        if (index <= 0)
        {
            addAtHead(val);
        }
        // 处理正常情况
        LinkNode *current = head;
        int now_index = 0;
        index--;
        while (current->next != NULL)
        {
            if (now_index == index)
            {
                LinkNode *newNode = new LinkNode(val); // 创建新节点
                newNode->next = current->next;         // 将新节点的next指向当前节点的下一个节点
                current->next = newNode;               // 将当前节点的next指向新节点
                return head;                           // 返回头节点
            }
            now_index++;
            current = current->next; // 移动到下一个节点
        }
        // 处理等于链表长度的情况
        index++;
        if (index == now_index + 1)
        {
            addAtTail(val);
        }
        return head;
    };
    LinkNode *deleteAtIndex(int index)
    {
        int size = 0;
        LinkNode *current = head;
        index--;
        while (current->next != NULL)
        {
            if(size == index)
            {
                LinkNode *temp = current->next;      // 保存要删除的节点
                current->next = current->next->next; // 删除节点
                delete temp;                         // 释放内存
                return head;                         // 返回头节点
            }
            size++;
            current = current->next;
        }
        return head;
    };
    inline LinkNode *getHead()
    {
        return head; // 返回链表的头节点
    };
protected:
    LinkNode *head = NULL; // 链表的头节点
};

int main(int argc, const char **argv)
{
    MyLinkedList s;
    s.addAtHead(1);
    s.addAtTail(3);
    s.addAtIndex(1, 2); // 链表变为1->2->3
    cout << s.get(1) << endl; // 返回2
    s.deleteAtIndex(1); // 现在链表是1->3
    cout << s.get(1) << endl; // 返回3
    cout << "-----------------" << endl;
    LinkNode*current = s.getHead();
    while(current->next!=NULL)
    {
        cout << current->data << endl;
        current = current->next;
    }
    cout << current->data << endl;
    return 0;
}