#include <iostream>
#include "algorithm"
#include "vector"

using namespace std;

class Solution {
public:
    void permute_(vector<vector<int>> &ans, vector<int> &nums, vector<int>::iterator itr, vector<int>::iterator end) {
        if (itr == end) {
            ans.push_back(nums);
            return;
        }

        for(auto i = itr; i != end; ++i){
            swap(*itr, *i);
            permute2_(ans, nums, next(itr), end);
            swap(*itr, *i);
        }
    }

    vector<vector<int>> permute2(vector<int> &nums) {
        vector<vector<int>> answer;
        permute_(answer, nums, nums.begin(), nums.end());

        return answer;
    }

};

int main() {
    vector<int> v = {1,2,3};
    Solution s;
    s.permute(v);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
