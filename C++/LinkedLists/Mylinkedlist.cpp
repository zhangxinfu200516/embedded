#include <iostream>
using namespace std;

#ifdef MyLinkedList
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
            if (size == index)
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
    s.addAtIndex(1, 2);       // 链表变为1->2->3
    cout << s.get(1) << endl; // 返回2
    s.deleteAtIndex(1);       // 现在链表是1->3
    cout << s.get(1) << endl; // 返回3
    cout << "-----------------" << endl;
    LinkNode *current = s.getHead();
    while (current->next != NULL)
    {
        cout << current->data << endl;
        current = current->next;
    }
    cout << current->data << endl;
    return 0;
}
#endif
class MyLinkedList
{
public:
    struct LinkNode
    {
        int val;
        LinkNode *next;
        LinkNode(int _val) : val(_val), next(NULL) {}
    };

    MyLinkedList()
    {
        __dummyHead = new LinkNode(0); // 初始化虚拟头节点
        size = 0;                      // 初始化真实链表长度
    }

    int get(int index)
    {
        if (index < 0 || index > size - 1)
            return -1;

        if (size == 0)
            return NULL;

        LinkNode *cur_node = __dummyHead->next;
        while (index--)
        {
            cur_node = cur_node->next;
        }
        return cur_node->val;
    }

    void addAtHead(int val)
    {
        LinkNode *new_node = new LinkNode(val);
        new_node->next = __dummyHead->next;
        __dummyHead->next = new_node;
        size++;
    }

    void addAtTail(int val)
    {
        LinkNode *new_node = new LinkNode(val);
        LinkNode *cur_node = __dummyHead;
        while (cur_node->next != NULL) // 已找到尾节点
        {
            cur_node = cur_node->next;
        }
        cur_node->next = new_node;
        size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index > size)
            return;
        if (index < 0)
            return addAtHead(val);
        if (index == size)
            return addAtTail(val);

        LinkNode *new_node = new LinkNode(val);
        LinkNode *cur_node = __dummyHead;
        while (index--)
        {
            cur_node = cur_node->next;
        }
        new_node->next = cur_node->next;
        cur_node->next = new_node;
        size++;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index > size - 1 || size == 0)
            return;

        LinkNode *cur_node = __dummyHead;
        while (index--)
        {
            cur_node = cur_node->next;
        }
        LinkNode *del_node = cur_node->next;
        cur_node->next = cur_node->next->next;
        delete del_node;
        del_node = nullptr;
        size--;
    }

    void PrintLinkList()
    {
        LinkNode *cur_node = __dummyHead;
        while(cur_node->next!=NULL)
        {
            cout << cur_node->next->val << endl;
            cur_node = cur_node->next;
        }
        cout << "---------------------" << endl;
    }
protected:
    LinkNode *__dummyHead; // 定义虚拟头节点
    int size;
};
int main()
{
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(1);
    obj->PrintLinkList();
    obj->addAtTail(3);
    obj->PrintLinkList();
    obj->addAtIndex(1,2);
    obj->PrintLinkList();
    // obj->get(1);
    // obj->PrintLinkList();
    obj->deleteAtIndex(1);
    obj->PrintLinkList();

}

    /**
     * Your MyLinkedList object will be instantiated and called as such:
     * MyLinkedList* obj = new MyLinkedList();
     * int param_1 = obj->get(index);
     * obj->addAtHead(val);
     * obj->addAtTail(val);
     * obj->addAtIndex(index,val);
     * obj->deleteAtIndex(index);
     */
