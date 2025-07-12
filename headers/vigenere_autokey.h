#ifndef VIGENERE_AUTOKEY_H
#define VIGENERE_AUTOKEY_H

#include <string>
//VIGENERE CIPHER FUNCTIONS
void vigenere_encrypt(const std::string& plain_text, const std::string& key, std::string& cipher_text);
void vigenere_decrypt(const std::string& cipher_text, const std::string& key, std::string& plain_text);

//AUTOKEY CIPHER FUNCTIONS
void autokey_encrypt(const std::string& plain_text, const std::string& init_key, std::string& cipher_text);
void autokey_decrypt(const std::string& cipher_text, const std::string& init_key, std::string& plain_text);

#endif