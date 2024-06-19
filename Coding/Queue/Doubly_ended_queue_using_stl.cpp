//Doubly ended queue se front se dono push or pop k operation ho sakte h pop me front aage aayega or push me piche jaayega-same with rear

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    deque<int> d ;
    d.push_front(12);
    d.push_back(15);

    cout<<d.front()<<endl;
    cout<<d.back()<<endl;

    d.pop_front();

    cout<<d.front()<<endl;
    cout<<d.back()<<endl;

    d.pop_back();

    if(d.empty())
        cout<<"EMpty "<<endl;
    else
        cout<<"Not empty"<<endl;
}

