#include <iostream>

/*
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 * Assume a BST is defined as follows:
 *      The left subtree of a node contains only nodes with keys less than the node's key.
 *      The right subtree of a node contains only nodes with keys greater than the node's key.
 *      Both the left and right subtrees must also be binary search trees.
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
    bool isValidBST(TreeNode *root) {
        return isValidBST_(root, nullptr, nullptr);
    }

private:
    bool isValidBST_(TreeNode *root, TreeNode *lower_bound, TreeNode *upper_bound) {
        if (!root)
            return true;

        if (lower_bound && root->val <= lower_bound->val)
            return false;
        if (upper_bound && root->val >= upper_bound->val)
            return false;

        return isValidBST_(root->left, lower_bound, root) && isValidBST_(root->right, root, upper_bound);
    }

};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
