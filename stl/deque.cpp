#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque<int> d;

    d.push_back(2);  // Piche se 1 daala
    d.push_front(1); // Aage se 2 daala

    for (int i : d)
        cout << i << " ";

    //.front(),.back(),empty()functions all lie these

    d.push_back(3);
    d.push_back(4);
    d.push_back(5);

    // Erase function

    cout<<"Erase";

    d.erase(d.begin(), d.begin() + 2);    //1,2 hat gaye 

    for (int i : d)
        cout << i << " ";

    return 1;
}