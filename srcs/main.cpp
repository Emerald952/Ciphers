#include "headers/caesar_cipher.h"
#include "headers/xor_ciphers.h"
#include "headers/vigenere_autokey.h"
#include "headers/rsa_cipher.h"

#include <limits>

int main(){
    std::string plain_text, ciphertext, key, tst;
    char char_key;

    RSA x;
    std::vector<long> xx;

    char ch, ch1, ch2;;
    do{
        std::cout << "\t\t\tWelcome To My Cryptography Platform\n";
        std::cout << std::string(80, '-') << std::endl;
        std::cout << "\nWhich Cipher Do You Want To Use?(1-7)";
        std::cout << "\n\t1.Caesar Cipher";
        std::cout << "\n\t2.XOR Cipher";
        std::cout << "\n\t3.XOR Cipher with key as a string.";
        std::cout << "\n\t4.One time pad";
        std::cout << "\n\t5.Vigenere Cipher";
        std::cout << "\n\t6.Autokey";
        std::cout << "\n\t7.RSA";
        std::cout << "\n\t8.Exit\n";
        std::cout << std::string(80, '-') << std::endl;
        std::cout<<"\nChoose the type of Cipher: ";
        std::cin >> ch;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if(ch == '8') break;

        std::cout << "\nChoose: 1.Encrypt 2.Decrypt\n";
        std::cin >> ch1;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(ch){
            case '1':{
                std::cout << "\nEnter Your text: ";
                getline(std::cin, plain_text);

                long key1;
                std::cout << "\nEnter Key Value: ";
                std::cin >> key1;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                switch (ch1){
                    case '1':
                        Caesar_encrypt(plain_text, key1, ciphertext);
                        std::cout << "\nEncrypted text: " << ciphertext << std::endl;
                        break;
                    case '2':
                        Caesar_decrypt(plain_text, key1, ciphertext);
                        std::cout << "\nDecrypted text: " << ciphertext << std::endl;
                        break;
                    default:
                        std::cout << "\n!!! Invalid Input !!!";
                        break;
                }
            }
                break;
            case '2':{
                std::string XOR_text;
                switch (ch1){
                    case '1':
                        std::cout << "\nEnter Your text: ";
                        getline(std::cin, plain_text);
                        std::cout << "Enter key(character)";
                        std::cin >> char_key;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        break;
                    case '2':
                        
                        long ciphers_int;
                        std::cout << "\nEnter number of ciphertext integers:";
                        std::cin >> ciphers_int;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                        std::cout << "\nEnter Your ciphertext integers(seprated by spaces):";
                        XOR_text.clear();
                        XOR_text.resize(ciphers_int);

                        for (int i = 0; i < ciphers_int; ++i){
                            int tmp;
                            std::cin >> tmp;
                            XOR_text[i] = static_cast<char>(tmp);
                        }
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "\nEnter key(character):";
                        std::cin >> char_key;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        break;
                    default:
                        std::cout << "\n!!! Invalid Input !!!";
                        break;
                }
                XOR_encryptdecrypt(XOR_text, char_key, ciphertext);
                std::cout << "\nBinary representation of input text: ";
                str_to_binary(XOR_text);
                std::string temp_key(1, char_key);
                std::cout << "\nBinary representation of key: ";
                str_to_binary(temp_key);
                std::cout << "\nBinary representation of ciphertext: ";
                str_to_binary(ciphertext);

                switch (ch1){
                    case '1':
                        std::cout << "\nEncrypted text (integer representation): ";
                        for (long i = 0; i < ciphertext.length(); ++i){
                            std::cout << static_cast<int>(ciphertext[i]) << ' ';
                        }  
                        std::cout << '\n';
                        break;
                    case '2':
                        std::cout << "\nDecrypted text: " << ciphertext << std::endl;
                        break;
                }
            }
                break;
            case '3':{
                std::string XOR_text;
                switch (ch1){
                    case '1':
                        std::cout << "\nEnter Your text: ";
                        getline(std::cin, XOR_text);
                        break;
                    case '2':
                        long ciphers_int;
                        std::cout << "\nEnter number of ciphertext integers:";
                        std::cin >> ciphers_int;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                        std::cout << "\nEnter Your ciphertext integers(seprated by spaces):";
                        XOR_text.clear();
                        XOR_text.resize(ciphers_int);
        
                        for (int i = 0; i < ciphers_int; ++i){
                            int tmp;
                            std::cin >> tmp;
                            XOR_text[i] = static_cast<char>(tmp);
                        }
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        break;
                    default:
                        std::cout << "\n!!! Invalid Input !!!";
                        break;
                }
                std::cout << "\nEnter key: ";
                getline(std::cin, key);

                std::cout << "\nBinary representation of input text: ";
                str_to_binary(XOR_text);
                std::cout << "\nBinary representation of key: ";
                str_to_binary(key);
                XOR_encryptdecrypt_general(XOR_text, key, ciphertext);
                std::cout << "\nBinary representation of ciphertext: ";
                str_to_binary(ciphertext);
                
                switch (ch1){
                    case '1':
                        std::cout << "\nEncrypted text:";
                        for (long i = 0; i < ciphertext.length(); ++i){
                            std::cout << static_cast<int>(ciphertext[i]) << ' ';
                        }   
                        std::cout << '\n';
                        break;
                    case '2':
                        std::cout << "\nDecrypted text: "<< ciphertext << std::endl;
                        break;
                }
            }
                break;
            case '4':{
                std::string otp_text;
                switch (ch1){
                    case '1':
                        std::cout << "\nEnter Your text: ";
                        getline(std::cin, otp_text);
                        break;
                    case '2':
                        long ciphers_int;
                        std::cout << "\nEnter number of ciphertext integers:";
                        std::cin >> ciphers_int;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                        std::cout << "\nEnter Your ciphertext integers(seprated by spaces):";
                        otp_text.clear();
                        otp_text.resize(ciphers_int);

                        for (int i = 0; i < ciphers_int; ++i){
                            int tmp;
                            std::cin >> tmp;
                            otp_text[i] = static_cast<char>(tmp);
                        }
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                        break;
                    default:
                        std::cout << "\n!!! Invalid Input !!!";
                        break;
                }
                std::cout << "\nEnter key: ";
                getline(std::cin, key);

                if (key.length() < otp_text.length()){
                    std::cout << "\nWarning: Key size is not as large as plaintext. NOT a one time pad.\n";
                    break;
                }
                
                std::cout << "\nBinary representation of input text: ";
                str_to_binary(otp_text);
                std::cout << "\nBinary representation of key: ";
                str_to_binary(key);
            
                one_time_pad_encryptdecrypt(otp_text, key, ciphertext);
                std::cout << "\nBinary representation of ciphertext: ";
                str_to_binary(ciphertext);

                switch (ch1){
                case '1':
                    std::cout << "\nEncrypted text:";
                    for (long i = 0; i < ciphertext.length(); ++i){
                        std::cout << static_cast<int>(ciphertext[i]) << ' ';
                    }
                    std::cout << '\n';
                    break;
                case '2':
                    std::cout << "\nDecrypted text: "<< ciphertext << std::endl;
                    break;
                }
            }
                break;
            case '5':{
                std::cout << "\nEnter Your text: ";
                getline(std::cin, plain_text);
                std::cout << "\nEnter key: ";
                getline(std::cin, key);
                
                switch (ch1){
                    case '1':
                        vigenere_encrypt(plain_text, key, ciphertext);
                        std::cout << "\nEncrypted text: " << ciphertext << std::endl; 
                        break;
                    case '2':
                        vigenere_decrypt(plain_text, key, ciphertext);
                        std::cout << "\nDecrypted text: " << ciphertext << std::endl;
                        break;
                    default:
                        std::cout << "\n!!! Invalid Input !!!";
                        break;
                }
                break;
            }
            case '6':{
                std::cout << "\nEnter Your text: ";
                getline(std::cin, plain_text);
                std::cout << "\nEnter key: ";
                getline(std::cin, key);
                switch (ch1){
                    case '1':
                        autokey_encrypt(plain_text, key, ciphertext);
                        std::cout << "\nEncrypted text: " << ciphertext << std::endl;
                        break;
                    case '2':
                        autokey_decrypt(plain_text, key, ciphertext);
                        std::cout << "\nDecrypted text: " << ciphertext << std::endl;
                        break;
                    default:
                        std::cout << "\n!!! Invalid Input !!!";
                        break;
                }
            }
                break;
            case '7':{
                if(x.get_public_key().n == 0){
                    prompt_rsa(x);
                }
                switch (ch1)
                {
                    case '1':
                        std::cout << "\nEnter Your text: ";
                        getline(std::cin, plain_text);
                        x.encrypt(plain_text, xx);
                        
                        if(xx.empty() && !plain_text.empty()){
                            std::cout<<"\nEncryption failed due to invalid characters or uninitialized keys\n";
                            
                        }else if(!xx.empty()){
                            std::cout << "\nEncrypted text(blocks):";
                        
                            for (long val : xx){
                                std::cout << val << ' ';
                            }
                            std::cout << "\n"; 
                        }
                    
                        break;
                    case '2':
                        long sz;
                        std::cout << "Enter the number of encrypted blocks (size of array):\n";
                        std::cin >> sz;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        xx.clear();
                        xx.resize(sz);
                        
                        std::cout << "Enter the encrypted blocks (numbers seprated by spaces):\n";
                        for (int i = 0; i < sz; ++i){
                            std::cin >> xx[i];
                        }          
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                        std::cout << "\nDecrypted text:";
                        x.decrypt(xx, tst);
                        std::cout << tst << std::endl;
                        break;
                    default:
                        std::cout << "\n!!! Invalid Input !!!";
                        break;
                }
            }
                break;
            default:
                std::cout << "\n!!! Invalid Input !!!";
                break;
        }
        std::cout << "\n\nWant To Try Again?(y/n)\n";
        std::cin >> ch2;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }while(ch2 == 'y' || ch2 == 'Y');
    return 0;
}