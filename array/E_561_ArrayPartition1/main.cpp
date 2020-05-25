#include <iostream>
#include "vector"
#include "algorithm"

int arrayPairSum(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    int sum = 0;
    for (size_t i = 0, size = nums.size(); i < size; i += 2)
        sum += nums[i];
    return sum;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
