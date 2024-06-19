#include <iostream>
using namespace std;

// Function prototype
int getSum(int *arr, int n);

int main()
{
    int n;
    cout << "Enter the array size" << endl;
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Sum of array=" << getSum(arr, n);

    // Don't forget to free the dynamically allocated memory
    delete[] arr;

    return 0;
}

int getSum(int *arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }

    return sum;
}
