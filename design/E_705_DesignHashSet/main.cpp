#include <iostream>

using namespace std;

struct MyHashSetNode {
    MyHashSetNode(int v) : value(v), left(nullptr), right(nullptr) {}

    ~MyHashSetNode() {
        if (left != nullptr) delete left;
        if (right != nullptr) delete right;
    }

    int value;
    MyHashSetNode *left;
    MyHashSetNode *right;
};

class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() : root(nullptr) {}

    void add(int key) {
        if (Find(key) != nullptr)
            return;
        root = _add(key, root);
    }

    void remove(int key) {
        if (root == nullptr)
            return;
        root = _remove(key, root);
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        auto head = root;
        while (head != nullptr) {
            if (key == head->value)
                return true;
            head = key < head->value ? head->left : head->right;
        }
        return false;
    }

private:
    MyHashSetNode *root;

    MyHashSetNode *Find(int key) {
        auto head = root;
        while (head != nullptr) {
            if (key == head->value)
                return head;
            head = key < head->value ? head->left : head->right;
        }

        return head;
    }

    MyHashSetNode *FindMin(MyHashSetNode *head) {
        if (head->left == nullptr)
            return head;
        else
            return FindMin(head->left);
    }

    MyHashSetNode *RemoveMin(MyHashSetNode *parent) {
        if (parent == nullptr) {
            return nullptr;
        } else if (parent->left != nullptr) {
            parent->left = RemoveMin(parent->left);
            return parent;
        } else {
            MyHashSetNode *result = parent->right;

            parent->right = parent->left = nullptr;
            delete parent;
            return result;
        }
    }

    MyHashSetNode *_add(int key, MyHashSetNode *head) {
        MyHashSetNode *next = head;

        if (head == nullptr)
            next = new MyHashSetNode(key);
        else if (key < head->value)
            head->left = _add(key, head->left);
        else if (key > head->value)
            head->right = _add(key, head->right);
        // else:
        // duplicate key

        return next;
    }

    MyHashSetNode *_remove(int key, MyHashSetNode *head) {
        MyHashSetNode *next = head;
        MyHashSetNode *left = nullptr;
        MyHashSetNode *right = nullptr;

        if (next == nullptr)
            return next;

        left = head->left;
        right = head->right;

        if (key < next->value)
            next->left = _remove(key, next->left);
        else if (key > next->value)
            next->right = _remove(key, next->right);
            // => key == head->value
        else if (left != nullptr && right != nullptr) {
            current->val = FindMin(right)->val;
            current->right = RemoveMin(right);
//            MyHashSetNode *min{FindMin(right)};
//
//            if (min != nullptr) {
//                next->value = min->value;
//                head->right = RemoveMin(right);
//            }
        } else {
            next = (left != nullptr) ? left : right;
            head->right = head->left = nullptr;
            delete head;
        }

        return next;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

int main() {

    MyHashSet *obj = new MyHashSet();
    obj->add(10);
    obj->add(14);
    obj->add(15);
    obj->add(12);
    obj->remove(14);

    return 0;
}
