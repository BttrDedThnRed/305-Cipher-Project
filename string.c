#include "string.h"
#include <string.h>
#include <stdlib.h>
#include "caesar.h"
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
	
	// s->print = print_string;
	// s->encrypt = encrypt_string;
	// s->decrypt = decrypt_string;
	
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
		str->cipher=caesar_encrypt(s, key);
		return str;
		break;
	
	case AUGUSTUS:
		break;
	
	case AES:                                                           
		break;                                                            
	}
}

char *decrypt_string(cipher c, string *str, char *key) {
	
	
}
