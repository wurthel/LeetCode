#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> storage;
        for (string& w : words){
            auto itr = storage.find(w);
            if (itr == storage.end())
                storage[w] = 1;
            else
                itr->second += 1;
        }

        vector<pair<string, int>> pairs(storage.begin(), storage.end());

        auto cmp = [](auto& a, auto& b) {
            return get<1>(a) != get<1>(b) ? get<1>(a) > get<1>(b) : get<0>(a) < get<0>(b);
        };
        partial_sort(pairs.begin(), pairs.begin() + k, pairs.end(), cmp);

        vector<string> result;
        for (int i = 0; i < k; ++i)
            result.push_back(get<0>(pairs[i]));

        return result;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
