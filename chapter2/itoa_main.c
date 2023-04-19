#include <stdio.h>
#include <string.h>

#include "mygetline.c"
#include "atoi.c"

void reverse(char s[]);
void itoa(int n, char s[], int base);
int todigit(int c, int base);

int main() {
	int n;
	char line[100], s[100];

	while (mygetline(line, 100) > 1) {
		n = atoi(line);

		itoa(n, s, 2);
		printf("base2 : %s\n", s);
		itoa(n, s, 8);
		printf("base8 : %s\n", s);
		itoa(n, s, 10);
		printf("base10: %s\n", s);
		itoa(n, s, 16);
		printf("base16: %s\n", s);
	}
	return 0;
}

void itoa(int n, char s[], int base) {
	int i, c, sign;
	
	if ((sign = n) < 0) {
		n = -((long) n);
	}
	
	i = 0;
	while (1) {
		c = n % base;
		if (c < 10) 
			s[i++] = c + '0';
		else
			s[i++] = todigit(c, base);
		
		if ((n /= base) == 0)
			break;
	}
	
	if (base == 8)
		s[i++] = '0';
	else if (base == 16)
		s[i++] = 'x', s[i++] = '0';
	
	if (sign < 0)
		s[i++] = '-';
	
	s[i] = '\0';
	
	reverse(s); 
}

void reverse(char s[]) {
	int i, j;
	char temp;
	
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
		temp = s[i], s[i] = s[j], s[j] = temp;
}

int todigit(int c, int base) {
	if (base == 16)
		return 'A' + c - 10;
}

