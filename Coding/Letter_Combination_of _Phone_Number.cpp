#include <iostream>
using namespace std;

void solve(string digit, string output, int index, vector<string>& ans, string mapping[] )
{
    if(index> digits.length())
    {
        ans.push_back(output);
        return;
    }

    


}

int main()
{
    vector<string> ans;
    string digits;
    cout<<"Enter the digits"<<endl;
    cin>>digits;
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl","mno","pqrs","tuv","wxyz"};
    int index=0;
    string output;
    int ans[10][10];
    solve(digits, output, index, ans, mapping);


}