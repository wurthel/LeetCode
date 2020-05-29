#include "iostream"

/*
 * Reservoir sampling («резервуарная выборка», нет устоявшегося русского перевода)
 * представляет собой семейство вероятностных алгоритмов произвольного выбора из спика S
 * размера n, где n -- очень большое неизвестное число.
 * Обычно n достаточно велико, в результате чего весь список не умещается в памяти.
 *
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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode *head) {
        main_ = head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        ListNode* helper = main_;
        ListNode* itr = main_->next;
        int i = 2;
        while (itr){
            int r = rand() % i; // get random r in the range 0 to (i - 1)
            if (r == 0) // or 1
                helper = itr;
            itr = itr->next;
            i++;
        }

        return helper->val;
    }

private:
    ListNode* main_;
};

int main() {
    std::cout << rand() % 5 << std::endl;
    return 0;
}
