#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        // Convert vector to array using data() method (also works with &nums[0])
        int* arr = nums.data();

        std::sort(arr, arr + n);

        for (int i = 0; i < n - 1; i++) { // Change n to n - 1 to avoid accessing out-of-bounds index
            if (arr[i] == arr[i + 1]) {
                sum = sum + 1;
                break;
            }
        }
        if (sum > 0)
            return true;
        else
            return false;
    }
};

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 2}; // Test input vector with a duplicate element

    Solution solution;
    bool hasDuplicate = solution.containsDuplicate(nums);

    if (hasDuplicate) {
        std::cout << "The vector contains duplicates." << std::endl;
    } else {
        std::cout << "The vector does not contain duplicates." << std::endl;
    }

    return 0;
}
