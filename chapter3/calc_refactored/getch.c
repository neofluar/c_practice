#include <stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE];  	/* buffer for ungetch() */
int bufp = 0;       	/* next free position in buf */

int getch(void) {    	/* get symbol from buf or input stream */
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {	/* turn back c in input stream */
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

