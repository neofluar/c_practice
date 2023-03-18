#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20


/* Fahrenheight to Celsius convertion */
void fahr2cel()
{
	float fahr, cels;
	int lower, upper, step;
	
	lower = 0;
    upper = 300;
    step = 20;
	
	printf("%5s\t%5s\n", "fahr", "cels");

	fahr = lower;
	while (fahr <= upper) {
		cels = (5.0/9.0) * (fahr - 32.0);
		printf("%5.0f\t%5.1f\n", fahr, cels);
		fahr = fahr + step;
	}
}

/* Celsius to Fahrenheight convertion */
void cels2fahr()
{
	float fahr, cels;
	int lower, upper, step;
	
	lower = -20;
    upper = 150;
    step = 20;
	
	printf("%5s\t%5s\n", "cels", "fahr");

	cels = lower;
	while (cels <= upper) {
		fahr = (9.0/5.0) * cels + 32.0;
		printf("%5.0f\t%5.1f\n", cels, fahr);
		cels = cels + step;
	}
}

void reversed_fahr2cel()
{
	float fahr;
	
	printf("%5s\t%5s\n", "fahr", "cels");
	
	for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP){
		printf("%5.0f\t%5.1f\n", fahr, (5.0/9.0) * (fahr-32.0));
	}
}

int main()
{
    fahr2cel();
    cels2fahr();
    reversed_fahr2cel();
    return 0;
}

