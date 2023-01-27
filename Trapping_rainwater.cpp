#include <iostream>
using namespace std;

const int N = 1005;
int height[N];
int n;

int trappingWater() {
    int left[n], right[n];
    left[0] = height[0];
    for (int i = 1; i < n; i++) {
        left[i] = max(left[i-1], height[i]);
    }
    right[n-1] = height[n-1];
    for (int i = n-2; i >= 0; i--) {
        right[i] = max(right[i+1], height[i]);
    }
    int water = 0;
    for (int i = 0; i < n; i++) {
        water += min(left[i], right[i]) - height[i];
    }
    return water;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }
    cout << trappingWater() << endl;
    return 0;
}