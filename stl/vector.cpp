#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    cout << "size-" << v.capacity() << endl;

    v.push_back(0);
    cout << "size-" << v.capacity() << endl; // Vector ki capacity bharne par double hoti rehti h

    v.push_back(1);
    cout << "size-" << v.capacity() << endl;

    v.push_back(2);
    cout << "size-" << v.capacity() << endl;

    cout << "size-" << v.size() << endl; // Size tell ki kitne elements bhare huue h

    cout << "Element at 2nd index is :" << v.at(2) << endl;

 

    cout << "before pop back function";
    for (int i : v)
        cout << i << " ";
    cout << endl;

    v.pop_back();

    cout << "After Pop"<<endl;

    for (int i : v)
        cout << i << " ";
    cout << endl;

       return 0;
}
