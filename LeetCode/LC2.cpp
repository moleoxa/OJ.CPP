#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto head = new ListNode();
        auto pre = head;
        auto cur = head;
        int car = 0;
        while (l1 || l2) {
            if (l1) {
                cur = l1;
                l1 = l1->next;
                if (l2) {
                    cur->val += l2->val;
                    l2 = l2->next;
                }
            } else {
                cur = l2;
                l2 = l2->next;
            }
            cur->val += car;
            car = cur->val / 10;
            cur->val %= 10;
            pre->next = cur;
            pre = cur;
        }
        if (car) {
            pre->next = new ListNode(car);
        }
        return head->next;
    }
};