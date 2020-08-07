#include <iostream>
#include "vector"

using namespace std;

// Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> answer;

        if (numRows > 0)
            answer.push_back({1});

        for (int n = 1; n < numRows; ++n) {
            vector<int> row;
            row.reserve(n + 1);

            row.push_back(1);
            for (int i = 1; i < n; ++i)
                row.push_back(answer[n - 1][i] + answer[n - 1][i - 1]);
            row.push_back(1);

            answer.push_back(row);
        }

        return answer;
    }
};

int main() {
    Solution solution;

    auto arr {solution.generate(5)};
    for (auto x: arr) {
        copy(begin(x), end(x), ostream_iterator<int>(cout, ","));
        cout << "\n";
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
