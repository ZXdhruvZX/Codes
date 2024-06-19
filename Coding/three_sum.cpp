
#include <iostream>
#include <algorithm>

int* three_sum(int a[], int n) {
    int* a1 = new int[3];
    int *ptr=NULL;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                if(a[i] + a[j] + a[k] == 0) {
                    a1[0] = a[i];
                    a1[1] = a[j];
                    a1[2] = a[k];
                    return a1;
                }
            }
        }
    }
    return ptr; // Return nullptr if no such triplet is found
}

int main() {
	int *ptr=NULL;
    int nums[] = { -1, 0, 1, 2, -1, -4 };
    int n = sizeof(nums) / sizeof(nums[0]);

    int* result = three_sum(nums, n);
    if(result != ptr) {
        std::cout << "Three elements that sum up to 0 are: " << result[0] << ", " << result[1] << ", " << result[2] << std::endl;
        delete[] result; // Free the dynamically allocated memory
    } else {
        std::cout << "No such triplet found." << std::endl;
    }

    return 0;
}

