#include <iostream>
#include "vector"

using namespace std;

/*
 * Given an array of integers A, We need to sort the array performing a series of pancake flips.

In one pancake flip we do the following steps:

Choose an integer k where 0 <= k < A.length.
Reverse the sub-array A[0...k].
For example, if A = [3,2,1,4] and we performed a pancake flip choosing k = 2, we reverse
 the sub-array [3,2,1], so A = [1,2,3,4] after the pancake flip at k = 2.

Return an array of the k-values of the pancake flips that should be performed in order to sort A.
 Any valid answer that sorts the array within 10 * A.length flips will be judged as correct.
 */

class Solution {
public:
    void pancakeSort(vector<int> &A) {
        for (int i = A.size(); i > 1; --i) {
            int maxNumPos = 0;
            for (int j = 0; j < i; ++j)
                maxNumPos = A[j] > A[maxNumPos] ? j : maxNumPos;
            if (maxNumPos == (i - 1))
                continue;
            else {
                flip(A, maxNumPos, i);
            }
        }
    }

    void flip(vector<int> &arr, int beg, int end) {
        reverse(arr.begin() + beg, arr.begin() + end);
    }
};

int main() {
    Solution s;

    vector<int> v{3, 2, 4, 1};

    auto ans = s.pancakeSort(v);
    for (auto x : ans)
        cout << x << ", ";
    cout << "\n";
    for (auto x : v)
        cout << x << ", ";
    return 0;
}
