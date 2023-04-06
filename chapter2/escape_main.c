#include <stdio.h>

#include "../chapter1/mygetline.c"

void escape(char s[], char d[]);
void unescape(char s[], char d[]);

void escape(char s[], char d[]) {
	int i, j = 0;

	for (i = 0; s[i] != '\0'; i++) {
		switch (s[i]) {
			case '\a':
		        d[j++] = '\\';
		        d[j] = 'a';
		        break;    
		    case '\b':
		        d[j++] = '\\';
		        d[j] = 'b';
		        break;
		    case '\f':
		        d[j++] = '\\';
		        d[j] = 'f';
		        break;
		    case '\n':
				d[j++] = '\\';
				d[j] = 'n';
				break;
			case '\r':
		        d[j++] = '\\';
		        d[j] = 'r';
		        break;
		    case '\t':
				d[j++] = '\\';
				d[j] = 't';
				break;        
		    case '\v':
		        d[j++] = '\\';
		        d[j] = 'v';
		        break;
		    case '\\':
		        d[j++] = '\\';
		        d[j] = '\\';
		        break;
		    case '\?':
		        d[j++] = '\\';
		        d[j] = '?';
		        break;    
		    case '\"':
		        d[j++] = '\\';
		        d[j] = '\"';
		        break;
			default:
				d[j] = s[i];
				break;
		}
		j++;
	}
	d[j] = '\0';
}

void unescape(char s[], char d[]) {
	int i, j = 0;

	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] == '\\')
			switch (s[i + 1]) {
				case 'a':
				    d[j] = '\a';
				    i++;
				    break;    
				case 'b':
				    d[j] = '\b';
				    i++;
				    break;
				case 'f':
				    d[j] = '\f';
				    i++;
				    break;
				case 'n':
					d[j] = '\n';
					i++;
					break;
				case 'r':
				    d[j] = '\r';
				    break;
				case 't':
					d[j] = '\t';
					i++;
					break;        
				case 'v':
				    d[j] = '\v';
				    break;
				case '\\':
				    d[j] = '\\';
				    i++;
				    break;
				case '?':
				    d[j] = '\?';
				    i++;
				    break;    
				case '"':
				    d[j] = '\"';
				    i++;
				    break;
			}
		else
			d[j] = s[i];

		j++;
	}
	d[j] = '\0';
}


int main() {
	char source[MAXLINE], dest[MAXLINE];
	
	while (mygetline(source) > 0) {
		escape(source, dest);
		printf("%s\n", dest);
		unescape(dest, source);
		printf("%s\n", source);	
	}
	return 0;
}

