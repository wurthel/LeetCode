#include <iostream>
#include "vector"
#include "map"

using namespace std;

// O((N * M)^2)
vector<int> findDiagonalOrder(vector<vector<int>> &matrix) {
    if (matrix.empty())
        return {};

    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> diag;
    for (int s = 0; s <= n + m - 2; ++s) {
        for (int x = 0; x <= s; ++x) {
            int i = x;
            int j = s - i;

            if (s % 2 == 0) swap(i, j);

            if (i >= n || j >= m)
                continue;

            diag.push_back(matrix[i][j]);
        }
    }

    return diag;
}

// O(N * M)
vector<int> findDiagonalOrder2(vector<vector<int>> &matrix) {
    if (matrix.empty())
        return {};

    map<int, vector<int>> hash;
    const int n = matrix.size();
    const int m = matrix[0].size();

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            hash[i + j].push_back(matrix[i][j]);

    vector<int> diag;
    for (auto &p: hash) {
        if (p.first % 2 == 0)
            reverse(p.second.begin(), p.second.end());
        for (auto x: p.second)
            diag.push_back(x);
    }

    return diag;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
