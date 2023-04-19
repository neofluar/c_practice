#include <stdio.h>

#define MAXLINE 1000

unsigned atoi(char s[]);
int mygetline(char s[], int lim);

/* Convert a string s to integer */
unsigned int atoi(char s[]) {
	int i, n;
	
	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = n * 10 + (s[i] - '0');
	return n;
}

int mygetline(char s[], int lim) {
	int i;
	char c;
	
	i = 0;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

int main() {

	char line[MAXLINE];
	
	while (mygetline(line, MAXLINE) > 0) {
		printf("%u\n", atoi(line));
	}

	return 0;
}

