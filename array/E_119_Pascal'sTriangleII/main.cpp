#include <iostream>
#include "vector"

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> answer(rowIndex + 1, 0);

        answer[0] = 1;
        for (int j = 1; j <= rowIndex; j++)
            for (int i = j; i >= 1; i--)
                answer[i] = answer[i - 1] + answer[i];

        return answer;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
