#include <iostream>
#include "vector"
#include "unordered_set"
#include "unordered_map"

using namespace std;

/*
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> helper;
        vector<int> answer;
        for (int i = 0, size = nums.size(); i < size; ++i){
            int complement = target - nums[i];

            // if complement is found in map, return them
            auto comp_itr = helper.find(complement);

            if (comp_itr != helper.end()){
                answer.push_back(i);
                answer.push_back(comp_itr->second);
                break;
            }

            //number was not found. Put it in the map.
            helper.insert(make_pair(nums[i], i));
        }
        return answer;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
