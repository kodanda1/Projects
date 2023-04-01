#include <stdio.h>
#include <grlcoa/tools.h>
#include <grlcoa/unittest.h>
#include <time.h>
#include <stdlib.h>

// Assembly language functions
int first_minor(int *data, int size);
int last_minor(int *data, int size);

void show(int *data, int size);
void test_fm(int *data, int size, int expected, const char *msg);
void test_lm(int *data, int size, int expected, const char *msg);

void test1()
{
	int data1[] = {48, 37, 92, 4, 15, 55, 37};
	int data2[] = {48, 12, 92, 4, 15, 55, 37, 1};
	
    test_start("Testing first_minor");

	test_fm(data1, sizeof(data1)/sizeof(int), 4, "Testing first_minor");
	test_fm(data2, sizeof(data2)/sizeof(int), 12, "Testing first_minor");
}


void test2()
{
	int data1[] = {17, 48, 37, 92, 4, 15, 55, 37};
	int data2[] = {48, 18, 92, 44, 65, 55, 37, 41, 16};
	
    test_start("Tests first_minor works for first and last item in array");

	test_fm(data1, sizeof(data1)/sizeof(int), 17, "Testing first_minor first element in array");
	test_fm(data2, sizeof(data2)/sizeof(int), 16, "Testing first_minor last element in array");
}


void test3()
{
	int data1[] = {48, 37, 92, 4, 15, 55, 37};
	int data2[] = {48, 12, 92, 4, 66, 55, 37, 21};
	
    test_start("Testing last_minor");

	test_lm(data1, sizeof(data1)/sizeof(int), 15, "Testing last_minor");
	test_lm(data2, sizeof(data2)/sizeof(int), 4, "Testing last_minor");
}


void test4()
{
	int data1[] = {17, 48, 37, 92, 34, 25, 55, 37, 57};
	int data2[] = {16, 48, 18, 92, 44, 65, 55, 37, 41, 16};
	
    test_start("Tests last_minor works for first and last item in array");

	test_lm(data1, sizeof(data1)/sizeof(int), 17, "Testing last_minor first element in array");
	test_lm(data2, sizeof(data2)/sizeof(int), 16, "Testing last_minor last element in array");
}




int main(int argc, char *argv[])
{
    srand((unsigned int)time(NULL));

    tests_start();
    
    test1();
    test2();
    test3();
    test4();
          
    tests_end();

    return 0;
}


void test_fm(int *data, int size, int expected, const char *msg)
{
	show(data, size);
	assert_equal_int(first_minor(data, size), expected, msg);
}


void test_lm(int *data, int size, int expected, const char *msg)
{
	show(data, size);
	assert_equal_int(last_minor(data, size), expected, msg);
}


/**
 * Display a list of numbers
 * @param data Pointer to list
 * @param size Size of the list
 */
void show(int *data, int size) 
{
	int i;
	
	for(i=0; i<size; i++)
	{
		printf("%d ", data[i]);
	}
	
	printf("\n");
}



