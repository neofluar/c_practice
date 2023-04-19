#include <stdio.h>

#define MAXLINE 1000

int mygetline(char s[]);

int mygetline(char s[]) {
	int i;
	char c;
	
	i = 0;
	for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

