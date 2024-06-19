#include <iostream>
#include <string>
#include <vector>

// Function to print errors
void print_error(const std::string& msg) {
    std::cerr << "Error: " << msg << std::endl;
}

// Generate a random symmetric key
std::vector<unsigned char> generate_random_key(size_t key_length) {
    std::vector<unsigned char> key(key_length);
    for (size_t i = 0; i < key_length; ++i) {
        key[i] = static_cast<unsigned char>(rand() % 256);  // Generate random byte
    }
    return key;
}

// Encrypt data using a symmetric key
std::vector<unsigned char> encrypt_data(const std::vector<unsigned char>& data, const std::vector<unsigned char>& key) {
    std::vector<unsigned char> encrypted_data(data.size());
    for (size_t i = 0; i < data.size(); ++i) {
        encrypted_data[i] = data[i] ^ key[i % key.size()];  // XOR encryption
    }
    return encrypted_data;
}

// Decrypt data using a symmetric key
std::vector<unsigned char> decrypt_data(const std::vector<unsigned char>& encrypted_data, const std::vector<unsigned char>& key) {
    std::vector<unsigned char> decrypted_data(encrypted_data.size());
    for (size_t i = 0; i < encrypted_data.size(); ++i) {
        decrypted_data[i] = encrypted_data[i] ^ key[i % key.size()];  // XOR decryption
    }
    return decrypted_data;
}

int main() {
    // Generate a random symmetric key
    size_t key_length = 16;  // 128-bit key
    std::vector<unsigned char> symmetric_key = generate_random_key(key_length);

    // Original data
    std::string original_data = "Hello, ECC!";

    // Convert data to bytes
    std::vector<unsigned char> data_bytes(original_data.begin(), original_data.end());

    // Encrypt the data
    std::vector<unsigned char> encrypted_data = encrypt_data(data_bytes, symmetric_key);
    std::cout << "Data encrypted successfully!" << std::endl;

    // Decrypt the data
    std::vector<unsigned char> decrypted_data = decrypt_data(encrypted_data, symmetric_key);
    std::string decrypted_str(decrypted_data.begin(), decrypted_data.end());
    std::cout << "Data decrypted successfully: " << decrypted_str << std::endl;

    return 0;
}
