#include <iostream>
#include <algorithm>

int func(int arr[], int n, int k)
{
    std::sort(arr, arr + n);
    return arr[k - 1];
}

int main()
{
    int n, k;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    int arr[n];
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    std::cout << "Enter the value of k: ";
    std::cin >> k;

    int result = func(arr, n, k);
    std::cout << "The k-th smallest element is: " << result << std::endl;

    return 0;
}

