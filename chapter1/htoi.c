#include <stdio.h>
#include <ctype.h>

#include "mygetline.c"

unsigned int htoi(char s[]);

/* Convert a hex string to an unsigned integer */
unsigned int htoi(char s[]) {
	int i, n;
	
	n = 0;
	if (s[0] == '0' && tolower(s[1]) == 'x') {
		for (i = 2; s[i] != '\n'; ++i)
			if (isdigit(s[i]))
				n = 16 * n + s[i] - '0';
			else
				n = 16 * n + (tolower(s[i]) - 'a' + 10);
	}

	return n;
}

int main() {
	int len;
	char line[MAXLINE];

	while ((len = mygetline(line)) > 0)
		printf("%u\n", htoi(line));
	
	return 0;
}

