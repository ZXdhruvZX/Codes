#include <iostream>
using namespace std;

int binarysearch(int s, int e, int arr[], int key, int n)
{
    if (n == 0)
    {
        return -1; // Element not found
    }

    int mid = (s + e) / 2;

    if (arr[mid] == key)
    {
        return mid; // Element found
    }
    else if (arr[mid] > key)
    {
        return binarysearch(s, mid, arr, key, n);
    }
    else if (arr[mid] < key)
    {
        return binarysearch(mid, e, arr, key, n);
    }

    return -1; // Element not found
}

int main()
{
    int key, n;
    cout << "Enter the element you want to search" << endl;
    cin >> key;
    cout << "Enter the size of array" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int s = 0;
    int e = n - 1;
    int ans = binarysearch(s, e, arr, key, n);

    if (ans != -1)
    {
        cout << "Element found at index: " << ans << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    return 0;
}
