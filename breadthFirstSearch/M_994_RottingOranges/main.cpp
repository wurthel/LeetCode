#include <iostream>
#include "vector"

using namespace std;

/*
 * In a given grid, each cell can have one of three values:
 *  the value 0 representing an empty cell;
 *  the value 1 representing a fresh orange;
 *  the value 2 representing a rotten orange.
 *
 *  Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.
 *  Return the minimum number of minutes that must elapse until no cell has a fresh orange.
 *  If this is impossible, return -1 instead.
 */


class Solution {
public:
    int orangesRotting(vector<vector<int>> &grid) {
        int count_of_minutes{countOfMinutes(grid)};

        return count_of_minutes;
    }

private:
    int countFreshOranges(vector<vector<int>> const &grid) {
        int answer{0};

        bool isFresh{false}; // is there rotten orange?
        bool isRotten{false}; // is there rotten orange?

        for (int i = 0, isize = grid.size(); i < isize; ++i)
            for (int j = 0, jsize = grid[0].size(); j < jsize; ++j) {
                if (!isFresh && grid[i][j] == 1) isFresh = true;
                if (!isRotten && grid[i][j] == 2) isRotten = true;
                if (grid[i][j] == 1) answer++;
            }

        if (!isRotten && !isFresh) return 0;
        if (!isRotten) return -1;
        if (!isFresh) return 0;
        return answer;
    }

    int countOfMinutes(vector<vector<int>> grid) {
        int num_of_fresh{countFreshOranges(grid)};
        if (num_of_fresh == -1 || num_of_fresh == 0)
            return num_of_fresh;

        int answer = 0;
        int next_num_of_fresh{num_of_fresh};
        vector<vector<int>> next_grid{grid};

        while (num_of_fresh > 0) {
            answer++;

            for (int i = 0, isize = grid.size(); i < isize; ++i)
                for (int j = 0, jsize = grid[0].size(); j < jsize; ++j) {
                    if (grid[i][j] == 2) {
                        if (i > 0 && grid[i - 1][j] == 1 && next_grid[i - 1][j] != 2)
                            next_grid[i - 1][j] = 2, next_num_of_fresh--;
                        if (j < jsize - 1 && grid[i][j + 1] == 1 && next_grid[i][j + 1] != 2)
                            next_grid[i][j + 1] = 2, next_num_of_fresh--;
                        if (i < isize - 1 && grid[i + 1][j] == 1 && next_grid[i + 1][j] != 2)
                            next_grid[i + 1][j] = 2, next_num_of_fresh--;
                        if (j > 0 && grid[i][j - 1] == 1 && next_grid[i][j - 1] != 2)
                            next_grid[i][j - 1] = 2, next_num_of_fresh--;
                    }
                }

            // copy data from "NEXT" to "CUR"
            if (num_of_fresh == next_num_of_fresh) {
                answer = -1;
                break;
            } else {
                num_of_fresh = next_num_of_fresh;
                grid = next_grid;
            }
        }

        return answer;
    }
};


int main() {
    vector<vector<int>> grid1{{2, 1, 1},
                              {1, 1, 0},
                              {0, 1, 1}};
    vector<vector<int>> grid2{{2, 1, 1},
                              {0, 1, 1},
                              {1, 0, 1}};
    vector<vector<int>> grid3{{0, 2}};
    vector<vector<int>> grid4{{1, 2}};
    vector<vector<int>> grid5{{2},
                              {2},
                              {1},
                              {0},
                              {1},
                              {1}};

    Solution solution;

    std::cout << boolalpha << (solution.orangesRotting(grid1) == 4) << std::endl;
    std::cout << boolalpha << (solution.orangesRotting(grid2) == -1) << std::endl;
    std::cout << boolalpha << (solution.orangesRotting(grid3) == 0) << std::endl;
    std::cout << boolalpha << (solution.orangesRotting(grid4) == 1) << std::endl;
    std::cout << boolalpha << (solution.orangesRotting(grid5) == -1) << std::endl;
    return 0;
}
