#include <iostream>
using namespace std;

void fibo(int &a, int &b)
{
    int temp = a + b;
    a = b;
    b = temp;
}

int main()
{
    int n;
    cout << "Enter the number of times you want the Fibonacci series to run" << endl;
    cin >> n;
    
    int *arr = new int[n];

    int a = 0;
    int b = 1;
    arr[0] = a;
    arr[1] = b;

    for (int i = 2; i < n; i++)
    {
        fibo(a, b);
        arr[i] = b;
    }

    if (n == 1 || n == 2)
    {
        cout << b;
    }
    else
    {
        cout << b;
    }



    // Free the dynamically allocated memory
    delete[] arr;

    return 0;
}
