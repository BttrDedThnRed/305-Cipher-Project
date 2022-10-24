#include <stdio.h>
#include <string.h>
#include "string.h"

int main (int argc, char **argv) {

    int running = 1;
    while (running) {
                //Checks if there is a file argument
                if (argv[0]) {
                    
                }
        	printf("Default keys:\n");
        	printf("Caesar: 1\n");
        	printf("Augustus: 12");
        	printf("AES: 0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6\n");
        	printf("0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c\n");
        
        	printf("Enter command - q(uit), c(aesar), au(gustus), ae(s): ");
        	
        	char cipherType[120];
        	string_type cipher;
        
        	fgets(cipherType, 120, stdin);
        	cipherType[strcspn(cipherType, "\n")] = '\0';  // replace \n with \0
        	
        	if (cipherType=="c") {
        		cipher=CAESAR;
        	} 
        	 else if (cipherType=="au") {
        		cipher=AUGUSTUS;
        	
        	}
        	else if (cipherType=="ae") {
        		cipher=AES;
        	}
    

        	printf("\nEnter string: ");
        	char plain[120];
        	char *plainP = plain;
        	fgets(plain, 120, stdin);
        	plain[strcspn(plain, "\n")] = '\0';  // replace \n with \0
        
        	if (strlen(plain) == 0) {
        		printf("You must enter a string!");
        		continue;
        	}
        
        	printf("\nEnter key (Enter for default: ");
        	char key[120];
		char *keyP=key;
        	fgets(key, 120, stdin);
        	plain[strcspn(plain, "\n")] = '\0';
	
        	if (strlen(key) == 0) {
        		if (cipherType=="c") {
        			keyP="1";
        		
        		} 
        		else if (cipherType=="au") {
        			cipher=AUGUSTUS;
        			keyP="12";
			}
        		else if (cipherType=="ae") {
        			
        		}
        	}
        	
		if (cipherType=="ae") {
        		printf("AES key must be 16 bytes. "); 
        	
		}
       		
	        	
        	string *ms = new_plain(plain, cipher==AES);
		//printf("%s\n", ms->plain);
        	
		printf("\nPlain text string:\n");
        	//ms->print(ms, PLAIN);
        	string *b = ms->encrypt(cipher, plain, keyP);
        	printf("\nCipher text string:\n");
        	b->print(b, CIPHER);
        	char *s = b->decrypt(cipher, b, keyP);
        	printf("\nDecrypted input:\n");
        	printf("%s\n", s);
        	//print_C_string(s);
        	b->print(b, PLAIN);

    }
}
