#include <iostream>

/*
 * Write a function that takes an unsigned integer and return the number of '1' bits it has (also known as the Hamming weight).
 */

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int answer = 0;
        uint32_t mask = 1;
        for (int i = 0; i < 32; ++i) {
            if ((mask & n) != 0)
                answer += 1;
            mask = mask << 1;
        }
        return answer;
    }
};



int main() {
    Solution solution;

    uint32_t x = 00000000000000000000000000001011;
    std::cout << solution.hammingWeight(x);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
