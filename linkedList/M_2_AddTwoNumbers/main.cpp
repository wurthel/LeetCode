#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *addTwoNumbers_(ListNode *l1, ListNode *l2, int a){
        if (l1 == nullptr && l2 == nullptr && a == 0)
            return nullptr;

        ListNode *l = new ListNode();

        int x = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + a;
        ListNode* next_l1 = l1 ? l1->next : l1;
        ListNode* next_l2 = l2 ? l2->next : l2;

        l->val = x % 10;
        l->next = addTwoNumbers_(next_l1, next_l2, x / 10);

        return l;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        return addTwoNumbers_(l1, l2, 0);
    }
};

int main() {
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution x;
    auto r = x.addTwoNumbers(l1, l2);

    return 0;
}
