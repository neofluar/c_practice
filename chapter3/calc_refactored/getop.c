#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/* getop: read the next operand or operator */
int getop(char s[]) {
	int i, c, cc;
	
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';

	if (!isdigit(c) && c != '.' && c != '-')
		return c;    /* operator */
	
	i = 0;
	if (c == '-')
		if (isdigit(c = getch()))
			s[++i] = c;
		else {
			ungetch(c);
			return '-';
		}

	if (isdigit(c))  /* read the mantis */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')    /* read the exp */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	printf("get_op: read number %s\n", s);
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

