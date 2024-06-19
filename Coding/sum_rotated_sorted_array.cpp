#include <iostream>
#include <algorithm>

void sum_rotated(int nums[], int n, int sum)
{
    std::sort(nums, nums + n);
    int t = -1;
    for (int i = 0; i < n; i++) {
        if (nums[i] == sum) {
            t = i;
            break;
        }
    }
    
    if (t == -1) {
        std::cout << "no" << std::endl;
        return;
    }
    
    for (int i = 0; i <= t; i++) {
        int r = nums[i];
        for (int j = 0; j <= t; j++) {
            if (r + nums[j] == sum && i != j) {
                std::cout << "yes" << std::endl;
                return;
            }
        }
    }
    
    std::cout << "no" << std::endl;
}

int main()
{
    int arr[] = {5, 2, 8, 1, 3};
    int sum = 8;
    
    int n = sizeof(arr) / sizeof(arr[0]);
    sum_rotated(arr, n, sum);

    return 0;
}

