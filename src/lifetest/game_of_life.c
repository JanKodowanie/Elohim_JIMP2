#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "game_of_life.h"

void transform_cells(board cells, config cfg) {
    int n=0;
    /*if (cfg->ispngactive == 1) {
        char* zerogen = malloc((strlen(cfg->output)+9) * sizeof(char));
        strcpy(zerogen, cfg->output);
        strcat(zerogen, "/000.png");
        write_png_file(zerogen, cells, cfg->defchar);
        free(zerogen);
    }*/
    int r, c, counter;
    char **next = malloc(cells->rows*sizeof(char*));
    for (int i=0; i<cells->rows; i++)
	    next[i] = malloc (sizeof(char) * cells->columns);

    while (n < cfg->ngen) {
        for (r=0; r<cells->rows; r++) {
            for (c=0; c<cells->columns; c++) {
                counter = 0;
                if (r>0             && c>0                && cells->matrix[r-1][c-1] == cfg->defchar)  counter++;
                if (r>0             && c>=0               && cells->matrix[r-1][c  ] == cfg->defchar)  counter++;
                if (r>0             && c<cells->columns-1 && cells->matrix[r-1][c+1] == cfg->defchar)  counter++;
                if (r>=0            && c>0                && cells->matrix[r  ][c-1] == cfg->defchar)  counter++;
                if (r>=0            && c<cells->columns-1 && cells->matrix[r  ][c+1] == cfg->defchar)  counter++;
                if (r<cells->rows-1 && c>0                && cells->matrix[r+1][c-1] == cfg->defchar)  counter++;
                if (r<cells->rows-1 && c>=0               && cells->matrix[r+1][c  ] == cfg->defchar)  counter++;
                if (r<cells->rows-1 && c<cells->columns-1 && cells->matrix[r+1][c+1] == cfg->defchar)  counter++;      //zliczanie żywych sąsiadów

                if (cells->matrix[r][c] == '1') {                                                         //określanie następnej generacji
                    if (counter > 1 && counter < 4)
                        next[r][c] = cfg->defchar;
                    else next[r][c] = '0';
                }
                else {
                    if (counter == 3)
                        next[r][c] = cfg->defchar;
                    else next[r][c] = '0';
                }
            }
        }
        for (int i=0; i<cells->rows; i++)
            for(int j=0; j<cells->columns;j++) {
                cells->matrix[i][j] = next[i][j];
            }
        n++;
        /*if (cfg->ispngactive == 1) {
            char* nthgen = malloc ((strlen(cfg->output)+9) * sizeof(char));
            strcpy(nthgen, cfg->output);
            char* number = malloc (9*sizeof(char));
            snprintf (number, 5, "/%03i", n);
            strcat(number, ".png");
            strcat(nthgen, number);
            write_png_file(nthgen, cells, cfg->defchar);
            free(number);
            free(nthgen);
        }*/
    }
    for (int i=0; i<cells->rows; i++)
	    free(next[i]);
    free(next);

}

