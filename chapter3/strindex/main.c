#include <stdio.h>

#define MAXLINE 1000

int mygetline(char s[], int lim);
int strindex(char s[], char t[]);

char pattern[] = "ould";

int main() {
	char line[MAXLINE];
	int found = 0;
	
	while (mygetline(line, MAXLINE) > 0)
		if (strindex(line, pattern) >= 0) {
			printf("%s", line);
			found++;
		}
	return found;
}

