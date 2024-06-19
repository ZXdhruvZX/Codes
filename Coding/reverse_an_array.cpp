/*
#include <iostream>
using namespace std;

int main() {
    int d;
    cout << "Enter the size of the array: ";
    cin >> d;
    int arr[d];
    int rev_arr[d];

    for (int i = 0; i < d; i++) {
        cout << "Enter the element at index " << i << ": ";
        cin >> arr[i];
    }

    for (int i = d - 1; i >= 0; i--) {
        rev_arr[d - 1 - i] = arr[i];
    }

    cout << "After reversing we get: ";
    for (int i = 0; i < d; i++) {
        cout << rev_arr[i] << " ";
    }

    return 0;
}

*/


//--------------------------------------------------------------------------------------------------------------------------------------


//Starting value or end value ko swap karenge

// Iterative C++ program to reverse an array
#include <bits/stdc++.h>
using namespace std;

/* Function to reverse arr[] from start to end*/
void rvereseArray(int arr[], int start, int end)
{
	while (start < end)
	{
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}	


/* Utility function to print an array */
void printArray(int arr[], int size)
{
for (int i = 0; i < size; i++)
cout << arr[i] << " ";

cout << endl;
}

/* Driver function to test above functions */
int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6};
	
	int n = sizeof(arr) / sizeof(arr[0]);

	// To print original array
	printArray(arr, n);
	
	// Function calling
	rvereseArray(arr, 0, n-1);
	
	cout << "Reversed array is" << endl;
	
	// To print the Reversed array
	printArray(arr, n);
	
	return 0;
}
