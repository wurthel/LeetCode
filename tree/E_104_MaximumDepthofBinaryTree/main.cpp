#include <iostream>

// Given a binary tree, find its maximum depth.


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
    int maxDepth(TreeNode *root) {
        if (root)
            return 1 + max(maxDepth(root->left), maxDepth(root->right));
        else
            return 0;
    }
//private:
//    int maxDepth_(TreeNode* root, int counter) {
//        if (root == nullptr)
//            return 0;
//        else
//            return 1 + max(maxDepth_(root->left), maxDepth_(root->right));
//    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
