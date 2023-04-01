//   cache-perf.cpp
//	 Assignment 1.  Cache Enhancement of Code Execution
//   CSE 325, Fall 2021
//   Courtesy of R. James and P. McKinley

//   This program uses access to the Time Stamp Counter register to
//   measure the effect of caching on memory access time.

#include <stdio.h>
#include <cstdint>
#include <x86intrin.h>	//	Linux dev
#include <string.h>

#define PAGELEN 4096
#define MAXPAGE 32

// function to print message in case of invalid usage
void usage();


//	main(int argc, char * argv[])
//	This is a 'C' standard format to handle command-line parameters
//		argc -	the number of command-line parameters.  This includes
//				the name of the executable, so argc will always be >= 1.
//		argv -	An array of pointers to 'C' strings, not instances of the 'C++'
//				String class.  This array of pointers is NULL terminated.
int main(int argc, char * argv[]) 
{

    // should be two command line parameters, number of pages and probe value
    if(argc != 3)
    {
        usage();
        return(-1);
    }

    char *newarray = NULL;           // used to allocate an array of length NUMPAGE * PAGELEN
	int numpage = 2;                 // number of pages in newarray
    int probe = 1;                   // number of page to be probed
    char x = 0;                       // character used to "probe" the array
    unsigned long long start, stop;  // start and stop rdtsc "timer"
    int i = 0;                       // counter

	// convert ascii command line parameters to integers
    numpage = atoi( argv[1] );
    probe = atoi( argv[2] );

    // check validity of numpage
    if ((numpage <= 1) || (numpage > MAXPAGE))
    {
	  printf("Invalid 'numpage' value --> %d\n", numpage);
	  printf("Value of 'numpage' must be greater than 1 and less than %d\n",(int) MAXPAGE+1);
	  return(-2);
    }

    // check validity of probe
    if ((probe <= 0) || (probe >= numpage))
    {
	  printf("Invalid 'probe' value --> %d\n", probe);
	  printf("Value of 'probe' must be greater than 0 and less than %d\n",(int) numpage);
	  return(-2);
    }

	
	// allocate space for newarray
	newarray = (char*)malloc(numpage * PAGELEN);

	if (newarray == NULL)
	{
		printf("Memory allocation error!\n");
		return(-1);
	}

	// The variable probe identifies a page of the array to be probed.
	// Probe that page by reading the first byte of the page into the variable x.

    //  [1. INSERT YOUR CODE HERE]
	// Assigning newarray to the character x.
	x= newarray[(probe*PAGELEN)];

	//	In a loop, read the first byte of each page of the array into the variable x.
	//  Use __rdtsc() to measure the cycles elapsed for each read operation, and print out that value.
	for (i = 0; i < numpage; i++)
	{
	    //  [2. INSERT YOUR CODE HERE]
		start = _rdtsc();       // Assigning number of cycles to start variable.          
	    x= newarray[i * PAGELEN]; // Assigning each character of first page to variable x.
	    stop = _rdtsc(); //Assigning number of cycles to stop variable. 
	    printf("cycles used for ==%llu\n", stop -start); // Difference between stop and start will be the number of cycles.
	}

	// we increment x in order to silence a compiler warning
	x++;
	free(newarray);
	return(0);
}


void usage()
{
	printf("Usage: cache-perf numpage probe \n");
	printf("Where:\n");
	printf("cache-perf - The name of the executable.\n");
	printf("numpage - The number of pages allocated for the array.\n");
	printf("probe - The index of the page to be probed.\n");
}

