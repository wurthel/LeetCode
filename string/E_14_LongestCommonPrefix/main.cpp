#include <iostream>
#include "string"
#include "vector"

using namespace std;

/*
 * Write a function to find the longest common prefix string amongst an array of strings.
 *
 * If there is no common prefix, return an empty string "".
 */

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string answer;

        int size{min_size(strs)};

        for (int i = 0; i < size; ++i) {
            char c = strs[0][i];
            auto pred = [&i, &c](string str) { return str[i] == c;};
            if (all_of(strs.begin() + 1, strs.end(), pred))
                answer.push_back(c);
            else
                break;
        }

        return answer;

    }

    int min_size(vector<string> &strs) {
        if (strs.size() == 0)
            return INT16_MIN;

        int size = INT16_MAX;
        for (int i = 0; i < strs.size(); ++i)
            size = strs[i].size() < size ? strs[i].size() : size;

        return size;
    }
};


int main() {
    Solution solution;

    vector<string> v;

    solution.longestCommonPrefix(v);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
