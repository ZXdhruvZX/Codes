// C++ implementation of the approach to find maximum and minimum of an array using minimum and maximum no. of comparisons




#include <algorithm>
#include <iostream>
using namespace std;

struct Pair {                    //Structure is used when we want to allow different types of datatype into a single name
	int min;
	int max;
};

Pair getMinMax(int arr[], int n)        
{
	Pair minmax;

	sort(arr, arr + n);                   //sort function use karne k liye algorithm header use karenge

	minmax.min = arr[0];
	minmax.max = arr[n - 1];

	return minmax;
}

int main()
{
	int arr[] = { 1000, 11, 445, 1, 330, 3000 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	Pair minmax = getMinMax(arr, arr_size);

	cout << "Minimum element is " << minmax.min << endl;
	cout << "Maximum element is " << minmax.max << endl;

	return 0;
}

