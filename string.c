#include "string.h"
#include <string.h>
#include <stdlib.h>
#include "caesar.h"
string *new_plain(char *s, int roundup) {
	
	string *str=malloc(sizeof(string));
	str->plain=malloc(sizeof(s));
	strcpy(str->plain,s);
	str->len=strlen(s);
	
	//s->print = print_string;
	//s->encrypt = encrypt_string;   
	//s->decrypt = decrypt_string;   
	
	return(str);
}

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

string *encrypt_string(cipher c, char *s, char *key) {
	
	string *str=malloc(sizeof(string));
	str->plain=malloc(sizeof(s));
	strcpy(str->plain,s);
	switch (cipher):
	case CAESAR:
		return(caesar_encrypt(char *s, char *key));
		break;
	case AUGUSTUS:
		break;
	case AES:
		break;


	
}


