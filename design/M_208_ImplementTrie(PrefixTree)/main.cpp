#include <iostream>
#include "string"

using namespace std;

/*
 * Implement a trie with insert, search, and startsWith methods
 */

class TrieNode {
public:
    TrieNode() {
        isEnd = false;
        for (auto &node : nodes)
            node = nullptr;
    }

    bool isEnd;
    TrieNode *nodes[26];
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *head = root;
        for (char c : word) {
            TrieNode *node = head->nodes[c - 'a'];
            if (!node)
                head->nodes[c - 'a'] = new TrieNode();
            head = head->nodes[c - 'a'];
        }
        head->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *head = root;
        for (char c : word) {
            TrieNode *node = head->nodes[c - 'a'];
            if (!node)
                return false;
            head = head->nodes[c - 'a'];
        }
        return head->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *head = root;
        for (char c : prefix) {
            TrieNode *node = head->nodes[c - 'a'];
            if (!node)
                return false;
            head = head->nodes[c - 'a'];
        }
        return true;
    }

private:
    TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
    Trie trie;
    trie.insert("apple");

    assert(trie.search("apple") == true);
    assert(trie.startsWith("app") == true);
    assert(trie.startsWith("app1") == false);

    trie.insert("app");
    assert(trie.search("app") == true);

    cout << "END\n";
    return 0;
}
