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
        bool flag = true;

        if (root && root->left) {
            if (root->val < root->left->val || isValidBST(root->left) == false)
                flag = false;
        }

        if (flag && root && root->right) {
            if (root->val > root->right->val || isValidBST(root->right) == false)
                flag = false;
        }

        return flag;
    }

private:

};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
