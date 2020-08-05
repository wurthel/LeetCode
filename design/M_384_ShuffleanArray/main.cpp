#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution(vector<int>& nums) {
        copy = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return copy;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> shuffled {copy};
        random_shuffle(begin(shuffled), end(shuffled));
        return shuffled;
    }

private:
    vector<int> copy;

};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
