#include <iostream>
#include <algorithm>

int* product_array(int a[], int n) {
    int* prod = new int[n];
    for (int i = 0; i < n; i++) {
        int prod1 = 1;
        for (int j = 0; j < n; j++) {
            if (j != i) {
                prod1 *= a[j];
            }
        }
        prod[i] = prod1;
    }
    return prod;
}

int main() {
    int arr[] = {2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int* result = product_array(arr, n);

    std::cout << "Product Array: ";
    for (int i = 0; i < n; i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    delete[] result;

    return 0;
}

