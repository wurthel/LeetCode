#include <iostream>
#include "vector"
#include "unordered_map"
#include "unordered_set"

using namespace std;

class Solution {
public:
    int singleNumber_HashTable(vector<int> &nums) {
        unordered_map<int, int> bucket; // unordered_map<number, count>

        for (int x: nums) {
            auto search = bucket.find(x);
            if (search != bucket.end())
                search->second += 1;
            else
                bucket[x] = 1;
        }

        for (auto x: bucket) {
            if (x.second == 1)
                return x.first;
        }

        return 0;
    }

    int singleNumber_Math(vector<int> &nums){
        // Idea: 2 * (a + b + c) - (a + a + b + b + c) = c

        unordered_set<int> bucket;
        int sumOfSet = 0;
        int realSum = 0;

        for (int x: nums){
            if (bucket.find(x) == bucket.end()) {
                sumOfSet += x;
                bucket.insert(x);
            }
            realSum += x;
        }

        int answer = 2 * sumOfSet - realSum;

        return answer;
    }

    int singleNumber_BitManipulation(vector<int> &nums){
        // Idea:
        // 1) a XOR 0 = a;
        // 2) a XOR a = 0;
        // => a XOR a XOR b = (a XOR a) XOR b = b;

        int result = 0;
        for (int x : nums)
            result ^= x;
        return result;
    }
};

int main() {
    vector<int> v{2, 2, 1};
    Solution solution;

    int x1 = solution.singleNumber_HashTable(v);
    int x2 = solution.singleNumber_Math(v);
    int x3 = solution.singleNumber_BitManipulation(v);

    assert((x1 == x2) == x3);
    return 0;
}
