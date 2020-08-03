#include <iostream>
#include "string"
#include "unordered_map"

using namespace std;

// Given a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1.

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> map{};
        for (char c : s) {
            map[c] += 1;
        }

        for (int i = 0; i < s.size(); ++i) {
            if (map[s[i]] == 1)
                return i;
        }

        return -1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
