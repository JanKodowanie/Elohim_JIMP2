#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>

#include "game_config.h"
#include "board_storage.h"
#include "png.h"

#define MAX_RES 640

void write_png_file(char* file_name, board cells, char defchar) {

    int x, y;
    png_bytep * row_pointers;

    int resolution = cells->columns > cells->rows ? MAX_RES/cells->columns : MAX_RES/cells->rows;
    int width = cells->columns * resolution;
    int height = cells ->rows * resolution;
    char** bigmatrix = malloc (sizeof(char*) * height);

    for (int i=0; i<height; i++) {
        bigmatrix[i] = malloc (sizeof(char) * width);
        for (int j=0; j<width; j++)
            bigmatrix[i][j] = cells->matrix[i/resolution][j/resolution];
    }
    png_byte bit_depth = 8;
    png_byte color_type = PNG_COLOR_TYPE_GRAY;

    row_pointers = (png_bytep*) malloc(sizeof(png_bytep) * height);
    for (y=0; y<height; y++)
        row_pointers[y] = (png_byte*) malloc(sizeof(png_byte) * width);

    for (y=0; y<height; y++) {
        png_byte* row = row_pointers[y];
        for (x=0; x<width; x++) {
            if (bigmatrix[y][x] == defchar) row[x] = 0;
            else row[x] = 255;
        }
    }

    FILE *fp = fopen(file_name, "wb");
    if (!fp)
        printf("[write_png_file] File %s could not be opened for writing", file_name);

    png_structp png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

    if (!png_ptr) {
        printf("[write_png_file] png_create_write_struct failed");
    }

    png_infop info_ptr = png_create_info_struct(png_ptr);
    if (!info_ptr)
        printf("[write_png_file] png_create_info_struct failed");

    if (setjmp(png_jmpbuf(png_ptr)))
        printf("[write_png_file] Error during init_io");

    png_init_io(png_ptr, fp);

    if (setjmp(png_jmpbuf(png_ptr)))
        printf("[write_png_file] Error during writing header");

    png_set_IHDR(png_ptr, info_ptr, width, height,
    bit_depth, color_type, PNG_INTERLACE_NONE,
    PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);

    png_write_info(png_ptr, info_ptr);

    if (setjmp(png_jmpbuf(png_ptr)))
        printf("[write_png_file] Error during writing bytes");

    png_write_image(png_ptr, row_pointers);

    if (setjmp(png_jmpbuf(png_ptr)))
        printf("[write_png_file] Error during end of write");

    png_write_end(png_ptr, NULL);

    png_destroy_write_struct(&png_ptr, &info_ptr);
    png_free_data(png_ptr, info_ptr, PNG_FREE_ALL, -1);

    for (int i=0; i<height; i++)
        free(bigmatrix[i]);
    free (bigmatrix);

    for (y=0; y<height; y++)
        free(row_pointers[y]);
    free(row_pointers);

    fclose(fp);
}
