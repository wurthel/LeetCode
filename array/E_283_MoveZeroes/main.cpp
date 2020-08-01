#include <iostream>
#include "vector"
#include "algorithm"

using namespace std;

void moveZeroes(vector<int> &nums) {
    for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
        if (nums[cur] != 0) {
            swap(nums[lastNonZeroFoundAt++], nums[cur]);
        }
    }
}

int main() {
    vector<int> arr{0, 1, 0, 3, 12, 0, 0};

    Solution solution;
    solution.moveZeroes(arr);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
