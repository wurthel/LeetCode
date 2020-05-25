#include <iostream>
#include "vector"

using namespace std;

int maxArea(vector<int> &height) {
    int area = 0;
    int max_area = 0;
    int l = 0, r = height.size() - 1;
    while (l < r) {
        area = (r - l) * min(height[l], height[r]);
        max_area = max(max_area, area);
        if (height[l] < height[r])
            l++;
        else
            r--;
    }
    return max_area;
}

int main() {
    return 0;
}
