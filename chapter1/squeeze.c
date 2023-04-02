#include <stdio.h>

#include "mygetline.c"

void squeeze_char(char s[], int c);
void squeeze_all(char s1[], char s2[]);
int char_in_line(char s[], int c);

/* Remove a symbol from a line */
void squeeze_char(char s[], int c) {
	int i, j;

	for (i = j = 0; s[i] != '\0'; i++)
		if (s[i] != c)
			s[j++] = s[i];
	s[j] = '\0';
}

/* Remove a symbol from a line if it presents in other line */
void squeeze_all(char s1[], char s2[]) {
	int i, j;
	
	for (i = j = 0; s1[i] != '\0'; i++)
		if (!char_in_line(s2, s1[i]))
			s1[j++] = s1[i];
	s1[j++] = '\n';
	s1[j] = '\0';
}

/* Return 1 if a symbol belongs to a line */
int char_in_line(char s[], int c) {
	int i;
	
	for (i = 0; s[i] != '\0'; i++)
		if (s[i] == c)
			return 1;
	return 0;
}

int main() {
	char line[MAXLINE];
	char cc[MAXLINE];
	
	while (mygetline(line) > 0) {
		mygetline(cc);
		/* squeeze_char(line, cc[0]); */
		squeeze_all(line, cc);
		printf("%s", line);
	}
	return 0;
}

