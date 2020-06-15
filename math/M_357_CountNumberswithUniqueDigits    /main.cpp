#include <iostream>

// Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.

class Solution {
public:
    int countNumbersWithUniqueDigits_optimized(int n) {
        // without recursion
        if (n == 0)
            return 1;
        int answer = 10; // n == 1
        int helper = 9;
        for (int i = 2; i <= n && i <= 10; ++i){
            helper = helper * (9 - i + 2);
            answer += helper;
        }

        return answer;
    }

    int countNumbersWithUniqueDigits(int n) {
        int answer = 0;
        if (n == 0)
            answer = 1;
        else if (n < 11)
            answer = reverse_fact(n) + countNumbersWithUniqueDigits(n - 1);
        else
            answer = countNumbersWithUniqueDigits(9);
        return answer;
    }

private:
    int reverse_fact(int n) {
        int res = 9;
        int i = 9;
        for (; n > 1; n--)
            res *= (i--);
        return res;
    }
};

int main() {
    Solution solution;
    int r = solution.countNumbersWithUniqueDigits(10);
    std::cout << r << std::endl;
    return 0;
}
