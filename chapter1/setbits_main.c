#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);

/* Returns n bits starting from p-th */
unsigned getbits(unsigned x, int p, int n) {
	return (x >> (p + 1 - n)) & ~(~0 << n);
}

/* Returns x where n bits starting from p-th 
   replaced by n rightmost bits of y */
unsigned setbits(unsigned x, int p, int n, unsigned y) {
	unsigned a = ~(~0 << n);	
	unsigned b = ~(a << (p + 1 - n));
	
	return (x & b) | ((y & a) << (p + 1 - n));
}

int main() {
	printf("%u\n", getbits(20, 4, 3));
	printf("%x\n", setbits(0xd51, 5, 2, 0xad));
	return 0;
}

