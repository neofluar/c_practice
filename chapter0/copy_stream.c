#include <stdio.h>

int copy_v1()
{
	int c;
	
	c = getchar();
	while (c != EOF) {
		putchar(c);
		c = getchar();
	}
	return 0;
}

int copy_v2()
{
	int c;

	while ((c = getchar()) != EOF) {
		putchar(c);
	}

	return 0;
}

int ex_16()
{
	int c, a;
	
	c = getchar();
	a = c == EOF;
	printf("%d", a);
	putchar(c);

	return 0;
}

int ex_17()
{
	printf("%d\n", EOF);

	return 0;
}


int main()
{
	copy_v2();
	return 0;
}

