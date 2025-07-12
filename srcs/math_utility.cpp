#include "./headers/math_utility.h"

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