#include <stdio.h>
#include <stdlib.h>
#include <png.h>
#include <math.h>
#include "image.h"


int write_image(void *image, const char *filename)
{
	// File pointer and libpng pointers
	FILE *fp = NULL;
	png_structp png_ptr = NULL;
	png_infop info_ptr = NULL;
	png_bytep row = NULL;

	// The image size we will make
	int width = get_width(image);
	int height =get_height(image);
	
	// Open file for writing (binary mode)
	fp = fopen(filename, "wb");
	if (fp == NULL) {
		fprintf(stderr, "Could not open file %s for writing\n", filename);
		return 0;
	}
	
	/*
	 * Initialize libpng
	 */
	 
	// Initialize write structure
	png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (png_ptr == NULL) {
		fprintf(stderr, "Could not allocate write struct\n");
		return 0;
	}

	// Initialize info structure
	info_ptr = png_create_info_struct(png_ptr);
	if (info_ptr == NULL) {
		fprintf(stderr, "Could not allocate info struct\n");
		return 0;
	}
                
	png_init_io(png_ptr, fp);

	// Write header (8 bit colour depth)
	png_set_IHDR(png_ptr, info_ptr, width, height,
         8, PNG_COLOR_TYPE_RGBA, PNG_INTERLACE_NONE,
         PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);

	png_write_info(png_ptr, info_ptr);
   
	// Allocate memory for one row (4 bytes per pixel - RGBA)
	row = (png_bytep) calloc(4 * width, sizeof(png_byte));

	// Write image data
	int r, c;
	for (r=0 ; r<height ; r++) 
	{
		for (c=0 ; c<width ; c++) 
		{
			//double x = xc - scale + scale * 2 * c / width;
			//double y = yc - scale + scale * 2 * r / height;
			//int m = tricorn(x, y);

			double value = get_pixel(image, r, c) * 255;
			if(value < 0) 
			{
				value = 0;
			}
			if(value > 255) 
			{
				 value = 255;
			}
			 
			png_byte bp = (png_byte)value;
			png_byte *pixel = &row[c*4];
			pixel[0] = bp;
			pixel[1] = bp;
			pixel[2] = bp;
			pixel[3] = 0xff;
		}

		png_write_row(png_ptr, row);
	}

	free(row);

	// End write
	png_write_end(png_ptr, NULL);
	png_destroy_write_struct(&png_ptr, &info_ptr);

	fclose(fp);

	return 1;
}
