#include <iostream>
#include <array> // Include the <array> header to use std::array

using namespace std;

int main()
{
	int basic[3]={1,2,3};
	
    array<int, 4> a = {1, 2, 3, 4};

    int size = a.size();

    for (int i = 0; i < size; i++)
    {
        cout << a[i] << endl;
    }

    cout << "Element at 2nd place: " << a.at(2) << endl; // Use [] operator for arrays

    cout << "Check if the array is empty or not:"<<a.empty()<<endl; // Arrays don't have an empty() function

    cout << "First element: " << a.front() << endl;

    cout << "Last element: " << a.back() << endl;

    return 0;
}

