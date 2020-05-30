#include <iostream>
#include "vector"

using namespace std;

/*
 * Merge k sorted linked lists and return it as one sorted list.
 * Analyze and describe its complexity.
 */

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void mergeKLists_(vector<ListNode *> &lists, ListNode **head) {
        int j = -1;
        for (int i = 0, size = lists.size(); i < size; ++i) {
            if (j == -1 || lists[j] == nullptr || (lists[i] && lists[i]->val < lists[j]->val))
                j = i;
        }

        *head = lists[j];
        if (lists[j] != nullptr) {
            lists[j] = lists[j]->next;
            mergeKLists_(lists, &(*head)->next);
        }
    }

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        merged_ = nullptr;
        if (!lists.empty())
            mergeKLists_(lists, &merged_);
        return merged_;
    }

private:
    ListNode *merged_;
};

int main() {
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    ListNode *l3 = new ListNode(2);
    l3->next = new ListNode(6);

    vector<ListNode *> v = {l1, l2, l3};

    Solution s;
    s.mergeKLists(v);

    return 0;
}
