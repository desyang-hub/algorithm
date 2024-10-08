#include "bits/stdc++.h"
#include "ListNode.cpp"
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 * 
 * @brief 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 为了方便可以构建一个虚拟头节点，这样可以方便处理头节点被移除的情况
        ListNode* viausl_head = new ListNode();

        viausl_head->next = head;

        ListNode* pre = viausl_head;
        ListNode* next = NULL;
        while (head != NULL) {
            next = head->next;
            if (head->val == val) { // 需要移除
                pre->next = next;
            }
            else {  // 无需移除
                pre = head;
            }
            head = next;
        }

        head = viausl_head->next;
        // 内存释放
        delete viausl_head;
        return head;
    }
};