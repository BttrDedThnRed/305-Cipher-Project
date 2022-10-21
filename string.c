#include "string.h"
#include <string.h>
#include <stdlib.h>
string *new_plain(char *str, int roundup) {
	string *s=malloc(sizeof(string));
	//s->plain=malloc(sizeof(s->plain))
	//s->plain=str;
	strcpy(s->plain,str);
	s->len=strlen(str);
	return(s);
}


