#include <iostream>
#include "string"
#include "unordered_map"

using namespace std;

/*
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 */

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2)
            return s;

        int start = 0;
        longest_begin = start, longest_end = start;
        longestPalindrome(s, start);

        string answer(s, longest_begin, longest_end - longest_begin + 1);

        return answer;
    }

private:
    int longest_begin;
    int longest_end;

    void longestPalindrome(const string &s, int start) {
        if (start == s.size())
            return;

        int length1 = expandBoundary(s, start, start);
        int length2 = expandBoundary(s, start, start + 1);
        int length = max(length1, length2);

        if (length > longest_end - longest_begin) {
            longest_begin = start - (length - 1) / 2;
            longest_end = start + length / 2;
        }

        longestPalindrome(s, start + 1);
    }

    int expandBoundary(const string &s, int left, int right) {
        while (left > -1 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return right - left - 1;
    }
};

int main() {
    Solution solution;

    cout << solution.longestPalindrome("ba") << "\n";
    cout << solution.longestPalindrome("babad") << "\n";
    cout << solution.longestPalindrome("babab") << "\n";
    cout << solution.longestPalindrome("badt") << "\n";

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
