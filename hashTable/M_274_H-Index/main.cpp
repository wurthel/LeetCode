#include <iostream>
#include "vector"

using namespace std;

/*
 * Given an array of citations (each citation is a non-negative integer) of a researcher,
 * write a function to compute the researcher's h-index.
 *
 * According to the definition of h-index on Wikipedia:
 * "A scientist has index h if h of his/her N papers have at least h citations each,
 * and the other N − h papers have no more than h citations each."
 */

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int N = citations.size();
        sort(citations.begin(), citations.end());

        int h = 0;
        for(int i = 0, size = citations.size(); i < size; ++i)
            if (citations[i] >= N - i) {
                h = N - i;
                break;
            }
        return h;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
