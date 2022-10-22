#include "string.h"
#include <stdio.h>
#include "caesar.h"
int main(){
	string *s=new_plain("gusty",0);
	printf("%s\n", s->plain);
	printf("%d", (int) sizeof(s->plain));
	printf("%d\n", s->len);
	printf("%d\n",(int)sizeof(string));
	
	printf("Encrypted Gusty: %s\n", caesar_encrypt("Gusty", "123"));
	//s->print(s, CIPHER);
	//string *s2 = encrypt_string(CAESAR, "Gusty", "123");
}
