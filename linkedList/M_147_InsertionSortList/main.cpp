#include <iostream>

/*
 * Sort a linked list using insertion sort.
 *
 * Algorithm of Insertion Sort:
 * 1. Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
 * 2. At each iteration, insertion sort removes one element from the input data, finds the location
 *    it belongs within the sorted list, and inserts it there.
 * 3. It repeats until no input elements remain.
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
    ListNode *insertionSortList(ListNode *head) {
        if (head == nullptr)
            return head;

        ListNode *helper = new ListNode(INT_MIN);
        while (head) {
            ListNode *itr_node = helper;
            while (itr_node->next && head->val > itr_node->next->val)
                itr_node = itr_node->next;
            ListNode * next = head->next;
            head->next = itr_node->next;
            itr_node->next = head;
            head = next;
        }
        return helper->next;
    }
};

int main() {
    ListNode* l1 = new ListNode(4);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(1);
    ListNode* l4 = new ListNode(3);

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;

    Solution s;
    auto p = s.insertionSortList(l1);


    std::cout << p->val << std::endl;
    return 0;
}
