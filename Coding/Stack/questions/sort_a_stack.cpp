#include <iostream>
#include <stack>
using namespace std;
void sortedinsert(stack<int> &s, int num)
{
    if (s.empty() || s.top() < num)
    {
        s.push(num);
        return;
    }

    int n = s.top();
    s.pop();

    // recursive calls
    sortedinsert(s, num);
    s.push(n);
}
void sortedstack(stack<int> &stack)
{
    if (stack.empty())
        return;

    int num = stack.top();
    stack.pop();

    // recursive_calls
    sortedstack(stack);

    sortedinsert(stack, num);
}

int main()
{
    std::stack<int> myStack;
    myStack.push(5);
    myStack.push(-2);
    myStack.push(9);
    myStack.push(-7);
    myStack.push(3);

    sortedstack(myStack);
    while (!myStack.empty())
    {
        std::cout << myStack.top() << " ";
        myStack.pop();
    }
}