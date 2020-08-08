#include <iostream>
#include "vector"

using namespace std;

/*
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
 */

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int helper1 = nums.size();
        int helper2 {0};
        for (int i = 0; i < nums.size(); ++i) {
            helper1 += i;
            helper2 += nums[i];
        }
        return helper1 - helper2;
    }

    // using bit manipulation
    // XOR:
    // 0 ^ 0 = 0
    // 0 ^ 1 = 1
    // 1 ^ 0 = 1
    // 1 ^ 1 = 0
    int missingNumber2(vector<int>& nums) {
        int answer = nums.size();

        for (int i = 0; i < nums.size(); ++i) {
            answer ^= i;
            answer ^= nums[i];
        }
        return answer;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
