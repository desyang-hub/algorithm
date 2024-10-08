#include "bits/stdc++.h"
using namespace std;

// 单链表结构体
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
