#include <iostream>
#include "vector"

using namespace std;

class Solution {
public:
    void combinationSum_(vector<vector<int>> &ans, vector<int> trace, vector<int> &candidates, int k, int value, int target) {
        if (value == target) {
            ans.push_back(trace);
        } else if (value < target) {
            for (int i = k; i < candidates.size(); ++i) {
                int v = candidates[i];
                trace.push_back(v);
                combinationSum_(ans, trace, candidates, i, value + v, target);
                trace.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> trace;
        combinationSum_(answer, trace, candidates, 0, 0, target);
        return answer;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
