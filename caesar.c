#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "caesar.h"

//Encryption
char caesar_encrypt_char(char plain, int key) {

    //Define variables
    char encrypted;

    //Checks if lowercase
    if (plain >= 'a' && plain <= 'z') {
        encrypted = 'a' + ((plain - 'a' + key) % 26);
    }
    //Checks if uppercase
    else if (plain >= 'A' && plain <= 'Z') {
        encrypted = 'A' + ((plain - 'A' + key) % 26);
    }

    //Checks if special character
    else if (plain >= '!' && plain <= ':') {
        encrypted = '!' + ((plain - '!' + key) % 26);
    }
    //If not any of those return itself
    else {
        return plain;   
    }

    return encrypted;
}

int convert_key(char *key) {
    
    //Define variables
    int boolean;
    int intKey = key[0];

    //Check for an all integer key
    for (int i = 0; i < strlen(key); i++) {
        if (key[i] >= '0' && key[i] <= '9') {
            boolean = 1;
        }
        else {
            boolean = 0;
            break;
        }
    }

    //If key is all integers then return atoi(key). atoi turns string literal ints into ints. Ignores non-ints. If passed only non-ints returns 0.
    if (boolean == 1) {
        return atoi(key);
    }

    //If key is not all integers then xor all characters and return that
    else {
        for (int i = 1; i < strlen(key); i++) {
            intKey = intKey ^ key[i];
        }

        return intKey;
    }

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
    
    //Define variables
    char unencrypted;

    //Checks if lowercase
    if (cipher >= 'a' && cipher <= 'z') {
        unencrypted = (((cipher - 'a' - key) % 26 + 26) % 26) + 'a';
    }
    //Checks if uppercase
    else if (cipher >= 'A' && cipher <= 'Z') {
        unencrypted = (((cipher - 'A' - key) % 26 + 26) % 26) + 'A';
    }
    //Checks if special character
    else if (cipher >= '!' && cipher <= ':') {
        unencrypted = (((cipher - '!' - key) % 26 + 26) % 26) + '!';
    }
    //if not any of those return itself
    else {
        return cipher;
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




