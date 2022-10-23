#include "caesar.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Encrypt
char *augustus_encrypt(char *plain, char *key) {
    
    //Define variables
    int intKey = convert_key(key);
    int left = intKey;
    int digits[strlen(key)];
    char *encrypted = malloc(sizeof(char) * strlen(plain));

    //First step - Run caesar cipher
    char *caesar = caesar_encrypt(plain, key);

    //Second step - Take key and separate each digit
    for (int i = 0; i < strlen(key); i++) {
        digits[i] = left % 10;
        left = left / 10;
    }

    //Final step - Caesar encrypt each char by respective digit
    for (int i = 0; i < strlen(plain); i++) {
            int x = i % strlen(key);
            encrypted[i] = caesar_encrypt_char(caesar[i], digits[x]);
    }

    return encrypted;
}





//Decrypt
char *augustus_decrypt(char *cipher, char *key) {

    //Define variables
    int intKey = convert_key(key);
    int left = intKey;
    int digits[strlen(key)];
    char *unencrypted = malloc(sizeof(char) * strlen(cipher));
    int keyLen = strlen(key);
    

    //First step - Take key and separate each digit
    for (int i = 0; i < strlen(key); i++) {
        digits[i] = left % 10;
        left = left / 10;
    }
    
    //Second step - Decrypt individual chars
    for (int i = 0; i < strlen(cipher); i++) {
        int x = i % strlen(key);
        unencrypted[i] = caesar_decrypt_char(cipher[i], digits[x]);
    }

    //Final step - Undo Caesar cipher
    unencrypted = caesar_decrypt(unencrypted, key);

    return unencrypted;
}
