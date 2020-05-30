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
    ListNode *oddEvenList(ListNode *head) {
        if (head == nullptr)
            return head;

        ListNode *even = head;
        ListNode *odd_head = head->next;
        ListNode *odd = odd_head;

        while (odd && odd->next) {
            even->next = even->next->next;
            odd->next = odd->next->next;
            even = even->next;
            odd = even->next;
        }

        even->next = odd_head;

        return head;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
