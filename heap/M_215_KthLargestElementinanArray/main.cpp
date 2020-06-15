#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Find the kth largest element in an unsorted array.
// Note that it is the kth largest element in the sorted order, not the kth distinct element.

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto cmp = [](int& a, int& b) {return a > b;};
        partial_sort(begin(nums), begin(nums) + k, end(nums), cmp);
        return nums[k - 1];
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
