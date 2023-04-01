#include <stdio.h>
#include <stdlib.h>
#include <png.h>
#include <math.h>
#include "image.h"

/*
 * To function as just a memory leak
 * test, set LEAKTEST to 1
 */
#define LEAKTEST 0

/* 
 * Set BLOCKY to 1 to do the actual 
 * image processing operation
 */
#define BLOCKY 1


int main(int argc, char **argv)
{
#if LEAKTEST
	/* 
	 * The following code can be used as a 
	 * memory leak tester with Valgrind. Just
	 * uncomment this block
	 */
	 
	void *img = create_image(1000, 1200);
	int r, c;
	for(r=0; r<get_height(img); r++) 
	{
		for(c=0; c<get_width(img);  c++)
		{
			set_pixel(img, 0, 0, 1);
			get_pixel(img, 0, 0);
		}
		
	}
	
	destroy_image(img);
	return 0;
#endif

	if(argc < 3)
	{
		printf("usage: blocky source.png result.png\n");
		return 1;
	}
	
	void *src = read_image(argv[1]);
	if(src == NULL) 
	{
		printf("Failed to read source image\n");
		return 1;
	}
	
	printf("Image %s read\n", argv[1]);
	

#if !BLOCKY
	int ret = write_image(src, argv[2]);
	if(!ret) 
	{
		printf("Failed to write destination image\n");
		return 1;
	}
	
	printf("Image %s written\n", argv[2]);
	
	destroy_image(src);
	printf("Image destroyed\n");
#else
	void *dest = blocky(src);
	
	printf("Blocky complete\n");
	
	int ret = write_image(dest, argv[2]);
	if(!ret) 
	{
		printf("Failed to write destination image\n");
		return 1;
	}
	
	printf("Image %s written\n", argv[2]);
	
	destroy_image(src);
	destroy_image(dest);
	printf("Images destroyed\n");
#endif

	return 0;
}
