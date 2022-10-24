#include "string.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "caesar.h"
#include "augustus.h"
#include "aes_cbc.h"
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
//char *test = str->plain;
//			        u_int8_t key[] = key;
//				        u_int8_t in[20];
//					        u_int8_t iv[] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05,0x06, 0x07,0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f };
//						        memcpy(in, test, 19);
//							        struct AES_ctx c;
//								        AES_init_ctx_iv(&c, key, iv);
//									        AES_CBC_encrypt_buffer(&c, in, 16);
//											printf("encrypted %s", test);
//											        for (int i = 0; i < 16; i++){
//													            printf("%.2x " , in[i]);
//														            }
//												        printf("  |  ");
//													        for (int i = 0; i < 16; i++){
//															            if (isprint(in[i]))
//																	                    printf("%c", in[i]);
//																                }
//														            else{
//																                    print(" ");
//
//	}
//															                printf("\n");
//																	            AES_init_ctx_iv(&c, key, iv);
//																		                AES_CBC_decrypt_buffer(&c, in, 16);
//																					printf("decrypted");
//
//																					            }
	    break;

	}
}

string *encrypt(cipher c, char *s, char *key) {
	
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

void *print(string *s, string_type st) {
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

string *encrypt1(cipher c, char *s, char *key) {
	
	string *str=malloc(sizeof(string));
	str->plain=malloc(sizeof(s));
	strcpy(str->plain, s);
	
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
