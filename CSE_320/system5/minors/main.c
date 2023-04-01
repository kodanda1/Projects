#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Local functions
void try_it(long size);
void show(long *data, long size);

// Assembly language functions
long first_minor(long *data, long size);
long last_minor(long *data, long size);

int main() 
{
	// Seed the random number generator
	srand(time(NULL));
	
	try_it(20);
	try_it(20);
	try_it(40);
	try_it(100);

    return 0;
}

/**
 * Try a random list of a specified size
 * @param size Size of list to try
 */
void try_it(long size) 
{
	long i;
	long *data = calloc(size, sizeof(long));
	
	for(i=0; i<size; i++)
	{
		data[i] = rand() % 80 + 1;
	}
	
	printf("Ages: ");
	show(data, size);
	
	long first = first_minor(data, size);
	long last = last_minor(data, size);
	
	printf("First minor is %ld years old, last minor is %ld years old\n", first, last);
	
	free(data);
}

/**
 * Display a list of numbers
 * @param data Pointer to list
 * @param size Size of the list
 */
void show(long *data, long size) 
{
	long i;
	
	for(i=0; i<size; i++)
	{
		printf("%ld ", data[i]);
	}
	
	printf("\n");
}

