#include <stdio.h>

/* Prototypes */
int power_v1(int m, int n);
int power_v2(int m, int n);

int main() 
{
	int i;
	
	printf(" i 2**i  -3**i\n");
	for (i = 0; i < 10; ++i)
		printf("%2d %4d %6d\n", i, power_v2(2, i), power_v2(-3, i));
	return 0;
}

/* power: base to the n-th, n >= 0 */
int power_v1(int base, int n) {
	int i, p;
	
	p = 1;
	for (i = 1; i <= n; ++i)
		p = p * base;
	return p;
}

int power_v2(int base, int n)
{
	int p;
	
	for (p = 1; n > 0; --n)
		p = p * base;
	return p;
}

