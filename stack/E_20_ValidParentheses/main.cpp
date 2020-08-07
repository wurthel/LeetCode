#include <iostream>
#include "string"
#include "stack"

using namespace std;

/*
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 *
 * An input string is valid if:
 *  Open brackets must be closed by the same type of brackets.
 *  Open brackets must be closed in the correct order.
 *
 * Note that an empty string is also considered valid.
 */

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            switch (c) {
                case ' ': continue;
                case '(': st.push(c); break;
                case '{': st.push(c); break;
                case '[': st.push(c); break;
                case ')': {
                    if (st.empty() || st.top() != '(')
                        return false;
                    st.pop();
                    break;
                }
                case '}': {
                    if (st.empty() || st.top() != '{')
                        return false;
                    st.pop();
                    break;
                }
                case ']': {
                    if (st.empty() || st.top() != '[')
                        return false;
                    st.pop();
                    break;
                }
            }
        }
        return st.empty();
    }
};

int main() {
    Solution solution;
    string str {"]"};

    cout << boolalpha << solution.isValid(str) << "\n";
    return 0;
}
