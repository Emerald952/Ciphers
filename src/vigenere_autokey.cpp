#include "vigenere_autokey.h"


void vigenere_encrypt(const std::string& plain_text, const std::string& key, std::string& cipher_text){
    if(plain_text.empty() || key.empty()){
        cipher_text.clear();
        return;
    }
    cipher_text.resize(plain_text.length());
    for (long i = 0; i < plain_text.length(); i++){
        char _key = key[i % key.length()];
        long shift = 0;
        if(_key >= 'a' && _key <= 'z'){
            shift = (_key - 'a');
        }
        else if(_key >= 'A' && _key <= 'Z'){
            shift = (_key - 'A');
        }

        if(plain_text[i] >= 'a' && plain_text[i] <= 'z'){
            long k_val = (plain_text[i] - 'a');
            k_val = (k_val + shift) % 26;
            cipher_text[i] = static_cast<char>(k_val + 'a');
        }
        else if(plain_text[i] >= 'A' && plain_text[i] <= 'Z'){
            long k_val = (plain_text[i] - 'A');
            k_val = (k_val + shift) % 26;
            cipher_text[i] = static_cast<char>(k_val + 'A');
        }
        else{
            cipher_text[i] = plain_text[i];
        }
    }
}

void vigenere_decrypt(const std::string&  cipher_text, const std::string& key, std::string& plain_text){
    if(cipher_text.empty() || key.empty()){
        plain_text.clear();
        return;
    }

    plain_text.resize(cipher_text.length());
    for (long i = 0; i < cipher_text.length(); i++){
        char _key = key[i % key.length()];
        long shift = 0;
        if(_key >= 'a' && _key <= 'z'){
            shift = (_key - 'a');
        }
        else if(_key >= 'A' && _key <= 'Z'){
            shift = (_key - 'A');
        }
        
        if(cipher_text[i] >= 'a' && cipher_text[i] <= 'z'){
            long k_val = (cipher_text[i] - 'a');
            k_val = (k_val - shift + 26) % 26;
            plain_text[i] = static_cast<char>(k_val + 'a');
        }
        else if(cipher_text[i] >= 'A' && cipher_text[i] <= 'Z'){
            long k_val = (cipher_text[i] - 'A');
            k_val = (k_val - shift + 26) % 26;
            plain_text[i] = static_cast<char>(k_val + 'A');
        }
        else{
            plain_text[i] = cipher_text[i];
        }
    }
}

void autokey_encrypt(const std::string& plain_text, const std::string& init_key, std::string& cipher_text){
    if(plain_text.empty() || init_key.empty()){
        cipher_text.clear();
        return;
    }

    cipher_text.resize(plain_text.length());

    for (long i = 0; i < plain_text.length(); ++i){
        char curr_key;
        if(i < init_key.length()){
            curr_key = init_key[i];
        }
        else{
            curr_key = plain_text[i - init_key.length()];
        }
        long shift = 0;
        if(curr_key >= 'a' && curr_key <= 'z'){
            shift = (curr_key - 'a');
        }
        else if(curr_key >= 'A' && curr_key <= 'Z'){
            shift = (curr_key - 'A');
        }

        if(plain_text[i] >= 'a' && plain_text[i] <= 'z'){
            long k_val = (plain_text[i] - 'a');
            k_val = (k_val + shift) % 26;
            cipher_text[i] = static_cast<char>(k_val + 'a');
        }
        else if(plain_text[i] >= 'A' && plain_text[i] <= 'Z'){
            long k_val = (plain_text[i] - 'A');
            k_val = (k_val + shift) % 26;
            cipher_text[i] = static_cast<char>(k_val + 'A');
        }
        else{
            cipher_text[i] = plain_text[i];
        }
    }
}

void autokey_decrypt(const std::string& cipher_text, const std::string& init_key, std::string& plain_text){
    if(cipher_text.empty() || init_key.empty()){
        plain_text.clear();
        return;
    }

    plain_text.resize(cipher_text.length());

    for (long i = 0; i < init_key.length() && i < cipher_text.length() ; ++i){
        long shift = 0;
        if(init_key[i] >= 'a' && init_key[i] <= 'z'){
            shift = (init_key[i] - 'a');
        }
        else if(init_key[i] >= 'A' && init_key[i] <= 'Z'){
            shift = (init_key[i] - 'A');
        }

        if(cipher_text[i] >= 'a' && cipher_text[i] <= 'z'){
            long k_val = (cipher_text[i] - 'a');
            k_val = (k_val - shift + 26) % 26;
            plain_text[i] = static_cast<char>(k_val + 'a');
        }
        else if(cipher_text[i] >= 'A' && cipher_text[i] <= 'Z'){
            long k_val = (cipher_text[i] - 'A');
            k_val = (k_val - shift + 26) % 26;
            plain_text[i] = static_cast<char>(k_val + 'A');
        }
        else{
            plain_text[i] = cipher_text[i];
        }
    }

    for (long i = init_key.length(); i < cipher_text.length(); ++i){
        long shift = 0;
        char derived_key = plain_text[i - init_key.length()];
        if(derived_key >= 'a' && derived_key <= 'z'){
            shift = (derived_key - 'a');
        }
        else if(derived_key >= 'A' && derived_key <= 'Z'){
            shift = (derived_key - 'A');
        }

        if(cipher_text[i] >= 'a' && cipher_text[i] <= 'z'){
            long k_val = (cipher_text[i] - 'a');
            k_val = (k_val - shift + 26) % 26;
            plain_text[i] = static_cast<char>(k_val + 'a');
        }
        else if(cipher_text[i] >= 'A' && cipher_text[i] <= 'Z'){
            long k_val = (cipher_text[i] - 'A');
            k_val = (k_val - shift + 26) % 26;
            plain_text[i] = static_cast<char>(k_val + 'A');
        }
        else{
            plain_text[i] = cipher_text[i];
        }
    }
}
