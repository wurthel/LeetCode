#include <iostream>
#include <vector>
#include "set"

using namespace std;

class Solution {
public:
    void combinationSum2_(set<vector<int>> &ans, vector<int> trace, vector<int> &candidates, int k, int value, int target) {
        if (value == target) {
            ans.insert(trace);
        } else if (value < target) {
            for (int i = k; i < candidates.size(); ++i) {
                int v = candidates[i];
                trace.push_back(v);
                combinationSum2_(ans, trace, candidates, i+1, value + v, target);
                trace.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> helper;
        vector<int> trace;
        sort(candidates.begin(), candidates.end());
        combinationSum2_(helper, trace, candidates, 0, 0, target);

        vector<vector<int>> answer;
        for (auto x: helper)
            answer.push_back(x);

        return answer;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
