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
    ListNode *reverseList(ListNode *head) {
        // iteratively implementation
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = head->next;

        ListNode* tmpNode;
        while(curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            curr = next;
        }

        return prev;
    }
};

int main() {
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);

    node1->next = node2;
    node2->next = node3;

    Solution solution;
    ListNode* node = solution.reverseList(node1);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
