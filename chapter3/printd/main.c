#include <stdio.h>
#include "atoi.c"
#include "printd.c"
#include "mygetline.c"

#define MAXLEN 100

int main() {
	int n;
	char line[MAXLEN];
	
	while (mygetline(line, MAXLEN) > 1) {
		n = atoi(line);
		printd(n);
		putchar('\n');
	}
	return 0;	
}

