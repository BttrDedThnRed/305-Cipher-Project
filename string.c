#include "string.h"
string *new_plain(char *str, int roundup) {
	string *s = malloc(sizeof(string));
	s->plain=*str;

