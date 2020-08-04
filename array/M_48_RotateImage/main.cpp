#include <iostream>
#include "vector"

using namespace std;

/*
 * You are given an n x n 2D matrix representing an image.
 *
 * Rotate the image by 90 degrees (clockwise).
 */

class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        for (int i = 0, size = matrix.size(); i < size / 2; ++i)
            for (int j = i; j < (size - 1) - i; ++j) {
                int a = matrix[i][j];
                int b = matrix[j][(size - 1) - i];
                int c = matrix[(size - 1) - i][(size - 1) - j];
                int d = matrix[(size - 1) - j][i];

                matrix[i][j] = d;
                matrix[j][(size - 1) - i] = a;
                matrix[(size - 1) - i][(size - 1) - j] = b;
                matrix[(size - 1) - j][i] = c;
            }
    }

    // other solution
    // first reverse up to down, then swap the symmetry
    void rotate2(vector<vector<int> > &matrix) {
        reverse(matrix.begin(), matrix.end());
        for (int i = 0, size = matrix.size(); i < size; ++i) {
            for (int j = i + 1; j < size; ++j)
                swap(matrix[i][j], matrix[j][i]);
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
