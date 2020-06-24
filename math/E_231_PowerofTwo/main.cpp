#include <iostream>

/*
 * Given an integer, write a function to determine if it is a power of two.
 */

class Solution {
public:
    bool isPowerOfTwo(int n) {
        unsigned int x = 1;
        if (n < 0) return false;
        while (true) {
            if (x == n)
                return true;
            else if (x > n)
                return false;
            else
                x <<= 1;
        }
    }

    /*
     * Power of 2 means only one bit of n is '1',
     * so use the trick n&(n-1)==0 to judge whether that is the case
     */
    bool isPowerOfTwo2(int n) {
        if (n <= 0)
            return false;
        return !(n & (n - 1));
    }
};

};

int main() {
    std::cout << (3 << 1) << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
