#include <iostream>
#include "vector"

using namespace std;

/*
 * Решать будем рекурсивно:
 * k, n -> возьмем первое число за 1 и будет решать задачу для k - 1, n - 1 ->
 * возьмем второе число за 2 и будет решать задачу для k - 1, n - 2 -> ...
 * если k == 1, то в качестве массива чисел возвращаем само n.
 */
void combinationSum3_(vector<vector<int>> &res, vector<int> &path, int k, int n, int s) {
    if (k == 0 && n == 0) {
        res.push_back(path);
    } else {
        for (int i = s; i <= n && i < 10; i++) {
            path.push_back(i);
            combinationSum3_(res, path, k - 1, n - i, i + 1);
            path.pop_back();
        }
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    vector<int> path;
    combinationSum3_(res, path, k, n, 1);
    return res;
}

int main() {
    int k = 3;
    int n = 15;
    vector<vector<int>> res = combinationSum3(k, n);
    for (auto x: res) {
        for (auto y: x)
            std::cout << y << " ";
        std::cout << "\n";
    }
    return 0;
}
