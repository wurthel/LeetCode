#include <iostream>
#include "vector"

using namespace std;

/*
 * Ищем возрастающие подпоследовательности.
 * Сумма разностей конца и начала каждой подпоследовательности и будет ответом к задаче.
 */

int maxProfit(vector<int>& prices) {
    int profit = 0;
    for (size_t i = 1, size = prices.size(); i < size; ++i)
        profit += max(prices[i] - prices[i-1], 0);
    return profit;

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
