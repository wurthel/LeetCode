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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode* buffer = new ListNode(0);
        buffer->next = head;

        ListNode* first = buffer;
        ListNode* second = buffer;

        for (size_t i = 0; i < n + 1; ++i)
            first = first->next;

        while (first != nullptr){
            first = first->next;
            second = second->next;
        }

        second->next = second->next->next;

        return head;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
