#include "string.h"
#include <stdio.h>
int main(){
	string *s=new_plain("gusty",0);
	printf("%s\n", s->plain);
	printf("%d\n", s->len);
	printf("%d\n",(int)sizeof(string));
}
