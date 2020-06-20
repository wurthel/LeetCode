#include <iostream>
#include "string"
#include "algorithm"

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string answer;
        generate_n(back_insert_iterator(answer), n, [i = 1]() mutable { return i++ + '0'; });

        for (int i = 1; i < k; ++i)
            next_permutation(answer.begin(), answer.end());

        return answer;
    }
};

int main() {
    Solution s;
    string res = s.getPermutation(3, 2);
    std::cout << res << std::endl;
    return 0;
}
