#include <iostream>
#include "vector"
#include "map"

using namespace std;

// Problem:
// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/552/week-4-august-22nd-august-28th/3436/

// Explanation:
// https://leetcode.com/problems/minimum-cost-for-tickets/discuss/227106/C%2B%2B-concise-4-line-0ms

class Solution {
public:
    int mincostTickets(vector<int> &days, vector<int> &costs) {
        map<int, int> dp{{-30, 0}};
        auto cost = [&](int day) { return prev(dp.upper_bound(day))->second; };
        for (int d:days)
            dp[d] = min({costs[0] + cost(d - 1), costs[1] + cost(d - 7), costs[2] + cost(d - 30)});
        // if you want O(N) solution, simply add one line in loop:  if(dp.size() > 31) dp.erase(dp.begin());
        return dp[days.back()];
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
