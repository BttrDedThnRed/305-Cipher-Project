#include "string.h"
#include <stdio.h>
#include "caesar.h"
#include "augustus.h"
int main(){
	string *s=new_plain("gusty",0);
	//printf("%s\n", s->plain);
	//s->print(s, PLAIN);
	string *sp = s->encrypt_string(CAESAR,"gusty","10");
	//print1(s, PLAIN);
	string *s2 = encrypt_string(AUGUSTUS,"Gusty", "123");
	//s->plain= decrypt_string(AUGUSTUS, s2, "123");	
	//string *s3 = encrypt1(AUGUSTUS, "Gusty", "123");
	printf("%s\n", s2->cipher);
	printf("%s\n", s2->plain);
	
	
	//s2->print(s2, CIPHER); 	
	//printf("Encrypted Gusty: %s\n", caesar_encrypt("gusty!#", "24"));
}
