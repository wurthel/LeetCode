#include <iostream>
#include "vector"
#include "map"
#include "set"

using namespace std;

/*
 * Given a binary tree, return the vertical order traversal of its nodes values.
 * For each node at position (X, Y), its left and right children respectively will be at positions (X-1, Y-1) and
 * (X+1, Y-1).
 *
 * Running a vertical line from X = -infinity to X = +infinity, whenever the vertical line touches some nodes, we report the values of the nodes in order from top to bottom (decreasing Y coordinates).
 *
 * If two nodes have the same position, then the value of the node that is reported first is the value that is smaller.
 *
 * Return an list of non-empty reports in order of X coordinate.  Every report will have a list of values of nodes.
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
    vector<vector<int>> verticalTraversal(TreeNode *root) {
        vector<vector<int>> answer;
        map<int, map<int, multiset<int>>> trav;

        makeMap(root, trav, 0, 0);

        for (const auto &itr1 : trav) {
            vector<int> vec{};
            for (const auto &itr2 : itr1.second)
                for (auto x: itr2.second)
                    vec.push_back(x);
            answer.push_back(vec);
        }

        return answer;

    }

private:
    void makeMap(TreeNode *root, map<int, map<int, multiset<int>>> &trav, int x, int y) {
        if (root == nullptr)
            return;

        trav[x][y].insert(root->val);
        makeMap(root->left, trav, x - 1, y + 1);
        makeMap(root->right, trav, x + 1, y + 1);
    }
};

int main() {
    TreeNode *tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->left->left = new TreeNode(4);
    tree->left->right = new TreeNode(5);
    tree->right = new TreeNode(3);
    tree->right->left = new TreeNode(6);
    tree->right->right = new TreeNode(7);

    Solution solution;
    auto arr = solution.verticalTraversal(tree);

    for (auto x : arr) {
        copy(begin(x), end(x), ostream_iterator<int>{cout, ","});
        cout << "\n";
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
