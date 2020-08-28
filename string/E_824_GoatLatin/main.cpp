#include <iostream>
#include <sstream>
#include "vector"
#include "string"
#include "unordered_set"

using namespace std;

class Solution {
public:
    string toGoatLatin(string S) {
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u',
                                   'A', 'E', 'I', 'O', 'U'};
        string result, word, postfix;
        istringstream iss{S};

        while (iss >> word) {
            postfix += "a";
            if (vowels.find(word[0]) == vowels.end())
                word = word.substr(1) + word[0];
            result += word + "ma" + postfix + " ";
        }
        result.pop_back(); // remove last space;

        return result;
    }
};

int main() {
    Solution s;
    s.toGoatLatin("asd")
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
