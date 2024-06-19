#include <iostream>
#include <string>
using namespace std;

// Function which computes the sequence
string printSequence(string arr[], string input) {
    string output = "";

    // Length of input string
    int n = input.length();
    for (int i = 0; i < n; i++) {
        // Checking for space
        if (input[i] == ' ')
            output = output + "0";

        else {
            // Calculating index for each character
            int position = input[i] - 'A';
            cout<<position;

            // Make sure the position is within the valid range
            if (position >= 0 && position <= 25) {
                output = output + arr[position];
            }
        }
    }

    // Output sequence
    return output;
}

int main() {
    // Storing the sequence in an array
    string str[] = { "2", "22", "222", "3", "33", "333", "4",
                     "44", "444", "5", "55", "555", "6", "66",
                     "666", "7", "77", "777", "7777", "8", "88",
                     "888", "9", "99", "999", "9999" };

    string input;
    cout << "Enter the input string: ";
    cin >> input;
    cout << printSequence(str, input) << endl;
    return 0;
}
