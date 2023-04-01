/**
 * @file main.c
 * Simple program to test and demonstrate and test digitcounter
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned int digitcounter(long value);

void test(unsigned long value);

int main(int argc, char **argv)
{
	test(5);
	test(22);
	test(108);
	
	return 0;
}

void test(unsigned long value) 
{
	printf("digitcounter(%lu) = %u\n", value, digitcounter(value));
}
