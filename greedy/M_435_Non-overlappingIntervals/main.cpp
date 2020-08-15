#include <iostream>
#include "vector"

using namespace std;

/*
 * Given a collection of intervals, find the minimum number of intervals you need
 * to remove to make the rest of the intervals non-overlapping.
 */

/*
 * explanation:
 * https://www.youtube.com/watch?v=BW7LeuJIMhE
 */

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() < 2) return 0;

        auto cmp = [](vector<int> const & a, vector<int> const & b) { return a[0] < b[0];};
        sort(intervals.begin(), intervals.end(), cmp);

        int last_included = 0, count = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < intervals[last_included][1]) { // overlap
                count++;
                if (intervals[i][1] < intervals[last_included][1])
                    last_included = i;
            } else
                last_included = i;

        }

        return count;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
