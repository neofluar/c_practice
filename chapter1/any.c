#include <stdio.h>

#include "mygetline.c"

int any(char s1[], char s2[]);

int any(char s1[], char s2[]) {
	int i, j;
	
	for (i = 0; s1[i] != '\n'; ++i)
		for (j = 0; s2[j] != '\n'; ++j)
			if (s2[j] == s1[i])
				return i;
	return -1; 
}

int main() {
	char line1[MAXLINE];
	char line2[MAXLINE];
	
	while (mygetline(line1) > 0) {
		mygetline(line2);
		printf("%d\n", any(line1, line2));
	}
	return 0;
}

