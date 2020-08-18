#include <iostream>
#include "vector"

using namespace std;

/*
 * Return all non-negative integers of length N such that the absolute difference between
 * every two consecutive digits is K.
 *
 * Note that every number in the answer must not have leading zeros except for the number 0 itself.
 * For example, 01 has one leading zero and is invalid, but 0 is valid.
 *
 * You may return the answer in any order.
 */

class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> answer;

        int begin = N == 1 ? 0 : 1;
        for (int x = begin; x < 10; x++)
            numsSameConsecDiff_(answer, x, x, N - 1, K);

        return answer;
    }

private:
    void numsSameConsecDiff_(vector<int> &answer, int path, int prev, int N, int K) {
        if (N == 0)
            answer.push_back(path);
        else {
            for (int x = 0; x < 10; x++)
                if (abs(prev - x) == K)
                    numsSameConsecDiff_(answer, path * 10 + x, x, N - 1, K);
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
