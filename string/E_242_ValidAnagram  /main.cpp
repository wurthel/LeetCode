#include <iostream>
#include <string>
#include "unordered_set"

using namespace std;

/*
 * Given two strings s and t , write a function to determine if t is an anagram of s.
 *
 * Example:
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 *
 * Input: s = "rat", t = "car"
 * Output: false
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_multiset<char> bucket{};

        if (s.size() != t.size())
            return false;

        for (char c: s)
            bucket.insert(c);

        for (char c: t) {
            auto search = bucket.find(c);
            if (search != bucket.end())
                bucket.erase(search);
            else return false;
        }

        return true;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
