#include <iostream>
#include "vector"
#include "algorithm"

using namespace std;

/*
 * Given a sorted array nums, remove the duplicates
 * in-place such that each element appear only once and return the new length.
 * Do not allocate extra space for another array,
 * you must do this by modifying the input array in-place with O(1) extra memory.
 */

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        return nums.size();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
