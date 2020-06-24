#include <iostream>
#include "vector"

using namespace std;

// Given an array, rotate the array to the right by k steps, where k is non-negative.

/*
 * This approach is based on the fact that when we rotate the array k times,
 * k elements from the back end of the array come to the front and the rest of the elements
 * from the front shift backwards.
 *
 * In this approach, we firstly reverse all the elements of the array.
 * Then, reversing the first k elements followed by reversing the rest n − k elements gives us the required result.
 *
 * Let n = 7 and k = 3.
 *
 * Original List                   : 1 2 3 4 5 6 7
 * After reversing all numbers     : 7 6 5 4 3 2 1
 * After reversing first k numbers : 5 6 7 4 3 2 1
 * After revering last n-k numbers : 5 6 7 1 2 3 4 --> Result
 */

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
