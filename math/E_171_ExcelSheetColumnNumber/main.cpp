#include <iostream>
#include "string"
#include "math.h"

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int answer = 0;
        int length = s.length();
        for (int i = 0; i < length; ++i)
            answer = answer + pow(26, length - 1 - i) * (s[i] - 'A' + 1);
        return answer;
    }
};




int main() {
    Solution solution;

    cout << solution.titleToNumber("ABC") << endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
