#include "string.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "caesar.h"
#include "augustus.h"
//allocates memory for and creates new string object
string *new_plain(char *s, int roundup) {
	
	string *str=malloc(sizeof(string));
	str->plain=malloc(sizeof(s));
	strcpy(str->plain,s);
	str->len=strlen(s);
	 
	return(str);
}
//does same as new_plain trying to figure out how its supposed to be different
string *new_cipher(char *s, int len, int roundup) {
	
	string *str=malloc(sizeof(string));
        str->plain=malloc(sizeof(s));
	strcpy(str->plain,s);
	str->len=strlen(s);
	return(str);                    
}
//makes calls to appropriate cipher interface
string *encrypt_string(cipher c, char *s, char *key) {
	
	string *str=malloc(sizeof(string));
	str->plain=malloc(sizeof(s));
	str->cipher=malloc(sizeof(s));
	strcpy(str->plain,s);
	switch (c) {
	case CAESAR:
	
		strcpy(str->cipher, caesar_encrypt(s, key));	
		//str->cipher=caesar_encrypt(s, key);
		return str;
		break;
	
	case AUGUSTUS:
		strcpy(str->cipher, augustus_encrypt(s, key));
		return str;
		break;
	
	case AES:
		break;
	}
}

string* encrypt(cipher c, char *s, char *key) {
	
	string *str=malloc(sizeof(string));
	str->plain=malloc(sizeof(s));
	strcpy(str->plain,s);
	
	switch (c) {
	case CAESAR:
		strcpy(str->cipher, caesar_encrypt(s, key));
		return str;
		break;
	
	case AUGUSTUS:
		strcpy(str->plain, augustus_encrypt(str->cipher, key));
		return str;
		break;
	
	case AES:                                                           
		break;                                                            
	}
}

char *decrypt_string(cipher c, string *str, char *key) {
	
	switch (c) {
	case CAESAR:
		strcpy(str->plain, caesar_decrypt(str->cipher, key));
		return str->plain;
       		break;
	
	case AUGUSTUS:
		strcpy(str->plain, augustus_decrypt(str->cipher, key));
		return str->plain;
		break;
	
	case AES:
	break;
	}	
}

char *decrypt(cipher c, string *str, char *key) {
	
	switch (c) {
	case CAESAR:
		strcpy(str->plain, caesar_decrypt(str->cipher, key));
	        return str->plain;
		break;

	case AUGUSTUS:
	strcpy(str->plain, augustus_decrypt(str->cipher, key));
	return str->plain;
	break;
	
	case AES:
	break;
	}
}

void print(string *s, string_type st) {
	printf("1");
	switch (st) {
		case PLAIN:
		printf("2");
		printf("%s", s->plain);
		break;
		case CIPHER:
		printf("%s", s->cipher);
		break;
	
	}
}
