#include <iostream>
#include "string"

using namespace std;

// Given two non-negative integers num1 and num2 represented as string,
// return the sum of num1 and num2.

class Solution {
public:
    string addStrings(string num1, string num2) {
        auto num1_itr = num1.rbegin();
        auto num2_itr = num2.rbegin();
        string answer;

        int num = 0;
        while (num1_itr != num1.rend() || num2_itr != num2.rend() || num != 0) {
            num += num1_itr != num1.rend() ? *(num1_itr++) - '0' : 0;
            num += num2_itr != num2.rend() ? *(num2_itr++) - '0' : 0;

            answer.insert(0, 1, static_cast<char>(num % 10 + '0'));
            num /= 10;
        }

        return answer;
    }
};

int main() {
    string s1 = "0";
    string s2 = "0";

    Solution solution;
    string answ = solution.addStrings(s1, s2);
    std::cout << answ << std::endl;
    return 0;
}
