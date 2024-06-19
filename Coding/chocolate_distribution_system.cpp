#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arr[] = {7, 3, 2, 4, 9, 12, 56};
    int n = sizeof(arr) / sizeof(arr[0]);
    int m;

    cout << "Enter the number of students: ";
    cin >> m;

    int ar1[m];

    sort(arr, arr + n);

    int i, j = 0;
    int x = 0;
    int ar2[m];
    int min_diff = INT_MAX; // Initialize to a large value

    for (i = 0; i + m <= n; i++)
    {
        for (j = 0; j < m; j++)
        {
            ar1[j] = arr[i + j]; // Corrected the index in accessing arr
        }

        int diff = ar1[m - 1] - ar1[0]; // Corrected the index in accessing ar1

        if (diff < min_diff)
        {
            min_diff = diff;
            for (int k = 0; k < m; k++)
                ar2[k] = ar1[k];
        }
    }

    cout << "Minimum difference between tallest and shortest is: " << min_diff << endl;

    cout << "Selected heights: ";
    for (int k = 0; k < m; k++)
        cout << ar2[k] << " ";
    cout << endl;

    return 0;
}
