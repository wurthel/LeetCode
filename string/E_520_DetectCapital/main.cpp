#include <iostream>
#include "string"
#include "algorithm"

using namespace std;

/*
 * Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
 */


class Solution {
public:
    bool detectCapitalUse(string word) {
        auto first = begin(word);
        auto last = end(word);
        return all_of(first, last, [](auto x) { return isupper(x); }) ||
               all_of(first, last, [](auto x) { return islower(x); }) ||
               (isupper(*first) && all_of(next(first), last, [](auto x) { return islower(x); }));
    }

    //    Other solution:
    //    for(int i = 1; i < word.size(); i++){
    //        if(isupper(word[1]) != isupper(word[i]) ||
    //           islower(word[0]) && isupper(word[i])) return false;
    //    }
    //    return true;
};


int main() {
    Solution solution;

    solution.detectCapitalUse("ABCd");

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
