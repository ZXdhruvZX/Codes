#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

// Function to calculate (base^exp) % mod
long long modExp(long long base, long long exp, long long mod) {
    if (exp == 0) return 1;
    long long temp = modExp(base, exp / 2, mod);
    temp = (temp * temp) % mod;
    if (exp % 2 == 1) temp = (temp * base) % mod;
    return temp;
}

// Function to generate public and private keys
void generateKeys(long long& p, long long& g, long long& x, long long& y) {
    // Choose a large prime number p
    p = 23; // Example, you can choose a larger prime in practice

    // Choose a primitive root g of p
    g = 5; // Example, 5 is a primitive root of 23

    // Choose a private key x
    x = rand() % (p - 2) + 1; // Private key is a random number between 1 and p-1

    // Calculate public key y = g^x mod p
    y = modExp(g, x, p);
}

// Function for encryption
void encrypt(long long p, long long g, long long y, long long plainText, long long& cipherText1, long long& cipherText2) {
    // Choose a random number k
    long long k = rand() % (p - 2) + 1;

    // Calculate first part of cipherText1 = g^k mod p
    cipherText1 = modExp(g, k, p);

    // Calculate second part of cipherText2 = (y^k * plainText) mod p
    cipherText2 = (modExp(y, k, p) * plainText) % p;
}

// Function for decryption
long long decrypt(long long p, long long x, long long cipherText1, long long cipherText2) {
    // Calculate plainText = (cipherText2 * (cipherText1^(-x))) mod p
    long long denominator = modExp(cipherText1, x, p);
    long long inverse = modExp(denominator, p - 2, p); // Using Fermat's Little Theorem
    return (cipherText2 * inverse) % p;
}

int main() {
    long long p, g, x, y;
    generateKeys(p, g, x, y);

    long long plainText;
    cout << "Enter the plaintext: ";
    cin >> plainText;

    long long cipherText1, cipherText2;
    encrypt(p, g, y, plainText, cipherText1, cipherText2);
    cout << "Encrypted ciphertext: (" << cipherText1 << ", " << cipherText2 << ")" << endl;

    long long decryptedText = decrypt(p, x, cipherText1, cipherText2);
    cout << "Decrypted plaintext: " << decryptedText << endl;

    return 0;
}
