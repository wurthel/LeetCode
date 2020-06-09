#include <iostream>
#include "vector"
#include "string"

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> answer;
        string ip;
        restoreIpAddresses_(answer, ip, 0, s, s.size(), 0);

        return answer;
    }

private:
    void restoreIpAddresses_(vector<string> &answer, string ip, int i, string s, int ssize, int part){
        if (part == 4) {
            if (ip.size() - 3 == ssize)
                answer.push_back(ip);
            return;
        }

        if (part != 0)
            ip += ".";

        for (int p = i; p < i + 3 && p < ssize; ++p){
            string substr = s.substr(i, p - i + 1); // copy_n(s.begin() + i, p - i + 1, back_inserter(substr));
            if (!isValidIPPart(substr))
                break;
            restoreIpAddresses_(answer, ip + substr, p + 1, s, ssize, part + 1);
        }
    }

    bool isValidIPPart(string &s){
        if (s[0] == '0' && s.size() > 1 )
            return false;
        return stoi(s) <= 255;
    }
};

int main() {
    Solution solution;

//    string s("25525511135");
    string s("010010");

    auto xs = solution.restoreIpAddresses(s);
    for (auto x: xs)
        cout << x << "\n";

    return 0;
}
