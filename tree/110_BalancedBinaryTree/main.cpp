#include <iostream>
#include "algorithm"
#include "tuple"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int Deepth(TreeNode *node) {
    if (node == nullptr)
        return 0;
    else
        return 1 + std::max(Deepth(node->left), Deepth(node->right));

}

bool isBalanced(TreeNode *root) {
    if (root == nullptr)
        return true;
    else {
        int l = Deepth(root->left);
        int r = Deepth(root->right);
        return abs(l - r) <= 1 and isBalanced(root->left) and isBalanced(root->right);
    }
}

int main() {
    return 0;
}
