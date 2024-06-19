// #include <iostream>
// #include <stack>
// using namespace std;

// class Stack
// {
// public:
//     int *arr;
//     int top;
//     int size;

//     Stack(int size)
//     {
//         this->size = size;
//         arr = new int[size];
//         top = -1;
//     }

//     void push(int element)
//     {
//         if (top < size - 1)
//         {
//             top++;
//             arr[top] = element;
//         }
//         else
//         {
//             cout << "Stack Overflow" << endl;
//         }
//     }

//     void pop()
//     {
//         if (top == -1)
//             cout << "Stack is empty" << endl;
//         else
//         {
//             while (top != -1)
//             {
//                 cout << static_cast<char>(arr[top]) << " ";
//                 top--;
//             }
//             cout << endl;
//         }
//     }
// };

// int main()
// {
//     Stack st(5);  // Create a single Stack object
//     st.push('v'); // Assuming you want to push characters
//     st.push('o');
//     st.push('i');
//     st.push('d');
//     st.push('s');

//     st.pop();

//     return 0;
// }






#include<iostream>
#include<stack>
using namespace std;



int main () {
    string str = "babbar";

    stack<char> s;

    for (int i = 0; i<str.length(); i++) {
        char ch = str[i];
        s.push(ch);
    }

    string ans = "";

    while(!s.empty()) {
        char ch = s.top();
        ans.push_back(ch);

        s.pop();
    }

    cout << "answer is: "<< ans << endl;

    return 0;
}