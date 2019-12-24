#include <stdio.h>
#include <stdint.h>
#include <math.h>

#ifdef __STDC_IEC_559__
const int iec_559 = 1;
#else
const int iec_559 = 0;
#endif

void test_intptr(void)
{
    if (sizeof(intptr_t) < sizeof(int64_t)) {
	printf("int64_t is larger than intptr_t\n");
    } else if (sizeof(intptr_t) > sizeof(int64_t)) {
	printf("int64_t is smaller than intptr_t\n");
    } else {
	printf("int64_t is the same as intptr_t\n");
    }
    printf("int64_t is %d bytes, intptr_t is %d bytes\n", sizeof(int64_t),
	   sizeof(intptr_t));
}

void test_int(void)
{
    printf
	("size of int=%d, long=%d, long int=%d, long long=%d, short=%d, char=%d\n",
	 sizeof(int), sizeof(long), sizeof(long int), sizeof(long long),
	 sizeof(short), sizeof(char));
}

/* 
 * Include <math.h> and test for __STDC_IEC_559__.
 *
 * If the macro is defined, not only are the types better specified (float
 * being 32bits and double being 64bits among others), but also the behavior
 * of builtin operators and standard-functions is more specified.
 */
void test_float(void)
{
    printf("size of float=%d, double=%d, long double=%d\n", sizeof(float),
	   sizeof(double), sizeof(long double));
    printf("IEC 559 is %sdefined\n", iec_559 ? "" : "not ");
}

int main(int argc, char **argv)
{
    test_intptr();
    test_int();
    test_float();
    return 0;
}
