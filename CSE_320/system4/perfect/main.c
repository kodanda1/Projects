/**
 * @file main.c
 * Simple program to test perfect square function.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long perfect_sqr(unsigned long num);
 
void test_perfect(unsigned long a);
long _perfect_sqr(unsigned long num);

int main()
{
	test_perfect(0);
	test_perfect(3);
	test_perfect(4);
	test_perfect(8);
	test_perfect(9);
	test_perfect(10);
	test_perfect(81);
	test_perfect(23175 * 23175);
	test_perfect(1823 * 1823);
	test_perfect(1823 * 1823 + 1);
	test_perfect(32767 * 32767);
	
	printf("\n");
	
	return 0;
}


void test_perfect(unsigned long a)
{
	long s = perfect_sqr(a);
	printf("perfect_sqr(%lu) = %ld / should be %ld\n", a, s, _perfect_sqr(a));
}



long _perfect_sqr(unsigned long num) {
    unsigned long n;
    unsigned long n_sqr = 1;
    
    for(n=1;  n<(0x80000000 - 1);  n++) {
        if(n_sqr == num) {
            break;
        }

        if(n_sqr > num) {
            return 0;
        }
        
        n_sqr += n * 2 + 1;
    }
    
    return 1;
}	



