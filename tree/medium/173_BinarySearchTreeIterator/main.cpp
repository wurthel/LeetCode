#include <iostream>
#include "stack"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        fillStack(root);
    }

    /** @return the next smallest number */
    int next() {
        int top = st.top();
        st.pop();
        return top;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return not st.empty();
    }

    void fillStack(TreeNode *root) {
        if (root != nullptr){
            fillStack(root->right);
            st.push(root->val);
            fillStack(root->left);
        }
    }

private:
    std::stack<int> st;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
