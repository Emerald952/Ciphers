#include "caesar_cipher.h"

void Caesar_encrypt(const std::string& plain_text, long key, std::string& cipher_text){
    cipher_text.resize(plain_text.length());
    for (long i = 0; i < plain_text.length(); i++){
        if(plain_text[i] >= 'a' && plain_text[i] <= 'z'){
            long x = plain_text[i] - 'a';
            x = (x + key + 26) % 26;
            cipher_text[i] = static_cast<char>('a' + x);
        }
        else if(plain_text[i] >= 'A' && plain_text[i] <= 'Z'){
            long x = plain_text[i] - 'A';
            x = (x + key + 26) % 26;
            cipher_text[i] = static_cast<char>('A' + x);
        }
        else{
            cipher_text[i] = plain_text[i];
        }
    }
}

void Caesar_decrypt(const std::string& cipher_text, long key, std::string& plain_text){
    plain_text.resize(cipher_text.length());
    for (long i = 0; i < cipher_text.length(); i++){
        if(cipher_text[i] >= 'a' && cipher_text[i] <= 'z'){
            long x = cipher_text[i] - 'a';
            x = (x - key + 26) % 26;
            plain_text[i] = static_cast<char>('a' + x);
        }
        else if(cipher_text[i] >= 'A' && cipher_text[i] <= 'Z'){
            long x = cipher_text[i] - 'A';
            x = (x - key + 26) % 26;
            plain_text[i] = static_cast<char>('A' + x);
        }
        else{
            plain_text[i] = cipher_text[i];
        }
    }
}