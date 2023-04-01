#pragma once

/*
 * Header file included by the C components
 */

void *read_image(const char *filename);
int write_image(void *image, const char *filename);

/* Assembly functions */
void *create_image(int wid, int hit);
void destroy_image(void *image);
int get_width(void *image);
int get_height(void *image);
void set_pixel(void *image, int row, int col, double value);
double get_pixel(void *image, int row, int col);

void *blocky(void *);
