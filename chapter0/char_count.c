#include <stdio.h>

int count_v1()
{
	long nc;
	
	nc = 0;
	while (getchar() != EOF) {
		++nc;
	}
	printf("%ld\n", nc);
	
	return 0;
}

int count_v2()
{
	double nc;
	
	for (nc=0; getchar() != EOF; ++nc)
		;
	printf("%.0f\n", nc);
	
	return 0;
}


int main()
{
	count_v2();

	return 0;
}
