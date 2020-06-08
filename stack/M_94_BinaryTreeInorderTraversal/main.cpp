#include <iostream>
#include "vector"
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
    void inorderTraversal_(vector<int> &answer, TreeNode* root){
        // Recursive approach
        if (root == nullptr)
            return;

        inorderTraversal_(answer, root->left);
        answer.push_back(root->val);
        inorderTraversal_(answer, root->right);
    }

    void inorderTraversal2_(vector<int> &answer, TreeNode* root){
        // Using stack
        stack<TreeNode*> stack;
        TreeNode* cur_node;

        while (root != nullptr || !stack.empty()) {
            while (root != nullptr) {
                stack.push(root);
                root = root->left;
            }

            cur_node = stack.top();
            stack.pop();
            answer.push_back(cur_node->val);
            root = cur_node->right;
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer;
        inorderTraversal_(answer, root);

        return answer;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
