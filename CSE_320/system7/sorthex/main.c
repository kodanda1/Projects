/**
 * @file main.c
 * Simple program to test and demonstrate the sort4 and support functions.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <grlcoa/tools.h>

int gethex(void *data, int size, int index);
void sethex(void *data, int size, int index, int value);
void sorthex(void *data, int size);

void demo_gethex();
void demo_sethex();
void demo_sorthex();


int main(int argc, char **argv)
{
	demo_gethex();
	demo_sethex();
	demo_sorthex();
	
	return 0;
}

void demo_gethex() 
{
	unsigned char data[] = {0x12, 0x34, 0xa1, 0x8c, 0x78, 0x56, 0x00, 0xf0};
	int size = sizeof(data);

	printf("----demo_gethex()----\n");
	memory(data, size);
	
	int i;
	
	/*
	 * gethex demonstrations
	 */
	for(i=0; i<size*2; i++) {
		printf("%x ", gethex(data, sizeof(data), i));
	}
	printf("\n");
		
	// Test before and after the data
	printf("%x %x %x\n", 
	gethex(data, sizeof(data), -1),
	gethex(data, sizeof(data), sizeof(data) * 2),
	gethex(data, sizeof(data), 100000));
}


void demo_sethex() 
{
	unsigned char data[] = {0x12, 0x34, 0xa1, 0x8c, 0x78, 0x56, 0x00, 0xf0};
	int size = sizeof(data);
	
	printf("----demo_sethex()----\n");
	memory(data, size);
	
	int i;

	/*
	 * sethex demonstrations
	 */
	sethex(data, sizeof(data), 0, 0xa);
	sethex(data, sizeof(data), 1, 0x8);
	
	memory(data, size);
	
	for(i=0; i<size*2; i++) {
		sethex(data, sizeof(data), i, i);
	}

	memory(data, size);
	
	// This should not cause a crash
	sethex(data, size, -1, 0xf);
	sethex(data, size, size * 2, 0xf);
}

void demo_sorthex() 
{
	unsigned char data[] = {0x12, 0x34, 0xa1, 0x8c, 0x78, 0x56, 0x00, 0xf0};
	int size = sizeof(data);
	
	printf("----demo_sorthex()----\n");
	memory(data, size);
	
	sorthex(data, size);
	
	memory(data, size);
}

