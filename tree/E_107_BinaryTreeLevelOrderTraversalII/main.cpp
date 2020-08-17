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
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> arr;
        levelOrderBottom_(arr, 0, root);
        reverse(arr.begin(), arr.end());
        return arr;
    }

private:
    void levelOrderBottom_(vector<vector<int>> &arr, int level, TreeNode *root) {
        if (root == nullptr)
            return;

        if (level + 1 > arr.size())
            arr.emplace_back();

        levelOrderBottom_(arr, level + 1, root->left);
        arr[level].push_back(root->val);
        levelOrderBottom_(arr, level + 1, root->right);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
