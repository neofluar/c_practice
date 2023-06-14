#include <stdio.h>
#include "calc.h"

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

