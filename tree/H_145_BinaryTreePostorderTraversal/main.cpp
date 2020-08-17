#include <iostream>
#include "vector"
#include "stack"

using namespace std;

/*
 * Given a binary tree, return the postorder traversal of its nodes' values.
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        // Аналогично preoder, только порядок надо инвертировать.
        // По сути postorder симметричен preorder.
        deque<int> danswer;
        if (root) {
            stack<TreeNode *> parents;
            parents.push(root);
            while (!parents.empty()) {
                TreeNode *top = parents.top();
                danswer.push_front(top->val);
                parents.pop();
                if (top->left) parents.push(top->left);
                if (top->right) parents.push(top->right);
            }
        }
        vector<int> vanswer;
        copy(danswer.begin(), danswer.end(), back_inserter(vanswer));

        return vanswer;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
