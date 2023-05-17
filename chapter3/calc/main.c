#include <stdio.h>
#include <stdlib.h>  /* to use atof() */
#include <math.h>    /* to use fmod() */

#define MAXOP 100    /* op max size */
#define NUMBER '0'   /* number property */

int getop(char s[]);
void push(double);
double pop(void);

/* Calculator in Reverse Polish notation */
int main() {
	int type;
	double op1, op2;
	char s[MAXOP];
	
	while ((type = getop(s)) != EOF) {
		if (type != '\n')
			printf("Got %s\n", s);
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0)
					push(pop() / op2);
				else
					printf("error: zero division\n");
				break;
			case '%':
				op2 = pop();
				op1 = pop();
				if (op2 != 0)
					push(op1 - op2 * floor(op1 / op2));
				else
					printf("error: zero division\n");
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	return 0;
}

#define MAXVAL 100  /* Max stack length */

int sp = 0;         /* Next free position in stack */
double val[MAXVAL]; /* Stack of operands */

/* push: put number f in the stack */
void push(double f) {
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("eror: stack full, can't push %g\n", f);
}

/* pop: return the next number from the stack */
double pop(void) {
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

#include <ctype.h>

int getch(void);
void ungetch(int);

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

