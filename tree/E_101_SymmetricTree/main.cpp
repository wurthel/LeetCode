#include <iostream>
#include <queue>
#include <stack>

using namespace std;

/*
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
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
    bool isSymmetric(TreeNode *root) {
        return isSymmetric_(root, root);
    }

private:
    // recursive solution
    bool isSymmetric_(TreeNode *root1, TreeNode *root2) {
        if (root1 == nullptr && root2 == nullptr) return true;
        if (root1 == nullptr || root2 == nullptr) return false;
        return (root1->val == root2->val &&
                isSymmetric_(root1->left, root2->right) &&
                isSymmetric_(root1->right, root2->left));
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
