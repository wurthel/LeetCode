#include <iostream>
#include "vector"
#include "map"

using namespace std;

class Solution {
public:
//     1. Сохраним все интервалы в unordered_map'e map<StartInt, (Index, Interval)>
//     2. Пройдемся по всем интервалам. Надем из map'е (описанного выше) подходящие
//     3. Вернем результат
    vector<int> findRightInterval(vector<vector<int>> &intervals) {
        vector<int> answer {};
        map<int, pair<int, vector<int>>> helper;

        for (int i = 0; i < intervals.size(); ++i) {
            auto interval = intervals[i];
            helper[interval[0]] = make_pair(i, interval);
        }

        for (int i = 0; i < intervals.size(); ++i) {
            auto interval = intervals[i];
            auto search = helper.lower_bound(interval[1]);
            if (search != helper.end())
                answer.push_back(search->second.first);
            else
                answer.push_back(-1);
        }

        return answer;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
