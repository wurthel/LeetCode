#include <iostream>

class Solution {
public:
    int trailingZeroes(int n) {
        // ответом будет количетво множителей "5" в факториале
        // 10! = 1 * 2 ... 5 ... * (10 = 5 * 2) = 2 множителя, или 10/2
        // 25! = 1 * 2 ... 5 ... * (10 = 5 * 2) * ... * (25 = 5 * 5) = 1 (от 5) + 1(от 10) + 1(от 15) + 1(от 20) + 2 (от 25)
        return n == 0 ? 0 : (n / 5 + (trailingZeroes(n / 5)));
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
