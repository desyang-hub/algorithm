#include "bits/stdc++.h"
#include "ListNode.cpp"
using namespace std;


/**
 * @brief 给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。
 * 
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode*> ask;
        stack<ListNode*> bsk;

        while (headA != NULL) {
            ask.push(headA);
            headA = headA->next;
        }

        while (headB != NULL) {
            bsk.push(headB);
            headB = headB->next;
        }

        ListNode *intersection_node = NULL;

        while (!ask.empty() && !bsk.empty()) {
            if (ask.top() == bsk.top()) {
                intersection_node = ask.top();
                ask.pop();
                bsk.pop();
            }
            else 
                break;
        }

        return intersection_node;
    }
};