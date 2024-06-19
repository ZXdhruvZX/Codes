#include <iostream>
#include <algorithm>

int find_min(int nums[])
{
    int n = sizeof(nums) / sizeof(nums[0]);
    std::sort(nums, nums + n);
    return nums[0];
}

int main()
{
    int arr[] = {5, 2, 8, 1, 3};
    int min_value = find_min(arr);
    
    std::cout << "Minimum value: " << min_value << std::endl;

    return 0;
}

