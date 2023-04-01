/**
 * Simple program to test and demonstrate bezier
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double bezier(double t);

void test(double t);

int main(int argc, char **argv)
{
	test(0);
	test(0.25);
	test(0.5);
	test(0.75);
	test(1);
		
	return 0;
}

void test(double t) 
{
	printf("bezier(%f) = %f\n", t, bezier(t));
}
