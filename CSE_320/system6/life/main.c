/**
 * @file main.c
 * Simple program to test and demonstrate the game of life function.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


void display(int *cells, int width, int height);
void life(int *cells, int width, int height);
int load(int *cells, int width, int height, const char *option);


int main(int argc, char **argv)
{
	char ch;
	int generation = 0;
	char *option = "random";
	
	srand((unsigned int)time(NULL));
    
	if(argc < 3) 
	{
		printf("Usage: life width height [option]\n");
		return 1;
	}
	
	int width = atoi(argv[1]);
	int height = atoi(argv[2]);
	
	if(argc > 3) {
		option = argv[3];
	}
	
	if(width < 2) 
	{
		printf("Width must be at least 2\n");
		return 1;
	}
	
	if(height < 2) 
	{
		printf("Height must be at least 2\n");
		return 1;
	}
	
	/*
	 * Allocate memory for the life cells
	 */
	int *cells = (int *)calloc(width * height, sizeof(int));
	if(!load(cells, width, height, option)) {
		return 1;
	}
	
	// Display initial generation
    printf("Generation: %d\n", generation);
	display(cells, width, height);
	
	ch = getchar();
	
	while(ch != 'x' && ch != 27 && ch != 'q') {
		generation++;
		life(cells, width, height);
		
		printf("Generation: %d\n", generation);
		display(cells, width, height);
	
		ch = getchar();
	};

	free(cells);
	return 0;
}

int load(int *cells, int width, int height, const char *option) {
	int i;
	
	if(strcmp(option, "blinker") == 0) {
		if(height < 3) 
		{
			printf("Height must be at least 3\n");
			free(cells);
			return 0;
		}
		
		cells[0] =          0x00010000;
		cells[width] =      0x00010000;
		cells[width * 2] =  0x00010000;
	} else if(strcmp(option, "glider") == 0) {
		if(height < 5) 
		{
			printf("Height must be at least 5\n");
			free(cells);
			return 0;
		}
		
		cells[0] =          0x00000000;
		cells[width] =      0x02000000;
		cells[width * 2] =  0x01000000;
		cells[width * 3] =  0x07000000;
		cells[width * 4] =  0x00000000;
	} else if(strcmp(option, "toad") == 0) {
		if(height < 4) 
		{
			printf("Height must be at least 4\n");
			free(cells);
			return 0;
		}
		
		cells[0] =          0x00020000;
		cells[width] =      0x00090000;
		cells[width * 2] =  0x00090000;
		cells[width * 3] =  0x00040000;
	} else if(strcmp(option, "beacon") == 0) {
		if(height < 4) 
		{
			printf("Height must be at least 4\n");
			free(cells);
			return 0;
		}
		
		cells[0] =          0x000c0000;
		cells[width] =      0x00080000;
		cells[width * 2] =  0x00010000;
		cells[width * 3] =  0x00030000;
	} else if(strcmp(option, "pulsar") == 0) {
		if(height < 17) 
		{
			printf("Height must be at least 17\n");
			free(cells);
			return 0;
		}
		
		cells[0] =          0x00000000;
		cells[width] =      0x00410000;
		cells[width * 2] =  0x00410000;
		cells[width * 3] =  0x00630000;
		cells[width * 4] =  0x00000000;
		cells[width * 5] =  0x07367000;
		cells[width * 6] =  0x01554000;
		cells[width * 7] =  0x00630000;
		cells[width * 8] =  0x00000000;
		cells[width * 9] =  0x00630000;
		cells[width *10] =  0x01554000;
		cells[width *11] =  0x07367000;
		cells[width *12] =  0x00000000;
		cells[width *13] =  0x00630000;
		cells[width *14] =  0x00410000;
		cells[width *15] =  0x00410000;
		cells[width *16] =  0x00000000;
	} else {
		// Random data
		for(i=0; i<width * height; i++) {
			cells[i] = (rand() & 0xffff) << 16 | (rand() & 0xffff);
		}
	}
	
	return 1;
}

void display(int *cells, int width, int height)
{
	int i, r, c;
	
	for(r=0; r<height; r++) {
		for(c=0; c<width; cells++, c++) 
		{
			for(i=0; i<32; i++) {
				if((*cells << i) & 0x80000000)
				{
                    printf("X");
				} 
				else
				{
                    printf(" ");
				}
			}
		}
		
		printf("\n");
	}
}

