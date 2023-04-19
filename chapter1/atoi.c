#include <stdio.h>
#include <ctype.h>

unsigned atoi(char s[]);

/* Convert a string s to integer */
unsigned int atoi(char s[]) {
	int i, n;
	
	n = 0;
	for (i = 0; isdigit(s[i]); ++i)
		n = n * 10 + (s[i] - '0');
	return n;
}

