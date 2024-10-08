#include "bits/stdc++.h"
#include "ListNode.cpp"
using namespace std;


/**
 * @brief 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 * 
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        ListNode* pre_head = new ListNode();

        pre_head->next = head;
        ListNode* cur = head->next;
        head->next = NULL;

        ListNode* next = NULL;

        while (cur != NULL) {
            next = cur->next;
            cur->next = pre_head->next;
            pre_head->next = cur;
            cur = next;
        }

        return pre_head->next;
    }
};