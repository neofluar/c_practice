#include <stdio.h>

#include "mygetline.c"
#include "reverse.c"

#define MAXLEN 100

int main() {
	int len;
	char line[MAXLEN];
	
	while ((len = mygetline(line, MAXLEN)) > 1) {
		recursive_reverse(line, 0, len - 1);
		printf("%s\n", line);
	}
	return 0;	
}

