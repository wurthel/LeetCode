#include <iostream>
#include "stack"

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
    bool isPalindrome_stack(ListNode *head) {
        stack<ListNode *> stack;
        ListNode *tmp = head;
        while (tmp) {
            stack.push(tmp);
            tmp = tmp->next;
        }

        while (!stack.empty()) {
            if (stack.top()->val != head->val)
                return false;
            stack.pop();
            head = head->next;
        }
        return true;
    }

    bool isPalindrome(ListNode *head) {
        int n = length(head);

        if (n == 1)
            return true;

        ListNode *reverse = nullptr;
        for (int i = 0, s = n / 2; i < s; ++i) {
            reverse = new ListNode(head->val, reverse);
            head = head->next;
        }

        if (n % 2 == 1)
            head = head->next;

        for (int i = n / 2; i > 0; --i) {
            if (head->val != reverse->val)
                return false;
            head = head->next;
            reverse = reverse->next;
        }

        return true;
    }

    int length(ListNode *head) {
        int i = 0;
        while (head) {
            i++;
            head = head->next;
        }

        return i;
    }
};

int main() {
    ListNode *l = new ListNode(1);
    l->next = new ListNode(2);
    l->next->next = new ListNode(2);
    l->next->next->next = new ListNode(1);

    Solution s;
    bool r = s.isPalindrome_stack(l);

    std::cout << r << std::endl;
    return 0;
}
