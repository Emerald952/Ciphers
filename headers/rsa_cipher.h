#ifndef RSA_CIPHER_H
#define RSA_CIPHER_H

#include <iostream>
#include <string>
#include <vector>
#include "math_utility.h"

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