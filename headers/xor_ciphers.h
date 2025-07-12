#ifndef XOR_CIPHER_H
#define XOR_CIPHER_H

#include <string>

//XOR CIPHER FUNCTIONS
void str_to_binary(const std::string& str);
void XOR_encryptdecrypt(const std::string& XOR_text, char key, std::string& cipher_text);
void XOR_encryptdecrypt_general(const std::string& XOR_text, const std::string& key, std::string& cipher_text);

//ONE TIME PAD FUNCTIONS
void one_time_pad_encryptdecrypt(const std::string& XOR_text, const std::string& key, std::string& cipher_text);

#endif