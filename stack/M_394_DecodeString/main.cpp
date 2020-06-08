#include <iostream>
#include "math.h"

using namespace std;

class Solution {
public:
    string decodeString_(string &s, string::iterator& itr) {
        string answer;
        while (itr != s.end() && (*itr) != ']') {
            if (!isdigit(*itr)) {
                answer += *itr;
                itr++;
            }
            else {
                int n = 0;
                while (isdigit(*itr)) {
                    n = n * 10 + (*itr - '0');
                    itr++;
                }

                itr++; // '['
                string tmp = decodeString_(s, itr);
                itr++; // ']'

                while (n > 0) {
                    answer += tmp;
                    n--;
                }
            }
        }
        return answer;
    }

    string decodeString(string s) {
        string::iterator itr = s.begin();
        string answer = decodeString_(s, itr);
        return answer;
    }
};

int main() {
    string s = "100[leetcode]";
    Solution sol;

    string ans = sol.decodeString(s);

    std::cout << ans << std::endl;
    return 0;
}
