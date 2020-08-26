#include <iostream>
#include "vector"

using namespace std;

class Solution {
public:
    vector <string> fizzBuzz(int n) {
        vector <string> answer(n, "");
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0)
                answer[i - 1] = (i % 5 == 0) ? "FizzBuzz" : "Fizz";
            else if (i % 5 == 0)
                answer[i - 1] = "Buzz";
            else
                answer[i - 1] = to_string(i);
        }
        return answer;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
