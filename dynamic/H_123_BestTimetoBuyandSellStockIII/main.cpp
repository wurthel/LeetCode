#include <iostream>
#include "vector"

using namespace std;

/*
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete at most two transactions.
 */

/*
 * Решение:
 * Разрешено проводить не более двух транзакций.
 * Будем искать максимальную выгоду следующим образом:
 * 1) С i-ой позиции найдем первую выгодную транзакцию. Затем найдем следующую транзакцию с i+1 позиции.
 * 2) Дойдя до конца, запишем результат. После этого стартуем с i+1 позиции и находим следующую выгодную транзакцию
 * 3) Дойдя до i = length, останавливаем работу алгоритма
 */

// Мое медленное решение. Сложность O(N^2).
//class Solution {
//public:
//    int maxProfit(vector<int> &prices) {
//        int max_profit = 0;
//        int profit = 0;
//        for (int i1 = 0; i1 < prices.size(); ++i1) {
//            for (int j1 = i1 + 1; j1 < prices.size(); ++j1) {
//                int t1 = prices[j1] - prices[i1];
//                if (t1 > 0) {
//                    profit += t1;
//                    int t2 = 0;
//                    for (int i2 = j1 + 1; i2 < prices.size(); ++i2)
//                        for (int j2 = i2 + 1; j2 < prices.size(); ++j2)
//                            t2 = max(prices[j2] - prices[i2], t2);
//                    profit += t2;
//                    max_profit = max(profit, max_profit);
//
//                    profit = 0;
//                }
//            }
//        }
//
//        return max_profit;
//    }
//};

//Быстрое решение. Сложность O(N)
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int buy1 = INT_MIN, sale1 = 0, buy2 = INT_MIN, sale2 = 0;
        for (int x : prices) {
            buy1 = max(buy1, -x);           // деньги, оставшиеся после покупки
            sale1 = max(sale1, x + buy1);   // деньги, оставшиеся после продажи
            buy2 = max(buy2, sale1 - x);    // деньги, оставшиеся после покупки
            sale2 = max(sale2, x + buy2);   // деньги, оставшиеся после продажи
        }

        return sale2;
    }
};

int main() {
    vector<int> v;
    Solution solution;

    v = {3, 3, 5, 0, 0, 3, 1, 4};
    assert(solution.maxProfit(v) == 6);

    v = {1, 2, 3, 4, 5};
    assert(solution.maxProfit(v) == 4);


    v = {7, 6, 4, 3, 1};
    assert(solution.maxProfit(v) == 0);

    return 0;
}
