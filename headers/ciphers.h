#ifndef CIPHERS_H
#define CIPHERS_H

#include <iostream>
#include <string>
#include <vector>
#include "math_utility.h"

//CAESAR CIPHER FUNCTIONS
void Caesar_encrypt(const std::string& plain_text, long key, std::string& cipher_text);
void Caesar_decrypt(const std::string& cipher_text, long key, std::string& plain_text);

//XOR CIPHER FUNCTIONS
void str_to_binary(const std::string& str);
void XOR_encryptdecrypt(const std::string& XOR_text, char key, std::string& cipher_text);
void XOR_encryptdecrypt_general(const std::string& XOR_text, const std::string& key, std::string& cipher_text);

//ONE TIME PAD FUNCTIONS
void one_time_pad_encryptdecrypt(const std::string& XOR_text, const std::string& key, std::string& cipher_text);

//VIGENERE CIPHER FUNCTIONS
void vigenere_encrypt(const std::string& plain_text, const std::string& key, std::string& cipher_text);
void vigenere_decrypt(const std::string& cipher_text, const std::string& key, std::string& plain_text);

//AUTOKEY CIPHER FUNCTIONS
void autokey_encrypt(const std::string& plain_text, const std::string& init_key, std::string& cipher_text);
void autokey_decrypt(const std::string& cipher_text, const std::string& init_key, std::string& plain_text);

//RSA CIPHER FUNCTIONS
struct rsa_key_pair{
    long n;
    long exp;
};
class RSA{
    private:
        rsa_key_pair public_key;
        rsa_key_pair private_key;

    public:
        void RSA_init(long p, long q);
        rsa_key_pair get_public_key() const;
        void encrypt(const std::string& plain_text, std::vector<long>& cipher_text) const;
        void decrypt(const std::vector<long>& cipher_text, std::string& plain_text) const;  
};
void prompt_rsa(RSA & rsa_obj);

#endif