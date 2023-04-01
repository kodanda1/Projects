#include <stdio.h>
#include <grlcoa/tools.h>
#include <grlcoa/unittest.h>
#include <time.h>
#include <stdlib.h>
#include <memory.h>

void testIt(int width, int height);

// Assembly language functions
void life(int *cells, int width, int height);
void _life(int *cells, int width, int height);

int _getbit(int *cells, int size, int desired);
void _setbit(int *cells, int size, int desired, int setit);

void binary(int *cells, int width, int height);

void test1()
{
	
    test_start("Test");

	testIt(1, 1);
	testIt(1, 2);
	testIt(1, 3);
	testIt(2, 1);
	testIt(2, 2);
	testIt(2, 5);
	testIt(4, 8);
}


void test2()
{

}


void test3()
{

}



int main(int argc, char *argv[])
{
    srand((unsigned int)time(NULL));

    tests_start();
    
    test1();
    test2();
    test3();

          
    tests_end();

    return 0;
}



void testIt(int width, int height)
{
	int i, r, c;
	
	int *data = (int *)calloc(width * height, sizeof(int));
	int *data2 = (int *)calloc(width * height, sizeof(int));

	int *save = (int *)calloc(width * height, sizeof(int));
	
	printf("Testing: %d, %d", width, height);
	
	for(i=0; i<width * height; i++)
	{
		data[i] = rand() + rand();
		data2[i] = data[i];
		save[i] = data[i];
	}
	
	printf("\n");
	
	
	life(data, width, height);			// Actual
	_life(data2, width, height);		// Expected
	
	for(i=0; i<width * height * 32; i++) 
	{
		int expected = _getbit(data2, width * height, i);
		int actual = _getbit(data, width * height, i);
		
		if(expected != actual) {
			printf("Failed at row %d column %d\n", i/(width * 32), i%(width * 32));
			//binary(save, width, height);
			//printf("\n");
			//binary(data2, width, height);
			
			for(r=-1; r<=1;  r++) {
				for(c=-1; c<=1; c++) {
					printf("%d", _getbit(save, width * height, i + r * 32 + c));
				}
				
				printf("\n");
			}
			
			printf("Actual Result:   %d\n", actual);
			printf("Expected Result: %d\n", expected);
			
			assert_equal_int(expected, actual, "values differ");
		}
		
		if(data[i] != data2[i])
		{	

		}
	}

	free(data);
	free(data2);
	free(save);
}

int _getbit(int *cells, int size, int desired)
{
	if(desired < 0 || desired >= (size * 32)) 
	{
		return 0;
	}
	
	return (cells[desired/32] >> (31 - (desired % 32))) & 1;
}

void _setbit(int *cells, int size, int desired, int setit)
{
	if(setit)
	{
		cells[desired/32] |= 1 << (31 - (desired % 32));
	} 
	else 
	{
		cells[desired/32] &= ~(1 << (31 - (desired % 32)));
	}
}

void _life(int *cells, int width, int height) {int i,r,c;int size=width*height;int*cells2=
(int *)calloc(size, sizeof(int));for(i=0;i<size*32;i++){int total=0;for(r=-1;r<=1;r++)
{for(c=-1;  c<=1;  c++) {if(r == 0 && c == 0) {continue;}total += _getbit(cells, size,
i+r*width*32+c);}}if(total < 2) {_setbit(cells2, size, i, 0);} else if(total == 2) {_setbit(
cells2, size, i, _getbit(cells, size, i));} else if(total == 3) {_setbit(cells2, size, i, 1);
} else {_setbit(cells2, size, i, 0);}}memcpy(cells, cells2, size * sizeof(int));free(cells2);}

void binary(int *cells, int width, int height)
{   int r, c, j;
    
	for(r=0;  r<height;  r++) {
		for(c=0;  c<width; c++) {
			for(j=31; j>=0; j--)
			{
				if((*cells & (1 << j))) 
				{
					printf("1");
				} 
				else
				{
					printf("0");
				}
				
			}
		
			cells++;
		}
		
		printf("\n");
	}
}




