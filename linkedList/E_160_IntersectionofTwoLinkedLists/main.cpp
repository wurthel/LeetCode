#include <iostream>
#include "unordered_set"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
        /* В этом решении мы обходим по каждому листу, замыкаясь
         * на соседних листах.
         * Пример:
         * l1 = 1 2 5 /0
         * l2 = 2 5 /0
         * Как сопоставляются элементы
         * 1 2  5 /0 2
         * 2 5 /0  1 2
         * Другими словами мы просто смещаем два листа относительно друг
         * друга по горизонтали.
        */
        ListNode *nextA = headA;
        ListNode *nextB = headB;
        while (nextA != nextB) {
            nextA = nextA ? nextA->next : headB;
            nextB = nextB ? nextB->next : headA;
        }
        return nextA;
    }

    /* Другая имплементация с использованием хэш-таблиц.
     * Мы запоминаем все адреса одного из листо, а потом пробегаемся
     * по другому листу и ищем совпадение адресов.
     */
    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> nodes;

        ListNode *itr = headA;
        while (itr) {
            nodes.insert(itr);
            itr = itr->next;
        }

        itr = headB;
        while (itr) {
            if (nodes.find(itr) != nodes.end())
                return itr;
            itr = itr->next;
        }

        return nullptr;
    }
};


int main() {
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(5);

    ListNode *l2 = new ListNode(2);
    l2->next = new ListNode(5);

    Solution s;
    ListNode *r1 = s.getIntersectionNode1(l1, l2);
    ListNode *r2 = s.getIntersectionNode2(l1, l2);
    std::cout << 0 << std::endl;
    return 0;
}
