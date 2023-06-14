#include <ctype.h>
#include "getch.c"

#define SIZE 10

int getch(void);
void ungetch(int);

int main() {
	int n, array[SIZE], getint(int *);
	int i;
	
	for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
		;
	for (i = 0; i < n; i++)
		printf("%d ", array[i]);
	printf("\n");
	return 0;
}

int getint(int *pn) {
	int c, sign;
	
	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '-' || c == '+') {
		c = getch();
		if (!isdigit(c) && c != EOF) {
			ungetch(c);
			return 0;
		}
	}
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}

