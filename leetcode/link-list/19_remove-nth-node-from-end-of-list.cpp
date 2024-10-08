#include "bits/stdc++.h"
#include "ListNode.cpp"
using namespace std;


/**
 * @brief 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
 * 
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *left = head;
        ListNode *right = head;

        while (n--) {
            right = right->next;
        }

        ListNode *pre_front = NULL;

        while (right != NULL) {
            pre_front = left;
            left = left->next;
            right = right->next;
        }

        if (pre_front == NULL) {
            return head->next;
        }
        else {
            pre_front->next = left->next;
            return head;
        }
    }
};