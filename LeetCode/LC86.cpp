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
    ListNode* partition(ListNode* head, int x) {
        auto L = new ListNode();
        auto R = new ListNode();
        auto l = L;
        auto r = R;
        while (head) {
            if (head->val < x) {
                l->next = head;
                l = l->next;
            } else {
                r->next = head;
                r = r->next;
            }
            head = head->next;
        }
        // r->next = nullptr;
        l->next = R->next;
        return L->next;
    }
};