#include <iostream>
#include "vector"
#include "set"
#include "stack"

using namespace std;

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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> answer;
        if (root) {
            stack<TreeNode *> parents;
            parents.push(root);
            while (!parents.empty()) {
                TreeNode *top = parents.top();
                answer.push_back(top->val);
                parents.pop();
                if (top->right) parents.push(top->right);
                if (top->left) parents.push(top->left);
            }
        }
        return answer;
    }
};

/*
 * Given a binary tree, return the preorder traversal of its nodes' values.
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 */

int main() {
    TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(-2);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(4);

    Solution solution;
    auto ans = solution.preorderTraversal(root);
    for (auto x: ans)
        cout << x << " ";

    return 0;
}
