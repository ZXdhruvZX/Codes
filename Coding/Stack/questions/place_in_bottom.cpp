#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int> &s, int x)
{
    // base case
    if (s.empty())
    {
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();

    // recursive call
    solve(s, x);

    s.push(num);
}

stack<int> pushAtBottom(stack<int> &myStack, int x)
{
    solve(myStack, x);
    return myStack;
}

int main()
{
    std::stack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);
    int x;
    cout << "Enter the element you want to place at bottom ";
    cin >> x;
    pushAtBottom(myStack, x);
    while (!myStack.empty())
    {
        std::cout << myStack.top() << " ";
        myStack.pop();
    }
}