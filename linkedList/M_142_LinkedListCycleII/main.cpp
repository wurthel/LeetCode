#include <iostream>
#include "unordered_set"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> nodes;

        ListNode* itr = head;
        while (itr){
            if (nodes.find(itr) == nodes.end())
                nodes.insert(itr);
            else
                return itr;
            itr = itr->next;
        }

        return nullptr;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
