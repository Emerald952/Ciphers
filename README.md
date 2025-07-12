# Ciphers
## Overview
This is a C++ command-line application that provides implementation of various classical ciphers.

## Features:
The application includes implementation of following ciphers:
- **Caesar Cipher:** Simple substitution cipher 
- **XOR Cipher:** Single-character and Multi-character XOR encryption/decryption
- **One Time Pad(OTP):** Random single use key for encryption/decryption
- **Vigenere Cipher:** Polyalphabetic substitution cipher
- **Autokey Cipher:** Variation of Vigenere cipher where key is extended by using plaintext as key
- **RSA:** Asymmetric public key cipher

### Technical Details and Design choice
- **Language:** C++17
- **Modular Architecture:** Codebase is structured into distinct header(`.h`) and source(`.cpp`) files for each cipher
- **Build Automation:** Utilizes Makefile for efficient and automated compilation, managing dependencies accross multiple files

## How to build and run
1. Clone repository
```bash 
git clone https://github.com/Emerald952/Ciphers
cd ciphers
```
2. Build the executable(Ensure you have `g++` and `make` installed)
```bash
make
```
3. Run the application
```bash
./ciphers
```

## Usage
The application presents an interactive command-line menu. Follow the prompts to select a cipher and perform encryption or decryption operations.

## Future Enhancement
- Adding more ciphers
- Creating a Graphical User Interface(GUI)
