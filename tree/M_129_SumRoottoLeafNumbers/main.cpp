#include <iostream>
#include "math.h"
/*
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 * An example is the root-to-leaf path 1->2->3 which represents the number 123.
 * Find the total sum of all root-to-leaf numbers.
 */

/*
 * Решение:
 * 1. Спускаемся по дереву, передавая текущую сумму
 * 2. Текущую сумму домножаем на 10 и суммируем значение в корне.
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
    int sumNumbers(TreeNode *root) {
        if (root == nullptr)
            return 0;
        return sumNumbers_(root, 0);
    }

private:
    int sumNumbers_(TreeNode *root, int prev) {
        if (root && root->left == nullptr && root->right == nullptr)
            return prev * 10 + root->val;

        int cur = prev * 10 + root->val;
        int l_sum = root->left ? sumNumbers_(root->left, cur) : 0;
        int r_sum = root->right ? sumNumbers_(root->right, cur) : 0;

        return l_sum + r_sum;
    }
};

int main() {
    TreeNode* tree = new TreeNode(4);
    tree->left = new TreeNode(9);
    tree->left->left = new TreeNode(5);
    tree->left->right = new TreeNode(1);
    tree->right = new TreeNode(0);

    Solution solution;
    int answ = solution.sumNumbers(tree);

    std::cout << "Hello, World!" << std::endl;
    std::cout << "Answer: " << answ << std::endl;
    return 0;
}