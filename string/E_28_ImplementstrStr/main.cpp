#include <iostream>
#include "string"

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int hs = haystack.size();
        int ns = needle.size();

        for (int i = 0; i <= hs - ns; ++i) {
            int j = 0;
            for (; j < ns; j++) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }

            if (j == ns) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;

    solution.strStr("a", "a");

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
