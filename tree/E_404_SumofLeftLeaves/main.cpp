

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
    int sumOfLeftLeaves(TreeNode *root) {
        int sum{0};
        sumOfLeftLeaves_(root, sum, false);
        return sum;
    }

    void sumOfLeftLeaves_(TreeNode *root, int &sum, bool is_left) {
        if (!root) return;
        if (!root->left && !root->right && is_left) sum += root->val;
        sumOfLeftLeaves_(root->left, sum, true);
        sumOfLeftLeaves_(root->right, sum, false);
    }
};