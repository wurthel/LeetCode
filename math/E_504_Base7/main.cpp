#include <iostream>
#include "string"

using namespace std;

// Given an integer, return its base 7 string representation.

class Solution {
public:
    string convertToBase7(int num) {
        string answer;

        int sign = num < 0 ? -1 : +1;
        num = abs(num);
        while (num >= 7){
            answer.insert(0, 1, static_cast<char>(num % 7 + '0'));
            num /= 7;
        };
        answer.insert(0, 1, static_cast<char>(num % 7 + '0'));
        if (sign == -1)
            answer.insert(0, 1, '-');
        return answer;
    }
};

int main() {
    Solution solution;

    string res = solution.convertToBase7(-7);

    std::cout << res << std::endl;
    return 0;
}
