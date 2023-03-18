#include <stdio.h>

int main()
{
	int c;
	long nl, nt, ns;
	
	nl = nt = ns = 0;
	
	while ((c = getchar()) != EOF) {
	    if (c == '\n')
			++nl;
		if (c == '\t')
			++nt;
		if (c == ' ')
			++ns;
	}
	
	printf("lines\ttabs\tspaces\n");
	printf("%ld\t%ld\t%ld\n", nl, nt, ns);
	
	return 0;
}
