#include <iostream>
using namespace std;


string encrypting(string p_text, int key) {
    string c_text = "";
    for (int i = 0; i < p_text.length(); i++) {
        if (isupper(p_text[i])) {
            c_text += char((int(p_text[i]) + key - 65) % 26 + 65);
        } else if (islower(p_text[i])) {
            c_text += char((int(p_text[i]) + key - 97) % 26 + 97);
        } else {
            c_text += p_text[i]; 
        }
    }
    return c_text;
}


string decrypting(string c_text, int key) {
    string p_text = "";
    for (int i = 0; i < c_text.length(); i++) {
        if (isupper(c_text[i])) {
            p_text += char((int(c_text[i]) - key - 65 + 26) % 26 + 65);
        } else if (islower(c_text[i])) {
            p_text += char((int(c_text[i]) - key - 97 + 26) % 26 + 97);
        } else {
            p_text += c_text[i]; 
        }
    }
    return p_text;
}

int main() {
    string p_text = "";
    cout << "Enter the plain text: ";
    cin >> p_text;

    int key;
    cout << "Enter Key: ";
    cin >> key;


    key = key % 26;

    string c_text = encrypting(p_text, key);
    string decrypted_text = decrypting(c_text, key);

    cout << "Plain Text : " << p_text << endl;
    cout << "Shift: " << key << endl;
    cout << "Cipher Text: " << c_text << endl;
    cout << "Decrypted Text: " << decrypted_text << endl;

    return 0;
}
