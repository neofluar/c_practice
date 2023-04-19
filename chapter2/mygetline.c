#include <stdio.h>

int mygetline(char line[], int lim);

int mygetline(char line[], int lim) {
	int i, c;
	
	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		line[i++] = c;
	if (c == '\n')
		line[i++] = c;
	line[i] = '\0';
	return i;
}

