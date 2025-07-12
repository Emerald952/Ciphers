#include "xor_ciphers.h"

void str_to_binary(const std::string& str){
    for(char c : str){
        unsigned char x = static_cast<unsigned char>(c);
        for(int i = 7; i >= 0; i--){
            std::cout << ((x >> i) & 1);
        } 
        std::cout<< " ";
    }
    std::cout << std::endl;
}

void XOR_encryptdecrypt(const std::string& XOR_text, char key, std::string& cipher_text){
    cipher_text.resize(XOR_text.length());
    for (long i = 0; i < XOR_text.length(); i++){
        cipher_text[i] = XOR_text[i] ^ key;
    }
}

void XOR_encryptdecrypt_general(const std::string& XOR_text, const std::string& key, std::string& cipher_text){
    if(XOR_text.empty() || key.empty()){
        cipher_text.clear();
        return;
    }

    cipher_text.resize(XOR_text.length());
    long key_len = key.length();

    for (long i = 0; i < XOR_text.length(); i++)    {
        cipher_text[i] = XOR_text[i] ^ key[i % key_len];
    }
}

void one_time_pad_encryptdecrypt(const std::string& XOR_text, const std::string& key, std::string& cipher_text){
    if(key.length() < XOR_text.length()){
        std::cerr<<"Warning: Key for One-Time Pad is shorter than plaintext. Not a true OTP.\n";
    }
    XOR_encryptdecrypt_general(XOR_text, key, cipher_text);
}
