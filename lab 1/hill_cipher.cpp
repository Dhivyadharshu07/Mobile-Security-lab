#include <iostream>
using namespace std;


void generateKeyMatrix(const string& key, int keyMatrix[][2]) {
    int index = 0;
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 2; col++) {
            keyMatrix[row][col] = (key[index] - 97) % 26;
            index++;
        }
    }
}


void encryptp_txt(int cipherMatrix[][1], const int keyMatrix[][2], const int p_txtVector[][1]) {
    int sum;
    for (int row = 0; row < 2; row++) {
        sum = 0;
        for (int col = 0; col < 2; col++) {
            sum += keyMatrix[row][col] * p_txtVector[col][0];
        }
        cipherMatrix[row][0] = sum % 26;
    }
}

void hill_cipher_encrypt(const string& p_txt, const string& key) {
    if (p_txt.length() != 2) {
        cerr << "Error: p_txt must be exactly 2 characters long." << endl;
        return;
    }
    if (key.length() != 4) {
        cerr << "Error: Key must be exactly 4 characters long." << endl;
        return;
    }

    int keyMatrix[2][2];
    generateKeyMatrix(key, keyMatrix);

    int p_txtVector[2][1];
    for (int i = 0; i < 2; i++)
        p_txtVector[i][0] = (p_txt[i] - 'A') % 26;

    int cipherMatrix[2][1];
    encryptp_txt(cipherMatrix, keyMatrix, p_txtVector);

    string c_txt;
    for (int i = 0; i < 2; i++)
        c_txt += char(cipherMatrix[i][0] + 'A');

    cout << "c_txt: " << c_txt << endl;
}

int main() {
    string p_txt;
    cout <<"Enter the plain text:";
    cin >> p_txt;

    string key;
     cout <<"Enter the key:";
    cin >> key;

    hill_cipher_encrypt(p_txt, key);

    return 0;
}
