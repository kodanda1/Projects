#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Local functions
void try_it(int size);
void show(int *data, int size);

// Assembly language functions
int first_minor(int *data, int size);
int last_minor(int *data, int size);

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
void try_it(int size) 
{
	int i;
	int *data = calloc(size, sizeof(int));
	
	for(i=0; i<size; i++)
	{
		data[i] = rand() % 80 + 1;
	}
	
	printf("Ages: ");
	show(data, size);
	
	int first = first_minor(data, size);
	int last = last_minor(data, size);
	
	printf("First minor is %d years old, last minor is %d years old\n", first, last);
	
	free(data);
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

