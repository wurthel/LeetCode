#include <iostream>
#include "string"
#include "set"

using namespace std;

/*
 * В основе лежит структура данных "префиксное дерево"
 */

const int ALPHABET_SIZE = 26;

struct Node {
    Node *children[ALPHABET_SIZE];
    bool isEndOfWord;
};

Node *makeNode() {
    Node *pNode = new Node;
    for (int i = 0; i < ALPHABET_SIZE; ++i)
        pNode->children[i] = nullptr;
    pNode->isEndOfWord = false;

    return pNode;
}

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() : root(makeNode()) {}

    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node *head = root;
        for (int i = 0; i < word.size(); ++i) {
            int index = word[i] - 'a';
            if (!head->children[index])
                head->children[index] = makeNode();
            head = head->children[index];
        }
        head->isEndOfWord = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search_(word, 0, root);
    }

private:
    Node *root;

    bool search_(string word, int p, Node *head) {
        if (!head)
            return false;

        for (int i = p; i < word.size(); ++i) {
            if (word[i] == '.') {
                for (int j = 0; j < ALPHABET_SIZE; ++j) {
                    if (search_(word, i + 1, head->children[j]))
                        return true;
                }
                return false;
            }
            int index = word[i] - 'a';
            if (!head->children[index])
                return false;
            head = head->children[index];
        }

        return head->isEndOfWord;
    }
};


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main() {
    WordDictionary solution;

    solution.addWord("at");
    solution.addWord("and");
    solution.addWord("an");
    solution.addWord("add");

    std::cout << solution.search("a") << endl;
    std::cout << solution.search(".at") << endl;

    solution.addWord("bat");

    std::cout << solution.search(".at") << endl;
    std::cout << solution.search("an.") << endl;
    std::cout << solution.search("a.d.") << endl;
    std::cout << solution.search("b.") << endl;
    std::cout << solution.search("a.d") << endl;
    std::cout << solution.search(".") << endl;

    return 0;
}
