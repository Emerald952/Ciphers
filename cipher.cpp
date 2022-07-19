#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

#define MAXLEN 100
void Caesar_encrypt(char Caesar_text[], long key, char cipher_text[], long n)
{
    for (long i = 0; i < n; i++)
    {
        long x = Caesar_text[i] - 'a';
        x = (x + key) % 26;
        cipher_text[i] = 'a' + x;
    }
    cipher_text[n] = '\0';
}

void Caesar_decrypt(char Caesar_text[], long key, char cipher_text[], long n)
{
    for (long i = 0; Caesar_text[i] != '\0'; i++)
    {
        long x = Caesar_text[i] - 'a';
        x = (x - key + 26) % 26;
        cipher_text[i] = 'a' + x;
    }
    cipher_text[n] = '\0';
}

void str_to_ascii(char str[], long n)
{
    long i;
    for (long j = 0; j < n; j++)
    {
        long x = str[j];
        char strs[8];
        for (i = 0; i < 8; ++i)
            strs[i] = '0';
        i = 7;
        while (x > 0)
        {
            strs[i] = x % 2 + '0';
            x /= 2;
            --i;
        }
        cout << strs << " ";
    }
    cout << endl;
}

void XOR_encryptdecrypt(char XOR_text[], char key, char cipher_text[], long n)
{
    for (long i = 0; i < n; i++)
    {
        cipher_text[i] = XOR_text[i] ^ key;
    }
    cipher_text[n] = '\0';
}

void XOR_encryptdecrypt_general(char XOR_text[], char key[], char cipher_text[], long n)
{
    for (long i = 0; i < n;)
    {
        for (long j = 0; key[j] != '\0'; ++j)
        {
            if (i == n)
                break;
            cipher_text[i] = XOR_text[i] ^ key[j];
            ++i;
        }
    }
    cipher_text[n] = '\0';
}

void one_time_pad_encryptdecrypt(char XOR_text[], char key[], char cipher_text[], long n)
{
    for (long i = 0; i < n; ++i)
    {
        cipher_text[i] = XOR_text[i] ^ key[i];
    }
    cipher_text[n] = '\0';
}

void vigenere_encrypt(char text[], char key[], char cipher_text[], long n)
{
    long m = strlen(key);
    for (long i = 0; i < n;)
    {
        for (long j = 0; j < m && i < n; ++j)
        {
            long k = (text[i] - 'a');
            k += key[j] - 'a';
            k %= 26;
            cipher_text[i] = k + 'a';
            ++i;
        }
    }
    cipher_text[n] = '\0';
}

void vigenere_decrypt(char text[], char key[], char cipher_text[], long n)
{
    long m = strlen(key);
    for (long i = 0; i < n;)
    {
        for (long j = 0; j < m && i < n; ++j)
        {
            long k = (text[i] - 'a');
            k -= key[j] - 'a';
            k = (k + 26) % 26;
            cipher_text[i] = k + 'a';
            ++i;
        }
    }
    cipher_text[n] = '\0';
}

void autokey_encrypt(char text[], char key[], char cipher_text[], long n)
{
    char key_[2 * MAXLEN];
    long m = strlen(key), i;
    for (i = 0; i < m; ++i)
        key_[i] = key[i];
    for (i = m; i < n; ++i)
        key_[i] = text[i - m];
    for (i = 0; i < n; ++i)
    {
        long k = (text[i] - 'a');
        k += key_[i] - 'a';
        k %= 26;
        cipher_text[i] = k + 'a';
    }
    cipher_text[n] = '\0';
}

void autokey_decrypt(char text[], char key[], char cipher_text[], long n)
{
    long m = strlen(key), i, j;
    for (i = 0, j = 0; i < m; ++i)
    {
        long k = (text[i] - 'a');
        k -= key[i] - 'a';
        k = (k + 26) % 26;
        cipher_text[i] = k + 'a';
    }
    for (i = m, j = 0; i < n; ++i, ++j)
    {
        long k = (text[i] - 'a');
        k -= cipher_text[j] - 'a';
        k = (k + 26) % 26;
        cipher_text[i] = k + 'a';
    }
    cipher_text[n] = '\0';
}

struct rsa_key_pair
{
    long n;
    long de;
};

long hcf(long a, long b)
{
    if (a < b)
    {
        long temp = a;
        a = b;
        b = temp;
    }
    while (b > 0)
    {
        long temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

long is_prime(long n)
{
    if (n == 1)
        return 0;
    if (n == 2 || n == 3)
        return 1;
    for (long i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return 0;
    return 1;
}

long pow_mod(long nm, long power, long mod)
{
    long res = 1;
    for (long i = 0; i < power; ++i)
        res = (res * nm) % mod;
    return res;
}

class RSA
{
private:
    rsa_key_pair public_key;
    rsa_key_pair private_key;

public:
    void RSA_init(long p, long q)
    {
        if (is_prime(p) == 0 || is_prime(q) == 0)
        {
            cout << "Error: Not primes.\n";
            return;
        }
        long n = p * q;
        long phi_n = (p - 1) * (q - 1), e = -1;
        for (long _e = 2; _e < phi_n; ++_e)
        {
            if (hcf(phi_n, _e) == 1)
            {
                e = _e;
                break;
            }
        }
        if (e == -1)
        {
            cout << "Error occured.\n";
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
        if (d == -1)
        {
            cout << "Error occured.\n";
            return;
        }
        public_key.n = n, public_key.de = e;
        private_key.n = n, private_key.de = d;
    }

    rsa_key_pair get_public_key()
    {
        return public_key;
    }

    void decrypt(char text[], long cipher_text[], long n)
    {
        for (long i = 0; i < n; ++i)
        {
            long nm = cipher_text[i];
            long nm_r = pow_mod(nm, private_key.de, private_key.n);
            text[i] = (char)nm_r;
        }
        text[n] = '\0';
    }

    void encrypt(char text[], long cipher_text[], long n)
    {
        for (long i = 0; i < n; ++i)
        {
            long nm = text[i];
            long nm_r = pow_mod(nm, public_key.de, public_key.n);
            cipher_text[i] = nm_r;
        }
    }
};

int main()
{
    char text[MAXLEN], ciphertext[MAXLEN], key[MAXLEN], tst[MAXLEN];
    long n, m;
    RSA x;
    x.RSA_init(13, 17);
    char ch, ch1, ch2 = 'Y';
    while (ch2 == 'y' || ch2 == 'Y')
    {
        cout << "\t\t\tWelcome To My Cryptography Platform\n";
        for (int s = 0; s < 80; ++s)
        {
            cout << "-";
        }
        cout << "\nWhich Cipher Do You Want To Use?(1-7)";
        cout << "\n\t1.Caesar Cipher";
        cout << "\n\t2.XOR Cipher";
        cout << "\n\t3.XOR Cipher with key as a string.";
        cout << "\n\t4.One time pad";
        cout << "\n\t5.Vigenere Cipher";
        cout << "\n\t6.Autokey";
        cout << "\n\t7.RSA\n";
        for (int s = 0; s < 80; ++s)
        {
            cout << "-";
        }
        cout<<"\nEnter Your choice:";
        cin >> ch;
        cout << "\nWhat do you want to do(1-2):";
        cout << "\n1.Encrypt";
        cout << "\n2.Decrypt\n";
        cout<<"\nEnter Your choice:";
        cin >> ch1;
        switch (ch)
        {
        case '1':
            cout << "\nEnter size of text: ";
            cin >> n;
            cout << "\nEnter Your text: ";
            cin >> text;
            long key1;
            cout << "\nEnter Key Value: ";
            cin >> key1;
            switch (ch1)
            {
            case '1':
                Caesar_encrypt(text, key1, ciphertext, n);
                cout << "\nEncrypted text: " << ciphertext;
                break;
            case '2':
                Caesar_decrypt(text, key1, ciphertext, n);
                cout << "\nDecrypted text: " << ciphertext;
                break;
            default:
                cout << "\n!!! Invalid Input !!!";
                break;
            }
            break;
        case '2':
            cout << "\nEnter size of text: ";
            cin >> n;
            switch (ch1)
            {
            case '1':
                cout << "\nEnter Your text: ";
                cin >> text;
                break;
            case '2':
                cout << "\nEnter Your ciphertext array.:\n";
                for (int i = 0; i < n; ++i)
                {
                    int tmp;
                    cin >> tmp;
                    text[i] = tmp;
                }
                text[n] = '\0';
                break;
            default:
                cout << "\n!!! Invalid Input !!!";
                break;
            }
            cout << "\nEnter key(character): ";
            cin >> key;
            XOR_encryptdecrypt(text, key[0], ciphertext, n);
            str_to_ascii(text, n);
            str_to_ascii(key, 1);
            str_to_ascii(ciphertext, n);
            switch (ch1)
            {
            case '1':
                cout << "\nEncrypted text:";
                for (int i = 0; i < n; ++i)
                    cout << (int)ciphertext[i] << ' ';
                cout << '\n';
                break;
            case '2':
                cout << "\nDecrypted text:";
                cout << ciphertext << '\n';
                break;
            }
            break;
        case '3':
            cout << "\nEnter size of text: ";
            cin >> n;
            switch (ch1)
            {
            case '1':
                cout << "\nEnter Your text: ";
                cin >> text;
                break;
            case '2':
                cout << "\nEnter Your ciphertext array.:\n";
                for (int i = 0; i < n; ++i)
                {
                    int tmp;
                    cin >> tmp;
                    text[i] = tmp;
                }
                text[n] = '\0';
                break;
            default:
                cout << "\n!!! Invalid Input !!!";
                break;
            }
            cout << "\nEnter size of key: ";
            cin >> m;
            cout << "\nEnter key: ";
            cin >> key;
            str_to_ascii(text, n);
            str_to_ascii(key, m);
            XOR_encryptdecrypt_general(text, key, ciphertext, n);
            str_to_ascii(ciphertext, n);
            switch (ch1)
            {
            case '1':
                cout << "\nEncrypted text:";
                for (int i = 0; i < n; ++i)
                    cout << (int)ciphertext[i] << ' ';
                cout << '\n';
                break;
            case '2':
                cout << "\nDecrypted text:";
                cout << ciphertext << '\n';
                break;
            }
            break;
        case '4':
            cout << "\nEnter size of text: ";
            cin >> n;
            switch (ch1)
            {
            case '1':
                cout << "\nEnter Your text: ";
                cin >> text;
                break;
            case '2':
                cout << "\nEnter Your ciphertext array.:\n";
                for (int i = 0; i < n; ++i)
                {
                    int tmp;
                    cin >> tmp;
                    text[i] = tmp;
                }
                text[n] = '\0';
                break;
            default:
                cout << "\n!!! Invalid Input !!!";
                break;
            }
            cout << "Enter size of key: ";
            cin >> m;
            cout << "\nEnter key: ";
            cin >> key;
            if (m < n)
            {
                cout << "\nKey size is not as large as plaintext. Not a one time pad.\n";
            }
            else
            {
                str_to_ascii(text, n);
                str_to_ascii(key, m);
                one_time_pad_encryptdecrypt(text, key, ciphertext, n);
                str_to_ascii(ciphertext, n);
                switch (ch1)
                {
                case '1':
                    cout << "\nEncrypted text:";
                    for (int i = 0; i < n; ++i)
                        cout << (int)ciphertext[i] << ' ';
                    cout << '\n';
                    break;
                case '2':
                    cout << "\nDecrypted text:";
                    cout << ciphertext << '\n';
                    break;
                }
            }
            break;
        case '5':
            cout << "\nEnter size of text: ";
            cin >> n;
            cout << "\nEnter Your text: ";
            cin >> text;
            cout << "\nEnter key: ";
            cin >> key;
            switch (ch1)
            {
            case '1':
                vigenere_encrypt(text, key, ciphertext, n);
                cout << "\nEncrypted text: " << ciphertext;
                break;
            case '2':

                vigenere_decrypt(text, key, ciphertext, n);
                cout << "\nDecrypted text: " << ciphertext;
                break;
            default:
                cout << "\n!!! Invalid Input !!!";
                break;
            }
            break;
        case '6':
            cout << "\nEnter size of text: ";
            cin >> n;
            cout << "\nEnter Your text: ";
            cin >> text;
            cout << "\nEnter key: ";
            cin >> key;
            switch (ch1)
            {
            case '1':
                autokey_encrypt(text, key, ciphertext, n);
                cout << "\nEncrypted text: " << ciphertext;
                break;
            case '2':
                autokey_decrypt(text, key, ciphertext, n);
                cout << "\nDecrypted text: " << ciphertext;
                break;
            default:
                cout << "\n!!! Invalid Input !!!";
                break;
            }
            break;
        case '7':
            long xx[MAXLEN];
            cout << "\nEnter size of text: ";
            cin >> n;
            switch (ch1)
            {
            case '1':
                cout << "\nEnter Your text: ";
                cin >> text;
                cout << "\nEncrypted text:";
                x.encrypt(text, xx, n);
                for (int i = 0; i < n; ++i)
                    cout << xx[i] << ' ';
                break;
            case '2':
                long sz;
                cout << "Enter the size of array:\n";
                cin >> sz;
                cout << "Enter the array\n";
                for (int i = 0; i < sz; ++i)
                    cin >> xx[i];
                cout << "\nDecrypted text:";
                x.decrypt(tst, xx, n);
                cout << tst << endl;
                break;
            default:
                cout << "\n!!! Invalid Input !!!";
                break;
            }
            break;
        default:
            cout << "\n!!! Invalid Input !!!";
            break;
        }
        cout << "\n\nWant To Try Again?(y/n)\n";
        cin >> ch2;
    }

    return 0;
}