#include <stdio.h>

#include "atoi.c"
#include "mygetline.c"

int bitcount(unsigned x);
int faster_bitcount(unsigned x);

int bitcount(unsigned x) {
	int b;
	
	for (b = 0; x != 0; x >>= 1)
		if (x & 01)
			b++;
	return b;
}

int faster_bitcount(unsigned x) {
	int b = 0;

	while (x &= (x - 1))
		b++;
	return b + 1;
}

int main() {
	unsigned x;
	char line[MAXLINE];
	
	x = 0;

	
	/* while (x < 100000000) {
		bitcount(x); is about 4 times slower
		faster_bitcount(x);
		x++;
	} */

	while (mygetline(line) > 0) {
		x = atoi(line);
		printf("%u == %u\n", bitcount(x), faster_bitcount(x));
	}
	return 0;
}

