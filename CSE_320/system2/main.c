/**
 * @file
 * Simple main function designed to exercise and test bin2dec
 */

#include <stdio.h>
#include "bin2dec.h"

/*
 * Forward references
 */
void test_binary(const char *binary);

/**
 * Program main entry point 
 */
int main()
{
	printf("%u\n", bin2dec("YNYNNNYYY"));
    test_binary("N");
    test_binary("Y");
    test_binary("YNY N Y");
    test_binary("Y Y");
    test_binary("Y N N Y");
    test_binary("Y");
    test_binary("YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY");
    test_binary("NYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY");
    test_binary("NYYYYYYYYYYYNYYYYYYNYYYYYYYYYYYY");
    test_binary("YN");
    test_binary("YNN");
    test_binary("YNNN");
    test_binary("YNNNN");
    test_binary("YNNN");

    return 0;
}

/**
 * A simple function that converts a binary number and displays the result
 */
void test_binary(const char *binary)
{
    printf("'%s' converts to %u\n", binary, bin2dec(binary));
}
