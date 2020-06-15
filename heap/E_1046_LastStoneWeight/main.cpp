#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> bin(begin(stones), end(stones));

        int s1, s2;
        while (bin.size() > 1){
            s1 = bin.top(); bin.pop();
            s2 = bin.top(); bin.pop();
            bin.push(abs(s1 - s2));
        }

        return bin.empty() ? 0 : bin.top();
    }
};

int main(){
    vector<int> stones = {2,7,4,1,8,1};
    Solution solution;
    solution.lastStoneWeight(stones);
    std::cout << "Hello!" << std::endl;
}