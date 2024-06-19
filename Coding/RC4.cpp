#include <iostream>
#include <vector>
using namespace std;

void encryption(int pt[], int key[], int n, int CipherText[]) {
    // Initialization of S and T
    vector<int> s(n);
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        s[i] = i;
        t[i] = key[i % 4];
    }
    int j = 0;
    // Permutation of S with T
    for (int i = 0; i < n; i++) {
        j = (j + s[i] + t[i]) % n;
        swap(s[i], s[j]);
    }
    // Stream Generation
    int k;
    int i = 0, temp;
    j = 0;
    for (int idx = 0; idx < 4; idx++) {
        i = (i + 1) % n;
        j = (j + s[i]) % n;
        swap(s[i], s[j]);
        temp = (s[i] + s[j]) % n;
        k = s[temp];
        CipherText[idx] = (k ^ pt[idx]);
    }
}

void decryption(int CipherText[], int key[], int n, int DecryptedText[]) {
    // Initialization of S and T
    vector<int> s(n);
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        s[i] = i;
        t[i] = key[i % 4];
    }
    int j = 0;
    // Permutation of S with T
    for (int i = 0; i < n; i++) {
        j = (j + s[i] + t[i]) % n;
        swap(s[i], s[j]);
    }
    // Stream Generation
    int k;
    int i = 0, temp;
    j = 0;
    for (int idx = 0; idx < 4; idx++) {
        i = (i + 1) % n;
        j = (j + s[i]) % n;
        swap(s[i], s[j]);
        temp = (s[i] + s[j]) % n;
        k = s[temp];
        DecryptedText[idx] = (k ^ CipherText[idx]);
    }
}

int main() {
    int key[4];
    int pt[4];
    int CipherText[4];
    int DecryptedText[4];

    cout << "Enter the Plain Text: ";
    for (int i = 0; i < 4; i++) {
        cin >> pt[i];
    }

    cout << "Enter the Key: ";
    for (int i = 0; i < 4; i++) {
        cin >> key[i];
    }

    int n;
    cout << "Enter the number of bits: ";
    cin >> n;

    encryption(pt, key, n, CipherText);
    cout << "Cipher Text: ";
    for (int i = 0; i < 4; i++) {
        cout << CipherText[i] << " ";
    }

    decryption(CipherText, key, n, DecryptedText);
    cout << "\nDecrypted Text: ";
    for (int i = 0; i < 4; i++) {
        cout << DecryptedText[i] << " ";
    }

    return 0;
}
