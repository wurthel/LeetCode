#include <iostream>
#include "vector"
#include "set"

using namespace std;

class Solution {
public:
    void
    permuteUnique_(set<vector<int>> &ans, vector<int> &nums, vector<int>::iterator itr, vector<int>::iterator end) {
        if (itr == end) {
            ans.insert(nums);
            return;
        }

        for (auto i = itr; i != end; ++i) {
            if (i != itr && *i == *itr)
                continue;
            swap(*itr, *i);
            permuteUnique_(ans, nums, next(itr), end);
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums) {
        set<vector<int>> helper;
        permuteUnique_(helper, nums, nums.begin(), nums.end());

        vector<vector<int>> answer(helper.size());
        move(helper.begin(), helper.end(), answer.begin());

        return answer;
    }
};

int main() {
    Solution solution;
    vector<int> vec = {1, 1, 2};

    vector<vector<int>> res = solution.permuteUnique(vec);

    for (auto xs : res) {
        for (auto x : xs)
            std::cout << x << " ";
        std::cout << std::endl;
    }

    return 0;
}
