#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<string> s;

    s.push("Dhruv");
    s.push("Shailendra");
    s.push("Sharma");

    cout<<"Top element->"<<s.top()<<endl;

    s.pop();

    cout<<"Top Element->"<<s.top()<<endl;

    cout<<"Size of stack->"<<s.size()<<endl;

    cout<<"Empty or not->"<<s.empty()<<endl;
}

