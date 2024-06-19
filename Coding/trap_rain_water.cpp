#include <iostream>
#include <algorithm>

int rainwater(int a[], int n) {
    int left[n];
    int right[n];

    left[0] = a[0];
    for (int i = 1; i < n; i++) {
        left[i] = std::max(a[i], left[i - 1]);
    }

    right[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        right[i] = std::max(a[i], right[i + 1]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += std::min(left[i], right[i]) - a[i];
    }

    return ans;
}

int main() {
    int a[] = {3, 0, 0, 2, 0, 4};
    int n = sizeof(a) / sizeof(a[0]);

    int result = rainwater(a, n);
    std::cout << "The trapped rainwater is: " << result << std::endl;

    return 0;
}

