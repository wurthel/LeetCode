#include <iostream>
#include <vector>

using namespace std;

/*
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
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
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> arr;
        levelOrder_(arr, 1, root);
        return arr;
    }

private:
    void levelOrder_(vector<vector<int>> &arr, int level, TreeNode *root) {
        if (root == nullptr)
            return;

        if (level > arr.size())
            arr.push_back({});

        levelOrder_(arr, level + 1, root->left);
        arr[level - 1].push_back(root->val);
        levelOrder_(arr, level + 1, root->right);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
