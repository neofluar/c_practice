#include <stdio.h>

#define MAX_WORD_LEN 15

int main() 
{
	int i, j, c, len;
	int lengths[MAX_WORD_LEN];
	
	len = 0;
	for (i = 0; i < MAX_WORD_LEN; ++i)
		lengths[i] = 0;
	
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			if (len != 0) {
				++lengths[len];
				len = 0;
			}
		}
		else
			++len;
	}

	for (i = 1; i < MAX_WORD_LEN; ++i) {
		printf("%2d", i);
		for (j = 0; j < lengths[i]; ++j)
			printf("|");
		printf("\n");
	}
	
	return 0;
}

