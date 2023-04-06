#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "../chapter1/mygetline.c" 

void expand(char s1[], char s2[]);
int isexpandable(int c1, int c2);

/* Expand "-a-b-e0-0-3--\n\0" to "-abce0-0123--\n\0" */
void expand(char s1[], char s2[]) {
	int i, j, k;
	
	for (i = j = 0; s1[i] == '-' || s1[i] == '\n'; i++, j++) /* copy leading "-" */  
		s2[j] = s1[i];
		
	while (s1[i] != '\n') {
		if (s1[i] == '-' && isexpandable(s1[i - 1], s1[i + 1])) {
			for (k = 1; s1[i - 1] + k != s1[i + 1]; k++)
				s2[j++] = s1[i - 1] + k;		
		}
		else
			s2[j++] = s1[i];
		i++;
	}
	s2[j++] = s1[i++];
	s2[j] = '\0';
}

int isexpandable(int c1, int c2) {
	if (c1 < c2) {
		if (isalpha(c1) && isalpha(c2))
			return (isupper(c1) && isupper(c2)) || (islower(c1) && islower(c2));
		else
			return isdigit(c1) && isdigit(c2);
	}
	else
		return 0;
}
	
int main() {
	char s1[MAXLINE], s2[MAXLINE];
	
	while (mygetline(s1) > 0) {
		expand(s1, s2);
		printf("%s", s2);	
	}
	return 0;

}

