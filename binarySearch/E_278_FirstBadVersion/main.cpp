#include <iostream>

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        int middle = left + (right - left) / 2;

        while (right - left > 1) {
            if (isBadVersion(middle))
                right = middle;
            else
                left = middle;
            middle = left + (right - left) / 2;
        }

        return isBadVersion(left) ? left : right;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
