#include <iostream>
#include <vector>
#include "map"

using namespace std;

class Solution {
public:
    map<char, string> dictionary = {
            {'1', ""},
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
    };

    void letterCombinations_(vector<string> &ans, string &trace, string::iterator itr, string::iterator end) {
        if (itr == end) {
            ans.push_back(trace);
            return;
        }
        string available_letters = dictionary[*itr];
        for (auto c: available_letters){
            trace.push_back(c);
            letterCombinations_(ans, trace, next(itr), end);
            trace.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {
        vector<string> answer;
        string trace;
        if (!digits.empty())
            letterCombinations_(answer, trace, digits.begin(), digits.end());

        return answer;
    }
};

int main() {
    Solution s;
    s.letterCombinations("234");
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
