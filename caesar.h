#ifndef _CAESAR_H
#define _CAESAR_H

char *caesar_encrypt(char *plain, char *key);
char *caesar_decrypt(char *cipher, char *key);
char caesar_encrypt_char(char plain, int key);
char caesar_decrypt_char(char cipher, int key);
int convert_key(char *key);

#endif // _CAESAR_H

