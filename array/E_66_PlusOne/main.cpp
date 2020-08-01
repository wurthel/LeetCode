#include <iostream>
#include "algorithm"
#include "vector"

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> answer{digits};

        reverse(begin(answer), end(answer));

        int mod{1};
        for (int &x: answer) {
            x += mod;
            mod = x / 10;
            x %= 10;
        }
        if (mod != 0)
            answer.push_back(mod);

        reverse(begin(answer), end(answer));

        return answer;
    }
};

int main() {
    vector<int> arr{9, 9, 9};
    Solution solution;

    vector<int> answ{solution.plusOne(arr)};

    copy(begin(answ), end(answ), ostream_iterator<int>{cout, ", "});

    return 0;
}
