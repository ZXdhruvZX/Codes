#include <iostream>
#include <stack>
using namespace std;

void parenthesis(string s, int size) {
    stack<char> inp;
    for (int i = 0; i < size; i++) {
        char ch = s[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            inp.push(ch);
        } else {
            if (!inp.empty()) {
                char top = inp.top();
                if ((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '[')) {
                    inp.pop();
                } else {
                    cout << "Invalid" << " " << endl;
                    return;
                }
            } else {
                cout << "Invalid" << " " << endl;
                return;
            }
        }
    }

    if (!inp.empty()) {
        cout << "Invalid" << " " << endl;
    } else {
        cout << "Valid" << " " << endl;
    }
}

int main() {
    string s = "";
    int size;
    cout << "Enter the total length: ";
    cin >> size;
    cout << "Enter the parentheses: ";
    for (int i = 0; i < size; i++) {
        char ch;
        cin >> ch;
        s.push_back(ch);
    }

    parenthesis(s, size);

    return 0;
}
