#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int charToNum(char c) {
    return toupper(c) - 'A';
}

char numToChar(int n) {
    return static_cast<char>(n + 'A');
}

int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1;
}

string encrypt(const string& message, const vector<vector<int>>& keyMatrix) {
    int keySize = keyMatrix.size();
    int blockSize = keySize;

    string paddedMessage = message;
    while (paddedMessage.length() % blockSize != 0) {
        paddedMessage.push_back('X');
    }

    string ciphertext = "";
    for (int i = 0; i < paddedMessage.length(); i += blockSize) {
        vector<int> block(blockSize, 0);
        for (int j = 0; j < blockSize; ++j) {
            block[j] = charToNum(paddedMessage[i + j]);
        }

        for (int j = 0; j < blockSize; ++j) {
            int sum = 0;
            for (int k = 0; k < blockSize; ++k) {
                sum += keyMatrix[j][k] * block[k];
            }
            ciphertext.push_back(numToChar(sum % 26));
        }
    }

    return ciphertext;
}
string decrypt(const string& ciphertext, const vector<vector<int>>& keyMatrix) {
    int keySize = keyMatrix.size();
    int blockSize = keySize;

    // Calculate determinant and its inverse
    int det = keyMatrix[0][0] * (keyMatrix[1][1] * keyMatrix[2][2] - keyMatrix[1][2] * keyMatrix[2][1])
             - keyMatrix[0][1] * (keyMatrix[1][0] * keyMatrix[2][2] - keyMatrix[1][2] * keyMatrix[2][0])
             + keyMatrix[0][2] * (keyMatrix[1][0] * keyMatrix[2][1] - keyMatrix[1][1] * keyMatrix[2][0]);

    det = (det % 26 + 26) % 26;

    int detInverse = modInverse(det, 26);

    // Calculate adjugate matrix
    vector<vector<int>> adjugate(keySize, vector<int>(keySize, 0));
    adjugate[0][0] = (keyMatrix[1][1] * keyMatrix[2][2] - keyMatrix[1][2] * keyMatrix[2][1]);
    adjugate[0][1] = (keyMatrix[0][2] * keyMatrix[2][1] - keyMatrix[0][1] * keyMatrix[2][2]);
    adjugate[0][2] = (keyMatrix[0][1] * keyMatrix[1][2] - keyMatrix[0][2] * keyMatrix[1][1]);
    adjugate[1][0] = (keyMatrix[1][2] * keyMatrix[2][0] - keyMatrix[1][0] * keyMatrix[2][2]);
    adjugate[1][1] = (keyMatrix[0][0] * keyMatrix[2][2] - keyMatrix[0][2] * keyMatrix[2][0]);
    adjugate[1][2] = (keyMatrix[0][2] * keyMatrix[1][0] - keyMatrix[0][0] * keyMatrix[1][2]);
    adjugate[2][0] = (keyMatrix[1][0] * keyMatrix[2][1] - keyMatrix[1][1] * keyMatrix[2][0]);
    adjugate[2][1] = (keyMatrix[0][1] * keyMatrix[2][0] - keyMatrix[0][0] * keyMatrix[2][1]);
    adjugate[2][2] = (keyMatrix[0][0] * keyMatrix[1][1] - keyMatrix[0][1] * keyMatrix[1][0]);

    // Calculate inverse matrix
    vector<vector<int>> inverse(keySize, vector<int>(keySize, 0));
    for (int i = 0; i < keySize; ++i) {
        for (int j = 0; j < keySize; ++j) {
            inverse[i][j] = (adjugate[i][j] * detInverse) % 26;
            if (inverse[i][j] < 0) {
                inverse[i][j] += 26;  // Ensure positive result
            }
        }
    }

    // Decrypt the ciphertext
    string plaintext = "";
    for (int i = 0; i < ciphertext.length(); i += blockSize) {
        vector<int> block(blockSize, 0);
        for (int j = 0; j < blockSize; ++j) {
            block[j] = charToNum(ciphertext[i + j]);
        }

        for (int j = 0; j < blockSize; ++j) {
            int sum = 0;
            for (int k = 0; k < blockSize; ++k) {
                sum += inverse[j][k] * block[k];
            }
            plaintext.push_back(numToChar(sum % 26));
        }
    }

    return plaintext;
}

int main() {
    int keySize;
    cout << "Enter the size of the key matrix (e.g., 2 for a 2x2 matrix): ";
    cin >> keySize;

    vector<vector<int>> keyMatrix(keySize, vector<int>(keySize, 0));
    cout << "Enter the key matrix elements (row-wise):" << endl;
    for (int i = 0; i < keySize; ++i) {
        for (int j = 0; j < keySize; ++j) {
            cin >> keyMatrix[i][j];
        }
    }

    string message;
    cout << "Enter the message to be encrypted: ";
    cin.ignore(); // Ignore newline from previous input
    getline(cin, message);

    // Encryption
    string ciphertext = encrypt(message, keyMatrix);
    cout << "Encrypted: " << ciphertext << endl;

    // Decryption
    string decryptedText = decrypt(ciphertext, keyMatrix);
    cout << "Decrypted: " << decryptedText << endl;

    return 0;
}