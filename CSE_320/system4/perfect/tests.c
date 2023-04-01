/**
 * Tests for the assembly dumb multiply function.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <grlcoa/unittest.h>

long perfect_sqr(unsigned long num);
long _perfect_sqr(unsigned long num);

void tests();
void test_perfect(unsigned long a);


int main()
{
    srand((unsigned int)time(NULL));

    tests_start();
    
    tests();
    
    tests_end();

    return 0;
}

void tests() 
{
    int i;
    
    test_start("Testing perfect_sqr");
    
    test_perfect(81);
    test_perfect(1);
    test_perfect(2);
    test_perfect(3);
    test_perfect(4);
    test_perfect(5);
    test_perfect(8);
    test_perfect(9);
    test_perfect(10);
    for(i=0; i<20; i++) {
        test_perfect(rand() & 0x3fffffff);
    }
    for(i=0; i<20; i++) {
        unsigned int num = rand() & 0x7ffe;
        num *= num;
        test_perfect(num);
        test_perfect(num + 1);
    }

}


void test_perfect(unsigned long a)
{
    long actual = perfect_sqr(a);
    long expected = _perfect_sqr(a);
    char buffer[200];
    snprintf(buffer, 199, "Perfect Square: perfect_sqr(%lu) = %ld / should be %ld\n", a, actual, expected);
    assert_equal_long(actual, expected, buffer);
}

long _perfect_sqr(unsigned long num) {
    unsigned long n;
    unsigned long n_sqr = 1;
    unsigned long max;
    
    max = 1;
    max <<= 32;
    
    for(n=1;  n<max;  n++) {
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
