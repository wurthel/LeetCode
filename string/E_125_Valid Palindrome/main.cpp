#include <iostream>
#include "string"
#include "algorithm"

using namespace std;

/*
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 *
 * Note: For the purpose of this problem, we define empty string as valid palindrome.
 */

class Solution {
public:
    bool isPalindrome(string s) {
        string filtered;

        auto pred = [](char c) { return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || isdigit(c); };
        copy_if(begin(s), end(s), back_inserter(filtered), pred);

        auto front = begin(filtered);
        auto back = end(filtered) - 1;
        while (front < back){
            if (tolower(*front) != tolower(*back))
                return false;
            ++front;
            --back;
        }

        return true;
    }
};

int main() {
    Solution solution;
    solution.isPalindrome("asdsdD  dl;;;; d;");
    return 0;
}
