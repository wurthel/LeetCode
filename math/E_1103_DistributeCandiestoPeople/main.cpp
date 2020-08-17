#include <iostream>
#include "vector"

using namespace std;

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> answer(num_people, 0);
        int sum_candies = 0;
        int cur_person = 0;
        for (int count = 1; sum_candies + count < candies;) {
            answer[cur_person % num_people] += count;
            sum_candies += count;
            ++count;
            ++cur_person;
        }
        answer[cur_person % num_people] += candies - sum_candies;
        return answer;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
