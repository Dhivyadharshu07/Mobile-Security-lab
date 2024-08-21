#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


std::string padText(const std::string &text, int length) {
    std::string paddedText = text;
    while (paddedText.length() % length != 0) {
        paddedText += 'X'; // Padding character
    }
    return paddedText;
}


std::string rowTranspositionEncrypt(const std::string &plaintext, const std::vector<int> &key) {
    int numCols = key.size();
    int numRows = (plaintext.length() + numCols - 1) / numCols;

    std::string paddedText = padText(plaintext, numCols);
    std::vector<std::string> grid(numRows);

   
    for (int i = 0; i < numRows; i++) {
        grid[i] = paddedText.substr(i * numCols, numCols);
    }

    
    std::string ciphertext = "";
    for (int col : key) {
        for (int row = 0; row < numRows; row++) {
            ciphertext += grid[row][col - 1]; // key is 1-based index
        }
    }

    return ciphertext;
}
std::string rowTranspositionDecrypt(const std::string &ciphertext, const std::vector<int> &key) {
    int numCols = key.size();
    int numRows = (ciphertext.length() + numCols - 1) / numCols;

    std::vector<std::string> grid(numRows, std::string(numCols, ' '));

    int index = 0;
    for (int col : key) {
        for (int row = 0; row < numRows; row++) {
            grid[row][col - 1] = ciphertext[index++];
        }
    }

    // Rebuild the plaintext from the grid
    std::string plaintext = "";
    for (const auto &row : grid) {
        plaintext += row;
    }

    // Remove padding (if any)
    plaintext.erase(std::find(plaintext.begin(), plaintext.end(), 'X'), plaintext.end());

    return plaintext;
}

int main() {
    std::string plaintext = "HELLOWORLD";
    std::vector<int> key = {4, 3, 1, 2, 5};

    std::string encryptedText = rowTranspositionEncrypt(plaintext, key);
    std::string decryptedText = rowTranspositionDecrypt(encryptedText, key);

    std::cout << "Plaintext: " << plaintext << std::endl;
    std::cout << "Encrypted: " << encryptedText << std::endl;
    std::cout << "Decrypted: " << decryptedText << std::endl;

    return 0;
}