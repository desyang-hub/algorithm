#include "bits/stdc++.h"
#include "ListNode.cpp"
using namespace std;


/**
 * @brief 你可以选择使用单链表或者双链表，设计并实现自己的链表。

单链表中的节点应该具备两个属性：val 和 next 。val 是当前节点的值，next 是指向下一个节点的指针/引用。

如果是双向链表，则还需要属性 prev 以指示链表中的上一个节点。假设链表中的所有节点下标从 0 开始。

实现 MyLinkedList 类：

MyLinkedList() 初始化 MyLinkedList 对象。
int get(int index) 获取链表中下标为 index 的节点的值。如果下标无效，则返回 -1 。
void addAtHead(int val) 将一个值为 val 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。
void addAtTail(int val) 将一个值为 val 的节点追加到链表中作为链表的最后一个元素。
void addAtIndex(int index, int val) 将一个值为 val 的节点插入到链表中下标为 index 的节点之前。如果 index 等于链表的长度，那么该节点会被追加到链表的末尾。如果 index 比长度更大，该节点将 不会插入 到链表中。
void deleteAtIndex(int index) 如果下标有效，则删除链表中下标为 index 的节点。
 * 
 */
class MyLinkedList {
private:
    int length;
    ListNode* pre_head = NULL;
    ListNode* tail = NULL;
public:
    MyLinkedList() {
        pre_head = new ListNode();
        length = 0;
    }
    
    int get(int index) {
        if (index < 0 || index >= length) {
            return -1;
        }
        
        ListNode *cur = pre_head->next;
        while (index--) {
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        ListNode* build_node = new ListNode(val);
        ListNode* next = pre_head->next;

        pre_head->next = build_node;
        build_node->next = next;
        if (tail == NULL) {
            tail = build_node;
        }
        ++length;
    }
    
    void addAtTail(int val) {
        if (tail == NULL) {
            addAtHead(val);
        }
        else {
            ListNode* build_node = new ListNode(val);

            tail->next = build_node;
            tail = build_node;
            ++length;
        }
    }
    
    void addAtIndex(int index, int val) {
        if (index > length || index < 0) {
            return;
        }
        if (index == 0) {
            addAtHead(val);
            return;
        }
        if (index == length) {
            addAtTail(val);
            return;
        }
        ListNode* build_node = new ListNode(val);

        ListNode* cur = pre_head->next;
        ListNode* pre = pre_head;

        while (index--) {
            pre = cur;
            cur = cur->next;
        }

        pre->next = build_node;
        build_node->next = cur;
        ++length;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= length) {
            return;
        }

        int index_copy = index;

        ListNode* cur = pre_head->next;
        ListNode* pre = pre_head;
        while (index--) {
            pre = cur;
            cur = cur->next;
        }

        ListNode* next = cur->next;
        delete cur; // 内存释放
        pre->next = next;
        if (index_copy == length - 1) { // 删除的是tail
            if (index_copy == 0) {
                tail = NULL;
            }
            else {
                tail = pre;
            }
            
        }
        --length;
    }

    int size() {
        return length;
    }

    friend ostream& operator<<(ostream &out, MyLinkedList &list) {
        int size = list.size();
        out << size;
        out << '[';
        for (int i = 0; i < size; ++i) {
            if (i == 0) {
                out << list.get(i);
            }
            else {
                out << ", " << list.get(i);
            }
        }
        out << ']';
        return out;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */