#include <iostream>

// Q: Given a complete binary tree, count the number of nodes.

struct TreeNode {
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    int val;
    TreeNode *left;

    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    int countNodes(TreeNode *root) {
        if (root == nullptr)
            return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
