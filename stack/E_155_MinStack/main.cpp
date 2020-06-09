#include <iostream>
#include "vector"
#include "stack"

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        st_m.push(INT_MAX);
    }

    void push(int x) {
        st.push(x);
        if (x <= getMin())
            st_m.push(x);
    }

    void pop() {
        if (st.top() == getMin())
            st_m.pop();
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return st_m.top();
    }

private:
    stack<int> st;
    stack<int> st_m;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
