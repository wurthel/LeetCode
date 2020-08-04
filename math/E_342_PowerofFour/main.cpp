#include <iostream>

class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;

        // Explanation
        // 1. num & (num - 1) = 0 ~~ 0001 0000 & 0000 1111 = 0000 0000
        // 2. (4^1 - 1) = 3
        //    (4^2 - 1) = (4 - 1)(4 + 1) = 3 (4 + 1)
        //    (4^3 - 1) = (2^6 - 1) = (2^3 - 1) (2^3 + 1) = (2^3 - 1) 9
        //    (4^4 - 1) = (4^2 - 1) (4^2 + 1)
        //    (4^5 - 1) = (2^10 - 1) = (2^5 - 1) (2^5 + 1) = (2^5 - 1) 33
        //    (4^6 - 1) = (4^3 - 1) (4^3 + 1)
        //    (4^7 - 1) = (2^14 - 1) = (2^7 - 1) (2^7 + 1) = (2^5 - 1) 129
        //    ...
	//    (4^n - 1) % 3 == 0
	//    another proof:
	//    (1) 4^n - 1 = (2^n + 1) * (2^n - 1)
	//    (2) among any 3 consecutive numbers, there must be one that is a multiple of 3
	//    among (2^n-1), (2^n), (2^n+1), one of them must be a multiple of 3, and (2^n) cannot be the one, 
	//    therefore either (2^n-1) or (2^n+1) must be a multiple of 3, and 4^n-1 must be a multiple of 3 as well.
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
