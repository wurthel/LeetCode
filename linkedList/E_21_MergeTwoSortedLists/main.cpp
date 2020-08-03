#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *answer = new ListNode(0);
        ListNode *pointer = answer;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                pointer->next = l1;
                l1 = l1->next;
            } else {
                pointer->next = l2;
                l2 = l2->next;
            }
            pointer = pointer->next;
        }
        pointer->next = l1 ? l1 : l2;

        return answer->next;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
