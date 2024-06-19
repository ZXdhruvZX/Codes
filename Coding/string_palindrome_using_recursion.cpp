#include <iostream>
using namespace std;

string palin(string str2, int s, int e)
{
    if (s < e)
    {
        swap(str2[s], str2[e]);
        s++;
        e--;
        return palin(str2, s, e);
    }
    return str2;
}

int main()
{
    string str;
    cout << "Enter the string" << endl;
    cin >> str;

    int size = str.length();
    int s = 0;
    int e = size - 1;

    string str2 = palin(str, s, e);

    cout << "Reversed string: " << str2 << endl;

    if (str == str2)
    {
        cout << "String is a Palindrome" << endl;
    }
    else
    {
        cout << "String is not a palindrome" << endl;
    }

    return 0;
}
