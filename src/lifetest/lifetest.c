#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "game_of_life.h"

int main (int argc, char **argv) {
    board cells = malloc(sizeof(board));
    config settings = malloc(sizeof(*settings));
    settings->defchar = '1';
    settings->ngen = atoi(argv[3]);
    settings->ispngactive=1;
    int i,j;
    cells->rows = atoi(argv[1]);
    cells->columns = atoi(argv[2]);
    srand(time(NULL));
    cells->matrix = malloc (sizeof(char*) * cells->rows);
    for (i=0; i<cells->rows; i++)
	    cells->matrix[i] = malloc (sizeof(char) * cells->columns);

    for (i=0;i<cells->rows;i++) {
        for (j=0; j<cells->columns;j++) {
	    int dupa = rand() % 2;
            cells->matrix[i][j] = dupa == 1 ? settings->defchar : '0';
        }
    }
    transform_cells(cells, settings);
    /*wypisywanie*/
    printf("%i %i\n", cells->rows, cells->columns);
    for (i=0;i<cells->rows;i++) {
        for (j=0; j<cells->columns;j++)
            printf ("%c ", cells->matrix[i][j]);
        printf ("\n");
    }
    for (i=0; i<cells->rows; i++)
        free(cells->matrix[i]);
    free (cells->matrix);
    free(cells);
    //free(settings->input);
    //free(settings->output);
    free(settings);
    return 0;
}


