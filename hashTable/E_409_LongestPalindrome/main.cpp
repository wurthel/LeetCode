#include <iostream>
#include "string"
#include "unordered_map"

using namespace std;

/*
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 */

/* Solution:
 * 1. Посчитаем количество в слове.
 * 2. Будем брать по 2 символа до тех пор, пока не останется 0 или 1 символов
 * 3. Когда таких символов больше не останется, обойдем еще раз все символы до первого символа, которого больше 1.
 * 4. Прибавим его к ответу и прервемся
 * 5. Вернем результат
 */
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> syllables{};
        int answer{0};

        for (char c: s)
            syllables[c] += 1;

        for (auto &itr: syllables) {
            answer += (itr.second / 2) * 2;
            itr.second -= (itr.second / 2) * 2;
        }

        for (auto &itr: syllables) {
            if (itr.second == 1) {
                answer += 1;
                break;
            }
        }

        return answer;
    }
};

int main() {
    Solution solution;

    assert(solution.longestPalindrome("abccccdd") == 7);
    assert(solution.longestPalindrome("Aa") == 1);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
