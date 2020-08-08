#include <iostream>
#include "unordered_set"

using namespace std;
/*
 * You are given a binary tree in which each node contains an integer value.
 *
 * Find the number of paths that sum to a given value.
 *
 * The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).
 *
 * The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.
 */

/* Логика:
 * Спускаемся вниз по дереву из произвольной ноды до тех пор, пока не наберется необходимая сумма.
 * Если мы преодолели значение суммы, то вниз спускаться нет необходимости -- обход закончен.
 * Если мы набрали нужную сумму, но не достигли листьев, то внось запускаем процедуру поиска.
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
    int pathSum(TreeNode *root, int sum) {
        int answer{0};

        if (root) {
            pathSum_(root, answer, sum, 0);
            answer += pathSum(root->left, sum);
            answer += pathSum(root->right, sum);
        }

        return answer;
    }

private:
    void pathSum_(TreeNode *root, int &result, int sum, int cur_val) {
        if (root != nullptr) {
            int new_val{cur_val + root->val};

            if (new_val == sum)
                result++;

            pathSum_(root->left, result, sum, new_val);
            pathSum_(root->right, result, sum, new_val);
        }
    }
};

int main() {
    TreeNode *node = new TreeNode(1);
    node->right = new TreeNode(2);
    node->right->right = new TreeNode(3);
    node->right->right->right = new TreeNode(4);
    node->right->right->right->right = new TreeNode(5);

    Solution solution;
    std::cout << solution.pathSum(node, 3);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
