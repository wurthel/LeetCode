#include <iostream>
#include "algorithm"
#include "vector"

using namespace std;

/*
 * Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
 *
 * Find all the elements that appear twice in this array.
 * Could you do it without extra space and in O(n) runtime?
 */

class Solution {
public:
    vector<int> findDuplicates(vector<int> &nums) {
        // Идея:
        // в массиве все числа положительные и находятся в интервале от 1 до n (n -- размер массива).
        // Будем использовать в качестве того, что число встречалось другие числа.
        // Например пусть n = 7:
        // arr = {7, 2, 3, 3, 2, 5, 1}.
        // В качестве маркера того, что встречалось число 7 можно использовать число arr[7 - 1], то есть 1.
        // А для числа 1 можно использовать arr[1 - 1], то есть 7.

        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            nums[abs(nums[i]) - 1] *= -1;
            if (nums[abs(nums[i]) - 1] > 0)
                result.push_back(abs(nums[i]));
        }
        return result;
    }
};

int main() {
    vector<int> arr{1, 2, 3, 3, 3, 4};

    copy(begin(arr), end(arr), ostream_iterator<int>{cout, ","});
    std::cout << "\n";
    auto itr = begin(arr);
    arr.erase(itr);
    itr++;
    copy(itr, end(arr), ostream_iterator<int>{cout, ","});
    std::cout << "\n";

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
