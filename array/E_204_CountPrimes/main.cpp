#include <iostream>
#include "vector"
#include "algorithm"

using namespace std;

int countPrimes(int n) {
    vector<bool> isPrime (n, true);
    for (size_t i = 2; i < n; i++){
        if (!isPrime[i])
            continue;
        for (size_t j = i * i; j < n; j += i)
            isPrime[j] = false;
    }
    int countPrimes = count(isPrime.begin(), isPrime.end(), true) - 2; // without 0 and 1.
    return max(0, countPrimes);
}

int main() {
    std::cout << countPrimes(10) << std::endl;
    return 0;
}
