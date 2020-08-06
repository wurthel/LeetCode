#include <iostream>

class Solution {
public:
    int hammingDistance(int x, int y) {
        uint32_t mask = 1;
        int answer = 0;
        for (int i = 0; i < 32; ++i) {
            if ((mask & x) != (mask & y))
                answer++;
            mask = mask << 1;
        }
        return answer;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
