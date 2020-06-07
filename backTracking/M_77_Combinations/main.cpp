#include <iostream>
#include "vector"

using namespace std;

class Solution
{
public:
    void combine_(vector<vector<int>> &ans, vector<int> trace, int s, int n, int k)
    {
        if (k == 0)
        {
            ans.push_back(trace);
            return;
        }

        for (int i = s; i <= n; ++i)
        {
            trace.push_back(i);
            combine_(ans, trace, i + 1, n, k - 1);
            trace.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> answer;
        vector<int> trace;
        combine_(answer, trace, 1, n, k);

        return answer;
    }
};

int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
