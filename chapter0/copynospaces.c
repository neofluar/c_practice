#include <stdio.h>

int main()
{
	int c;
	short flag;
	
	flag = 0;

	while ((c = getchar()) != EOF) {
		if (c != ' ') {
			flag = 0;
			putchar(c);
		}
		
		if (c == ' ' && flag == 0) {
			flag = 1;
			putchar(c);
		}
			
		if (c == ' ' && flag == 1)
			;
	}

	return 0;
}
