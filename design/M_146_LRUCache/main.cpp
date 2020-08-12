#include <iostream>
#include "unordered_map"
#include "list"

using namespace std;

// Design and implement a data structure for Least Recently Used (LRU) cache.
// It should support the following operations: get and put.

class LRUCache {
public:
    using TKey = int;
    using TVal = int;

    using TKeyValPair = pair<TKey, TVal>;
    using TKeyValPairItr = list<TKeyValPair>::iterator;

    LRUCache(int capacity) : mCapacity(capacity) {}

    int get(int key) {
        auto itr = mCacheMap.find(key);
        if (itr == mCacheMap.end())
            return -1; // not found
        mCacheList.splice(mCacheList.begin(), mCacheList, itr->second); // transfer to begin. This pair is last used.
        return itr->second->second; // return value

    }

    void put(int key, int value) {
        auto itr = mCacheMap.find(key);

        if (itr != mCacheMap.end()) {
            mCacheList.erase(itr->second);
            mCacheMap.erase(itr);
        }

        mCacheList.push_front(make_pair(key, value));
        mCacheMap[key] = mCacheList.begin();

        if (mCacheMap.size() > mCapacity) {
            auto last = mCacheList.end();
            --last;
            mCacheMap.erase(last->first);
            mCacheList.pop_back();
        }
    }

private:
    int mCapacity;
    list<TKeyValPair> mCacheList;
    unordered_map<TKey, TKeyValPairItr> mCacheMap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    cache.get(1);       // returns 1
    cache.put(3, 3);    // evicts key 2
    cache.get(2);       // returns -1 (not found)
    cache.put(4, 4);    // evicts key 1
    cache.get(1);       // returns -1 (not found)
    cache.get(3);       // returns 3
    cache.get(4);       // returns 4

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
