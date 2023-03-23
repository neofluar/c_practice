#include <stdio.h>
#include <limits.h>

int main() {
	printf("Number of bits in a `char` = %d\n", CHAR_BIT);
	printf("Range of a `signed char`            = [%d, %d]\n", SCHAR_MIN, SCHAR_MAX);
	printf("Range of a `unsigned char`          = [%u, %d]\n", 0, UCHAR_MAX);
	printf("Range of a `signed short int`       = [%d, %d]\n", SHRT_MIN, SHRT_MAX);
	printf("Range of a `unsigned short int`     = [%u, %d]\n", 0, USHRT_MAX);
	printf("Range of a `signed int`             = [%d, %d]\n", INT_MIN, INT_MAX);
	printf("Range of a `unsigned int`           = [%u, %u]\n", 0, UINT_MAX);
	printf("Range of a `signed long int`        = [%ld, %ld]\n", LONG_MIN, LONG_MAX);
	printf("Range of a `unsigned long int`      = [%u, %lu]\n", 0, ULONG_MAX);
	printf("Range of a `signed long long int`   = [%lld, %lld]\n", LLONG_MIN, LLONG_MAX);
	printf("Range of a `unsigned long long int` = [%u, %llu]\n", 0, ULLONG_MAX);	
}
