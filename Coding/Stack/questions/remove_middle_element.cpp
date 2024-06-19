#include <iostream>
#include <stack>

void solve(std::stack<int>& inputStack, int count, int size) {
    // Base case
    if (count == size / 2) {
        inputStack.pop();
        return;
    }

    int num = inputStack.top();
    inputStack.pop();

    // Recursive call
    solve(inputStack, count + 1, size);

    inputStack.push(num);
}

void deleteMiddle(std::stack<int>& inputStack, int N) {
    int count = 0;
    solve(inputStack, count, N);
}

int main() {
    // Create a stack and push some elements
    std::stack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);

    // Display the original stack
    std::cout << "Original Stack: ";
    while (!myStack.empty()) {
        std::cout << myStack.top() << " ";
        myStack.pop();
    }
    std::cout << std::endl;

    // Push elements again for demonstration
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);

    // Delete the middle element
    deleteMiddle(myStack, myStack.size());

    // Display the stack after deleting the middle element
    std::cout << "Stack after deleting middle element: ";
    while (!myStack.empty()) {
        std::cout << myStack.top() << " ";
        myStack.pop();
    }
    std::cout << std::endl;

    return 0;
}
