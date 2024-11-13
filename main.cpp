#include <iostream>
#include <string>
#include <algorithm>   // algorithm library

// This function to generate key for Autokey Vigenère system
std::string generateKey(const std::string& plaintext, const std::string& keyword) {
    std::string key = keyword;
    int keyLength = keyword.length();
    int textLength = plaintext.length();

// Repeats the keyword then uses the plaintext for the remaining characters
    for (int i = 0; i < textLength - keyLength; ++i) {
        key += plaintext[i];
    }

    return key;
}

// This function encrypts the plaintext using the key
std::string encrypt(const std::string& plaintext, const std::string& key) {
    std::string cipherText;
    for (size_t i = 0; i < plaintext.length(); ++i) {
        char x = (plaintext[i] + key[i]) % 26;
        x += 'A';
        cipherText += x;
    }
    return cipherText;
}

// This function decrypts the ciphertext using the key
std::string decrypt(const std::string& cipherText, const std::string& key) {
    std::string decryptedText;
    for (size_t i = 0; i < cipherText.length(); ++i) {
        char x = (cipherText[i] - key[i] + 26) % 26;
        x += 'A';
        decryptedText += x;
    }
    return decryptedText;
}

int main() {
    std::string plaintext, keyword;

// This takes the users input for plaintext
    std::cout << "Enter plaintext (max 15 characters): ";
    std::cin >> plaintext;
    if (plaintext.length() > 15) {
        std::cerr << "Plaintext exceeds maximum length of 15 characters." << std::endl;
        return 1;
    }

// This takes the users input for keyword
    std::cout << "Enter keyword (2-15 characters): ";
    std::cin >> keyword;
    if (keyword.length() < 2 || keyword.length() > 15) {
        std::cerr << "Keyword length must be between 2 and 15 characters." << std::endl;
        return 1;
    }

// This converts the plaintext and keyword to uppercase to handle lowercase letters
    std::transform(plaintext.begin(), plaintext.end(), plaintext.begin(), ::toupper);
    std::transform(keyword.begin(), keyword.end(), keyword.begin(), ::toupper);

// This generates the key that matches the plaintext length
    std::string key = generateKey(plaintext, keyword);
    
// This encrypts the plaintext using the key.
    std::string cipherText = encrypt(plaintext, key);
    std::cout << "Encrypted Text: " << cipherText << std::endl;

// This decrypts the ciphertext using the key.
    std::string decryptedText = decrypt(cipherText, key);
    std::cout << "Decrypted Text: " << decryptedText << std::endl;

    return 0;
}