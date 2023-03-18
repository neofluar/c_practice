#include <stdio.h>

#define SHOWLIMIT 20
#define MAXLINE 1000

int mygetline(char s[], int limit);
void myshowline(char s[]);

int main() {
	
	int len;
	char line[MAXLINE];
	
	while ((len = mygetline(line, MAXLINE)) > 0)
		if (len > SHOWLIMIT)
			myshowline(line);
	
	return 0;
}

int mygetline(char s[], int limit) {
	int c, i;
	
	for (i = 0; i <= limit && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void myshowline(char s[]) {
	int c, i;
	
	i = 0;
	while ((c = s[i]) != '\0') {
		putchar(c);
		++i;
	}
}
