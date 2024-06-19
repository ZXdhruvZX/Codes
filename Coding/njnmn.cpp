#include <iostream>

int main()
{
    int n, m;
    std::cin >> n;
    std::cin >> m;
    int bus = 0;
    int tot_people = 0; 
    int a[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] < m)
        {
            bus++;
            a[i] = 0;
        }
        else if (a[i] > m)
        {
            bus++;
            a[i] = 0;
            a[i + 1] += a[i] - m; 
        }
    }
    std::cout << bus; 
    return 0; 
}
