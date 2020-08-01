#include <iostream>
#include "vector"

using namespace std;

// Given two arrays, write a function to compute their intersection.

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v_intersection;

        auto capacity {min(nums1.size(), nums2.size())};
        v_intersection.reserve(capacity);

        sort(begin(nums1), end(nums1));
        sort(begin(nums2), end(nums2));
        set_intersection(begin(nums1), end(nums1), begin(nums2), end(nums2), back_inserter(v_intersection));
        v_intersection.shrink_to_fit();

        return v_intersection;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
