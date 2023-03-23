#include <stdio.h>

#include "mygetline.c"

int lower(int c);

int lower(int c) {
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
}

int main() {
	int c, i, len;
	char line[MAXLINE];
	
	while ((len = mygetline(line)) > 0) {
		
		for (i = 0; line[i] != '\0'; ++i)
			line[i] = lower(line[i]);
		line[i] = '\0';

		printf("%s\n", line);
	}

	return 0;
}

