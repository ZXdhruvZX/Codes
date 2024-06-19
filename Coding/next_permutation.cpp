#include <iostream>
#include <algorithm>

int main() {
    int nums[] = {1, 2, 3};
    int infpt = 0;
    int n = sizeof(nums) / sizeof(nums[0]);

    for (int i = n - 1; i > 0; i--) {
        if (nums[i] > nums[i - 1]) {
            infpt = i;
            break;
        }
    }

    if (infpt == 0) {
        std::sort(nums, nums + n);
    } else {
        int min = INT_MAX;
        int toswap = nums[infpt - 1];

        for (int j = infpt; j < n; j++) {
            if (nums[j] > toswap && nums[j] - toswap < min) {
                int temp = nums[j];
                nums[j] = nums[infpt - 1];
                nums[infpt - 1] = temp;
            }
        }

        std::sort(nums + infpt, nums + n);
    }

    std::cout << "Next permutation: ";
    for (int i = 0; i < n; i++) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
