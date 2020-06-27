#include <iostream>
#include <vector>

using namespace std;

/*
 * Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree in which
 * the depth of the two subtrees of every node never differ by more than 1.
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
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return sortedArrayToBST_(nums, 0, nums.size());
    }

private:
    TreeNode *sortedArrayToBST_(vector<int> &nums, int begin, int end) {
        if (begin >= end)
            return nullptr;

        int middle_idx = (begin + end) / 2;
        TreeNode *root = new TreeNode(nums[middle_idx]);

        root->left = sortedArrayToBST_(nums, begin, middle_idx);
        root->right = sortedArrayToBST_(nums, middle_idx + 1, end);

        return root;
    }
};

int main() {
    vector<int> arr = {-10, -3, 0, 5, 9};

    Solution solution;
    solution.sortedArrayToBST(arr);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
