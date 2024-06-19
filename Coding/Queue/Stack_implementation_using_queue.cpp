#include <iostream>
#include <queue>

class MyStack {
private:
    std::queue<int> queue1;
    std::queue<int> queue2;

public:
    MyStack() {}

    void push(int x) {
        if (queue1.empty()) {
            queue1.push(x);
            while (!queue2.empty()) {
                queue1.push(queue2.front());
                queue2.pop();
            }
        } else {
            queue2.push(x);
            while (!queue1.empty()) {
                queue2.push(queue1.front());
                queue1.pop();
            }
        }
    }

    int pop() {
        int topElement = -1;
        if (!queue1.empty()) {
            topElement = queue1.front();
            queue1.pop();
        } else if (!queue2.empty()) {
            topElement = queue2.front();
            queue2.pop();
        }
        return topElement;
    }

    int top() {
        if (!queue1.empty()) {
            return queue1.front();
        } else if (!queue2.empty()) {
            return queue2.front();
        }
        return -1;
    }

    bool empty() {
        return queue1.empty() && queue2.empty();
    }
};

int main() {
    MyStack stack;
    stack.push(1);
    stack.push(2);

    std::cout << "Top element: " << stack.top() << std::endl;
    int poppedElement = stack.pop();
    std::cout << "Pop: " << poppedElement << std::endl;
    std::cout << "Is empty: " << (stack.empty() ? "true" : "false") << std::endl;

    return 0;
}
