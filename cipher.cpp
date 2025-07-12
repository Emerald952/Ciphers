#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

void Caesar_encrypt(const string& plain_text, long key, string& cipher_text){
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

void Caesar_decrypt(const string& cipher_text, long key, string& plain_text){
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

void str_to_binary(const string& str){
    for(char c : str){
        unsigned char x = static_cast<unsigned char>(c);
        for(int i = 7; i >= 0; i--){
            cout << ((x >> i) & 1);
        } 
        cout<< " ";
    }
    cout << endl;
}

void XOR_encryptdecrypt(const string& XOR_text, char key, string& cipher_text){
    cipher_text.resize(XOR_text.length());
    for (long i = 0; i < XOR_text.length(); i++){
        cipher_text[i] = XOR_text[i] ^ key;
    }
}

void XOR_encryptdecrypt_general(const string& XOR_text, const string& key, string& cipher_text){
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

void one_time_pad_encryptdecrypt(const string& XOR_text, const string& key, string& cipher_text){
    if(key.length() < XOR_text.length()){
        cerr<<"Warning: Key for One-Time Pad is shorter than plaintext. Not a true OTP.\n";
    }
    XOR_encryptdecrypt_general(XOR_text, key, cipher_text);
}

void vigenere_encrypt(const string& plain_text, const string& key, string& cipher_text){
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

void vigenere_decrypt(const string&  cipher_text, const string& key, string& plain_text){
    if(cipher_text.empty() || key.empty()){
        plain_text.clear();
        return;
    }

    plain_text.resize(cipher_text.length());
    long key_len = key.length();
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

void autokey_encrypt(const string& plain_text, const string& init_key, string& cipher_text){
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

void autokey_decrypt(const string& cipher_text, const string& init_key, string& plain_text){
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

struct rsa_key_pair{
    long n;
    long exp;
};

long hcf(long num1, long num2){
    if (num1 < num2){
        long temp = num1;
        num1 = num2;
        num2 = temp;
    }
    while (num2 > 0){
        long temp = num1;
        num1 = num2;
        num2 = temp % num2;
    }
    return num1;
}

long is_prime(long n){
    if (n <= 1) return 0;
    if (n == 2 || n == 3) return 1;
    if(n % 2 == 0 || n % 3 == 0) return 0;

    for (long i = 5; i * i <= n; i+=6){
        if (n % i == 0 || n % (i+2) == 0) return 0;
    }
    return 1;
}

long pow_mod(long base, long power, long mod){
    long res = 1;
    base %= mod;
    while(power > 0){
        if(power % 2 == 1) res = (res * base ) % mod;
        base = (base * base) % mod;
        power /= 2;
    }   
    return res;
}

class RSA{
    private:
        rsa_key_pair public_key;
        rsa_key_pair private_key;

    public:
        void RSA_init(long p, long q){
            if (is_prime(p) == 0 || is_prime(q) == 0)
            {
                cerr<<"Error: P or Q are not prime numbers.\n";
                public_key.n = 0;
                private_key.n = 0;
                return;
            }
            if(p == q){
                cerr << "Error: P and Q must be distinct prime numbers\n";
                public_key.n = 0;
                private_key.n = 0;
                return;
            }
            long n_val = p * q;
            long phi_n = (p - 1) * (q - 1);
            long e = -1;

            for (long _e = 2; _e < phi_n; ++_e){
                if (hcf(phi_n, _e) == 1){
                    e = _e;
                    break;
                }
            }
            if (e == -1){
                cerr << "Error: Could not find a suitable public exponent (e)\n";
                public_key.n = 0;
                private_key.n = 0;
                return;
            }
            long d = -1; 
            for (long _d = 2; _d < phi_n; ++_d)
            {
                long kc = (_d * e) % phi_n;
                if (kc == 1)
                {
                    d = _d;
                    break;
                }
            }
            if (d == -1){
                cerr << "Error: could not find a suitable private exponent (d)\n";
                public_key.n = 0;
                private_key.n = 0;
                return;
            }
            public_key.n = n_val;
            public_key.exp = e;
            private_key.n = n_val;
            private_key.exp = d;
            cout << "RSA key generated successfully\n";
            cout<<"Public key (n, e): (" << public_key.n <<", "<< public_key.exp << ")\n";
            cout<<"Private key (n, d): (" << private_key.n << ", " << private_key.exp << ")\n";
        }

        rsa_key_pair get_public_key() const {
            return public_key;
        }

        void decrypt(const vector<long>& cipher_text, string& plain_text) const{
            if(private_key.n == 0){
                cerr << "Error: RSA keys not initialized for decryption\n";
                plain_text.clear();
                return;
            }
            if(cipher_text.empty()){
                plain_text.clear();
                return;
            }
            plain_text.resize(cipher_text.size());

            for (long i = 0; i < cipher_text.size(); ++i){
                long block_val = cipher_text[i];
                long decrypt_val = pow_mod(block_val, private_key.exp, private_key.n);

                if(decrypt_val < 0 || decrypt_val > 255){
                    cerr << "Warning: Decrypted value out of standard char range (0-255). Value: " << decrypt_val << endl;
                    plain_text[i] = '?';                
                }else{
                    plain_text[i] = static_cast<char>(decrypt_val);
                }
            }
        }

        void encrypt(const string& plain_text, vector<long>& cipher_text) const{
            if(public_key.n == 0){
                cerr << "Error: RSA keys not initialized for encryption\n";
                cipher_text.clear();
                return;
            }
            if(plain_text.empty()){
                cipher_text.clear();
                return;
            }
            cipher_text.resize(plain_text.length());

            for (long i = 0; i < plain_text.length(); ++i){
                long char_ascii = static_cast<long>(plain_text[i]);
                if(char_ascii >= public_key.n){
                    cerr << "Error: Character '" << plain_text[i] << "' (ASCII "<< char_ascii<< ") is >= n (" << public_key.n << "). Cannot Encrypt\n";
                    cipher_text.clear();
                    return;
                }
                long encrypt_blk = pow_mod(char_ascii, public_key.exp, public_key.n);
                cipher_text[i] = encrypt_blk;
            }
        }
};

void prompt_rsa(RSA & rsa_obj){
    while(rsa_obj.get_public_key().n == 0){
        long p,q;
        cout << "\n---RSA Key Generation ---";
        cout << "\nEnter two distinct prime numbers (p and q) to initialize RSA: ";
        cin >> p >> q;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        rsa_obj.RSA_init(p,q);
        if(rsa_obj.get_public_key().n == 0){
            cout << "\nRSA initialization failed. Please try again with valid primes. \n";
        }
    }
}

int main(){
    string plain_text, ciphertext, key, tst;
    char char_key;

    RSA x;
    vector<long> xx;

    char ch, ch1, ch2;;
    do{
        cout << "\t\t\tWelcome To My Cryptography Platform\n";
        cout << string(80, '-') << endl;
        cout << "\nWhich Cipher Do You Want To Use?(1-7)";
        cout << "\n\t1.Caesar Cipher";
        cout << "\n\t2.XOR Cipher";
        cout << "\n\t3.XOR Cipher with key as a string.";
        cout << "\n\t4.One time pad";
        cout << "\n\t5.Vigenere Cipher";
        cout << "\n\t6.Autokey";
        cout << "\n\t7.RSA";
        cout << "\n\t8.Exit\n";
        cout << string(80, '-') << endl;
        cout<<"\nChoose the type of Cipher: ";
        cin >> ch;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if(ch == '8') break;

        cout << "\nChoose: 1.Encrypt 2.Decrypt\n";
        cin >> ch1;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch(ch){
            case '1':{
                cout << "\nEnter Your text: ";
                getline(cin, plain_text);

                long key1;
                cout << "\nEnter Key Value: ";
                cin >> key1;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                switch (ch1){
                    case '1':
                        Caesar_encrypt(plain_text, key1, ciphertext);
                        cout << "\nEncrypted text: " << ciphertext << endl;
                        break;
                    case '2':
                        Caesar_decrypt(plain_text, key1, ciphertext);
                        cout << "\nDecrypted text: " << ciphertext << endl;
                        break;
                    default:
                        cout << "\n!!! Invalid Input !!!";
                        break;
                }
            }
                break;
            case '2':{
                string XOR_text;
                switch (ch1){
                    case '1':
                        cout << "\nEnter Your text: ";
                        getline(cin, plain_text);
                        cout << "Enter key(character)";
                        cin >> char_key;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    case '2':
                        
                        long ciphers_int;
                        cout << "\nEnter number of ciphertext integers:";
                        cin >> ciphers_int;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        cout << "\nEnter Your ciphertext integers(seprated by spaces):";
                        XOR_text.clear();
                        XOR_text.resize(ciphers_int);

                        for (int i = 0; i < ciphers_int; ++i){
                            int tmp;
                            cin >> tmp;
                             XOR_text[i] = static_cast<char>(tmp);
                        }
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "\nEnter key(character):";
                        cin >> char_key;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    default:
                        cout << "\n!!! Invalid Input !!!";
                        break;
                }
                XOR_encryptdecrypt(XOR_text, char_key, ciphertext);
                cout << "\nBinary representation of input text: ";
                str_to_binary(XOR_text);
                string temp_key(1, char_key);
                cout << "\nBinary representation of key: ";
                str_to_binary(temp_key);
                cout << "\nBinary representation of ciphertext: ";
                str_to_binary(ciphertext);

                switch (ch1){
                    case '1':
                        cout << "\nEncrypted text (integer representation): ";
                        for (long i = 0; i < ciphertext.length(); ++i){
                            cout << static_cast<int>(ciphertext[i]) << ' ';
                        }  
                        cout << '\n';
                        break;
                    case '2':
                        cout << "\nDecrypted text: " << ciphertext << endl;
                        break;
                }
            }
                break;
            case '3':{
                string XOR_text;
                switch (ch1){
                    case '1':
                        cout << "\nEnter Your text: ";
                        getline(cin, XOR_text);
                        break;
                    case '2':
                        long ciphers_int;
                        cout << "\nEnter number of ciphertext integers:";
                        cin >> ciphers_int;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        cout << "\nEnter Your ciphertext integers(seprated by spaces):";
                        XOR_text.clear();
                        XOR_text.resize(ciphers_int);
        
                        for (int i = 0; i < ciphers_int; ++i){
                            int tmp;
                            cin >> tmp;
                            XOR_text[i] = static_cast<char>(tmp);
                        }
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    default:
                        cout << "\n!!! Invalid Input !!!";
                        break;
                }
                cout << "\nEnter key: ";
                getline(cin, key);

                cout << "\nBinary representation of input text: ";
                str_to_binary(XOR_text);
                cout << "\nBinary representation of key: ";
                str_to_binary(key);
                XOR_encryptdecrypt_general(XOR_text, key, ciphertext);
                cout << "\nBinary representation of ciphertext: ";
                str_to_binary(ciphertext);
                
                switch (ch1){
                    case '1':
                        cout << "\nEncrypted text:";
                        for (long i = 0; i < ciphertext.length(); ++i){
                            cout << static_cast<int>(ciphertext[i]) << ' ';
                        }   
                        cout << '\n';
                        break;
                    case '2':
                        cout << "\nDecrypted text: "<< ciphertext << endl;
                        break;
                }
            }
                break;
            case '4':{
                string otp_text;
                switch (ch1){
                    case '1':
                        cout << "\nEnter Your text: ";
                        getline(cin, otp_text);
                        break;
                    case '2':
                        long ciphers_int;
                        cout << "\nEnter number of ciphertext integers:";
                        cin >> ciphers_int;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        cout << "\nEnter Your ciphertext integers(seprated by spaces):";
                        otp_text.clear();
                        otp_text.resize(ciphers_int);

                        for (int i = 0; i < ciphers_int; ++i){
                            int tmp;
                            cin >> tmp;
                            otp_text[i] = static_cast<char>(tmp);
                        }
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        break;
                    default:
                        cout << "\n!!! Invalid Input !!!";
                        break;
                }
                cout << "\nEnter key: ";
                getline(cin, key);

                if (key.length() < otp_text.length()){
                    cout << "\nWarning: Key size is not as large as plaintext. NOT a one time pad.\n";
                    break;
                }
                
                cout << "\nBinary representation of input text: ";
                str_to_binary(otp_text);
                cout << "\nBinary representation of key: ";
                str_to_binary(key);
            
                one_time_pad_encryptdecrypt(otp_text, key, ciphertext);
                cout << "\nBinary representation of ciphertext: ";
                str_to_binary(ciphertext);

                switch (ch1){
                case '1':
                    cout << "\nEncrypted text:";
                    for (long i = 0; i < ciphertext.length(); ++i){
                        cout << static_cast<int>(ciphertext[i]) << ' ';
                    }
                    cout << '\n';
                    break;
                case '2':
                    cout << "\nDecrypted text: "<< ciphertext << endl;
                    break;
                }
            }
                break;
            case '5':{
                cout << "\nEnter Your text: ";
                getline(cin, plain_text);
                cout << "\nEnter key: ";
                getline(cin, key);
                
                switch (ch1){
                    case '1':
                        vigenere_encrypt(plain_text, key, ciphertext);
                        cout << "\nEncrypted text: " << ciphertext << endl; 
                        break;
                    case '2':
                        vigenere_decrypt(plain_text, key, ciphertext);
                        cout << "\nDecrypted text: " << ciphertext << endl;
                        break;
                    default:
                        cout << "\n!!! Invalid Input !!!";
                        break;
                }
                break;
            }
            case '6':{
                cout << "\nEnter Your text: ";
                getline(cin, plain_text);
                cout << "\nEnter key: ";
                getline(cin, key);
                switch (ch1){
                    case '1':
                        autokey_encrypt(plain_text, key, ciphertext);
                        cout << "\nEncrypted text: " << ciphertext << endl;
                        break;
                    case '2':
                        autokey_decrypt(plain_text, key, ciphertext);
                        cout << "\nDecrypted text: " << ciphertext << endl;
                        break;
                    default:
                        cout << "\n!!! Invalid Input !!!";
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
                        cout << "\nEnter Your text: ";
                        getline(cin, plain_text);
                        x.encrypt(plain_text, xx);
                        
                        if(xx.empty() && !plain_text.empty()){
                            cout<<"\nEncryption failed due to invalid characters or uninitialized keys\n";
                            
                        }else if(!xx.empty()){
                            cout << "\nEncrypted text(blocks):";
                        
                            for (long val : xx){
                                cout << val << ' ';
                            }
                            cout << "\n"; 
                        }
                    
                        break;
                    case '2':
                        long sz;
                        cout << "Enter the number of encrypted blocks (size of array):\n";
                        cin >> sz;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        xx.clear();
                        xx.resize(sz);
                        
                        cout << "Enter the encrypted blocks (numbers seprated by spaces):\n";
                        for (int i = 0; i < sz; ++i){
                            cin >> xx[i];
                        }          
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        cout << "\nDecrypted text:";
                        x.decrypt(xx, tst);
                        cout << tst << endl;
                        break;
                    default:
                        cout << "\n!!! Invalid Input !!!";
                        break;
                }
            }
                break;
            default:
                cout << "\n!!! Invalid Input !!!";
                break;
        }
        cout << "\n\nWant To Try Again?(y/n)\n";
        cin >> ch2;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }while(ch2 == 'y' || ch2 == 'Y');
    return 0;
}