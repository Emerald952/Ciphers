#ifndef CAESAR_CIPHER_H
#define CAESAR_CIPHER_H

#include <string>

void Caesar_encrypt(const std::string& plain_text, long key, std::string& cipher_text);
void Caesar_decrypt(const std::string& cipher_text, long key, std::string& plain_text);

#endif