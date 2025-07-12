#include "rsa_cipher.h"

void RSA::RSA_init(long p, long q){
    if (is_prime(p) == 0 || is_prime(q) == 0)
    {
        std::cerr<<"Error: P or Q are not prime numbers.\n";
        public_key.n = 0;
        private_key.n = 0;
        return;
    }
    if(p == q){
        std::cerr << "Error: P and Q must be distinct prime numbers\n";
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
        std::cerr << "Error: Could not find a suitable public exponent (e)\n";
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
        std::cerr << "Error: could not find a suitable private exponent (d)\n";
        public_key.n = 0;
        private_key.n = 0;
        return;
    }
    public_key.n = n_val;
    public_key.exp = e;
    private_key.n = n_val;
    private_key.exp = d;
    std::cout << "RSA key generated successfully\n";
    std::cout<<"Public key (n, e): (" << public_key.n <<", "<< public_key.exp << ")\n";
    std::cout<<"Private key (n, d): (" << private_key.n << ", " << private_key.exp << ")\n";
}

rsa_key_pair RSA::get_public_key() const {
    return public_key;
}

void RSA::decrypt(const std::vector<long>& cipher_text, std::string& plain_text) const{
    if(private_key.n == 0){
        std::cerr << "Error: RSA keys not initialized for decryption\n";
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
            std::cerr << "Warning: Decrypted value out of standard char range (0-255). Value: " << decrypt_val << std::endl;
            plain_text[i] = '?';                
        }else{
            plain_text[i] = static_cast<char>(decrypt_val);
        }
    }
}

void RSA::encrypt(const std::string& plain_text, std::vector<long>& cipher_text) const{
    if(public_key.n == 0){
        std::cerr << "Error: RSA keys not initialized for encryption\n";
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
            std::cerr << "Error: Character '" << plain_text[i] << "' (ASCII "<< char_ascii<< ") is >= n (" << public_key.n << "). Cannot Encrypt\n";
            cipher_text.clear();
            return;
        }
        long encrypt_blk = pow_mod(char_ascii, public_key.exp, public_key.n);
        cipher_text[i] = encrypt_blk;
    }
}

void prompt_rsa(RSA & rsa_obj){
    while(rsa_obj.get_public_key().n == 0){
        long p,q;
        std::cout << "\n---RSA Key Generation ---";
        std::cout << "\nEnter two distinct prime numbers (p and q) to initialize RSA: ";
        std::cin >> p >> q;
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        rsa_obj.RSA_init(p,q);
        if(rsa_obj.get_public_key().n == 0){
            std::cout << "\nRSA initialization failed. Please try again with valid primes. \n";
        }
    }
}