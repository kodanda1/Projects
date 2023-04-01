#include <stdio.h>
#include <stdlib.h>
#include <png.h>
#include <math.h>

#include <complex.h>

#define MAX_COLORS 256
#define WIDTH 512
#define HEIGHT WIDTH


int ship(double x0, double y0);
void init_colors(png_byte colors[MAX_COLORS][3]);
void demo(double x, double y);

int main(int argc, char **argv)
{
    demo(0, 0);
    demo(-1.75, -1.75);
    demo(2.0, 17.1);
    demo(2.0, 17.1);
    demo(-0.69043, -0.69043);
    demo(0.765625, -1.11426);
    demo(-1.51074, 0);
    

    // The x and y centers for the image
    double xc = 0;
    double yc = 0;
    
    // The image size in the Madelbrot scale
    double scale = 1.75;
    
    // File pointer and libpng pointers
    FILE *fp = NULL;
    png_structp png_ptr = NULL;
    png_infop info_ptr = NULL;
    png_bytep row = NULL;
    
    png_byte colors[256][3];
    init_colors(colors);

    // The image size we will make
    int width = WIDTH;
    int height = HEIGHT;
   
    // Do we have a command line argument?
    if(argc < 2) 
    {
        fprintf(stderr, "Usage: mandelbrot filename\n");
        return 1;
    }
    
    // Open file for writing (binary mode)
    fp = fopen(argv[1], "wb");
    if (fp == NULL) {
        fprintf(stderr, "Could not open file %s for writing\n", argv[1]);
        return 1;
    }
    
    /*
     * Initialize libpng
     */
     
    // Initialize write structure
    png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (png_ptr == NULL) {
        fprintf(stderr, "Could not allocate write struct\n");
        return 1;
    }

    // Initialize info structure
    info_ptr = png_create_info_struct(png_ptr);
    if (info_ptr == NULL) {
        fprintf(stderr, "Could not allocate info struct\n");
        return 1;
    }
                
    png_init_io(png_ptr, fp);

    // Write header (8 bit colour depth)
    png_set_IHDR(png_ptr, info_ptr, width, height,
         8, PNG_COLOR_TYPE_RGBA, PNG_INTERLACE_NONE,
         PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);

    png_write_info(png_ptr, info_ptr);
   
    // Allocate memory for one row (4 bytes per pixel - RGB)
    row = (png_bytep) calloc(4 * width, sizeof(png_byte));

    // Write image data
    int r, c;
    for (r=0 ; r<height ; r++) 
    {
        for (c=0 ; c<width ; c++) 
        {
            double x = xc - scale + scale * 2 * c / width;
            double y = yc - scale + scale * 2 * r / height;
            int m = ship(x, y);

            png_byte *pixel = &row[c*4];
            pixel[0] = colors[m][0];
            pixel[1] = colors[m][1];
            pixel[2] = colors[m][2];
            pixel[3] = 0xff;
        }

        png_write_row(png_ptr, row);
    }

    free(row);


    // End write
    png_write_end(png_ptr, NULL);
    png_destroy_write_struct(&png_ptr, &info_ptr);

    fclose(fp);

    return 0;
}

void demo(double x, double y)
{
    int c = ship(x, y);
    printf("ship(%f, %f) = %d\n", x, y, c);
}



void init_colors(png_byte colors[MAX_COLORS][3])
{
    int c;
    for(c=0; c<MAX_COLORS; c++) 
    {
        double x = (double)c / (double)MAX_COLORS;
        x = pow(x, 0.25);
        if(x < 0.5) 
        {
            x *= 2;     // Range is now 0-1
            colors[c][2] = (png_byte)((1 - x) * 255);
            colors[c][1] = (png_byte)(x * 255);
            colors[c][0] = 0;
        }
        else 
        {
            x = (x - 0.5) * 2;  // Range is now 0-1
            colors[c][2] = 0;
            colors[c][1] = (png_byte)((1 - x) * 255);
            colors[c][0] = (png_byte)(x * 255);
        }
    }
    
    // Force maximum iterations to be black
    colors[MAX_COLORS-1][0] = 0;
    colors[MAX_COLORS-1][1] = 0;
    colors[MAX_COLORS-1][1] = 0;
}


