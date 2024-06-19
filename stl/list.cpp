#include <iostream>

#include <list>

using namespace std;

int main()
{
    list<int> l;

    l.push_back(2);
    l.push_front(1);

    for(int i:l)
    cout<<i<<endl;

    //Similarly we can run erase and size and other functions

    list<int> n(5,100); //n me 5 baar 100 store ho jayega
    for(int i:n)
    cout<<i<<endl;
}