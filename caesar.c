#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "caesar.h"


char caesar_encrypt_char(char plain, int key) {
    //Standarize keys
    key = key % 26;
    char encrypted;

    //Checks if lowercase
    if (plain >= 'a' && plain <= 'z') {
        encrypted = (plain + key);

        //Make sure the character is a lower case letter
        if (encrypted > 'z') {
            encrypted = encrypted - 'z' + 'a' - 1;
        }
    }
    //Checks if uppercase
    else if (plain >= 'A' && plain <= 'Z') {
        encrypted = (plain + key);

        //Make sure the character is an upper case letter
        if (encrypted > 'Z') {
            encrypted = encrypted - 'Z' + 'A' - 1;
        }
    }

    return encrypted;
}

int convert_key(char *key) {
    //atoi turns string literal ints into ints. Ignores non-ints. If passed only non-ints returns 0.
    return atoi(key);
}

char *caesar_encrypt(char *plain, char *key) {

    //Allocate memory so we can actually return the encrypted string
    char *encrypted = malloc(sizeof(char) * strlen(plain));

    //Convert key
    int intKey = convert_key(key);

    //Encrypt each character in the string and add it to new string
    for (int i = 0; i < strlen(plain); i++) {
        encrypted[i] = caesar_encrypt_char(plain[i], intKey);
    }
    
    return encrypted;

}




//Decryption
char caesar_decrypt_char(char cipher, int key) {

    //Standardize keys
    key = key % 26;
    char unencrypted;

    //Checks if lowercase
    if (cipher >= 'a' && cipher <= 'z') {
        unencrypted = cipher - key;

        //Make sure the character is a lower case letter
        if (unencrypted < 'a') {
            unencrypted = unencrypted + 'z' - 'a' + 1;
        }
    }
    //Checks if uppercase
    else if (cipher >= 'A' && cipher <= 'Z') {
        unencrypted = cipher - key;

        //Make sure the character is an upper case letter
        if (unencrypted < 'A') {
            unencrypted = unencrypted + 'Z' - 'A' + 1;
        }
    }

    return unencrypted;
}

char *caesar_decrypt(char *cipher, char *key) {

    //Allocate memory so we can actually return the unencrypted string
    char *unencrypted = malloc(sizeof(char) * strlen(cipher));

    //Convert key
    int intKey = convert_key(key);

    //Unencrypt each character in the string and add it to new string
    for (int i = 0; i < strlen(cipher); i++) {
        unencrypted[i] = caesar_decrypt_char(cipher[i], intKey);
    }

    return unencrypted;

}
