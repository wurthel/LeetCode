#include <iostream>
#include "vector"

using namespace std;

/*
 * 1. Движемся слева направо и сверху вниз.
 * 2. Для индексов в середине вектора: если в текущей клетке 'X', а сверху или снизу '.', то это новый корабль.
 * 3. Для остальных индексов аналогично, только накладывается условие на границы массива.
 */
int countBattleships(vector<vector<char>> &board) {
    int count = 0;
    for (size_t x = 0, size_x = board.size(); x < size_x; ++x)
        for (size_t y = 0, size_y = board[0].size(); y < size_y; ++y) {
            if (board[x][y] == 'X') {
                if (x == 0 && y == 0) {
                    count++;
                } else if (x == 0) {
                    if (board[x][y - 1] == '.')
                        count++;
                } else if (y == 0) {
                    if (board[x - 1][y] == '.')
                        count++;
                } else {
                    if (board[x - 1][y] == '.' && board[x][y - 1] == '.')
                        count++;
                }
            }
        }
    return count;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
