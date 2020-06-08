#include <iostream>
#include "stack"
#include "string"
#include "math.h"
#include <boost/any.hpp>

using namespace std;

class Solution {
public:
    int evalute(stack<boost::any> &stack) {
        int res = 0;

        while (!stack.empty() && boost::any_cast<char>(stack.top()) != ')') {
            char sign = boost::any_cast<char>(stack.top());
            stack.pop();

            if (sign == '+')
                res += boost::any_cast<int>(stack.top());
            else
                res -= boost::any_cast<int>(stack.top());
            stack.pop();
        }

        return res;
    }

    int calculate(string s) {
        stack<boost::any> st;
        int term = 0;
        int n = 0;

        auto itr = s.rbegin();
        while (itr != s.rend()) {
            char c = *itr;

            if (isdigit(c)) {
                term += (int) pow(10, n) * (int) (c - '0');
                n++;
            } else if (c != ' ') {
                if (n != 0) {
                    st.push(term);
                    term = 0;
                    n = 0;
                }
                if (c == '(') {
                    int res = evalute(st);
                    st.pop();
                    st.push(res);
                } else {
                    st.push(c);
                }
            }
            itr++;
        }

        if (n != 0)
            st.push(term);

        term = evalute(st);
        return term;

    }
};

int main() {
    string expr = "(1+(4+5+2)-3)+(6+8)";
//    string expr = "-1-2";
    Solution s;
    cout << s.calculate(expr) << endl;
    return 0;
}
