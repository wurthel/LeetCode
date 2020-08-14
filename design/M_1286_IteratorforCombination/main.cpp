#include <iostream>
#include "string"
#include "queue"
#include "set"
#include "bitset"

using namespace std;

/*
 * Design an Iterator class, which has:
 *  A constructor that takes a string characters of sorted distinct lowercase English letters and a number combinationLength as arguments.
 *  A function next() that returns the next combination of length combinationLength in lexicographical order.
 *  A function hasNext() that returns True if and only if there exists a next combination.
 */

/*
 * Constraints:
 *  1 <= combinationLength <= characters.length <= 15
 *  There will be at most 10^4 function calls per test.
 *  It's guaranteed that all calls of the function next are valid.
 */


int ones_count(uint16_t val) {
    int ans = 0;
    for (int i = 0; i < 16; ++i)
        if (val & (1 << i))
            ans++;
    return ans;
}

class CombinationIterator {
public:
    CombinationIterator(string characters, int combinationLength) {
        word = characters;
        length = combinationLength;
        mask = 0;

        for (int i = 0; i < length; ++i)
            mask |= 1 << (word.size() - i - 1);
    }

    string next() {
        string answer;

        for (int i = 0; i < word.size(); ++i)
            if (mask & (1 << (word.size() - i - 1)))
                answer.push_back(word[i]);

        do {
            --mask;
        } while (mask > 0 && ones_count(mask) != length);

        return answer;
    }

    bool hasNext() {
        return mask != 0;
    }

private:
    int mask;
    int length;
    string word;
};

int main() {
    CombinationIterator solution("abc", 2);

    cout << solution.next() << "\n";
    cout << solution.next() << "\n";
    cout << solution.next() << "\n";
    cout << boolalpha << solution.hasNext() << "\n";


    return 0;
}
