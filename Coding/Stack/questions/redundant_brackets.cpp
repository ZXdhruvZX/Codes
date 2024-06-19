#include<stack>
#include<iostream>
using namespace std;

bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for(int i=0; i<s.length(); i++) {
        char ch =s[i];
        
        if(ch == '(' || ch == '+' ||ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        }
        else
        {
            //ch ya toh ')' hai or lowercase letter
            
            if(ch == ')') {
                bool isRedundant = true;
                
                while(st.top() != '(') {
                    char top = st.top();
                    if(top == '+' ||top == '-' || top == '*' || top == '/') {
                        isRedundant = false;
                    }
                    st.pop();
                }
                
                if(isRedundant == true)
                    return true;
                st.pop();
            }
            
        } 
    }
    return false;
}

int main() {
    // Test cases
    string test1 = "{(a+b)}";
    string test2 = "((a+b))";
    string test3 = "((a+b)*c)";
    string test4 = "(a+b)";
    
    cout << "Test 1: " << (findRedundantBrackets(test1) ? "Redundant brackets are present" : "Redundant brackets are not present") << endl;
    cout << "Test 2: " << (findRedundantBrackets(test2) ? "Redundant brackets are present" : "Redundant brackets are not present") << endl;
    cout << "Test 3: " << (findRedundantBrackets(test3) ? "Redundant brackets are present" : "Redundant brackets are not present") << endl;
    cout << "Test 4: " << (findRedundantBrackets(test4) ? "Redundant brackets are present" : "Redundant brackets are not present") << endl;

    return 0;
}