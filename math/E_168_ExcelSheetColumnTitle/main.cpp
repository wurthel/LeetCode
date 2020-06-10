#include <iostream>
#include "string"

using namespace std;

// Given a positive integer, return its corresponding column title as appear in an Excel sheet.

class Solution {
public:
    string convertToTitle(int n) {
        string answer;
        do {
            answer.insert(0, 1, static_cast<char>((n - 1) % 26 + 'A'));
            n = (n - 1) / 26;
        } while (n != 0);

        return answer;
    }
};

int main() {
    Solution solution;
    string res = solution.convertToTitle(701);
    std::cout << res << std::endl;
    return 0;
}
