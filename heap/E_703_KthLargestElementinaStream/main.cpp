#include <iostream>
#include "vector"
#include "deque"
#include "set"
#include "algorithm"
#include "queue"
//Design a class to find the kth largest element in a stream.
// Note that it is the kth largest element in the sorted order,
// not the kth distinct element.

using namespace std;

class KthLargest2 {
public:
    KthLargest2(int k, vector<int> &nums) {
        capacity_ = k;
        for (int n: nums){
            queue_.push(n);
            if (queue_.size() > capacity_)
                queue_.pop();
        }
    }

    int add(int val) {
        queue_.push(val);
        if (queue_.size() > capacity_)
            queue_.pop();
        return queue_.top();
    }

private:
    int capacity_;
    priority_queue<int, vector<int>, greater<int>> queue_;
};

class KthLargest {
public:
    KthLargest(int k, vector<int> &nums) {
        if (nums.empty()) {
            deque_.push_back(INT_MIN);
        } else {
            int n = (k == nums.size() + 1) ? k - 1 : k;
            auto cmp = [](int &a, int &b) { return a > b; };
            partial_sort(nums.begin(), nums.begin() + n, nums.end(), cmp);
            for (size_t i = 0; i < n; ++i)
                deque_.push_back(nums[i]);
        }

        while (deque_.size() < k)
            deque_.push_back(INT_MIN);

        kth_ = deque_.back();
    }

    int add(int val) {
        if (val > kth_) {
            deque_.pop_back();
            auto ins_itr = lower_bound(deque_.rbegin(), deque_.rend(), val);
            deque_.insert(ins_itr.base(), val);
            kth_ = deque_.back();
        }
        return kth_;
    }

private:
    int kth_;
    deque<int> deque_;
};

int main() {
    int k = 3;
    vector<int> arr = {5, 4, 6, 7, -1};
    KthLargest2 kthLargest(4, arr);
    int x = kthLargest.add(-3);
    std::cout << x << std::endl;
    x = kthLargest.add(5);
    std::cout << x << std::endl;
    return 0;
}
