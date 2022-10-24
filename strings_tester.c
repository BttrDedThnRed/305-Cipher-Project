#include <stdio.h>
#include <string.h>
#include "string.h"
#include "caesar.h" //this and augustus can/should get removed when string.h is implemented
#include "augustus.h" 

int main (int argc, char **argv) {

    int running = 1;
    while (running) {
    if (strcmp(argv[1], "default") == 0) {
        printf("Argument is default");
        return 0;
    }
    //Checks if there is a file argument
    else if (argv[1]) {

        //File I/O definitions
        FILE *file = fopen(argv[1], "r");
        char * line = NULL;
        size_t len = 0;
        ssize_t read;


        //Other definitions
        int triplet = 1;
        char *ciphers[] = {"Caesar", "Augustus", "AES"};


        while ((read = getline(&line, &len, file)) != -1) {
            if (line[0] == '#') {
                continue;
            }
            else if (strcmp(line, "encrypt caesar\n") == 0) {


                //get next line
                read = getline(&line, &len, file);

                //if that next line is commented ignore it and get next line that isn't commented
                while (line[0] == '#') {
                    read = getline(&line, &len, file);
                }

                //set key
                char *key = calloc(len, sizeof(char));
                for (int i = 0; i < (int)(strlen(line)) - 1; i++) {
                    key[i] = line[i];
                }

                //get next line
                read = getline(&line, &len, file);

                //if that next line is commented ignore it and get next line that isn't commented
                while (line[0] == '#') {
                    read = getline(&line, &len, file);
                }

                //set string
                char *stringText = calloc(len, sizeof(char));
                for (int i = 0; i < (int)(strlen(line)) - 1; i++) {
                    stringText[i] = line[i];
                }

                //print
                printf("Triplet: %d, Cipher: %s, %s \n", triplet++, ciphers[0], "Encrypt");
                printf("Output: %s\n\n", caesar_encrypt(stringText, key));


            }
            else if (strcmp(line, "encrypt augustus\n") == 0) {
                //get next line
                read = getline(&line, &len, file);

                //if that next line is commented ignore it and get next line that isn't commented
                while (line[0] == '#') {
                    read = getline(&line, &len, file);
                }

                //set key
                char *key = calloc(len, sizeof(char));
                for (int i = 0; i < (int)(strlen(line)) - 1; i++) {
                    key[i] = line[i];
                }

                //get next line
                read = getline(&line, &len, file);

                //if that next line is commented ignore it and get next line that isn't commented
                while (line[0] == '#') {
                    read = getline(&line, &len, file);
                }

                //set string
                char *stringText = calloc(len, sizeof(char));
                for (int i = 0; i < (int)(strlen(line)) - 1; i++) {
                    stringText[i] = line[i];
                }

                //print
                printf("Triplet: %d, Cipher: %s, %s \n", triplet++, ciphers[1], "Encrypt");
                printf("Output: %s \n\n", augustus_encrypt(stringText, key));
            }
            else if (strcmp(line, "encrypt aes\n") == 0) {
                printf("Triplet: %d, Cipher: %s, %s \n", triplet++, ciphers[2], "Encrypt");
                printf("Don't have aes stuff so ignore\n\n");
            }
            else if (strcmp(line, "decrypt caesar\n") == 0) {

                //get next line
                read = getline(&line, &len, file);

                //if that next line is commented ignore it and get next line that isn't commented
                while (line[0] == '#') {
                    read = getline(&line, &len, file);
                }

                //set key
                char *key = calloc(len, sizeof(char));
                for (int i = 0; i < (int)(strlen(line)) - 1; i++) {
                    key[i] = line[i];
                }

                //get next line
                read = getline(&line, &len, file);

                //if that next line is commented ignore it and get next line that isn't commented
                while (line[0] == '#') {
                    read = getline(&line, &len, file);
                }

                //set string
                char *stringText = calloc(len, sizeof(char));
                for (int i = 0; i < (int)(strlen(line)) - 1; i++) {
                    stringText[i] = line[i];
                }

                //print
                printf("Triplet: %d, Cipher: %s, %s \n", triplet++, ciphers[0], "Decrypt");
                printf("Output: %s \n\n", caesar_decrypt(stringText, key));
            }
            else if (strcmp(line, "decrypt augustus\n") == 0) {

                //get next line
                read = getline(&line, &len, file);

                //if that next line is commented ignore it and get next line that isn't commented
                while (line[0] == '#') {
                    read = getline(&line, &len, file);
                }

                //set key
                char *key = calloc(len, sizeof(char));
                for (int i = 0; i < (int)(strlen(line)) - 1; i++) {
                    key[i] = line[i];
                }
                
                //get next line
                read = getline(&line, &len, file);

                //if that next line is commented ignore it and get next line that isn't commented
                while (line[0] == '#') {
                    read = getline(&line, &len, file);
                }

                //set string
                char *stringText = calloc(len, sizeof(char));
                for (int i = 0; i < (int)(strlen(line)) - 1; i++) {
                    stringText[i] = line[i];
                }

                //print
                printf("Triplet: %d, Cipher: %s, %s \n", triplet++, ciphers[0], "Decrypt");
                printf("Output: %s \n\n", augustus_decrypt(stringText, key));
            }
            else if (strcmp(line, "decrypt aes\n") == 0) {
                printf("Triplet: %d, Cipher: %s, %s \n", triplet++, ciphers[2], "Decrypt");
                printf("Don't have aes stuff so ignore\n\n");
            }


        }


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
