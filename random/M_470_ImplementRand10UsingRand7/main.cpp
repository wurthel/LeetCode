#include <iostream>

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        // explanation: https://leetcode.com/problems/implement-rand10-using-rand7/solution/
        // This solution is based upon Rejection Sampling.
        //    1  2  3  4  5  6  7
        // 1  1  2  3  4  5  6  7
        // 2  8  9  10 1  2  3  4
        // 3  5  6  7  8  9  10 1
        // 4  2  3  4  5  6  7  8
        // 5  9  10 1  2  3  4  5
        // 6  6  7  8  9  10 *  *
        // 7  *  *  *  *  *  *  *
        int row;
        int col;
        int idx;
        do {
            row = rand7();
            col = rand7();
            idx = col + (row - 1) * 7;
        } while (idx > 40);
        return idx % 10 + 1;

    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
