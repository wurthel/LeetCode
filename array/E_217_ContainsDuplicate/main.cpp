#include <iostream>
#include "algorithm"
#include "vector"
#include "unordered_set"

using namespace std;

/*
 * Given an array of integers, find if the array contains any duplicates.
 * Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
 */

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_set<int> helper;
        for (int x: nums) {
            if (helper.find(x) != end(helper))
                return true;
            helper.insert(x);
        }
        return false;
    }
};

int main() {
    vector<int> arr{1, 2, 3, 1};
    Solution solution;

    bool ans{solution.containsDuplicate(arr)};

    std::cout << boolalpha << ans << std::endl;

    return 0;
}
