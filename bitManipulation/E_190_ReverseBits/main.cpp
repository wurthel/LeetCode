#include <iostream>

// Reverse bits of a given 32 bits unsigned integer.

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t answer = 0;
        for (int i = 31; i >= 0; i--) {
            ans |= (n & 1) << i;
            n >>= 1;
        }
        return answer;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
